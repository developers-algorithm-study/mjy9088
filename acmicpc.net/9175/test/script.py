import sys
from os import path, sep
from importlib import import_module
from json import loads
from typing import List

base_path = path.dirname(path.dirname(path.abspath(__file__)))
root_path = path.dirname(path.dirname(base_path))
sys.path.append(root_path + sep + 'test')


def n_queen(size: int, positions: List[str]):
    if max(positions) != size - 1:
        return True;
    if min(positions) != 0:
        return True;
    if len(positions) != size:
        return True;
    if len(set(positions)) != size:
        return True;
    if len(set([x + i for x, i in enumerate(positions)])) != size:
        return True;
    if len(set([x - i for x, i in enumerate(positions)])) != size:
        return True;
    return False


def comparator(actual: str, expected: str):
    sizes = expected.rstrip().split('\n');
    positions = actual.split();
    index = 0
    for size in sizes:
        size = int(size);
        if int(positions[index]) != size:
            return True;
        if n_queen(size, list(map(int, positions[index + 1:index + size + 1]))):
            return True;
        index = index + size + 1;
    return False;


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
    path_to_cases_json=sep.join([base_path, 'test', 'cases.json']),
    stdout_comparator=comparator
):
    print('Passed all cases')
else:
    exit(1)
