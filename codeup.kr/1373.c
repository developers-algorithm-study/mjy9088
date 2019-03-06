#include <stdio.h>

int main(int argc, char **argv)
{
	int N, M, K, P;
	scanf("%d %d %d %d", &N, &M, &K, &P);
	if(M < 0) M = -M;
	if(N < 0) N = -N;
	if(M > N)
	{
		int tmp = M;
		M = N;
		N = tmp;
	}
	if(!M && !N)
	{
		printf("%d %d", K ? 6 : 4, P ? 8 * (1 + K * 2) % P : 8 * (1 + K * 2));
	}
	else if(!M && N == 1)
	{
		printf("%d %d", K ? 5 : 3, P ? (K ? 10 : 2) % P : K ? 10 : 2);
	}
	else if(!M && N == 2)
	{
		printf("4 %d", P ? (K ? 2 : 2) % P : K ? 2 : 2);
	}
	else if(!M)
	{
		if(K && N == 3) printf("5 10");
		else printf("%d %d", N + 2, P ? N * (N + 1) % P : N * (N + 1));
	}
	else if(M == 1 && N == 1)
	{
		printf("4 %d", P ? 4 % P : 4);
	}
	else if(M == 1 && N == 2)
	{
		printf("%d %d", K ? 5 : 3, P ? (K ? 8 : 1) % P : K ? 8 : 1);
	}
	else if(M == 1)
	{
		printf("%d %d", N + 1, P ? (N - 1) % P : N - 1);
	}
	else if(M == 2 && N == 2)
	{
		printf("4 %d", P ? (K ? 2 : 6) % P : K ? 2 : 6);
	}
	else
	{
		int arr1[M], arr2[M];
		int *now = &arr1[0], *prev = &arr2[0], *tmp;
		int i, j;
		for(i = 0; i < M; i++)
		{
			arr1[i] = i + 2;
		}
		for(i = 1; i < N; i++)
		{
			tmp = prev;
			prev = now;
			now = tmp;
			now[0] = 1 + prev[0];
			for(j = 1; j < M; j++)
			{
				now[j] = P ? (now[j - 1] + prev[j]) % P : now[j - 1] + prev[j];
			}
		}
		i = P ? (now[M - 1] + P - 2) % P : now[M - 1] - 2;
		if(K)
		{
			if(M == N) i = P ? (i + P - 2) % P : i - 2;
			else if(M + 1 == N) i = P ? (i + P - 1) % P : i - 1;
		}
		printf("%d %d", M + N, i);
	}
	return 0;
}

