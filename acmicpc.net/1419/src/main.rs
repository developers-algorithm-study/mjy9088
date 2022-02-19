use std::{cmp, io, str::FromStr};

fn gcd(a: i32, b: i32) -> i32 {
    let r = a % b;
    if r == 0 {
        b
    } else {
        gcd(b, r)
    }
}

fn multiple_in_inclusive(divisor: i32, from: i32, to: i32) -> i32 {
    to / divisor - from / divisor + if from % divisor == 0 { 1 } else { 0 }
}

fn two_multiple_in_inclusive(div1: i32, div2: i32, from: i32, to: i32) -> i32 {
    if from > to {
        return 0;
    }
    let gcd = gcd(div1, div2);
    let mul = div1 * div2;
    let mul_gcd = mul as usize / gcd as usize;
    let mut available = vec![false; mul_gcd];
    let step1 = div1 as usize / gcd as usize;
    let step2 = div2 as usize / gcd as usize;
    for i in (step1..mul_gcd).step_by(step1) {
        for j in (i + step2..mul_gcd).step_by(step2) {
            available[j] = true;
        }
    }
    for i in (step2..mul_gcd).step_by(step2) {
        for j in (i + step1..mul_gcd).step_by(step1) {
            available[j] = true;
        }
    }
    let max = cmp::min(mul_gcd as i32 - 1, to / gcd);
    let min = from / gcd + if from % gcd != 0 { 1 } else { 0 };
    let unavailable_count_in_range = (min..=max).fold(0, |result, i| {
        if available[i as usize] {
            result
        } else {
            result + 1
        }
    });
    multiple_in_inclusive(gcd, from, to) - unavailable_count_in_range
}

fn get_line<T: FromStr>() -> Result<T, <T as FromStr>::Err> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<T>()
}

fn main() {
    let left = get_line::<i32>().unwrap();
    let right = get_line::<i32>().unwrap();
    let degree_x = get_line::<i32>().unwrap();
    let degree_d = degree_x * (degree_x - 1) / 2;
    let min = degree_x + degree_d;
    let left = cmp::max(min, left);
    println!(
        "{}",
        if degree_x == degree_d || degree_d == 0 {
            multiple_in_inclusive(degree_x, left, right)
        } else {
            two_multiple_in_inclusive(degree_x, degree_d, left, right)
        }
    );
}
