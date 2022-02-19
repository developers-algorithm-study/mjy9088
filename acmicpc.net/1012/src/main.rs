use std::{io, ops::ControlFlow};

fn get_line() -> Result<String, io::Error> {
    let mut line = String::new();
    match io::stdin().read_line(&mut line) {
        Ok(_) => Ok(line),
        Err(err) => Err(err),
    }
}

fn tuple2<T>(it: &mut dyn Iterator<Item = T>) -> (T, T) {
    (it.next().unwrap(), it.next().unwrap())
}

fn tuple3<T>(it: &mut dyn Iterator<Item = T>) -> (T, T, T) {
    (it.next().unwrap(), it.next().unwrap(), it.next().unwrap())
}

fn find1(vec: &Vec<Vec<usize>>) -> Option<(usize, usize)> {
    match vec
        .iter()
        .enumerate()
        .try_fold(None as Option<(usize, usize)>, |_, (y, vec)| {
            vec.iter()
                .enumerate()
                .try_fold(None as Option<(usize, usize)>, |_, (x, &value)| {
                    if value == 1 {
                        ControlFlow::Break(Some((x, y)))
                    } else {
                        ControlFlow::Continue(None)
                    }
                })
        }) {
        ControlFlow::Break(result) => result,
        _ => None,
    }
}

fn flood_fill(vec: &mut Vec<Vec<usize>>, x: usize, y: usize) {
    if vec[y][x] == 0 {
        return;
    }
    vec[y][x] = 0;
    if vec.len() > y + 1 {
        flood_fill(vec, x, y + 1);
    }
    if vec[y].len() > x + 1 {
        flood_fill(vec, x + 1, y);
    }
    if y > 0 {
        flood_fill(vec, x, y - 1);
    }
    if x > 0 {
        flood_fill(vec, x - 1, y);
    }
}

fn main() {
    for _ in 0..get_line().unwrap().trim().parse::<usize>().unwrap() {
        let (w, h, k) = tuple3(
            &mut get_line()
                .unwrap()
                .trim()
                .split(' ')
                .flat_map(str::parse::<usize>),
        );
        let mut map = vec![vec![0; w]; h];
        for _ in 0..k {
            let (x, y) = tuple2(
                &mut get_line()
                    .unwrap()
                    .trim()
                    .split(' ')
                    .flat_map(str::parse::<usize>),
            );
            map[y][x] = 1;
        }
        let mut result = 0;
        loop {
            match find1(&map) {
                None => break,
                Some((x, y)) => {
                    flood_fill(&mut map, x, y);
                    result = result + 1;
                }
            }
        }
        println!("{}", result);
    }
}
