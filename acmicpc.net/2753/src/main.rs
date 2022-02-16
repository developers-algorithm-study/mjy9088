use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<u32>().unwrap();

    println!(
        "{}",
        if n % 4 == 0 && (n % 100 != 0 || n % 400 == 0) {
            1
        } else {
            0
        }
    )
}
