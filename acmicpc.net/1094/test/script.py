import sys
from os import path, sep
from importlib import import_module

base_path = path.dirname(path.dirname(path.abspath(__file__)))
root_path = path.dirname(path.dirname(base_path))
sys.path.append(root_path + sep + 'test')

if import_module('pipe').test(
    prelaunch_tasks=[['cargo', 'build']],
    popen_params=sep.join([base_path, 'target', 'debug', 'acmicpc_1094']),
    path_to_cases_json=sep.join([base_path, 'test', 'cases.json'])
):
    print('Passed all cases')
else:
    exit(1)
