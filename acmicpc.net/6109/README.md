# Dairy Queen

[6109](https://www.acmicpc.net/problem/6109)

시간 제한: 1 초

메모리 제한: 128 MB

## 문제

Bessie, always in need of an income, has decided to leverage her dairy skills by taking a part-time job at the local Dairy Queen restaurant. She is running a special cash register (since she has hooves instead of fingers and thus requires special accommodation). Her job is making change for customers as they make a purchase.

As she was counting out 83 cents in change, she wondered: "How many ways can I count out 83 cents? I can use three quarters and eight pennies, seven dimes and three pennies, 83 pennies... there must be a zillion ways!"

How many different ways can one make change for $N$ $(1 \le N \le 300)$ cents using coins from a set of $C$ $(1 \le C \le 8)$ coins of supplied values $C_i$ $(1 \le C_i \le 200)$?  "Different" means differing counts of coins.

Thus, 8 cents can be made, in American currency, with 1 five-cent piece + 3 one-cent pieces and also with 8 one-cent pieces. Using 3 one-cent pieces + 1 five-cent piece is the same as 1 five-cent piece + 3 one-cent pieces, so one can create eight cents in just two different ways. Note that some coin systems are poor at making change and result in an answer of '0'.

Coin values in the input file are listed in descending order from largest to smallest. All coin values will be distinct.

HINT: Consider recursion as a solution technique.

## 입력

- Line 1: Two space-separated integers: $N$ and $C$
- Lines 2..C+1: Line i+1 contains a single integer: $C_i$

## 출력

- Line 1: A single line with a single integer that is the number of ways to create N cents of change using the supplied coins. The answer is guaranteed to fit into a signed 32-bit integer.

## 예제 입력 1

```text
83 5
50
25
10
5
1
```

## 예제 출력 1

```text
159
```

## 힌트

Here are 15 of the 159 ways of making 83 cents:

```text
0 x 50  0 x 25  0 x 10  0 x 5  83 x 1
0 x 50  0 x 25  0 x 10  1 x 5  78 x 1
0 x 50  0 x 25  0 x 10  2 x 5  73 x 1
0 x 50  0 x 25  0 x 10  3 x 5  68 x 1
0 x 50  0 x 25  0 x 10  4 x 5  63 x 1
0 x 50  0 x 25  0 x 10  5 x 5  58 x 1
0 x 50  0 x 25  0 x 10  6 x 5  53 x 1
0 x 50  0 x 25  0 x 10  7 x 5  48 x 1
0 x 50  0 x 25  0 x 10  8 x 5  43 x 1
0 x 50  0 x 25  0 x 10  9 x 5  38 x 1
0 x 50  0 x 25  0 x 10  10 x 5  33 x 1
0 x 50  0 x 25  0 x 10  11 x 5  28 x 1
0 x 50  0 x 25  0 x 10  12 x 5  23 x 1
0 x 50  0 x 25  0 x 10  13 x 5  18 x 1
0 x 50  0 x 25  0 x 10  14 x 5  13 x 1
```
