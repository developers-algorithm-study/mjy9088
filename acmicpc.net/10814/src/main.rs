use std::io::{self, Read};

fn main() {
    let mut contents = String::new();
    io::stdin().read_to_string(&mut contents).unwrap();
    let lines = contents.split('\n').collect::<Vec<_>>();
    let mut members = (1..=lines[0].trim().parse::<usize>().unwrap())
        .map(|i| {
            let mut tmp = lines[i].trim().split(' ');
            (
                tmp.nth(0).unwrap().parse::<i32>().unwrap(),
                tmp.nth(0).unwrap(),
            )
        })
        .collect::<Vec<_>>();
    members.sort_by(|s1, s2| s1.0.cmp(&s2.0));
    let mut output = String::new();
    for (age, name) in members {
        output = output + &age.to_string() + " " + name + "\n";
    }
    print!("{}", output);
}
