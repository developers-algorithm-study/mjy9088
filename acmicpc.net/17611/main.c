#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int position;
	int type; // 시작일 경우 1, 끝일 경우 -1
} Point;

int comparator(Point *a, Point *b) {
	// 우선 위치로 비교하되
	if (a->position != b->position) {
		return a->position - b->position;
	}
	// 위치가 같은 경우 시작점보다 끝점이 먼저
	return b->type < a->type;
}

int main(int argc, char **argv)
{
	int N, i, verticalCount = 0, x, y;
	scanf("%d", &N);
	// 길이 2N의 배열 lines에서 앞 2*verticalCount개는 세로 선, 나머지는 가로 선
	Point *points = malloc(sizeof(Point) * N * 2);
	int firstX, firstY, previousX, previousY;
	for(i = 0; i <= N; i++)	// 마지막 점은 첫번째 점과 연결해야 하므로 반복을 1회 더! (자세히는 후술)
	{
		// 이번 점 x, y를 입력받음
		if (i != N) {
			// 마지막 반복이 아닌 경우에만 (N회만) 입력받음!
			scanf("%d %d", &x, &y);
		} else {
			// 마지막 선을 완성하기 위한 마지막 반복
			x = firstX;
			y = firstY;
		}

		// 이전 점과 이번 점을 통해 선을 완성
		if (i == 0) {
			// 마지막 선을 완성하기 위해서는 첫 점이 필요
			firstX = x;
			firstY = y;
		} else {
			// 첫 점은 이전 점이 없으므로 선을 완성할 수 없으므로 두번째부터 (대신 반복 1회 더 함)
			if (previousY == y) { // 이전 점과 이번 점의 y가 같은 경우 = 이번 선이 가로 선인 경우
				// 가로 선은 배열의 끝부터 입력받음 // i가 이미 1부터 시작하므로 1을 더 빼지 않음
				int currentIndex = N - i + verticalCount;
				// 위치 (가로 선은 x만 저장. y는 필요 없음)
				points[currentIndex * 2].position = previousX;
				points[currentIndex * 2 + 1].position = x;
				// 시작/끝 타입 (왼쪽 점: 시작 (+1), 오른쪽 점: 끝 (-1))
				points[currentIndex * 2].type = previousX < x ? 1 : -1;
				points[currentIndex * 2 + 1].type = previousX < x ? -1 : 1;
			} else { // 이번 선이 세로 선인 경우 (대각선은 없다고 가정함)
				int currentIndex = verticalCount++; // 세로 선은 배열의 앞부터 입력받음
				// 위치 (세로 선은 y만 저장. x는 필요 없음)
				points[currentIndex * 2].position = previousY;
				points[currentIndex * 2 + 1].position = y;
				// 시작/끝 타입 (위쪽 점: 시작 (+1), 아래쪽 점: 끝 (-1))
				points[currentIndex * 2].type = previousY < y ? 1 : -1;
				points[currentIndex * 2 + 1].type = previousY < y ? -1 : 1;
			}
		}
		// 이번 점 위치를 다음 반복에서는 이전 점 위치로 사용함
		previousX = x;
		previousY = y;
	}

	qsort(points, verticalCount * 2, sizeof(Point), (int (*)(const void *, const void *))&comparator); // 세로 선 정렬
	qsort(points + verticalCount * 2, ((N - verticalCount) * 2), sizeof(Point), (int (*)(const void *, const void *))&comparator); // 가로 선 정렬

	// 결과 0으로 시작. 모든 점을 거치면서 시작 점이면 1을 더하고, 끝 점이면 1을 뺄 것임
	// 세로 선의 처리가 끝나고 가로 선의 처리가 시작될 때 current가 0일 것이므로 분리할 필요 없음
	int result = 0, current = 0;
	for (i = 0; i < N * 2; i++) {
		current += points[i].type;
		if (result < current) result = current;
	}
	printf("%d\n", result);
	return 0;
}

