use std::cmp::max;
use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let numbers = line
        .trim()
        .split(' ')
        .flat_map(str::parse::<i64>)
        .collect::<Vec<_>>();
    // let numbers: Vec<i64> = vec![1, 4, 1, 3, 1];
    // DP - 각 돌 별로, 그 돌을 밟으려면 필요한 최대 힘...을 저장할 벡터
    let mut minimum = Vec::<i64>::new();
    // N번째 돌의 힘을 구하려면 0..N번째 힘이 모두 필요하므로 0부터
    for i in 0..numbers.len() {
        // i번째 돌을 밟으려면 필요한 최대 힘을 구함
        minimum.push(
            // minimum이 비어 있다면 (첫번째 돌이라면) 0이 될 것
            match (0..minimum.len())
                // 이전(j번째) 돌에서 i번째 돌로 오는 경우 중 가장 작은 것!
                .map(|j| {
                    // j번째 돌에서 i번째 돌로 오는 경우
                    max(
                        // 그 전 돌을 밟으려면 필요한 최대 힘 (재귀적)
                        minimum[j],
                        // 그 전 돌에서 이 돌로 건너오는 힘
                        (i - j) as i64 * (1 + (numbers[i] - numbers[j]).abs()),
                    )
                })
                .min()
            {
                Some(value) => value,
                None => 0,
            },
        )
    }
    println!("{}", minimum.last().unwrap());
}
