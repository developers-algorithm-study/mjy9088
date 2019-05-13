#include <stdio.h>
#include <stdlib.h>

int lut[1000001];

int main(int argc, char **argv)
{
	int i, tmp, N;
	scanf("%d", &N);
	lut[1] = 0;
	for(i = 2; i <= N; i++)
	{
		lut[i] = lut[i - 1] + 1;
		if(i % 2 == 0)
		{
			tmp = lut[i / 2] + 1;
			if(lut[i] > tmp)
			{
				lut[i] = tmp;
			}
		}
		if(i % 3 == 0)
		{
			tmp = lut[i / 3] + 1;
			if(lut[i] > tmp)
			{
				lut[i] = tmp;
			}
		}
	}
	printf("%d\n", lut[N]);
	return 0;
}

