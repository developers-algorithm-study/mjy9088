from functools import reduce

int(input())
print(reduce((lambda result, tmp: int(tmp % 5 == 0) * tmp + result), map(int, input().split()), 0))
