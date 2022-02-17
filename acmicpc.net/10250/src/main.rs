use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let test_cases = line.trim().parse::<usize>().unwrap();
    for _ in 0..test_cases {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let numbers = line
            .trim()
            .split(' ')
            .flat_map(str::parse::<usize>)
            .collect::<Vec<_>>();
        println!(
            "{}{:0>2}",
            (numbers[2] - 1) % numbers[0] + 1,
            (numbers[2] - 1) / numbers[0] + 1
        )
    }
}
