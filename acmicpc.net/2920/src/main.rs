use std::io;
use std::ops::ControlFlow;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    match line.trim().split(' ').flat_map(str::parse::<u32>).try_fold(
        (None as Option<u32>, true, true),
        |(prev, ascending, descending), i| {
            let ascending = match prev {
                None => true,
                Some(x) => ascending && i >= x,
            };
            let descending = match prev {
                None => true,
                Some(x) => descending && i <= x,
            };
            if ascending || descending {
                ControlFlow::Continue((Some(i), ascending, descending))
            } else {
                ControlFlow::Break(())
            }
        },
    ) {
        ControlFlow::Continue((_, ascending, descending)) => {
            if ascending {
                println!("ascending");
            }
            if descending {
                println!("descending");
            }
        }
        ControlFlow::Break(_) => println!("mixed"),
    }
}
