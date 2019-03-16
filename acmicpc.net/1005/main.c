#include <stdio.h>

typedef struct _tagR
{
	struct _tagR *next;
	int b;
} R;

typedef struct _tagB
{
	R *head;
	int time;
	int cal;
} B;

int solve(B *arr, int t)
{
	int result = arr[t].time;
	R *tmp = arr[t].head;
	printf(" %d", t);
	while(tmp)
	{
		if(arr[tmp->b].cal == -1)
		{
			result += solve(arr, tmp->b);
		}
		tmp = tmp->next;
	}
	return arr[t].cal = result;
}

int main(int argc, char **argv)
{
	int T, N, K, i, j, t;
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &K);
		B arr[N];
		R tmp[K];
		for(j = 0; j < N; j++)
		{
			scanf("%d", &arr[j].time);
			arr[j].head = NULL;
			arr[j].cal = -1;
		}
		for(j = 0; j < K; j++)
		{
			scanf("%d %d", &tmp[j].b, &t);
			tmp[j].next = arr[t].head;
			arr[t].head = &tmp[j];
		}
		scanf("%d", &t);
		printf("%d\n", solve(arr, t));
	}
	return 0;
}

