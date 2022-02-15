use std::io;

fn main() {
    let (max, idx) = (0..9)
        .map(|_| {
            let mut line = String::new();
            io::stdin().read_line(&mut line).unwrap();
            line.trim().parse::<usize>().unwrap()
        })
        .enumerate()
        .fold(
            (0usize, 0usize),
            |(max, idx), (i, n)| if max < n { (n, i) } else { (max, idx) },
        );
    println!("{}", max);
    println!("{}", idx + 1);
}
