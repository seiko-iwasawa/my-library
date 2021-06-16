from subprocess import Popen, PIPE, CREATE_NO_WINDOW
from random import seed, randint

solve_path = "C:\\Users\\tulen\\source\\repos\\A\\Release\\A.exe"

def gen_test():
    global n, a, ans
    n = 5
    a = [randint(1, 10) for i in range(n)]
    ans = min(a)


def get_line():
    res = solve.stdout.readline().decode().strip()
    print('\t', res, sep='')
    return res


def write_line(s):
    print(s)
    solve.stdin.write((s+ '\n').encode())
    solve.stdin.flush()


def print_test():
    print(n)
    print(*a)


def run():
    gen_test()
    write_line(str(n))
    while True:
        t, i = get_line().split()
        i = int(i)
        if t == '?':
            i -= 1
            write_line(str(a[i]))
        else:
            if i != ans:
                print("FAIL")
                print_test()
                input()
            else:
                print("SUCCES")
            break


seed(7)
test_n = 1
while True:
    print("TEST #", test_n, sep = '')
    solve = Popen([solve_path], stdin=PIPE, stdout=PIPE, creationflags = CREATE_NO_WINDOW)
    run()
    test_n += 1
