def solve(s, b):
	result = 1
	for i in range(s):
		result *= b - i
	for i in range(s):
		result /= i + 1
	return result
for i in range(int(input())):
	N, M = map(int, input().split())
	print(int(solve(N, M) + 0.5))