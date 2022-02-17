use std::io::{self, Read};

fn main() {
    let mut contents = String::new();
    io::stdin().read_to_string(&mut contents).unwrap();
    let lines = contents.split('\n').collect::<Vec<_>>();
    let mut numbers = (1..=lines[0].trim().parse::<usize>().unwrap())
        .map(|i| {
            let mut tmp = lines[i].trim().split(' ');
            (
                tmp.nth(0).unwrap().parse::<i32>().unwrap(),
                tmp.nth(0).unwrap().parse::<i32>().unwrap(),
            )
        })
        .collect::<Vec<_>>();
    numbers.sort_by(|s1, s2| s1.0.cmp(&s2.0).then(s1.1.cmp(&s2.1)));
    let mut output = String::new();
    for (a, b) in numbers {
        output = output + &a.to_string() + " " + &b.to_string() + "\n";
    }
    print!("{}", output);
}
