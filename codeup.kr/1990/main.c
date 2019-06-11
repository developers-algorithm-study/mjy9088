#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	int n = 0;
	char c;
	while(scanf(" %c", &c) == 1)
	{
		n = (n + c - '0') % 3;
	}
	printf("%d\n", n ? 0 : 1);
	return 0;
}

