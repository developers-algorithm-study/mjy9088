#include <stdio.h>

int arr1[1024], arr2[1024], masks[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

/**
 * �־��� ��Ȳ���� ���� �� �ִ� �л� ���� ����
 *
 * @param availableSeats �������� ���� �ڸ��� ��Ÿ���� ��Ʈ �ʵ�
 * @param previousLine �� �ٿ� �л��� ���� �ڸ��� ��Ÿ���� ��Ʈ �ʵ�
 * @param currentLine �̹� �ٿ� �л��� ���� �ڸ��� ��Ÿ���� ��Ʈ �ʵ�
 * @param M ������ ���� ũ��
 * @param previousCount �� �ٱ��� ���� �� �ִ� ��ü �л��� ��
 * @returns �̹� �ٱ��� ���� �� �ִ� ��ü �л��� ��
 */
int studentCount(int availabeSeats, int previousLine, int currentLine, int M, int previousCount) {
	int i, result = 0;
	// �ڸ�����
	for (i = 0; i < M; i++) {
		if (!(currentLine & masks[i])) {
			// �� �ڸ��� �л��� ������ �н�
			continue;
		}
		// �� �ڸ��� �л��� �ɾ��ִٸ� ��� += 1
		result++;
		if ((currentLine & masks[i]) && !(availabeSeats & masks[i])) {
			// ������ �ڸ��� �л��� ���� �� ����
			return 0;
		}
		if (i != 0 && (currentLine & masks[i - 1])) {
			// �л� �ٷ� ���� �л��� ���� �� ����
			return 0;
		}
		if (i != 0 && (previousLine & masks[i - 1])) {
			// �л� �� �� ���ʿ� �л��� ���� �� ����
			return 0;
		}
		if (i != M - 1 && (previousLine & masks[i + 1])) {
			// �л� �� �� �����ʿ� �л��� ���� �� ����
			return 0;
		}
	}
	// �̹� �ٿ� ���� �л� ���� ���� �ٱ����� �л� ���� ����
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

		// �� ���� ����, ù��° ��
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

			// �� ���� �ִ� ��
			for (k = 0; k < masks[M]; k++) { // �̹� �ٿ��� ������ ��� ��쿡 ����
				t2mp = studentCount(available, 0, k, M, 0); // �� �ٿ� �ƹ��� ���� �� 0���� ���
				for (l = 0; l < masks[M]; l++) { // �� �ٿ��� ������ ��� ��쿡 ����
					if (back[l] == 0) continue; // �� ���� �ùٸ��� ���� ��� �н�
					t3mp = studentCount(available, l, k, M, back[l]); 
					if (t2mp < t3mp) t2mp = t3mp; // t2mp = �̹� �ٿ� ������ �ִ� �л� ��
				}
				current[k] = t2mp;
			}
		}

		// ���
		t2mp = current[0];
		for (j = 1; j < masks[M]; j++) {
			if (t2mp < current[j]) t2mp = current[j];
		}
		printf("%d\n", t2mp);
	}
	return 0;
}

