#include <stdio.h>

typedef struct
{
	int u, d;
} frag;

int main(int argc, char **argv)
{
	int N, i, j, k, l = 0;
	scanf("%d", &N);
	frag tmp[12643], temp;
	tmp[l++] = (frag){0, 1};
	tmp[l++] = (frag){1, 1};
	for(i = 2; i <= N; i++)
	{
		tmp[l++] = (frag){1, i};
		for(j = 2; j < i; j++)
		{
			CONTINUE:
			for(k = 2; k <= j; k++)
			{
				if(i % k == 0 && j % k == 0)
				{
					j++;
					goto CONTINUE;
				}
			}
			tmp[l++] = (frag){j, i};
		}
	}
	for(i = 1; i < l; i++)
	{
		for(j = i; j >= 0; j--)
		{
			if(tmp[j].u * tmp[j - 1].d < tmp[j - 1].u * tmp[j].d)
			{
				temp = tmp[j];
				tmp[j] = tmp[j - 1];
				tmp[j - 1] = temp;
			}
		}
	}
	for(i = 0; i < l; i++)
	{
		printf("%d/%d\n", tmp[i].u, tmp[i].d);
	}
	return 0;
}

