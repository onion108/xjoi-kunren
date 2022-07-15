fn main() {
    let mut line_buffer = String::new();
    std::io::stdin().read_line(&mut line_buffer).expect("Fuck, can't read line");
    let splitted_line_buffer: Vec<&str> = line_buffer.trim().split(" ").collect();
    println!("{}", splitted_line_buffer[0].parse::<i32>().expect("cannot parse to int!") + splitted_line_buffer[1].parse::<i32>().expect("cannot parse to int!"));
}
