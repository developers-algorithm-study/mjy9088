use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    println!(
        "{}",
        line.trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .map(|x| x * x)
            .fold(0, |result, i| result + i)
            % 10
    );
}
