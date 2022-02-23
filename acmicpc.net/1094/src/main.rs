use std::io;

const START: i32 = 64;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input = input.trim().parse::<i32>().unwrap();
    let mut result = 1;
    let mut dropped = 0;
    while START - dropped != input {
        let mut smallest = START - dropped;
        while START - dropped > input {
            smallest = smallest / 2;
            if START - dropped - smallest >= input {
                dropped = dropped + smallest;
            } else {
                result = result + 1;
            }
        }
    }
    println!("{}", result);
}
