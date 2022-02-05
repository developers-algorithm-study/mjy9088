use std::io;

fn main() {
	let mut line = String::new();
	assert!(!io::stdin().read_line(&mut line).is_err());

	let numbers = line
		.trim()
		.split(' ')
		.flat_map(str::parse::<i32>)
		.collect::<Vec<_>>();
	assert!(numbers.len() == 2);
	println!("{}", numbers[0] + numbers[1]);
}
