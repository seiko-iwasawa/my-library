# unchecked

import random

def gcd(a, b):
    if b == 0: return a
    else: return gcd(b, a % b)


def nxt(seed):
    return seed * seed + 3


def pollard(n):
    if n % 2 == 0: return 2
    elif int(n ** 0.5) ** 2 == n: return int(n ** 0.5)
    else:
        x = y = random.randint(0, n - 1)
        for it in range(1000000):
            if x != y and gcd(abs(x - y), n) != 1:
                return gcd(abs(x - y), n)
            x = nxt(x) % n
            y = nxt(nxt(y)) % n
        return -1
