use std::io;

fn main() {
    loop {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let mut numbers = line
            .trim()
            .split(' ')
            .flat_map(str::parse::<usize>)
            .collect::<Vec<_>>();
        if numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 {
            break;
        }
        numbers.sort();
        println!(
            "{}",
            if numbers[0] * numbers[0] + numbers[1] * numbers[1] == numbers[2] * numbers[2] {
                "right"
            } else {
                "wrong"
            }
        )
    }
}
