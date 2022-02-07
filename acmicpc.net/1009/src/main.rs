use std::io;

fn get_rotation(base: usize) -> Vec<Vec<usize>> {
	(0..base)
		.map(|i| {
			let mut set = vec![false; base];
			let mut result = Vec::<usize>::new();
			result.push(i);
			set[i] = true;
			for _ in 0..base {
				let last = result.last().unwrap();
				let current = last * i % base;
				if set[current] {
					break;
				}
				result.push(current);
				set[current] = true;
			}
			result
		})
		.collect()
}

fn main() {
	const BASE: usize = 10;
	let precalculated = get_rotation(BASE);

	let mut line = String::new();
	io::stdin().read_line(&mut line).unwrap();
	let test_cases = str::parse::<usize>(&mut line.trim()).unwrap();

	for _ in 0..test_cases {
		let mut line = String::new();
		io::stdin().read_line(&mut line).unwrap();
		let numbers = line
			.trim()
			.split(' ')
			.flat_map(str::parse::<usize>)
			.collect::<Vec<_>>();
		debug_assert!(numbers.len() == 2);
		debug_assert!(numbers[0] != 0 && numbers[1] != 0);
		let vec = &precalculated[numbers[0] % BASE];
		let result = vec[(numbers[1] - 1) % vec.len()];
		println!("{}", if result != 0 { result } else { BASE });
	}
}
