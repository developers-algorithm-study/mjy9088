use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<i32>)
        .collect::<Vec<_>>();

    println!("{}", numbers[0] + numbers[1]);
    println!("{}", numbers[0] - numbers[1]);
    println!("{}", numbers[0] * numbers[1]);
    println!("{}", numbers[0] / numbers[1]);
    println!("{}", numbers[0] % numbers[1]);
}
