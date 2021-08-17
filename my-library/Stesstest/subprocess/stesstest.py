from settings import Config
from generator import gen_test
from comparator import compare
from printer import print_test

config = Config('config.txt')

def stresstest_with_checker():
    # TO DO
    pass


def stresstest_with_comparator():
    test_n = 1
    while True:
        print(f"TEST #{test_n}")
        test_n += 1
        gen_test(config, test_n)
        res = compare(config)
        if res == 1:
            print('FAIL')
        elif res == 2:
            print('Something went wrong.')
        else:
            print('SUCCES')
        if res != 0:
            print_test(config)


def stresstest_with_interactor():
    # TO DO
    pass


if __name__ == "__main__":
    stresstest_with_comparator()
