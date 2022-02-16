use std::io;

fn main() {
    loop {
        let mut line = String::new();
        if io::stdin().read_line(&mut line).is_err() || line.len() == 0 {
            break;
        }
        let numbers = line
            .trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .collect::<Vec<_>>();
        println!("{}", numbers[0] + numbers[1])
    }
}
