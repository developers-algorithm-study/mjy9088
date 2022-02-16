use std::io;

const MINUTE_PER_HOUR: u32 = 60;
const HOUR_PER_DAY: u32 = 24;
const MINUTE_PER_DAY: u32 = MINUTE_PER_HOUR * HOUR_PER_DAY;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<u32>)
        .collect::<Vec<_>>();
    let result = n[1] + n[0] * MINUTE_PER_HOUR + MINUTE_PER_DAY - 45;
    let result = result % MINUTE_PER_DAY;

    println!("{} {}", result / MINUTE_PER_HOUR, result % MINUTE_PER_HOUR);
}
