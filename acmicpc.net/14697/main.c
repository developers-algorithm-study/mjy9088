#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a, b, c, i, dp[301] = {0, };
	scanf("%d %d %d", &a, &b, &c);
	dp[a] = 1;
	dp[b] = 1;
	dp[c] = 1;
	for(i = 1; i <= 300; i++)
	{
		dp[i] = dp[i] || i > a && dp[i - a] || i > b && dp[i - b] || i > c && dp[i - c];
	}
	scanf("%d", &i);
	printf("%d", dp[i]);
	return 0;
}

