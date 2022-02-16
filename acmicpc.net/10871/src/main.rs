use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let x = line
        .trim()
        .split(' ')
        .nth(1)
        .unwrap()
        .parse::<i32>()
        .unwrap();

    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    println!(
        "{}",
        line.trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .filter(|&i| i < x)
            .fold(None as Option<String>, |result, idx| match result {
                None => Some(idx.to_string()),
                Some(x) => Some(x + " " + &idx.to_string()),
            })
            .unwrap()
    );
}
