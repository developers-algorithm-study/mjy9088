#include <stdio.h>

int main(int argc, char **argv)
{
	int i, j, k, n;
	scanf("%d", &n);
	for(i = 1; i <= 9; i++)
	{
		for(j = 1; j <= i; j++)
		{
			for(k = 0; k < n; k++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}

