N, K = map(int, input().split())

for i in range(0, N):
	for j in range(0, N):
		if i == 0 or j == 0 or i == N - 1 or j == N - 1 or (i + j) % K == K - 1:
			print('*', end='')
		else:
			print(' ', end='')
	print()
