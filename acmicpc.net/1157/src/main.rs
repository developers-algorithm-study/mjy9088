use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let &mut arr = line.to_uppercase().chars().fold(&mut [0; 26], |arr, c| {
        if c.is_alphabetic() {
            let idx = c as usize - 'A' as usize;
            arr[idx] = arr[idx] + 1;
        }
        arr
    });

    println!(
        "{}",
        arr.iter()
            .enumerate()
            .fold((0, '?'), |(max_count, result), (index, &count)| {
                if count > max_count {
                    (count, ('A' as usize + index) as u8 as char)
                } else if count == max_count {
                    (max_count, '?')
                } else {
                    (max_count, result)
                }
            })
            .1
    );
}
