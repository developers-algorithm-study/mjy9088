import sys
from os import path, sep
from importlib import import_module
from json import loads

base_path = path.dirname(path.dirname(path.abspath(__file__)))
root_path = path.dirname(path.dirname(base_path))
sys.path.append(root_path + sep + 'test')


def n_queen_comparator(actual: str, expected: str):
    lines = int(expected)
    positions = [int(x) - 1 for x in actual.rstrip().split('\n')]
    if max(positions) != lines - 1:
        print("max {} expected, actual: {} [{}]".format(lines - 1, max(positions), ", ".join(str(v) for v in positions)));
        return True;
    if min(positions) != 0:
        print("min {} expected, actual: {} [{}]".format(0, min(positions), ", ".join(str(v) for v in positions)));
        return True;
    if len(positions) != lines:
        return True;
    if len(set(positions)) != lines:
        return True;
    if len(set([x + i for x, i in enumerate(positions)])) != lines:
        return True;
    if len(set([x - i for x, i in enumerate(positions)])) != lines:
        return True;
    return False


def generate_test():
    template = """
    {{
        "name": "{} x {}",
        "stdin": "{}\\n",
        "stdout": "{}"
    }}
    """
    return [loads(template.format(x, x, x, x)) for x in [8, 26, 213, 2012, 99991, 99999]]


if import_module('pipe').test(
    # prelaunch_tasks=[['cargo', 'build']],
    # popen_params=sep.join([base_path, 'target', 'debug', 'acmicpc_21133']),
    prelaunch_tasks=[[
        'gcc',
        '-Wall',
        '-Wextra',
        '-Werror',
        '-std=c99',
        '-pedantic',
        sep.join([base_path, 'old', 'main.c']),
        '-o',
        sep.join([base_path, 'old', 'main.exe'])
    ]],
    popen_params=sep.join([base_path, 'old', 'main.exe']),
    # path_to_cases_json=sep.join([base_path, 'test', 'cases.json']),
    cases=generate_test(),
    stdout_comparator=n_queen_comparator
):
    print('Passed all cases')
else:
    exit(1)
