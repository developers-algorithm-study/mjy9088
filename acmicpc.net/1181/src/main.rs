use std::{cmp::Ordering, collections::BTreeSet, io};

struct MyString {
    str: String,
}

impl Ord for MyString {
    fn cmp(&self, other: &Self) -> Ordering {
        let l1 = self.str.len();
        let l2 = other.str.len();
        if l1 > l2 {
            Ordering::Greater
        } else if l1 < l2 {
            Ordering::Less
        } else {
            self.str.cmp(&other.str)
        }
    }
}

impl Eq for MyString {}

impl PartialOrd for MyString {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for MyString {
    fn eq(&self, other: &Self) -> bool {
        self.str == other.str
    }
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let n = line.trim().parse::<usize>().unwrap();
    for word in (0..n)
        .map(|_| {
            let mut line = String::new();
            io::stdin().read_line(&mut line).unwrap();
            MyString {
                str: line.trim().to_string(),
            }
        })
        .collect::<BTreeSet<_>>()
    {
        println!("{}", word.str.trim());
    }
}
