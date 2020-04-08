# unchecked

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def relax(a):
    d = 0
    for x in a:
        d = gcd(d, x)
    if d:
        for i in range(len(a)):
			a[i] //= d


N = int(input())
used = [False] * N
eq = [[0] * (N + 1) for _ range(N)]
for i in range(N):
    j = 0
    while j != N and (used[j] or eq[j][i] == 0):
        j += 1
    if j != N:
        used[j] = True
        for k in range(N):
            if k != j and eq[k][i] != 0:
                x = eq[k][i]
                y = eq[j][i]
                for t in range(N + 1):
                    eq[k][t] *= y
                    eq[j][t] *= x
                    eq[k][t] -= eq[j][t]
                relax(eq[k])
                relax(eq[j])
ans = [0] * N
flag = False
for i in range(N):
    j = 0
    while j != N and eq[i][j] == 0:
        j += 1
    if j != N:
        ans[j] = eq[i][N] / eq[i][j]
    elif eq[i][N]:
        print("No solutions")
        exit(0)
    else:
        flag = True
if flag:
    print("INF")
else:
    print(ans)
