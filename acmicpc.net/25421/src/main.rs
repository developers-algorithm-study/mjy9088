use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let number = str::parse::<usize>(line.trim()).unwrap();
    let result = (1..number).fold(vec![0, 1, 1, 1, 1, 1, 1, 1, 1, 1], |acc, _| {
        (0..10)
            .map(|x| {
                (0..10)
                    .map(|y| {
                        if x <= y + 2 && x + 2 >= y && x != 0 && y != 0 {
                            acc[y]
                        } else {
                            0
                        }
                    })
                    .fold(0, |a, c| (a + c) % 987654321)
            })
            .collect::<Vec<_>>()
    });

    println!("{}", result.iter().fold(0, |a, c| (a + c) % 987654321));
}
