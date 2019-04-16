# 브라우저

[1015](http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=294)

시간 제한: 1000 ms

메모리 제한: 64 MB



## 문제

표준 웹브라우저는 방문한 페이지들 내에서 이전 이후 페이지를 방문하는 기능이 있다.

이를 구현하는 방법으로 두 개의 스택을 이용하는 방법이 있다.



입력으로 아래의 명령들이 들어온다.



**BACK** : 현재 페이지를 forward stack에 push, backward stack에서 pop하여 현재 페이지로 설정한다. backward stack이 비어있다면 명령을 무시한다.

**FORWARD** : 현재 페이지를 backward stack에 push, forward stack에서 pop하여 현재 페이지로 설정한다. 만약 forward stack이 비었다면 명령은 무시된다.

**VISIT** : 현재 페이지를 backward stack에 push, 입력된 URL을 현재 페이지로 설정. forward stack은 비운다.

**QUIT**: 프로그램 종료.



초기 웹페이지는 <http://www.acm.org/>로 설정되었다고 가정한다.



## 입력 형식

각 줄에 명령이 입력된다.
URL은 70글자 이하이다.
Stack은 100개를 넘게 쌓이지 않는다고 가정한다.



## 출력 형식

각 줄마다 현재 페이지를 출력한다.
만약 명령이 무시되면 "Ignored"를 출력한다.



## 입력 예

```
VISIT http://acm.ashland.edu/
VISIT http://acm.baylor.edu/acmicpc/
BACK
BACK
BACK
FORWARD
VISIT http://www.ibm.com/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT
```



## 출력 예

```
http://acm.ashland.edu/
http://acm.baylor.edu/acmicpc/
http://acm.ashland.edu/
http://www.acm.org/
Ignored
http://acm.ashland.edu/
http://www.ibm.com/
http://acm.ashland.edu/
http://www.acm.org/
http://acm.ashland.edu/
http://www.ibm.com/
Ignored
```