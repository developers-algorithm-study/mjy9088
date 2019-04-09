#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b;
	while(1)
	{
		scanf("%d %d", &a, &b);
		if(a > 1000 || b > 4000)
		{
			printf("INPUT ERROR!\n");
			continue;
		}
		if(a == 0 && b == 0)
		{
			break;
		}
		if(b % 2)
		{
			printf("0\n");
			continue;
		}
		b = b / 2 - a;
		if(b < 0 || a < b)
		{
			printf("0\n");
			continue;
		}
		printf("%d %d\n", b, a - b);
	}
	return 0;
}

