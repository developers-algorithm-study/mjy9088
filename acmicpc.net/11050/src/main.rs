use std::io;

fn dp_factorial(to: i32, from: i32, prev: i32) -> i32 {
    (from + 1..=to).fold(prev, |prev, i| {
        prev * i
    })
}

fn binomial_coefficient(n: i32, k: i32) -> i32 {
    if n < k || k < 0 {
        0
    } else {
        let t = n - k;
        let (k, t) = if k < t { (t, k) } else { (k, t) };
        let t_factorial = dp_factorial(t, 1, 1);
        let k_factorial = dp_factorial(k, t, t_factorial);
        let n_factorial = dp_factorial(n, k, k_factorial);
        n_factorial / k_factorial / t_factorial
    }
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<i32>)
        .collect::<Vec<_>>();
    let n = numbers[0];
    let k = numbers[1];
    println!("{}", binomial_coefficient(n, k));
}
