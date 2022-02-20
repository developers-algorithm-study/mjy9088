use std::io;

fn get_line() -> Result<String, io::Error> {
    let mut line = String::new();
    match io::stdin().read_line(&mut line) {
        Ok(_) => Ok(line),
        Err(err) => Err(err),
    }
}

fn main() {
    let dividend = get_line().unwrap().trim().parse::<i32>().unwrap();
    let divisor = get_line().unwrap().trim().parse::<i32>().unwrap();
    let dividend = dividend / 100 * 100;
    for i in 0..100 {
        if (dividend + i) % divisor == 0 {
            println!("{:02}", i);
            break;
        }
    }
}
