#include <stdio.h>

int main(int argc, char **argv)
{
	int i, tmp;
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &tmp);
		if(tmp % 5 == 0)
		{
			printf("%d\n", tmp);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}

