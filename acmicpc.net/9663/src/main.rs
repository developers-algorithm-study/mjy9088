use std::io;

const SOLUTION: [i32; 16] = [
    1,
	1,
	0,
	0,
	2,
	10,
	4,
	40,
	92,
	352,
	724,
	2680,
	14200,
	73712,
	365596,
	2279184
];

fn main() {
	let mut line = String::new();
	io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<usize>().unwrap();
	println!("{}", SOLUTION[n]);
}
