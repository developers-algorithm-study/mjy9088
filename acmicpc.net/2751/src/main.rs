use std::{
    io::{self, Read},
};

fn main() {
    let mut contents = String::new();
    io::stdin().read_to_string(&mut contents).unwrap();
    let lines = contents.split('\n').collect::<Vec<_>>();
    let mut numbers = (0..lines[0].parse::<usize>().unwrap())
        .map(|i| lines[i + 1].parse::<i32>().unwrap())
        .collect::<Vec<_>>();
    numbers.sort();
    print!(
        "{}",
        numbers
            .iter()
            .fold(String::new(), |result, n| result + &n.to_string() + "\n")
    );
}
