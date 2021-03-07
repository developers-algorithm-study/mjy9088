#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int position;
	int type; // ������ ��� 1, ���� ��� -1
} Point;

int comparator(Point *a, Point *b) {
	// �켱 ��ġ�� ���ϵ�
	if (a->position != b->position) {
		return a->position - b->position;
	}
	// ��ġ�� ���� ��� ���������� ������ ����
	return b->type < a->type;
}

int main(int argc, char **argv)
{
	int N, i, verticalCount = 0, x, y;
	scanf("%d", &N);
	// ���� 2N�� �迭 lines���� �� 2*verticalCount���� ���� ��, �������� ���� ��
	Point *points = malloc(sizeof(Point) * N * 2);
	int firstX, firstY, previousX, previousY;
	for(i = 0; i <= N; i++)	// ������ ���� ù��° ���� �����ؾ� �ϹǷ� �ݺ��� 1ȸ ��! (�ڼ����� �ļ�)
	{
		// �̹� �� x, y�� �Է¹���
		if (i != N) {
			// ������ �ݺ��� �ƴ� ��쿡�� (Nȸ��) �Է¹���!
			scanf("%d %d", &x, &y);
		} else {
			// ������ ���� �ϼ��ϱ� ���� ������ �ݺ�
			x = firstX;
			y = firstY;
		}

		// ���� ���� �̹� ���� ���� ���� �ϼ�
		if (i == 0) {
			// ������ ���� �ϼ��ϱ� ���ؼ��� ù ���� �ʿ�
			firstX = x;
			firstY = y;
		} else {
			// ù ���� ���� ���� �����Ƿ� ���� �ϼ��� �� �����Ƿ� �ι�°���� (��� �ݺ� 1ȸ �� ��)
			if (previousY == y) { // ���� ���� �̹� ���� y�� ���� ��� = �̹� ���� ���� ���� ���
				// ���� ���� �迭�� ������ �Է¹��� // i�� �̹� 1���� �����ϹǷ� 1�� �� ���� ����
				int currentIndex = N - i + verticalCount;
				// ��ġ (���� ���� x�� ����. y�� �ʿ� ����)
				points[currentIndex * 2].position = previousX;
				points[currentIndex * 2 + 1].position = x;
				// ����/�� Ÿ�� (���� ��: ���� (+1), ������ ��: �� (-1))
				points[currentIndex * 2].type = previousX < x ? 1 : -1;
				points[currentIndex * 2 + 1].type = previousX < x ? -1 : 1;
			} else { // �̹� ���� ���� ���� ��� (�밢���� ���ٰ� ������)
				int currentIndex = verticalCount++; // ���� ���� �迭�� �պ��� �Է¹���
				// ��ġ (���� ���� y�� ����. x�� �ʿ� ����)
				points[currentIndex * 2].position = previousY;
				points[currentIndex * 2 + 1].position = y;
				// ����/�� Ÿ�� (���� ��: ���� (+1), �Ʒ��� ��: �� (-1))
				points[currentIndex * 2].type = previousY < y ? 1 : -1;
				points[currentIndex * 2 + 1].type = previousY < y ? -1 : 1;
			}
		}
		// �̹� �� ��ġ�� ���� �ݺ������� ���� �� ��ġ�� �����
		previousX = x;
		previousY = y;
	}

	qsort(points, verticalCount * 2, sizeof(Point), (int (*)(const void *, const void *))&comparator); // ���� �� ����
	qsort(points + verticalCount * 2, ((N - verticalCount) * 2), sizeof(Point), (int (*)(const void *, const void *))&comparator); // ���� �� ����

	// ��� 0���� ����. ��� ���� ��ġ�鼭 ���� ���̸� 1�� ���ϰ�, �� ���̸� 1�� �� ����
	// ���� ���� ó���� ������ ���� ���� ó���� ���۵� �� current�� 0�� ���̹Ƿ� �и��� �ʿ� ����
	int result = 0, current = 0;
	for (i = 0; i < N * 2; i++) {
		current += points[i].type;
		if (result < current) result = current;
	}
	printf("%d\n", result);
	return 0;
}

