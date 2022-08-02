use std::fs::File;
use std::io::{stdout, Write};
use std::path::Path;

use crossterm::style::Stylize;
use getchar::getchar;
use rand::thread_rng;
use rand::*;

fn main() {
    let mut randomizer = thread_rng();
    randomizer.next_u32();
    let charset = "qwertyuiopasdfghjklzxcvbnm1234567890@#$_".chars().collect::<Vec<char>>();
    let charset2 = "qw".chars().collect::<Vec<char>>();
    let charset3 = "qwe".chars().collect::<Vec<char>>();
    let charset4 = "qwerty".chars().collect::<Vec<char>>();
    let which_charset = 1;
    let log_path = Path::new("run.log");
    let mut log_file = {
        if log_path.exists() {
            File::options().write(true).truncate(false).open(log_path)
        } else {
            File::create(log_path)
        }
    }.unwrap();
    let charset_to_use = match which_charset {
        1 => charset,
        2 => charset2,
        3 => charset3,
        4 => charset4,
        _ => charset,
    };

    loop {
        let cchar = charset_to_use[(randomizer.next_u32() as usize) % charset_to_use.len()];
        let c = getchar().unwrap_or(' ');
        if c == '\u{1b}' {
            let next_c = getchar().unwrap_or(' ');
            if next_c == '\u{1b}' {
                break;
            }
        }
        if cchar != c {
            print!("{}", cchar);
        } else {
            print!("{}", format!("{}", cchar).bold().red());
        }
        writeln!(&mut log_file, "{:?}", c).unwrap();
        stdout().flush().unwrap();
    }
    println!();
}
