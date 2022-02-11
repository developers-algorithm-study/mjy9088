use std::io;
use std::collections::VecDeque;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut deque = (0..line
        .trim()
        .split(' ')
        .next()
        .unwrap()
        .parse::<usize>()
        .unwrap())
        .collect::<VecDeque<_>>();

    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .into_iter()
        .map(|x| str::parse::<usize>(x).unwrap() - 1)
        .collect::<Vec<_>>();
    let mut result = 0;
    for i in numbers {
        let pos = deque.iter().position(|&j| j == i).unwrap();
        if pos != 0 {
            let len = deque.len();
            let right = len - pos;
            if right < pos {
                result = result + right;
                deque.rotate_right(right);
            } else {
                result = result + pos;
                deque.rotate_left(pos);
            }
        }
        deque.pop_front();
    }
    println!("{}", result);
}
