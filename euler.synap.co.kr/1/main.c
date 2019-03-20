#include <stdio.h>

int main(int argc, char **argv)
{
	int A = 3, B = 5, C = 15, max = 1000 - 1;
	printf("%d\n", A * (max / A) * (max / A + 1) / 2 + B * (max / B) * (max / B + 1) / 2 - C * (max / C) * (max / C + 1) / 2);
	return 0;
}

