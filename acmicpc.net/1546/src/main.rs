use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let (max, sum, count) = line.trim().split(' ').flat_map(str::parse::<i32>).fold(
        (0, 0, 0),
        |(max, sum, count), score| {
            (
                if max < score { score } else { max },
                sum + score,
                count + 1,
            )
        },
    );
    println!("{:.3}", sum as f64 / count as f64 / max as f64 * 100.0);
}
