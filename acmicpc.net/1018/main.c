#include <stdio.h>

int main(int argc, char **argv)
{
	int W, H, i, j, k, result = 8;
	scanf("%d %d", &H, &W);
	int tmp[H][W + 7];
	char temp;
	for(i = 0; i < H; i++)
	{
		for(j = 0; j < W + 7; j++)
		{
			tmp[i][j] = 0;
		}
		for(j = 0; j < W; j++)
		{
			scanf(" %c", &temp);
			for(k = 0; k < 8; k++)
			{
				if((i + k) % 2 == (temp ? 0 : 1))
				{
					tmp[i][j + k]++;
				}
			}
		}
	}
	for(i = 0; i < H - 7; i++)
	{
		int w = 0, b = 0;
		for(j = 7; j < W; j++)
		{
			for(k = 0; k < W; k++)
			{
				if(k % 2)
				{
					w += 8 - tmp[i][j - k];
					b += tmp[i][j - k];
				}
				else
				{
					w += tmp[i][j - k];
					b += 8 - tmp[i][j - k];
				}
			}
			if(result > w)
			{
				result = w;
			}
			if(result > b)
			{
				result = b;
			}
		}
	}
	printf("%d\n", result);
	return 0;
}

