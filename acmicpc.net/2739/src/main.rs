use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<u32>().unwrap();

    for i in 1..=9 {
        println!("{} * {} = {}", n, i, n * i);
    }
}
