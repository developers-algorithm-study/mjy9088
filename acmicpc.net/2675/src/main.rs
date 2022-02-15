use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let test_cases = line.trim().parse::<u32>().unwrap();

    for _ in 0..test_cases {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let arr = line.trim().split(' ').collect::<Vec<&str>>();
        let num = arr[0].parse::<usize>().unwrap();
        println!(
            "{}",
            arr[1]
                .chars()
                .map(|c| std::iter::repeat(c).take(num).collect::<String>())
                .collect::<String>()
        )
    }
}
