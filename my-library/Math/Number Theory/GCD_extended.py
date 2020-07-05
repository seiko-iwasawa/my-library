def gcd_ext(a, b):
    if b == 0: return 1, 0
    else:
        y, x = gcd_ext(b, a % b)
        y -= a // b * x
        return x, y
