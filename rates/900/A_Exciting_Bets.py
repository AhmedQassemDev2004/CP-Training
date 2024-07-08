from math import gcd 


def solve(a: int, b: int):
    moves, res = 0,0

    if a != b:
        res = abs(a-b)
        moves = min(a%res, res-a%res)        

    return f"{res} {moves}"

t = int(input())

for _ in range(t):
    a, b = tuple(map(int, input().split()))
    print(solve(a, b))