from functools import reduce

print(reduce((lambda result, tmp: int(result == 0) * int(tmp % 5 == 0) * tmp + result), map(int, input().split()), 0))
