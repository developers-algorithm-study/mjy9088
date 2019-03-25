#include <stdio.h>

int main(int argc, char **argv)
{
	int T, N, tmp, i, sum = 0;
	char garbage[11];
	scanf("%d %d", &T, &N);
	for(i = 0; i < T; i++)
	{
		scanf(" %s %d\n", garbage, &tmp);
		sum += tmp;
	}
	printf("%d\n", N * 3 - sum);
	return 0;
}

