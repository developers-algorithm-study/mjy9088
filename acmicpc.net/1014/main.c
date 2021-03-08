#include <stdio.h>

int arr1[1024], arr2[1024], masks[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

/**
 * 주어진 상황에서 앉을 수 있는 학생 수를 구함
 *
 * @param availableSeats 망가지지 않은 자리를 나타내는 비트 필드
 * @param previousLine 앞 줄에 학생이 앉은 자리를 나타내는 비트 필드
 * @param currentLine 이번 줄에 학생이 앉을 자리를 나타내는 비트 필드
 * @param M 교실의 가로 크기
 * @param previousCount 앞 줄까지 앉을 수 있는 전체 학생의 수
 * @returns 이번 줄까지 앉을 수 있는 전체 학생의 수
 */
int studentCount(int availabeSeats, int previousLine, int currentLine, int M, int previousCount) {
	int i, result = 0;
	// 자리마다
	for (i = 0; i < M; i++) {
		if (!(currentLine & masks[i])) {
			// 이 자리에 학생이 없으면 패스
			continue;
		}
		// 이 자리에 학생이 앉아있다면 결과 += 1
		result++;
		if ((currentLine & masks[i]) && !(availabeSeats & masks[i])) {
			// 망가진 자리에 학생이 앉을 수 없음
			return 0;
		}
		if (i != 0 && (currentLine & masks[i - 1])) {
			// 학생 바로 옆에 학생이 앉을 수 없음
			return 0;
		}
		if (i != 0 && (previousLine & masks[i - 1])) {
			// 학생 앞 줄 왼쪽에 학생이 앉을 수 없음
			return 0;
		}
		if (i != M - 1 && (previousLine & masks[i + 1])) {
			// 학생 앞 줄 오른쪽에 학생이 앉을 수 없음
			return 0;
		}
	}
	// 이번 줄에 앉은 학생 수와 이전 줄까지의 학생 수를 더함
	return result + previousCount;
}

int main(int argc, char **argv)
{
	int T, N, M, i, j, k, l, t2mp, t3mp, available;
	char buffer[11];
	int *current = arr1, *back = arr2, *tmp;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		scanf("%s", buffer);
		available = 0;
		for (j = 0; j < M; j++) {
			available |= buffer[j] != 'x' ? masks[j] : 0;
		}

		// 앞 줄이 없는, 첫번째 줄
		for (j = 0; j < masks[M]; j++) {
			current[j] = studentCount(available, 0, j, M, 0);
		}

		for (j = 1; j < N; j++) {
			scanf("%s", buffer);
			available = 0;
			for (k = 0; k < M; k++) {
				available |= buffer[k] != 'x' ? masks[k] : 0;
			}
			tmp = current;
			current = back;
			back = tmp;

			// 앞 줄이 있는 줄
			for (k = 0; k < masks[M]; k++) { // 이번 줄에서 가능한 모든 경우에 대해
				t2mp = studentCount(available, 0, k, M, 0); // 앞 줄에 아무도 없고 총 0명인 경우
				for (l = 0; l < masks[M]; l++) { // 앞 줄에서 가능한 모든 경우에 대해
					if (back[l] == 0) continue; // 앞 줄이 올바르지 않은 경우 패스
					t3mp = studentCount(available, l, k, M, back[l]); 
					if (t2mp < t3mp) t2mp = t3mp; // t2mp = 이번 줄에 가능한 최대 학생 수
				}
				current[k] = t2mp;
			}
		}

		// 결과
		t2mp = current[0];
		for (j = 1; j < masks[M]; j++) {
			if (t2mp < current[j]) t2mp = current[j];
		}
		printf("%d\n", t2mp);
	}
	return 0;
}

