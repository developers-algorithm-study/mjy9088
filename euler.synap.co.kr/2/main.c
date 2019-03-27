#include <stdio.h>

int main(int argc, char **argv)
{
	int a = 1, b = 1, c = 2, result = 0;
	while(c <= 4000000)
	{
		c = a + b;
		a = b;
		b = c;
		if(c % 2 == 0)
		{
			result += c;
		}
	}
	printf("%d\n", result);
	return 0;
}

