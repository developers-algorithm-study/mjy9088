from functools import reduce

input(), print(reduce((lambda result, tmp: int(tmp % 5 == 0) * tmp + result), map(int, input().split()), 0))
