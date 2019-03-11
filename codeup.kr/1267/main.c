#include <stdio.h>

int main(int argc, char **argv)
{
	int N, tmp, result = 0;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &tmp);
		if(tmp % 5 == 0)
		{
			result += tmp;
		}
	}
	printf("%d\n", result);
	return 0;
}

