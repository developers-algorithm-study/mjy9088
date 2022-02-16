use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    println!(
        "{}",
        ('a'..='z')
            .map(|a| {
                match line.chars().position(|c| c == a) {
                    None => -1,
                    Some(x) => x as i32,
                }
            })
            .fold(None as Option<String>, |result, idx| match result {
                None => Some(idx.to_string()),
                Some(x) => Some(x + " " + &idx.to_string()),
            })
            .unwrap()
    )
}
