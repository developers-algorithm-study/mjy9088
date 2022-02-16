use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    println!(
        "{}",
        line.trim().chars().fold(0, |result, i| result
            + i.to_string().parse::<i32>().unwrap())
    );
}
