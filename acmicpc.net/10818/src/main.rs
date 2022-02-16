use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let (min, max) = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<i32>)
        .fold(None as Option<(i32, i32)>, |prev, i| match prev {
            None => Some((i, i)),
            Some((min, max)) => {
                Some((if min < i { min } else { i }, if max > i { max } else { i }))
            }
        })
        .unwrap();
    println!("{} {}", min, max);
}
