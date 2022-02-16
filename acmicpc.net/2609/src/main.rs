use std::io;

fn gcd(a: u32, b: u32) -> u32 {
    let r = a % b;
    if r == 0 {
        b
    } else {
        gcd(b, r)
    }
}

fn lcm(a: u32, b: u32, gcd: u32) -> u32 {
    a * b / gcd
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<u32>)
        .collect::<Vec<_>>();
    let gcd = gcd(numbers[0], numbers[1]);
    let lcm = lcm(numbers[0], numbers[1], gcd);
    println!("{}", gcd);
    println!("{}", lcm);
}
