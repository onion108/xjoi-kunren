fn read_numberline() -> Vec<i32> {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let mut result = Vec::<i32>::new();
    let splitted = line.trim().split(' ');
    for i in splitted {
        if i == "" {
            continue;
        } else {
            result.push(i.parse().unwrap());
        }
    }
    result
}

fn main() {
    let numbers = read_numberline();
    let mut dp = Vec::<i32>::new();
    for _i in 1..=(numbers[0] + 5) {
        dp.push(0);
    }
    dp[0] = 1;
    for i in 1..=numbers[0] {
        let mut sum = 0;
        let mut j = i - 1;
        let mut ct = 0;
        while j >= 0 && ct < numbers[1] {
            sum += dp[j as usize] % 100003;
            j -= 1;
            ct += 1;
        }
        dp[i as usize] = sum % 100003;
    }
    println!("{}", dp[numbers[0] as usize]);
}
