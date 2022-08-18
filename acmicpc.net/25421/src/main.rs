use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let number = str::parse::<usize>(line.trim()).unwrap();
    let result = (1..number).fold(vec![1; 9], |acc, _| {
        (0..9)
            .map(|x| {
                (0..9)
                    .map(|y| if x <= y + 2 && x + 2 >= y { acc[y] } else { 0 })
                    .fold(0, |a, c| (a + c) % 987654321)
            })
            .collect::<Vec<_>>()
    });

    println!("{}", result.iter().fold(0, |a, c| (a + c) % 987654321));
}
