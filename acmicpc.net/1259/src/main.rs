use std::io;

trait Palindrome {
    fn is_palindrome(&self) -> bool;
}

impl Palindrome for str {
    fn is_palindrome(&self) -> bool {
        self.chars()
            .zip(self.chars().rev())
            .all(|(asc, desc)| asc == desc)
    }
}

fn main() {
    loop {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let n = line.trim();
        if n == "0" {
            break;
        }
        println!("{}", if n.is_palindrome() { "yes" } else { "no" });
    }
}
