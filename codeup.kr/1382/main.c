#include <stdio.h>

int main(int argc, char **argv)
{
	int i, j;
	for(i = 1; i <= 9; i++)
	{
		for(j = 2; j <= 5; j++)
		{
			printf("%d x %d = %2d%s", j, i, i * j, j == 5 ? "\n" : "\t");
		}
	}
	return 0;
}

