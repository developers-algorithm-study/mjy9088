use std::io;

fn main() {
	let mut N = String::new();
	io::stdin().read_line(&mut N).expect("");
	let N: u32 = N.trim().parse().expect("");
	for i in 0..N
	{
		for i in 0..i + 1
		{
			print!("*");
		}
		println!();
	}
}
