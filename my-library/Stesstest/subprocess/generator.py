from random import *

def gen_test(config, test_n):
    seed(test_n)
    test = open(config.test, 'w')
    test.write(f"{str(randint(1, 10))} {str(randint(1, 10))}\n")
    test.close()
