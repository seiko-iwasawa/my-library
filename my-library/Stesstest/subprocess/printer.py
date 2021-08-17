import os

def print_file(file_path):
    fin = open(file_path, 'r')
    print(fin.read())
    fin.close()


def pause():
    # https://stackoverflow.com/a/1395006
    try:
        os.system('pause')  # windows, doesn't require enter
    except:
        os.system('read -p "Press any key to continue"') # linux


def print_test(config):
    print('TEST:')
    print_file(config.test)
    print('MY ANS:')
    print_file(config.my_ans)
    print('RIGHT ANS:')
    print_file(config.right_ans)
    pause()
