use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let c = line.chars().nth(0).unwrap();
    println!("{}", c as u8);
}
