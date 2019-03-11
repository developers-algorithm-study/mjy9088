from functools import reduce

int(input())
print(reduce((lambda result, tmp: int(int(tmp) % 5 == 0) * int(tmp) + result), input().split(), 0))
