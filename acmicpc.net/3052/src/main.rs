use std::io;
use std::collections::HashSet;

fn main() {
    println!("{}", (0..10).map(|_| {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        line.trim().parse::<i32>().unwrap() % 42
    }).collect::<HashSet<_>>().len());
}
