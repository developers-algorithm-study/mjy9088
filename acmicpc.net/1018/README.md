# 체스판 다시 칠하기

[1018](https://www.acmicpc.net/problem/1018)

시간 제한: 2 초

메모리 제한: 128 MB

## 문제

지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.

하지만 지민이는 이 보드가 체스판처럼 검정/흰색 패턴이 번갈아가며 색칠해져있지 않기 때문에 고민에 빠졌다. 따라서 지민이는  8×8크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야 겠다고 생각했다. 당연히 8×8크기는 아무데서나 골라도 된다.

현재 보드의 색이 어떤지 상태가 주어질 때, 지민이가 8×8크기로 자른 뒤에 다시 칠해야하는 정사각형 개수의 최솟값을 구하는 프로그램을 작성하시오.

체스판은 각 정사각형이 검정 또는 흰색이며, 변을 공유하는 두 개의 사각형이 같은 색이 아닐 때 이다. 따라서 위 정의에 의하면 체스판의 색은 항상 두 가지가 가능한데, 하나는 왼쪽 위 코너가 흰색인 것, 검정색인 것 두가지이다.

## 입력

첫째 줄에 N과 M이 주어진다. M과 N은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개 줄에는 체스판의 색 상태가 주어진다. B는 검정색이며, W는 흰색이다.

## 출력

첫째 줄에 지민이가 8*8크기로 자른 뒤에 다시 칠해야하는 정사각형 개수의 최솟값을 출력한다.

## 예제 입력 1

```text
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
```

## 예제 출력 1

```text
1
```

## 예제 입력 2

```text
10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB
```

## 예제 출력 2

```text
12
```

## 예제 입력 3

```text
8 8
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
```

## 예제 출력 3

```text
0
```

## 예제 입력 4

```text
9 23
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBW
```

## 예제 출력 4

```text
31
```

## 예제 입력 5

```text
10 10
BBBBBBBBBB
BBWBWBWBWB
BWBWBWBWBB
BBWBWBWBWB
BWBWBWBWBB
BBWBWBWBWB
BWBWBWBWBB
BBWBWBWBWB
BWBWBWBWBB
BBBBBBBBBB
```

## 예제 출력 5

```text
0
```
