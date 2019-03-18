#include <stdio.h>

int main(int argc, char **argv)
{
	int N, tmp, i, j;
	scanf("%d", &N);
	long a[21], b[21], result = 0;
	if(!N)
	{
		printf("0\n");
		return 0;
	}
	for(i = 0; i < 21; i++)
	{
		a[i] = 0;
	}
	scanf("%d", &tmp);
	a[tmp] = 1;
	for(i = 2; i < N; i++)
	{
		for(j = 0; j < 21; j++)
		{
			b[j] = a[j];
			a[j] = 0;
		}
		scanf("%d", &tmp);
		for(j = 0; j + tmp < 21; j++)
		{
			a[j] += b[j + tmp];
			a[j + tmp] += b[j];
		}
	}
	scanf("%d", &tmp);
	printf("%ld\n", a[tmp]);
	return 0;
}

