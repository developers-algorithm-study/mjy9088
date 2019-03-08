N = int(input())
Y, X = map((lambda a: int(a) - 1), input().split())

def abs(a):
	if a < 0:
		return -a
	else:
		return a

for i in range(0, N):
	for j in range(0, N):
		print(abs(X - j) + abs(Y - i) + 1, end=' ')
	print()
