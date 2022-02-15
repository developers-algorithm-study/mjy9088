use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    println!(
        "{}",
        line.chars().fold((0, true), |(len, space), c| {
            if c.is_whitespace() {
                if space {
                    (len, true)
                } else {
                    (len + 1, true)
                }
            } else {
                (len, false)
            }
        }).0
    );
}
