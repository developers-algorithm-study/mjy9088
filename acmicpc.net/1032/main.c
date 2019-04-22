#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int N, i, j;
	char result[51], tmp[51];
	scanf("%d", &N);
	getchar();
	gets(result);
	for(i = 1; i < N; i++)
	{
		gets(tmp);
		for(j = 0; tmp[j]; j++)
		{
			if(result[j] != tmp[j])
			{
				result[j] = '?';
			}
		}
	}
	puts(result);
	return 0;
}

