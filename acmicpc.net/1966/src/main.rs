use std::{
    collections::VecDeque,
    io::{self, Read},
};

fn main() {
    let mut lines = String::new();
    io::stdin().read_to_string(&mut lines).unwrap();
    let lines = lines
        .strip_suffix('\n')
        .unwrap()
        .split('\n')
        .collect::<Vec<_>>();
    let test_cases = lines[0].parse::<usize>().unwrap();
    for i in 0..test_cases {
        let mut result = 0;
        let mut offset = lines[2 * i + 1]
            .split(' ')
            .nth(1)
            .unwrap()
            .parse::<usize>()
            .unwrap();
        let mut queue = lines[2 * i + 2]
            .split(' ')
            .flat_map(str::parse::<i32>)
            .collect::<VecDeque<_>>();
        loop {
            let (index, max) = queue.iter().enumerate().skip(1).fold(
                (0usize, queue[0]),
                |(index, max), (i, &x)| {
                    if max < x {
                        (i, x)
                    } else {
                        (index, max)
                    }
                },
            );
            if queue[0] < max {
                queue.rotate_left(index);
                offset = (queue.len() - index + offset) % queue.len();
            } else if offset == 0 {
                break;
            } else {
                result += 1;
                offset -= 1;
                queue.pop_front();
            }
        }
        println!("{}", result + 1);
    }
}
