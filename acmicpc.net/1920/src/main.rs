use std::{
    collections::{HashSet, LinkedList},
    io::{self, Read},
};

fn main() {
    let mut contents = String::new();
    io::stdin().read_to_string(&mut contents).unwrap();
    let mut lines = contents.split('\n').collect::<LinkedList<_>>();
    lines.pop_front();
    let set = lines
        .pop_front()
        .unwrap()
        .split(' ')
        .flat_map(str::parse::<i32>)
        .collect::<HashSet<_>>();

    let mut output = String::new();

    lines.pop_front();
    for i in lines
        .pop_front()
        .unwrap()
        .split(' ')
        .flat_map(str::parse::<i32>)
    {
        output = output + if set.contains(&i) { "1\n" } else { "0\n" }
    }

    print!("{}", output);
}
