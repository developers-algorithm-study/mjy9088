#include <stdio.h>

int main(int argc, char **argv)
{
	int N, i;
	char *stars = "************************************************"
		"****************************************************" + 99;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		printf("%s\n", stars - i);
	}
	return 0;
}

