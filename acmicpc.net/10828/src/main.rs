use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let command_count = line.trim().parse::<usize>().unwrap();
    let mut stack = Vec::<i32>::new();

    for _ in 0..command_count {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let argv = line.trim().split(' ').collect::<Vec<_>>();
        match argv[0] {
            "push" => stack.push(argv[1].parse::<i32>().unwrap()),
            "pop" => println!("{}", stack.pop().unwrap_or(-1)),
            "size" => println!("{}", stack.len()),
            "empty" => println!("{}", if stack.len() == 0 { 1 } else { 0 }),
            "top" => println!("{}", stack.last().unwrap_or(&-1)),
            _ => panic!("Invalud input"),
        }
    }
}
