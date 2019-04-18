# (재귀함수) 우박수 (3n+1) (basic)

[1928](http://codeup.kr/problem.php?id=1928)

시간 제한: 1 Sec

메모리 제한: 128 MB



## 문제 설명

콜라츠의 추측, 

3*n*+1

 문제, 우박수 문제라고 불리는 이 문제는 다음과 같다.



1. 어떤 자연수 *n*이 입력되면,

2. *n*이 홀수이면 3*n*+1을 하고,

3. *n*이 짝수이면 *n*2를 한다.

4. 이 *n*이 1이 될때까지 2 3과정을 반복한다.

예를 들어 5는 5 → 16 → 8 → 4 → 2 → 1 이 된다.

이 처럼 어떤 자연수 *n*이 입력되면 위 알고리즘에 의해 1이 되는 과정을 모두 출력하시오.

**이 문제는 반복문 for, while 등을 이용하여 풀수 없습니다.**

금지 키워드 : for while goto 



## 입력

자연수 *n*이 입력된다. (1<=*n*<=10,000,000)

단, 3*n*+1이 되는 과정에서 *int*범위를 넘는 수는 입력으로 주어지지 않는다.



## 출력

3*n*+1의 과정을 출력한다.



## 입력 예시

```
5
```



## 출력 예시

```
5
16
8
4
2
1
```