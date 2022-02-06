use std::io;

const N_MAX: usize = 40;

fn fibonacci_precalculate(n: usize) -> Vec<i32> {
	let mut result = Vec::<i32>::new();
	let mut current: i32 = 1;
	let mut prev: i32 = 0;
	for _i in 0..=n {
		result.push(prev);
		let tmp = prev;
		prev = current;
		current = current + tmp;
	}
	result
}

fn main() {
	let precalculated = fibonacci_precalculate(N_MAX);

	let mut line = String::new();
	io::stdin().read_line(&mut line).unwrap();
	let test_cases = str::parse::<i32>(&mut line.trim()).unwrap();

	for _ in 0..test_cases {
		let mut line = String::new();
		io::stdin().read_line(&mut line).unwrap();
		let n = str::parse::<usize>(&mut line.trim()).unwrap();
		debug_assert!(n <= N_MAX);
		println!(
			"{} {}",
			if n == 0 { 1 } else { precalculated[n - 1] },
			precalculated[n]
		);
	}
}
