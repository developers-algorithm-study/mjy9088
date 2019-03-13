#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int count;
	int idx[];
} parsed;

void solve(parsed *a, parsed *b, parsed *c, int len, void(*onResult)(parsed *, parsed *, parsed *, int *));

void printx(parsed *self, int *val)
{
	int i;
	for(i = 0; i < self->count; i++)
	{
		printf("%d", val[self->idx[i]]);
	}
}

int evalx(parsed *self, int *val)
{
	int result = 0, i;
	for(i = 0; i < self->count; i++)
	{
		result = result * 10 + val[self->idx[i]];
	}
	return result;
}

int validx(parsed *self, int *val)
{
	return val[self->idx[0]];
}

void result(parsed *a, parsed *b, parsed *c, int *arr)
{
	printx(a, arr);
	printf("+");
	printx(b, arr);
	printf("=");
	printx(c, arr);
	printf("\n");
}

int main(int argc, char **argv)
{
	parsed *a = malloc(sizeof(parsed) + sizeof(int) * 2);
	parsed *b = malloc(sizeof(parsed) + sizeof(int) * 2);
	parsed *c = malloc(sizeof(parsed) + sizeof(int) * 3);
	a->count = 2; a->idx[0] = 0; a->idx[1] = 1;
	b->count = 2; b->idx[0] = 0; b->idx[1] = 1;
	c->count = 3; c->idx[0] = 2; c->idx[1] = 1; c->idx[2] = 1;
	solve(a, b, c, 3, &result);
	free(a);
	free(b);
	free(c);
	return 0;
}

void solve(parsed *a, parsed *b, parsed *c, int len, void(*onResult)(parsed *a, parsed *b, parsed *c, int *arr))
{
	int result[len], i;
	for(i = 0; i < len; i++)
	{
		result[i] = 0;
	}
	while(1)
	{
		if(evalx(a, result) + evalx(b, result) == evalx(c, result) && validx(a, result) && validx(b, result) && validx(c, result))
		{
			(*onResult)(a, b, c, result);
		}
		for(i = len - 1; ; i--)
		{
			if(result[i] = (result[i] + 1) % 10)
			{
				break;
			}
			if(!i) return;
		}
	}
}

