#include <stdio.h>
#include <string.h>

int stack_contents[10000]; // 귀찮아
int stack_size = 0;

int main(int argc, char **argv)
{
	int N, n, i;
	char command[6]; // 명령어 최대 5글자 (empty)
	scanf("%d", &N); // 첫째 줄에 주어지는 명령의 수 N
	for(i = 0; i < N; i++)
	{
		scanf("%s", command);
		if(strcmp(command, "push") == 0)
		{
			scanf("%d", &n);
			stack_contents[stack_size++] = n;
			continue;
		}
		if(strcmp(command, "pop") == 0)
		{
			if(stack_size == 0)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n", stack_contents[--stack_size]);
			continue;
		}
		if(strcmp(command, "size") == 0)
		{
			printf("%d\n", stack_size);
			continue;
		}
		if(strcmp(command, "empty") == 0)
		{
			if(stack_size == 0)
			{
				printf("1\n");
				continue;
			}
			printf("0\n");
			continue;
		}
		if(strcmp(command, "top") == 0)
		{
			if(stack_size == 0)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n", stack_contents[stack_size - 1]);
			continue;
		}
	}
	return 0;
}

