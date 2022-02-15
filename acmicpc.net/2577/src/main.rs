use std::io;

const BASE: u32 = 10;

fn main() {
    let num = (0..3)
        .map(|_| {
            let mut line = String::new();
            io::stdin().read_line(&mut line).unwrap();
            line.trim().parse::<u32>().unwrap()
        })
        .fold(1, |result, x| result * x);
    for i in 0..BASE {
        let mut result = 0;
        let mut tmp = num;
        while tmp != 0 {
            if tmp % BASE == i {
                result = result + 1;
            }
            tmp = tmp / BASE;
        }
        println!("{}", result);
    }
}
