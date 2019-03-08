#include <stdio.h>

int abs(int a)
{
	return a < 0 ? -a : a;
}

int main(int argc, char **argv)
{
	int N, X, Y, i, j;
	scanf("%d %d %d", &N, &Y, &X);
	X -= 1;
	Y -= 1;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", abs(X - j) + abs(Y - i) + 1);
		}
		printf("\n");
	}
	return 0;
}

