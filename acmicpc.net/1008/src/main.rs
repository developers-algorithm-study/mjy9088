use std::io;

fn main() {
	let mut line = String::new();
	io::stdin().read_line(&mut line).unwrap();

	let numbers = line
		.trim()
		.split(' ')
		.flat_map(str::parse::<i32>)
		.collect::<Vec<_>>();
	debug_assert!(numbers.len() == 2);
	println!("{:.11}", numbers[0] as f64 / numbers[1] as f64);
}
