#include <stdio.h>

int solve(int n)
{
	if(n != 1)
	{
		printf("%d\n", n);
		return solve(n % 2 ? 3 * n + 1 : n / 2);
	}
}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	solve(N);
	printf("1");
	return 0;
}

