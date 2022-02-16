#include <stdio.h>

int main(int argc, char **argv)
{
	int T, i, d, a;
	scanf("%d", &T);
	getchar();
	for(i = 0; i < T; i++)
	{
		a = d = 0;
		char c;
		while(1)
		{
			c = getchar();
			if(c == '(')
			{
				d++;
			}
			else if(c == ')')
			{
				d--;
				if(d < 0)
				{
					a = 1;
				}
			}
			else
			{
				break;
			}
		}
		printf("%s\n", a || d ? "NO" : "YES");
	}
	return 0;
}

