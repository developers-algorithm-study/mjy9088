use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let test_cases = line.trim().parse::<i32>().unwrap();

    for _ in 0..test_cases {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        println!(
            "{}",
            line.chars().fold((0, 0), |(combo, score), current| {
                let combo = if current == 'O' { combo + 1 } else { 0 };
                (combo, score + combo)
            }).1
        );
    }
}
