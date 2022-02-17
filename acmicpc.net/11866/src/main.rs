use std::{collections::VecDeque, io};

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<usize>)
        .collect::<Vec<_>>();
    let mut queue = (1..=numbers[0]).collect::<VecDeque<_>>();
    let mut result = Vec::<usize>::new();
    let n = numbers[1] - 1;
    while queue.len() != 0 {
        queue.rotate_left(n % queue.len());
        result.push(queue.pop_front().unwrap());
    }
    println!(
        "<{}>",
        result
            .iter()
            .fold(String::new(), |result, x| result + &x.to_string() + ", ")
            .strip_suffix(", ")
            .unwrap()
    )
}
