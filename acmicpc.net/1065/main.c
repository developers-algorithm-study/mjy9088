#include <stdio.h>

int main(int argc, char **argv)
{
	int N, i, result = 0, j, k, l;
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
	{
		j = i % 10;
		k = i / 10;
		if(!k)
		{
			result++;
			continue;
		}
		l = k % 10 - j;
		for(j = k % 10, k /= 10; k; j = k % 10, k /= 10)
		{
			if(l != k % 10 - j)
			{
				goto _continue;
			}
		}
		result++;
		_continue:
		continue;
	}
	printf("%d\n", result);
	return 0;
}

