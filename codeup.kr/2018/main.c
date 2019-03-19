#include <stdio.h>

typedef struct
{
	int n, c;
} i2;

int main(int argc, char **argv)
{
	int S, E, i, j, len, idx;
	scanf("%d %d", &S, &E);
	if(S == 1)
	{
		printf("1 \n");
	}
	S -= 2;
	if(E == 1)
	{
		return 0;
	}
	i2 A[452], B[339], *a = A, *b = B, *temp;
	len = 1;
	a[0] = (i2){1, 1};
	for(i = 1; i < E; i++)
	{
		temp = a;
		a = b;
		b = temp;
		a[idx = 0] = (i2){b[0].n, 1};
		if(a[idx].n == b[0].c)
		{
			a[idx].c++;
		}
		else
		{
			a[++idx] = (i2){b[0].c, 1};
		}
		if(S < i)
		{
			printf("%d %d ", b[0].n, b[0].c);
		}
		for(j = 1; j < len; j++)
		{
			if(S < i)
			{
				printf("%d %d ", b[j].n, b[j].c);
			}
			if(a[idx].n == b[j].n)
			{
				a[idx].c++;
			}
			else
			{
				a[++idx] = (i2){b[j].n, 1};
			}
			if(a[idx].n == b[j].c)
			{
				a[idx].c++;
			}
			else
			{
				a[++idx] = (i2){b[j].c, 1};
			}
		}
		if(S < i)
		{
			printf("\n");
		}
		len = idx + 1;
	}
	return 0;
}

