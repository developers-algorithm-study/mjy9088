#include <stdio.h>

int main() {
	int N, i;
	scanf("%d", &N);
	int any = 1; // ���� Ÿ���� 0�� �ƴ� ����� ��
	int invalid = 1; // ���� Ÿ���� 0�� ����� ��
	for(i = 1; i < N; i++) {
		int previous_any = any;
		int previous_invalid = invalid;

		// �̹��� 0�� ���� ��� + 1�� ���� ���
		any = previous_invalid + previous_any;
		// ���� Ÿ���� 0�̸� 1�� �� �� ����
		invalid = previous_any;

		any %= 15746;
		invalid %= 15746;
	}
	printf("%d\n", any);
	return 0;
}

