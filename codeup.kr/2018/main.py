S, E = map(int, input().split())
if S == 1:
	print('1 ')
S -= 2
if E == 1:
	exit()
a, b, len = [None] * 452, [None] * 591, 1
a[0] = [1, 1]
for i in range(1, E):
	a, b = b, a
	idx = 0
	a[0] = [b[0][1], 1]
	if a[0][0] == b[0][1]:
		a[0][1] += 1
	else:
		a[1] = [b[0][1], 1]
		idx += 1
	if S < i:
		print(b[0][0], end=' ')
		print(b[0][1], end=' ')
	for j in range(1, len):
		if S < i:
			print(b[j][0], end=' ')
			print(b[j][1], end=' ')
		if a[idx][0] == b[j][0]:
			a[idx][1] += 1
		else:
			idx += 1
			a[idx] = [b[j][0], 1]
		if a[idx][0] == b[j][1]:
			a[idx][1] += 1
		else:
			idx += 1
			a[idx] = [b[j][1], 1]
	if S < i:
		print()
	len = idx + 1
