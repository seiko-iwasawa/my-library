import subprocess

def compare_answers(test, my_fin, right_fin):
    return my_fin.read() != right_fin.read()


def run(solve_path, fin_name, fout_name):
    fin = open(fin_name, 'r')
    fout = open(fout_name, 'w')
    subprocess.call([solve_path], stdin=fin, stdout=fout)
    fin.close()
    fout.close()


def is_correct(test, ans):
    try:
        return True
    except:
        return False


def compare(config):
    run(*config.get_config_of_my_solve())
    run(*config.get_config_of_right_solve())
    if not is_correct(config.test, config.my_ans):
        return 1
    elif not is_correct(config.test, config.right_ans):
        return 2
    else:
        test = open(config.test, 'r')
        my_fin = open(config.my_ans, 'r')
        right_fin = open(config.right_ans, 'r')
        res = compare_answers(test, my_fin, right_fin)
        test.close()
        my_fin.close()
        right_fin.close()
        return res
