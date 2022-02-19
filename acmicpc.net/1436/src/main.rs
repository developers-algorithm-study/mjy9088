use std::io;

fn has666(n: i32) -> bool {
    n.to_string().contains("666")
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let number = line.trim().parse::<i32>().unwrap();
    let mut i = 666;
    let mut count = 1;
    while count != number {
        i = i + 1;
        while !has666(i) {
            i = i + 1;
        }
        count = count + 1;
    }
    println!("{}", i);
}
