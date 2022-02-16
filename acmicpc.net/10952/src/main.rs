use std::io;

fn main() {
    loop {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let numbers = line
            .trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .collect::<Vec<_>>();
        if numbers[0] == 0 && numbers[1] == 0 {
            break;
        }
        println!("{}", numbers[0] + numbers[1])
    }
}
