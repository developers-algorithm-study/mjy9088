#include <stdio.h>

/**
 * 두 원의 교점을 구하는 함수
 *
 * @param x1 큰 원의 x
 * @param y1 큰 원의 y
 * @param r1 큰 원의 반지름
 * @param x2 작은 원의 x
 * @param y2 작은 원의 y
 * @param r2 작은 원의 반지름
 * @returns 교점의 개수
 */
int solve(int x1, int y1, int r1, int x2, int y2, int r2) {
	// 겹치는 경우
	if (x1 == x2 && y1 == y2 && r1 == r2) {
		return -1;
	}
	// 거리 제곱
	int distanceSqr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	// 반지름 합 제곱
	int rSqr = (r1 + r2) * (r1 + r2);
	// 외접하는 경우
	if (distanceSqr == rSqr) {
		return 1;
	}
	// 멀어서 못 만나는 경우
	if (distanceSqr > rSqr) {
		return 0;
	}
	// 반지름 차 제곱
	rSqr = (r1 - r2) * (r1 - r2);
	// 내접하는 경우
	if (distanceSqr == rSqr) {
		return 1;
	}
	// 작은 원이 큰 원 안에 있어서 못 만나는 경우
	// (distance + r2 < r1) == (distance < r1 - r2)
	if (distanceSqr < rSqr) {
		return 0;
	}
	// 나머지
	return 2;
}

int main(int argc, char **argv)
{
	int T, x1, y1, r1, x2, y2, r2, i;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		printf("%d\n", r1 > r2 ? solve(x1, y1, r1, x2, y2, r2) : solve(x2, y2, r2, x1, y1, r1));
	} 
	return 0;
}

