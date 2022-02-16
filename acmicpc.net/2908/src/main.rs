use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let c = line.chars().collect::<Vec<_>>();
    let a = c[0..3].iter().rev().collect::<String>();
    let b = c[4..7].iter().rev().collect::<String>();

    if a.parse::<u32>().unwrap() > b.parse::<u32>().unwrap() {
        println!("{}", a);
    } else {
        println!("{}", b);
    }
}
