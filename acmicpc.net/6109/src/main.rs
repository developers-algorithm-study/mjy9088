use std::io;

fn tuple2(vec: Vec<i32>) -> (i32, i32) {
    debug_assert!(vec.len() == 2);
    (vec[0], vec[1])
}

fn solve(target: i32, types: &[i32]) -> i32 {
    if types.len() == 1 {
        match target % types[0] {
            0 => 1,
            _ => 0,
        }
    } else {
        (0..=(target / types[0]))
            .map(|x| solve(target - x * types[0], &types[1..]))
            .sum()
    }
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let (target, count) = tuple2(
        line.trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .collect::<Vec<_>>(),
    );
    let mut types = Vec::<i32>::new();
    for _ in 0..count {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        types.push(line.trim().parse::<i32>().unwrap())
    }
    println!("{}", solve(target, &types));
}
