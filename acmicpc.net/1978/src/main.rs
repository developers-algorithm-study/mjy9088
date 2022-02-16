use std::io;

const MAX: usize = 1000;

fn main() {
    let mut is_prime = [true; MAX + 1];
    is_prime[0] = false;
    is_prime[1] = false;
    for n in 2..=MAX / 2 {
        if !is_prime[n] {
            continue;
        }
        for n in (n * 2..=MAX).step_by(n) {
            is_prime[n] = false;
        }
    }
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    println!(
        "{}",
        line.trim()
            .split(' ')
            .map(|n| is_prime[n.trim().parse::<usize>().unwrap()])
            .filter(|&x| x)
            .count()
    );
}
