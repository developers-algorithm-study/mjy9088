#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	int N, i;
	uint64_t X[2] = {1, 1}, Y[2], *x = X, *y = Y, *z;
	scanf("%d", &N);
	for(i = 1; i < N; i++)
	{
		z = x;
		x = y;
		y = z;
		x[1] = y[0];
		x[0] = y[0] + y[1];
	}
	printf("%ld\n", x[0] + x[1]);
	return 0;
}

