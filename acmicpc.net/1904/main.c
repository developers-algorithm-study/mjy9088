#include <stdio.h>

int main() {
	int N, i;
	scanf("%d", &N);
	int any = 1; // 이전 타일이 0이 아닌 경우의 수
	int invalid = 1; // 이전 타일이 0인 경우의 수
	for(i = 1; i < N; i++) {
		int previous_any = any;
		int previous_invalid = invalid;

		// 이번에 0을 쓰는 경우 + 1을 쓰는 경우
		any = previous_invalid + previous_any;
		// 이전 타일이 0이면 1만 쓸 수 있음
		invalid = previous_any;

		any %= 15746;
		invalid %= 15746;
	}
	printf("%d\n", any);
	return 0;
}

