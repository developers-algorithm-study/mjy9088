#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define uint uint32_t

int exactSqrtI(uint distance) {
	int maybe = sqrt(distance);
	for (;;) {
		if (maybe * maybe > distance) {
			maybe--;
			continue;
		}
		if ((maybe + 1) * (maybe + 1) <= distance) {
			maybe++;
			continue;
		}
		break;
	}
	return maybe;
}

int solve(uint distance) {
	int tmp = exactSqrtI(distance - 1);
	// 왜 그런지는 몰라요. 아무튼 규칙 찾고 정리해보니 그럼.
	return tmp*tmp+tmp >= distance ? tmp*2 : tmp*2+1;
}

int main(int argc, char **argv)
{
	int T, i;
	uint from, to;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%" SCNu32 " %" SCNu32, &from, &to);
		printf("%d\n", solve(to - from));
	}
	return 0;
}

