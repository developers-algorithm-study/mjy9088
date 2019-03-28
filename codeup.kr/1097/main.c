#include <stdio.h>

int main(int argc, char **argv)
{
	int map[19][19], i, j, N, x, y;
	for(i = 0; i < 19; i++)
	{
		for(j = 0; j < 19; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		x -= 1;
		y -= 1;
		for(j = 0; j < 19; j++)
		{
			map[y][j] = !map[y][j];
			map[j][x] = !map[j][x];
		}
	}
	for(i = 0; i < 19; i++)
	{
		for(j = 0; j < 19; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}

