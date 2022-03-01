use std::{
    collections::HashMap,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .strip_suffix('\n')
        .unwrap()
        .split('\n')
        .skip(1)
        .flat_map(str::parse::<i32>)
        .collect::<Vec<_>>();
    input.sort();
    let sum = input.iter().fold(0, |sum, x| sum + x);
    println!(
        "{}",
        (sum as f64 / input.len() as f64 + 0.5 * sum.signum() as f64) as i32
    );
    println!("{}", input[input.len() / 2]);
    let mut count = HashMap::<i32, u32>::new();
    input.iter().for_each(|x| {
        match count.get_mut(x) {
            None => {
                count.insert(*x, 1);
            }
            Some(value) => {
                *value += 1;
            }
        };
    });
    let count = count.into_iter().collect::<Vec<_>>();
    let max_count = count
        .iter()
        .fold(None, |prev, (_, count)| match prev {
            None => Some(count),
            Some(max) => Some(if max < count { count } else { max }),
        })
        .unwrap();
    let mut max = count
        .iter()
        .filter(|(_, x)| x == max_count)
        .map(|x| x.0)
        .collect::<Vec<_>>();
    max.sort();
    println!(
        "{}",
        match max.len() {
            1 => max[0],
            _ => max[1],
        }
    );
    println!("{}", input.last().unwrap() - input.first().unwrap());
}
