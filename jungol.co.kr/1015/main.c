#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char forward[100][71], backward[100][71], now[71] = "http://www.acm.org/", command[8], f = 0, b = 0;
	while(1)
	{
		scanf("%s", command);
		switch(command[0])
		{
			case 'Q':
				return 0;
			case 'V':
				f = 0;
				strcpy(backward[b++], now);
				scanf("%s", now);
				printf("%s\n", now);
				break;
			case 'B':
				if(!b)
				{
					printf("Ignored\n");
					break;
				}
				strcpy(forward[f++], now);
				strcpy(now, backward[--b]);
				printf("%s\n", now);
				break;
			case 'F':
				if(!f)
				{
					printf("Ignored\n");
					break;
				}
				strcpy(backward[b++], now);
				strcpy(now, forward[--f]);
				printf("%s\n", now);
				break;
			default:
				return 0;
		}
	}
}

