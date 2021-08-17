class Config:
    def __init__(self, config_filename):
        config = open(config_filename, 'r')
        [self.test, self.my_solve, self.my_ans, self.right_solve, self.right_ans] = \
            [config_parse(param) for param in config.readlines()]
        config.close()


    def get_config_of_my_solve(self):
        return (self.my_solve, self.test, self.my_ans)


    def get_config_of_right_solve(self):
        return (self.right_solve, self.test, self.right_ans)

def config_parse(param):
    # FIX ME: there can be '=' in the path
    if param[-1] == '\n':
        param = param[:-1]
    return param[param.find('=') + 1:]
