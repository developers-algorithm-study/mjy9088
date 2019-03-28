arr = [None] * 19;
for i in range(19):
	arr[i] = list(map(int, input().split()))
N = int(input())
for i in range(N):
	x, y = map(lambda x: int(x) - 1, input().split())
	for j in range(19):
		arr[y][j] = 1 - arr[y][j]
		arr[j][x] = 1 - arr[j][x]
for i in range(19):
	print(" ".join(map(str, arr[i])))
