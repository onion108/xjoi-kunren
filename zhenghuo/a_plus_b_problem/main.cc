// Luogu P1001
// A+B Problem
// By 27Onion

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

using byte = unsigned char;

class vm_t {
    std::stack<byte> call_stack;
    std::stack<byte> mem_stack;
    std::vector<byte> ram;
    std::map<byte, unsigned int> intr_table;
    unsigned int pc;
    int registers[11] = {0};
    bool flag = false;

    void validate_regno(byte reg_no) {
        if (reg_no < 0 || reg_no >= 10) {
            throw std::invalid_argument("invalid register number");
        }
    }

    int concat_to_int(byte a_1, byte a_2, byte a_3, byte a_4) {
        return (a_1 << 24) + (a_2 << 16) + (a_3 << 8) + (a_4);
    }

    int content_of_reg(byte reg_no) {
        validate_regno(reg_no);
        return registers[reg_no];
    }

    public:

    vm_t() : ram(1024) {}

    void set_mem_at(unsigned int addr, byte val) {
        if (addr < ram.size()) {
            ram[addr] = val;
        } else {
            while(addr >= ram.size()) {
                ram.push_back(0);
            }
            ram[addr] = val;
        }
    }

    byte get_mem_at(unsigned int addr) {
        return addr < ram.size() ? ram[addr] : 0;
    }

    void write_to(std::vector<byte> data, unsigned start_addr) {
        int addr = start_addr;
        for (auto i : data) {
            set_mem_at(addr, i);
            addr++;
        }
    }

    void jmp_to(unsigned int addr) {
        pc = addr;
    }

    void call(unsigned int addr) {
        call_stack.push(pc);
        pc = addr;
    }

    void ret() {
        pc = call_stack.top();
        call_stack.pop();
    }

    void push(byte data) {
        mem_stack.push(data);
    }

    void pop() {
        registers[10] = mem_stack.top();
        mem_stack.pop();
    } 

    void mov(byte reg_no, int val) {
        validate_regno(reg_no);
        registers[reg_no] = val;
    }

    void mov_reg(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[reg_no2] = reg_no1;
    }
    
    void mov_ans(byte reg_no) {
        validate_regno(reg_no);
        registers[reg_no] = registers[10];
    }

    void add(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] + registers[reg_no2];
    }

    void sub(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] - registers[reg_no2];
    }

    void mul(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] * registers[reg_no2];
    }

    void div(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] / registers[reg_no2];
    }

    void mod(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] % registers[reg_no2];
    }

    void b_and(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] & registers[reg_no2];
    }

    void b_or(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] | registers[reg_no2];
    }

    void b_xor(byte reg_no1, byte reg_no2) {
        validate_regno(reg_no1);
        validate_regno(reg_no2);
        registers[10] = registers[reg_no1] ^ registers[reg_no2];
    }

    void b_not(byte reg_no) {
        validate_regno(reg_no);
        registers[10] = ~registers[reg_no];
    }

    // TODO: more interrupts.
    void intr(byte intr_code) {

        if (intr_code == 0x00) {
            // Output number intr.
            // r0: the number to output.
            cout << content_of_reg(0) << endl;
            return;
        }

        if (intr_code == 0x01) {
            // Read a number into the answer register.
            cin >> registers[10];
            return;
        }

        if (intr_code == 0x02) {
            // Output a character
            // r0: the character.
            cout << char(registers[0]);
            return;
        }

        if (intr_code == 0x03) {
            // Read a charater into the answer register.
            registers[10] = getchar();
            return;
        }

        if (intr_code == 0x05) {
            // Output pc's value
            cout << pc << endl;
        }

        // Otherwise, custom intr.
        call(intr_table[intr_code]);
        pc--;

    }

    void rshift(byte reg_no) {
        validate_regno(reg_no);
        registers[reg_no] >>= 1;
    }

    void lshift(byte reg_no) {
        validate_regno(reg_no);
        registers[reg_no] <<= 1;
    }

    void regist_interrupt(byte intr_no, unsigned int addr) {
        intr_table[intr_no] = addr;
    }

    void jmp_cond(unsigned int addr) {
        if (flag) {
            pc = addr;
        }
    }

    void store(byte reg_no, byte reg_addr) {
        validate_regno(reg_no);
        validate_regno(reg_addr);
        set_mem_at(registers[reg_addr], registers[reg_no]);
    }

    void load(byte reg_no, byte reg_addr) {
        validate_regno(reg_no);
        validate_regno(reg_addr);
        registers[reg_no] = get_mem_at(registers[reg_addr]);
    }

    void compare(byte reg_no1, byte reg_no2, byte mode) {

        auto r1_cont = content_of_reg(reg_no1);
        auto r2_cont = content_of_reg(reg_no2);

        // TODO: implement compare;
        if (mode == 0x00) {
            // Equal
            flag = (r1_cont == r2_cont);
            return;
        }

        if (mode == 0x01) {
            // Non-Equal
            flag = (r1_cont != r2_cont);
            return;
        }

        if (mode == 0x02) {
            // Greater than
            flag = (r1_cont > r2_cont);
            return;
        }

        if (mode == 0x03) {
            // Less than
            flag = (r1_cont < r2_cont);
            return;
        }

        if (mode == 0x04) {
            // Greater or Equal
            flag = (r1_cont >= r2_cont);
            return;
        }

        if (mode == 0x05) {
            // Less than or Equal
            flag = (r1_cont <= r2_cont);
            return;
        }

    }

    void exec_byte() {
        const int op_code = get_mem_at(pc);
        byte a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, a_9, a_10;
        switch (op_code)
        {
        case 0x00: // nop
        break;

        case 0x01: // mov #num:i32#, a1 ;mov number to a1
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        a_3 = ram[++pc];
        a_4 = ram[++pc];
        a_5 = ram[++pc];
        mov(a_5, concat_to_int(a_1, a_2, a_3, a_4));
        break;

        case 0x02: // mov a1, a2 ; move a1 to a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        mov_reg(a_1, a_2);
        break;

        case 0x03: // mov_ans a1 ; move the content of the answer reg to the a1
        a_1 = ram[++pc];
        mov_ans(a_1);
        break;

        case 0x04: // intr #num:i8#
        a_1 = ram[++pc];
        intr(a_1);
        break;

        case 0x05: // intr a1
        a_1 = ram[++pc];
        intr(byte(content_of_reg(a_1)));

        case 0x06: // store a1, a2 ; store a1's content to the address stored in a2.
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        store(a_1, a_2);
        break;

        case 0x07: // load a1, a2 ; Same as store, but load.
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        load(a_1, a_2);
        break;

        case 0x08: // add a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        add(a_1, a_2);
        break;

        case 0x09: // sub a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        sub(a_1, a_2);
        break;

        case 0x0A: // mul a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        mul(a_1, a_2);
        break;

        case 0x0B: // div a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        div(a_1, a_2);
        break;

        case 0x0C: // mod a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        mod(a_1, a_2);
        break;

        case 0x0D: // and a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        b_and(a_1, a_2);
        break;

        case 0x0E: // or a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        b_or(a_1, a_2);
        break;

        case 0x0F: // xor a1, a2
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        b_xor(a_1, a_2);
        break;

        case 0x10: // not a1
        a_1 = ram[++pc];
        b_not(a_1);
        break;

        case 0x11: // jmp a1
        a_1 = ram[++pc];
        jmp_to(content_of_reg(a_1));
        return;
        
        case 0x12: // jmp #num:i32#
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        a_3 = ram[++pc];
        a_4 = ram[++pc];
        jmp_to(concat_to_int(a_1, a_2, a_3, a_4));
        return;

        case 0x13: // lsf a1
        a_1 = ram[++pc];
        lshift(a_1);
        break;

        case 0x14: // rsf a2
        a_1 = ram[++pc];
        rshift(a_1);
        break;

        case 0x15: // jmp_cond a1
        a_1 = ram[++pc];
        jmp_cond(content_of_reg(a_1));
        if (flag) {
            return;
        }
        break;

        case 0x16: // jmp_cond #num:i32#
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        a_3 = ram[++pc];
        a_4 = ram[++pc];
        jmp_cond(concat_to_int(a_1, a_2, a_3, a_4));
        if (flag) {
            return;
        }
        break;

        case 0x17: // stop
        throw -1;
        break;

        case 0x18: // cmp a1, a2, #mode: i8#
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        a_3 = ram[++pc];
        compare(a_1, a_2, a_3);
        break;

        case 0x19: // call #num:i32#
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        a_3 = ram[++pc];
        a_4 = ram[++pc];
        call(concat_to_int(a_1, a_2, a_3, a_4));
        return;

        case 0x20: // call a1
        a_1 = ram[++pc];
        call(content_of_reg(a_1));
        return;

        case 0x21: // ret
        ret();
        return;

        case 0x22: // push #num:i8#
        a_1 = ram[++pc];
        push(a_1);
        break;

        case 0x23: // push a1
        a_1 = ram[++pc];
        push(content_of_reg(a_1));
        break;

        case 0x24: // pop
        pop();
        break;

        case 0x25: // rin #num:i8# #num:i32# ; Register the interrupt. The first is the intr number and the second is the addr.
        a_1 = ram[++pc];
        a_2 = ram[++pc];
        a_3 = ram[++pc];
        a_4 = ram[++pc];
        a_5 = ram[++pc];
        regist_interrupt(a_1, concat_to_int(a_2, a_3, a_4, a_5));
        break;

        default:
        throw std::runtime_error("ud2: undefined instruction.");
        break;
        }
        pc++;
    }

    void boot() {
        pc = 0x7c00; // Load MBR.
        while(1) {
            try {
                exec_byte();
                // printf("0x%08X\n", pc);
                // printf("%d\n", content_of_reg(5));
            } catch(int e) {
                if (e == -1) {
                    break;
                }
            }
        }
    }


};

int main() {
    vm_t computer;
    computer.write_to(std::vector<unsigned char> {
        0x04, 0x01,                               // intr 0x01
        0x03, 0x00,                               // mov_ans r0
        0x04, 0x01,                               // intr 0x01
        0x03, 0x01,                               // mov_ans r1
        0x08, 0x00, 0x01,                         // add r0, r1
        0x03, 0x00,                               // mov_ans r0
        0x04, 0x00,                               // intr 0x00
        0x12, 0x00, 0x00, 0x7c, 0x05              // jmp 0x7c05
    }, 0x0000);
    computer.write_to(std::vector<unsigned char> {
        0x12, 0x00, 0x00, 0x00, 0x00,             // jmp 0x00000000
        0x01, 0x00, 0x00, 0x00, 0x00, 0x05,       // mov 0x00, r5 ;Use r5 as a counter
        0x01, 0x00, 0x00, 0x00, 0x05, 0x06,       // mov 0x05, r6 ;Loop 6 times
        0x01, 0x00, 0x00, 0x00, 0x0A, 0x00,       // mov 0x0A, r0
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x48, 0x00,       // mov 0x48, r0 ;'H'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x65, 0x00,       // mov 0x65, r0 ;'e'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x6C, 0x00,       // mov 0x6C, r0 ;'l'
        0x04, 0x02,                               // intr 0x02
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x6F, 0x00,       // mov 0x6F, r0 ;'o'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x2C, 0x00,       // mov 0x2C, r0 ;','
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x20, 0x00,       // mov 0x20, r0 ;' '
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x77, 0x00,       // mov 0x77, r0 ;'w'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x6F, 0x00,       // mov 0x6F, r0 ;'o'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x72, 0x00,       // mov 0x72, r0 ;'r'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x6C, 0x00,       // mov 0x6C, r0 ;'l'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x64, 0x00,       // mov 0x64, r0 ;'d'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x21, 0x00,       // mov 0x21, r0 ;'!'
        0x04, 0x02,                               // intr 0x02
        0x01, 0x00, 0x00, 0x00, 0x0A, 0x00,       // mov 0x0A, r0 ;'\n'
        0x04, 0x02,                               // intr 0x02
        0x18, 0x05, 0x06, 0x03,                   // cmp r5, r6, 0x03
        0x01, 0x00, 0x00, 0x00, 0x01, 0x07,       // mov 0x01, r7
        0x08, 0x05, 0x07,                         // add r5, r7
        0x03, 0x05,                               // mov_ans r5
        0x16, 0x00, 0x00, 0x7c, 0x0B,             // jmp_cond 0x7c0b
        0x17,                                     // stop
    }, 0x7c00);
    computer.boot();
}
