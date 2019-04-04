#include <stdio.h>

int main(int argc, char **argv)
{
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	if(N % 2 == 0 || N > 100 || N < 0 || M > 4 || 1 > M)
	{
		printf("INPUT ERROR!\n");
		return 0;
	}
	switch(M)
	{
		case 1:
			for(i = 0; i < N; i++)
			{
				j = N - i;
				k = i + 1;
				for(j = j < k ? j : k; j; j--)
				{
					printf("*");
				}
				printf("\n");
			}
			break;
		case 2:
			for(i = 0; i < N; i++)
			{
				k = N / 2 - i;
				k = k < 0 ? -k : k;
				for(j = 0; j < k; j++)
				{
					printf(" ");
				}
				k = N / 2 - k + 1;
				for(j = 0; j < k; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			break;
		case 3:
			for(i = 0; i < N; i++)
			{
				j = N - i - 1;
				k = j < i ? j : i;
				for(j = 0; j < k; j++)
				{
					printf(" ");
				}
				k = N - k * 2;
				for(j = 0; j < k; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			break;
		default:
			for(i = 0; i < N; i++)
			{
				j = N - i - 1;
				k = j < i ? j : i;
				for(j = 0; j < i && j < N / 2; j++)
				{
					printf(" ");
				}
				k = N / 2 - k + 1;
				for(j = 0; j < k; j++)
				{
					printf("*");
				}
				printf("\n");
			}
	}
	return 0;
}

