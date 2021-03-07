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

// 그 건물을 짓는 데 걸리는 시간
int solve(Building *arr, int target)
{
	// if cache miss
	if (arr[target].cache == -1) {
		// 먼저 지어야 할 건물을 짓는데 걸리는 시간
		int latest = 0;
		Requirements *tmp = arr[target].head;
		// 그 건물을 짓기 전에 먼저 지어야 할 건물이 있다면
		while (tmp) { 
			int current = solve(arr, tmp->buildingIndex);
			// 먼저 지어야 할 건물 중 가장 오래 걸리는 시간으로
			if (current > latest) latest = current;
			tmp = tmp->next;
		}
		// 먼저 지어야 할 건물을 다 짓는 시간 + 본 건물을 짓는 시간
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
		// 건물 개수, 먼저 지어야 할 건물 규칙 개수
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
			// 1-based index이므로 0-based index로 만듦
			tmp[j].buildingIndex -= 1;
			t -= 1;
			// 링크드리스트 노드 삽입
			tmp[j].next = arr[t].head;
			arr[t].head = &tmp[j];
		}
		scanf("%d", &t);
		// 1-based index이므로 0-based index로 만듦
		t -= 1; 
		printf("%d\n", solve(arr, t));
		free(arr);
		free(tmp);
	}
	return 0;
}

