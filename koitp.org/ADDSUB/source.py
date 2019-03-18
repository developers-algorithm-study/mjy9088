N, a, b = int(input()), [None] * 21, [None] * 21
if N:
	u = list(map(int, input().split()))
	for i in range(21):
		a[i] = 0
	a[u[0]] = 1
	for i in range(1, N - 1):
		a, b = b, a
		for j in range(21):
			a[j] = 0
		for j in range(21 - u[i]):
			a[j] += b[j + u[i]]
			a[j + u[i]] += b[j]
	print(a[u[-1]])
else:
	print("0")
