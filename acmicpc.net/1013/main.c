#include <stdio.h>

// 제출 시 CRLF 주석 처리!
#define CRLF

#define FALSE 0
#define TRUE 1

#ifdef CRLF
char myGetChar() { char ret = getchar(); if (ret == '\r') return getchar(); return ret; }
#else
#define myGetChar getchar 
#endif

// input에 다음 글자를 받거나, 실패 시 return
#define NEXT_INPUT(RETURN_VALUE_IF_END) { if ((input = myGetChar()) == '\n' || input == EOF) return RETURN_VALUE_IF_END; }

// 이번 줄 버퍼를 비우고 return
#define SAFE_RETURN(RETURN_VALUE) { while (TRUE) { if ((input = myGetChar()) == '\n' || input == EOF) break; } return RETURN_VALUE; }

// 다음 글자가 VALUE인지 확인
#define ASSERT_NEXT_IS(VALUE) { NEXT_INPUT(FALSE); if (input != VALUE) SAFE_RETURN(FALSE); }

// VALUE가 입력될 때까지 기다림
#define IGNORE_UNTIL(VALUE, RETURN_VALUE_IF_END) { while (TRUE) { NEXT_INPUT(RETURN_VALUE_IF_END); if (input == VALUE) break; } }

// 이번 줄이 (100+1+ | 01)+인지 확인하는 함수. 편의상 (100+11* | 01)+라 하겠음 (N+는 1개 이상의 N, N*는 0개 이상의 N)
int solve() {
	// 빈 줄이면 false
	int RETURN_VALUE_ON_EMPTY = FALSE;
	// 위 매크로를 사용하기 위해 필요한 변수
	char input;
	// 아 진짜 goto 안 쓰고싶지만 이번만... 한 번만!
	RESET:
	// 100+11*에서 100+1까지 나오면 break (빈 줄 처리와 goto 빼면 아래와 같음)
	while (TRUE) {
		// 01만 나오고 끝나면 true. 단, 아무것도 안 나오면 false
		NEXT_INPUT(RETURN_VALUE_ON_EMPTY);
		// 한 글자 이상 있으니 빈 줄은 아님
		RETURN_VALUE_ON_EMPTY = TRUE;
		if (input == '0') {
			// 0이 나오면 다음은 반드시 1이 나와야 함 (01)
			ASSERT_NEXT_IS('1');
		} else {
			// 1이 나오면 다음은 반드시 0이 2번 이상 나와야 함 (100+1+)
			ASSERT_NEXT_IS('0');
			ASSERT_NEXT_IS('0');
			// 그 다음으로는 1이 언젠간 나와야 함
			IGNORE_UNTIL('1', FALSE);
			break;
		}
	}
	// 이제 1*이 나올 수 있고, 다시 (100+11* | 01)+가 반복됨
	while (TRUE) {
		// 아래 중첩 while에서 continue하기 위해 사용
		CONTINUE:
		// 100+1에서 끝나면 TRUE
		NEXT_INPUT(TRUE);
		if (input == '0') {
			// 100+1 다음에 바로 0이 나오는 경우는 (100+11*)(100+11*)일 수 없으므로 01임
			ASSERT_NEXT_IS('1');
			// 다시 1*이 나온 후 (100+11* | 01)+가 반복될 때 이 반복문에 진입하도록 초기화
			goto RESET;
		}
		// 0 안 나오고 1만 나오면 100+11*인 상태로 끝났으므로 true
		IGNORE_UNTIL('0', TRUE); 
		// 0으로 끝나면 false
		NEXT_INPUT(FALSE);
		if (input == '0') {
			// 0이 2번 연속으로 나왔으므로 100+11*인 경우. 또 100+1까지 받고 continue 하면 됨
			IGNORE_UNTIL('1', FALSE);
			continue;
		} else {
			// (100+11*)(01)인 경우. 또 100+1까지 받고 continue 하면 됨

			// 100+1+에서 100+1까지 나오면 continue (빈 줄 처리와 goto 빼면 위와 같음)
			while (TRUE) {
				// 01만 나오고 끝나면 true (앞서 한 글자 이상 입력된 상태니 빈 줄 처리는 생략)
				NEXT_INPUT(TRUE);
				if (input == '0') {
					// 0이 나오면 다음은 반드시 1이 나와야 함 (01)
					ASSERT_NEXT_IS('1');
				} else {
					// 1이 나오면 다음은 반드시 0이 2번 이상 나와야 함 (100+11*)
					ASSERT_NEXT_IS('0');
					ASSERT_NEXT_IS('0');
					// 그 다음으로는 1이 언젠간 나와야 함
					IGNORE_UNTIL('1', FALSE);
					// 여기서 continue 대신 goto임에 유의
					goto CONTINUE;
				}
			}

		}
	}
//	SAFE_RETURN(TRUE); // unreachable code
}

int main(int argc, char **argv)
{
	int T, i;
	scanf("%d", &T);
	myGetChar(); // 줄바꿈문자
	for (i = 0; i < T; i++) {
		if (solve()) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

