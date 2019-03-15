def solve(a, b):
	if b == 1:
		return a % 10
	if b % 2:
		return a * solve((a * a) % 10, b // 2) % 10
	else:
		if b:
			return solve((a * a) % 10, b // 2) % 10
		else:
			return 1;

for i in range(int(input())):
	A, B = map(int, input().split())
	print((9 + solve(A, B)) % 10 + 1)