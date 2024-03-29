# 징검다리 건너기 (large)

[22871](https://www.acmicpc.net/problem/22871)

시간 제한: 2 초

메모리 제한: 1024 MB

## 문제

$N$개의 돌이 일렬로 나열 되어 있다. $N$개의 돌에는 수 $A_1 A_2 ... A_i ... A_N$로 부여되어 있다. 가장 왼쪽에 있는 돌에서 출발하여 가장 오른쪽에 있는 돌로 건너가려고 한다.

1. 항상 오른쪽으로만 이동가능하다.
2. $i$번째 돌에서 $j(i < j)$번째 돌로 이동할 때 $(j - i) × (1 + |A_i - A_j|)$ 만큼 힘을 쓴다.
3. 돌을 한번 건너갈 때마다 쓸 수 있는 힘은 최대 $K$이다.

가장 왼쪽 돌에서 출발하여 가장 오른쪽에 있는 돌로 건너갈 수 있는 모든 경우 중 $K$의 최솟값을 구해보자.

## 입력

첫 번째 줄에 돌의 개수 $N$이 공백으로 구분되어 주어진다.

두 번째 줄에는 $N$개의 돌의 수 $A_i$가 공백으로 구분되어 주어진다.

## 출력

가장 왼쪽 돌에서 출발하여 가장 오른쪽에 있는 돌로 건너갈 수 있는 모든 경우 중 가능한 $K$의 최솟값을 출력한다.

## 제한

- $2 \le N \le 5,000$
- $1 \le A_i \le 1,000,000$

## 예제 입력 1

```text
5
1 4 1 3 1
```

## 예제 출력 1

```text
2
```

## 예제 입력 2

```text
5
1 5 2 1 6
```

## 예제 출력 2

```text
6
```
