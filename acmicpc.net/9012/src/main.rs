use std::{io, ops::ControlFlow};

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let test_cases = line.trim().parse::<usize>().unwrap();

    for _ in 0..test_cases {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();

        println!(
            "{}",
            match line.trim().chars().try_fold(0, |depth, c| {
                if c == '(' {
                    ControlFlow::Continue(depth + 1)
                } else if depth == 0 {
                    ControlFlow::Break(())
                } else {
                    ControlFlow::Continue(depth - 1)
                }
            }) {
                ControlFlow::Continue(x) =>
                    if x == 0 {
                        "YES"
                    } else {
                        "NO"
                    },
                _ => "NO",
            }
        );
    }
}
