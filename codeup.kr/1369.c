#include <stdio.h>

int main(int argc, char **argv)
{
	int N, K, i, j;
	char *star = "                                                                                                  *" + 98;
	scanf("%d %d", &N, &K);
	if(N == 1)
	{
		printf("*");
		return 0;
	}
	N -= 2;
	for(i = 0; i < N; i++)
	{
		printf("*");
	}
	printf("**\n*");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j <= N; j++)
		{
			int tmp = K - (i + j + 2) % K - 1;
			j += tmp;
			if(j > N) tmp -= j - N;
			printf("%s", star - tmp);
		}
		printf("\n*");
	}
	for(i = 0; i < N; i++)
	{
		printf("*");
	}
	printf("*");
	return 0;
}

