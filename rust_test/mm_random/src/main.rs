use std::io;

#[allow(unused_variables)]
#[allow(unused_mut)]
fn main() {
    let mut count_str = String::new();
    io::stdin().read_line(&mut count_str).expect("Cannot input");
    let count = count_str.parse::<i32>();
    let mut numbers_str = String::new();
    io::stdin().read_line(&mut numbers_str).expect("Cannot input");
    let mut numbers_strs = numbers_str.trim().split(' ').collect::<Vec<&str>>();
    let mut numbers = Vec::<i32>::new();
    for i in numbers_strs {
        numbers.push(i.parse::<i32>().unwrap());
    }
    numbers.sort();
    numbers.dedup();
    println!("{}", numbers.len());
    for i in numbers {
        print!("{} ", i);
    }
    println!();
}
