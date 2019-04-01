#include <stdio.h>

int main(int argc, char **argv)
{
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

