#include <stdio.h>

int main(int argc, char **argv)
{
	int m, n, x, y, i, j;
	scanf("%d %d %d %d", &m, &n, &x, &y);
	int field[n][m], tmp[n], temp, result;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d", &field[i][j]);
		}
	}

	for(i = 0; i < n; i++)
	{
		tmp[i] = 0;
	}
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < n; j++)
		{
			tmp[j] += field[j][i];
		}
	}

	temp = 0;
	for(i = 0; i < y; i++)
	{
		temp += tmp[i];
	}
	result = temp;
	for(; i < n; i++)
	{
		temp += tmp[i];
		temp -= tmp[i - y];
		if(temp > result) result = temp;
	}

	for(i = x; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			tmp[j] += field[j][i];
			tmp[j] -= field[j][i - x];
		}

		temp = 0;
		for(j = 0; j < y; j++)
		{
			temp += tmp[j];
		}
		if(temp > result) result = temp;
		for(; j < n; j++)
		{
			temp += tmp[j];
			temp -= tmp[j - y];
			if(temp > result) result = temp;
		}
	}
	printf("%d", result);
	return 0;
}
