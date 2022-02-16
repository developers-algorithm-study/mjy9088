use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<u32>().unwrap();

    print!(
        "{}",
        (0..n)
            .map(|i| {
                let mut result = (n - i).to_string();
                result.push('\n');
                result
            })
            .collect::<String>()
    )
}
