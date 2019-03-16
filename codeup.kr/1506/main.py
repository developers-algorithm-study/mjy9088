N = int(input())
arr = [None] * N
for i in range(N):
	arr[i] = [None] * N
s = N
c, x, y = 0, 0, 0
while s:
	c += 1
	arr[y][x] = c
	if s == 1:
		break
	for i in range(1, s):
		y += 1
		c += 1
		arr[y][x] = c
	for i in range(1, s):
		x += 1
		c += 1
		arr[y][x] = c
	for i in range(1, s):
		y -= 1
		c += 1
		arr[y][x] = c
	for i in range(2, s):
		x -= 1
		c += 1
		arr[y][x] = c
	y += 1
	s -= 2

for i in range(N):
	print(' '.join(map(str, arr[i])))
