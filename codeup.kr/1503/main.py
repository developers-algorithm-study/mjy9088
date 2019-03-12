N = int(input())
for i in range(N):
	for j in range(N):
		print((i + (i % 2)) * N + j * (1 - (i % 2) * 2) + (i + 1) % 2, end=' ')
	print()
