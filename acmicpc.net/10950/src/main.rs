use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let test_cases = line.trim().parse::<i32>().unwrap();

    for _ in 0..test_cases {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let numbers = line
            .trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .collect::<Vec<_>>();
        println!("{}", numbers[0] + numbers[1])
    }
}
