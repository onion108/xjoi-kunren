use std::{time::Duration, sync::Mutex, ops::AddAssign};
static mut a: i32 = 0;

fn main() {
    let handler = std::thread::spawn(|| {
        std::thread::sleep(Duration::from_millis(1000));
        println!("Hello, World! from thread");
        unsafe {
            a = 3;
        }
    });
    std::thread::sleep(Duration::from_millis(2000));
    println!("Hello, World! (from main())");
    match handler.join() {
        Ok(_) => {},
        Err(e) => println!("Cannot join: {:?}", e),
    }
    unsafe {
        println!("{}", a);
    }
}
