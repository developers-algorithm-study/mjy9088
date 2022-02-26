use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let input = input
        .strip_suffix('\n')
        .unwrap()
        .split('\n')
        .skip(1)
        .flat_map(str::parse::<i32>)
        .collect::<Vec<_>>();
    let mut result = String::new();
    let mut stack = Vec::<i32>::new();
    let mut tmp = 1;
    for i in input {
        while i >= tmp {
            result += "+\n";
            stack.push(tmp);
            tmp += 1;
        }
        if stack.len() == 0 || stack.pop().unwrap() != i {
            result = "NO\n".to_string();
            break;
        }
        result += "-\n";
    }
    print!("{}", result);
}
