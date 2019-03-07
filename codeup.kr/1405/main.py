N = int(input())
arr = [int(num) for num in input().split()]

for i in range(0, N):
	for j in range(0, N):
		print(arr[(i + j) % N], end=' ')
	print()
