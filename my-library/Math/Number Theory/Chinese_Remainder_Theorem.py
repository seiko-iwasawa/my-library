def gcd_ext(a, b):
    if b == 0:
        return 1, 0, a
    else:
        y, x, res = gcd_ext(b, a % b)
        y -= a // b * x
        return x, y, res


def chreth(n, a, m, b):
    k1, k2, d = gcd_ext(n, m)
    if (b - a) % d != 0:
        return -1
    return (k1 * (b - a) // d * n + a) % (n * m // d)


print(chreth(int(input()), int(input()), int(input()), int(input())))
