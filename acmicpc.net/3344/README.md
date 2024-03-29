# N-Queen

[3344](https://www.acmicpc.net/problem/3344)

시간 제한: 1 초

메모리 제한: 128 MB

## 문제

8*8 체스보드에 8개의 퀸을 서로 공격하지 못하게 놓는 문제는 잘 알려져 있는 문제이다. 퀸은 같은 행, 열, 또는 대각선 위에 있는 말을 공격할 수 있다. 이 문제의 한가지 정답은 아래 그림과 같다.


![N Queen 문제 정답 예시](https://www.acmicpc.net/upload/images/nqueen.png)

이 문제의 조금 더 일반화된 문제는 Franz Nauck이 1850년에 제기했다.

$N \times N$ 보드에 $N$개의 퀸을 서로 다른 두 퀸이 공격하지 못하게 놓는 경우의 수는 몇 가지가 있을까?

이 문제는 $N>3$인 경우에 경우의 수가 적어도 1개 라는 것이 증명되어 있다. 예를 들어, $N=26$인 경우에 $22\,317\,699\,616\,364\,044$가지 방법이 있다.

$N$이 주어졌을 때, $N \times N$ 보드에 $N$개의 퀸을 서로 다른 두 퀸이 공격하지 못하게 놓는 한가지 경우를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 $N$이 주어진다. $N$은 $8$, $26,$ $213$, $2\,012$, $99\,991$, $99\,999$중 하나이다.

## 출력

$N$개의 줄을 출력해야 한다. $i$번째 줄에는 하나의 정수를 출력해야 하고, 이 정수는 $i$번째 행에 있는 퀸이 있는 열의 번호이다.

## 예제 입력 1

```text
8
```

## 예제 출력 1

```text
3
6
8
1
4
7
5
2
```
