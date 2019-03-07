#include <stdio.h>

int main(int argc, char **argv)
{
	int N, i, j;
	scanf("%d", &N);
	int arr[N];
	for(i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", arr[(i + j) % N]);
		}
		printf("\n");
	}
	return 0;
}

