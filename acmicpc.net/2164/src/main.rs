use std::io;

const MSB_START: u32 = 262144;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<u32>().unwrap();
    println!("{}", match n {
        1 => 1,
        2 => 2,
        _ => {
            let mut msb = MSB_START;
            while n <= msb {
                msb = msb >> 1;
            }
            (n - msb) * 2
        }
    })
}
