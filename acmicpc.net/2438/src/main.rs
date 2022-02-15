use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let size = line.trim().parse::<usize>().unwrap();

    for width in 1..=size {
        println!("{}", std::iter::repeat("*").take(width).collect::<String>());
    }
}
