use std::{io, collections::VecDeque};

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let command_count = line.trim().parse::<usize>().unwrap();
    let mut queue = VecDeque::<i32>::new();

    for _ in 0..command_count {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let argv = line.trim().split(' ').collect::<Vec<_>>();
        match argv[0] {
            "push" => queue.push_back(argv[1].parse::<i32>().unwrap()),
            "pop" => println!("{}", queue.pop_front().unwrap_or(-1)),
            "size" => println!("{}", queue.len()),
            "empty" => println!("{}", if queue.len() == 0 { 1 } else { 0 }),
            "front" => println!("{}", queue.front().unwrap_or(&-1)),
            "back" => println!("{}", queue.back().unwrap_or(&-1)),
            _ => panic!("Invalid input"),
        }
    }
}
