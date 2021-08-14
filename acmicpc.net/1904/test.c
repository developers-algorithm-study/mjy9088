#include <stdio.h>

#define COUNT 1000000

typedef struct
{
	int i1, i2, i3, i4;
} mat2d;

mat2d mat2d_multiply(mat2d a, mat2d b, int div)
{
	return (mat2d){(a.i1 * b.i1 + a.i3 * b.i2) % div, (a.i2 * b.i1 + a.i4 * b.i2) % div
				 , (a.i1 * b.i3 + a.i3 * b.i4) % div, (a.i2 * b.i3 + a.i4 * b.i4) % div};
}

mat2d mat2d_pow(mat2d a, int b, int div)
{
	if(b / 2)
	{
		if(b % 2) return mat2d_multiply(a, mat2d_pow(mat2d_multiply(a, a, div), b / 2, div), div);
		else return mat2d_pow(mat2d_multiply(a, a, div), b / 2, div);
	}
	else
	{
		return a;
	}
}

int solution(int N) {
	mat2d fib = {0, 1, 1, 1};
	fib = mat2d_pow(fib, N, 15746);
	return fib.i4;
}

int main() {
	int i;
	int failed = 0;
	int any = 1; // ���� Ÿ���� 0�� �ƴ� ����� ��
	int invalid = 1; // ���� Ÿ���� 0�� ����� ��
	for(i = 1; i <= COUNT; i++) {
		int previous_any = any;
		int previous_invalid = invalid;

		// �̹��� 0�� ���� ��� + 1�� ���� ���
		any = previous_invalid + previous_any;
		// ���� Ÿ���� 0�̸� 1�� �� �� ����
		invalid = previous_any;

		any %= 15746;
		invalid %= 15746;

		int result = solution(i + 1);
		if (result != any) {
			printf("N�� %d�� ��� ����! (����: %d, ���: %d)\n", i, any, result);
			failed = 1;
		}
	}
	if (failed == 0) {
		puts("Passed all cases!");
	}
	return 0;
}

