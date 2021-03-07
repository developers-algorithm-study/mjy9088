#include <stdio.h>
#include <stdlib.h>

typedef struct requirements // linked list node
{
	struct requirements *next;
	int buildingIndex;
} Requirements;

typedef struct building
{
	int time;
	int cache;
	Requirements *head;
} Building;

// �� �ǹ��� ���� �� �ɸ��� �ð�
int solve(Building *arr, int target)
{
	// if cache miss
	if (arr[target].cache == -1) {
		// ���� ����� �� �ǹ��� ���µ� �ɸ��� �ð�
		int latest = 0;
		Requirements *tmp = arr[target].head;
		// �� �ǹ��� ���� ���� ���� ����� �� �ǹ��� �ִٸ�
		while (tmp) { 
			int current = solve(arr, tmp->buildingIndex);
			// ���� ����� �� �ǹ� �� ���� ���� �ɸ��� �ð�����
			if (current > latest) latest = current;
			tmp = tmp->next;
		}
		// ���� ����� �� �ǹ��� �� ���� �ð� + �� �ǹ��� ���� �ð�
		arr[target].cache = latest + arr[target].time;
	}
	return arr[target].cache;
}

int main(int argc, char **argv)
{
	int T, N, K, i, j, t;
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		// �ǹ� ����, ���� ����� �� �ǹ� ��Ģ ����
		scanf("%d %d", &N, &K);
		Building* arr = malloc(sizeof(Building) * N);
		Requirements* tmp = malloc(sizeof(Requirements) * K);
		for(j = 0; j < N; j++)
		{
			scanf("%d", &arr[j].time);
			arr[j].cache = -1; // INVALID_VALUE
			arr[j].head = NULL;
		}
		for(j = 0; j < K; j++)
		{
			scanf("%d %d", &tmp[j].buildingIndex, &t);
			// 1-based index�̹Ƿ� 0-based index�� ����
			tmp[j].buildingIndex -= 1;
			t -= 1;
			// ��ũ�帮��Ʈ ��� ����
			tmp[j].next = arr[t].head;
			arr[t].head = &tmp[j];
		}
		scanf("%d", &t);
		// 1-based index�̹Ƿ� 0-based index�� ����
		t -= 1; 
		printf("%d\n", solve(arr, t));
		free(arr);
		free(tmp);
	}
	return 0;
}

