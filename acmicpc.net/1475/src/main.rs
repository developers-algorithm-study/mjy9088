use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut arr = [0; 9];
    input.trim().chars().for_each(|x| {
        if x == '9' {
            arr[6] += 1;
        } else {
            arr[(x as u8 - b'0') as usize] += 1;
        }
    });
    arr[6] = (arr[6] + 1) / 2;
    println!("{}", arr.iter().max().unwrap());
}
