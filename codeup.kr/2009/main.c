#include <stdio.h>

int main(int argc, char **argv)
{
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d\n", N ? (N - 1) / (M - 1) : 0);
	return 0;
}

