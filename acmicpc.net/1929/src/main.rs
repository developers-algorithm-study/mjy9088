use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input = input
        .strip_suffix('\n')
        .unwrap()
        .split(' ')
        .flat_map(str::parse::<usize>)
        .collect::<Vec<_>>();
    let mut sieve = vec![true; input[1] + 1];
    sieve[0] = false;
    sieve[1] = false;
    for i in 2..=(input[1] as f64).sqrt() as usize {
        if i >= sieve.len() {
            break;
        }
        if !sieve[i] {
            continue;
        }
        for j in (i * 2..sieve.len()).step_by(i) {
            if j % i == 0 {
                sieve[j] = false;
            }
        }
    }
    print!("{}", sieve
        .iter()
        .enumerate()
        .filter(|(i, prime)| **prime && *i >= input[0])
        .fold(String::new(), |x, (i, _)| x + &i.to_string() + "\n")
    );
}
