use std::{collections::HashMap, io};

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut multi_set = HashMap::<i32, i32>::new();
    line.trim()
        .split(' ')
        .flat_map(str::parse::<i32>)
        .for_each(|x| match multi_set.get_mut(&x) {
            Some(v) => {
                *v = *v + 1;
            }
            None => {
                multi_set.insert(x, 1);
            }
        });
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    println!(
        "{}",
        line.trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .map(|x| multi_set.get(&x).unwrap_or(&0).to_string() + " ")
            .collect::<String>()
            .strip_suffix(' ')
            .unwrap()
    )
}
