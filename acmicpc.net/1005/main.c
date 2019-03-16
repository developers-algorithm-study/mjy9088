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
} B;

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
			arr[j].head = NULL;
			scanf("%d", &arr[j].time);
		}
		for(j = 0; j < K; j++)
		{
			scanf("%d %d", &tmp[j].b, &t);
			tmp[j].next = arr[t].head;
			arr[t].head = &tmp[j];
		}
	}
	return 0;
}

