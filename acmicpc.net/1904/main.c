#include <stdio.h>

#define DIV 15746

typedef struct
{
	int i1, i2, i3, i4;
} mat2d;

mat2d mat2d_multiply(mat2d a, mat2d b)
{
	return (mat2d){(a.i1 * b.i1 + a.i3 * b.i2) % DIV, (a.i2 * b.i1 + a.i4 * b.i2) % DIV
				 , (a.i1 * b.i3 + a.i3 * b.i4) % DIV, (a.i2 * b.i3 + a.i4 * b.i4) % DIV};
}

mat2d mat2d_pow(mat2d a, int b)
{
	if(b / 2)
	{
		if(b % 2) return mat2d_multiply(a, mat2d_pow(mat2d_multiply(a, a), b / 2));
		else return mat2d_pow(mat2d_multiply(a, a), b / 2);
	}
	else
	{
		return a;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d", mat2d_pow((mat2d){0, 1, 1, 1}, N).i4);
	return 0;
}

