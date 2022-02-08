use std::io;

fn tuple3(vec: &Vec<i32>) -> (i32, i32, i32) {
    debug_assert!(vec.len() == 3);
    (vec[0], vec[1], vec[2])
}
fn tuple4(vec: &Vec<i32>) -> (i32, i32, i32, i32) {
    debug_assert!(vec.len() == 4);
    (vec[0], vec[1], vec[2], vec[3])
}

fn process_case() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<i32>)
        .collect::<Vec<_>>();
    let (from_x, from_y, to_x, to_y) = tuple4(&numbers);
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let line_count = str::parse::<i32>(&mut line.trim()).unwrap();
    let mut result = 0;
    for _ in 0..line_count {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let numbers = line
            .trim()
            .split(' ')
            .flat_map(str::parse::<i32>)
            .collect::<Vec<_>>();
        let (x, y, radius) = tuple3(&numbers);
        let radius_sqr = radius * radius;

        let (dx, dy) = (from_x - x, from_y - y);
        let distance_from_sqr = dx * dx + dy * dy;
        let is_from_in = distance_from_sqr > radius_sqr;

        let (dx, dy) = (to_x - x, to_y - y);
        let distance_to_sqr = dx * dx + dy * dy;
        let is_to_in = distance_to_sqr > radius_sqr;

        if is_from_in != is_to_in {
            result = result + 1;
        }
    }
    println!("{}", result);
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let test_cases = str::parse::<i32>(&mut line.trim()).unwrap();
    for _ in 0..test_cases {
        process_case();
    }
}
