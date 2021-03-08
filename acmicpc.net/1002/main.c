#include <stdio.h>

/**
 * �� ���� ������ ���ϴ� �Լ�
 *
 * @param x1 ū ���� x
 * @param y1 ū ���� y
 * @param r1 ū ���� ������
 * @param x2 ���� ���� x
 * @param y2 ���� ���� y
 * @param r2 ���� ���� ������
 * @returns ������ ����
 */
int solve(int x1, int y1, int r1, int x2, int y2, int r2) {
	// ��ġ�� ���
	if (x1 == x2 && y1 == y2 && r1 == r2) {
		return -1;
	}
	// �Ÿ� ����
	int distanceSqr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	// ������ �� ����
	int rSqr = (r1 + r2) * (r1 + r2);
	// �����ϴ� ���
	if (distanceSqr == rSqr) {
		return 1;
	}
	// �־ �� ������ ���
	if (distanceSqr > rSqr) {
		return 0;
	}
	// ������ �� ����
	rSqr = (r1 - r2) * (r1 - r2);
	// �����ϴ� ���
	if (distanceSqr == rSqr) {
		return 1;
	}
	// ���� ���� ū �� �ȿ� �־ �� ������ ���
	// (distance + r2 < r1) == (distance < r1 - r2)
	if (distanceSqr < rSqr) {
		return 0;
	}
	// ������
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

