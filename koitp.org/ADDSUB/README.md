# 더하자빼자

[ADDSUB](https://koitp.org/problem/ADDSUB/read/)

시간 제한: 1 Sec

메모리 제한: 512 MB



## 문제

삼성이는 드디어 초등학교에 입학했다. 입학해서  처음 배운 수학이 덧셈과 뺄셈이었다. 선생님은 손가락과 발가락을 이용한 덧셈과 뺄셈을 알려주셨다. 예를들어 5-3+9이면 손가락  5개를 폈다가 3개를 다시 접는다. 그렇게 되면 2개의 손가락만 올라가므로 5-3까지는 결과가 2임을 알 수 있다. 그럼 이제  +9를 하면 되므로, 9개의 손가락과 발가락을 펼치면 된다. 즉 손가락 8개, 발가락 1개를 펼치면 9를 더할 수 있다. 따라서  최종적으로는 손가락 10개, 발가락 1개, 즉 11을 얻는다. 따라서 5-3+9=11임을 알 수 있다. 하지만 손가락과 발가락은 총  20개 이므로, 계산 도중에 20을 초과하는 경우는 계산할 수 없다. 또한 모든 손가락, 발가락을 접었을 때는 0이므로, 계산  도중에 0 미만의 수가 나오는 경우도 계산할 수 없다.

삼성이는 재미있는 놀이를 하고 있다. 한자리 수 몇 개를 일렬로 놓고, 인접한 두 수 사이에 +, -를 넣어서 계산하는  놀이를 하고 있다. 마지막 두 수 사이에는 =을 넣는다. 삼성이는 만든 식이 등식이 되는 경우의 수를 알고싶어 한다. 하지만  삼성이는 20이상의 수는 몰라서, 당신에게 부탁을 했다. 삼성이가 계산할 수 있는 등식의 개수를 구하시오.



## 입력

첫 번째 줄에 숫자 N이 주어진다.  (3≤N≤100)

두 번째 줄에 0이상 9이하의 자연수 N개가 공백으로 분리되어 주어진다.



## 출력

첫 번째 줄에 삼성이가 만들 수 있는 등식의 개수를 출력한다. 이 값은 2^63−1 이하이다.



## 입력 예제

```
11
8 3 2 4 8 7 2 4 0 8 8
```



## 출력 예제

```
10
```