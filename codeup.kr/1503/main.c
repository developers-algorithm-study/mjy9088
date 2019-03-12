#include <stdio.h>

int main(int argc, char **argv)
{
	int N, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", (i + (i % 2)) * N + j * (1 - (i % 2) * 2) + (i + 1) % 2);
		}
		printf("\n");
	}
	return 0;
}

