#include <stdio.h>

int main(int argc, char **argv)
{
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%.10lf", (double) A / B);
	return 0;
}

