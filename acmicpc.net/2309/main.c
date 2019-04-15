#include <stdio.h>

int main(int argc, char **argv)
{
	int i, j, arr[9], tmp, temp = 0;
	for(i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		temp += arr[i];
	}
	for(i = 0; i < 9; i++)
	{
		for(j = 7; j >= 0; j--)
		{
			if(arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	temp = temp - 100;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(i == j) continue;
			if(arr[i] + arr[j] == temp) goto endLoop;
		}
	}
	endLoop:
	for(tmp = 0; tmp < 9; tmp++)
	{
		if(tmp != i && tmp != j)
		{
			printf("%d\n", arr[tmp]);
		}
	}
	return 0;
}

