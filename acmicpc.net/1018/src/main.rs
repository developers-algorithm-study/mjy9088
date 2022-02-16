use std::io;

const RESULT_SIZE: usize = 8;

fn range2d(
    from_x: usize,
    from_y: usize,
    to_x: usize,
    to_y: usize,
) -> impl Iterator<Item = (usize, usize)> {
    (from_y..to_y).flat_map(move |y| (from_x..to_x).map(move |x| (x, y)))
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let sizes = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<usize>)
        .collect::<Vec<_>>();

    let board = (0..sizes[0])
        .map(|_| {
            let mut line = String::new();
            io::stdin().read_line(&mut line).unwrap();
            line.trim()
                .chars()
                .map(|c| c == 'B')
                .collect::<Vec<_>>()
        })
        .collect::<Vec<_>>();

    println!(
        "{}",
        range2d(0, 0, sizes[1] - RESULT_SIZE + 1, sizes[0] - RESULT_SIZE + 1)
            .map(|(start_x, start_y)| {
                range2d(0, 0, RESULT_SIZE, RESULT_SIZE)
                    .filter(|(x, y)| {
                        let first_filled = x % 2 == y % 2;
                        first_filled == board[start_y + y][start_x + x]
                    })
                    .count()
            })
            .map(|c| {
                if c * 2 > RESULT_SIZE * RESULT_SIZE {
                    RESULT_SIZE * RESULT_SIZE - c
                } else {
                    c
                }
            })
            .min()
            .unwrap()
    )
}
