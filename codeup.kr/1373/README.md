# 좌표 이동

[1373](http://codeup.kr/problem.php?id=1373), [해설](comment.md)

시간 제한: 1 Sec

메모리 제한: 128 MB



## 문제 설명

2차원 좌표평면이 있다. 좌표평면의 모든 점은 *x* 좌표와 *y* 좌표를 가지며, 이 좌표값은 모두 정수이다.

어떤 점(*x*, *y*)에서는 상하좌우로 이동할 수 있으며, *x* 좌표나 *y* 좌표의 값이 1만큼 변할 때마다 이동 거리는 1만큼 증가한다.

이 좌표평면의 원점(0, 0)에서 어떤 점(*n*, *m*)으로 이동하려고 한다. 그런데 그냥 이동하는 것은 재미없으므로 아래의 조건을 만족하도록 이동한다.

1. 같은 점은 여러 번 지날 수 있으나, 같은 길을 여러 번 지날 수는 없다.

2. 이동 중간에 최소 2개의 점에서 방향을 바꿔야 한다.

3. 이동 중간에 최소 *k*(0 ≤ *k* ≤ 1)개의 점에서는 방향을 바꾸지 않아야 한다.

4. 위의 세 가지 조건을 모두 만족하는 경로 중에서 가장 짧은 경로를 선택한다. 가장 짧은 경로가 2

개 이상 존재하는 경우 어느 경로를 선택해도 상관없다.

*n*, *m*이 입력될 때, 가장 짧은 경로로 이동할 경우의 이동 거리와 가장 짧은 경로의 수를 구하시오.



## 입력

네 정수 *n*, *m*, *k*, *p*가 공백을 사이에 두고 입력된다. (|*n*|, |*m*| ≤ 1,200, 0 ≤ *p* ≤ 6,000,000)



## 출력

원점에서 조건 4를 만족하면서 (*n*, *m*)으로 이동할 수 있는 경로의 길이와 경로의 수를 공백으로 구분하여 출력한다. 가장 짧은 경로의 수는 *p* = 0인 경우 그대로 출력하고 *p* > 0인 경우 *p*로 나눈 나머지를 출력한다.



## 입력 예시

```
2 3 1 7
```



## 출력 예시

```
5 0
```