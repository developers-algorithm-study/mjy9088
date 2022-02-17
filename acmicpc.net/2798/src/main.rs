use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<usize>)
        .collect::<Vec<_>>();
    let count = numbers[0];
    let max = numbers[1];
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<usize>)
        .collect::<Vec<_>>();
    println!(
        "{}",
        (0..count)
            .flat_map(|n| (n + 1..count).map(move |x| (n, x)))
            .flat_map(|(a, b)| (b + 1..count).map(move |c| (a, b, c)))
            .map(|(a, b, c)| numbers[a] + numbers[b] + numbers[c])
            .filter(|x| x <= &max)
            .max()
            .unwrap()
    );
}
