import json
from subprocess import Popen, PIPE
from typing import TypedDict, List, Tuple, Callable, Optional


class TestCase(TypedDict):
    name: Optional[str]
    stdin: Optional[str]
    stdout: Optional[str]
    stderr: Optional[str]
    exit_code: Optional[int]


class TestResult:
    case: TestCase
    stdout: str
    stderr: str
    exit_code: int
    passed: bool
    error_stdout: bool
    error_stderr: bool
    error_exit_code: bool

    def __init__(self, _case, out, err, status, cmp1, cmp2):
        self.case = _case
        self.stdout = out
        self.stderr = err
        self.exit_code = status
        if 'stdout' in _case:
            self.error_stdout = cmp1(out, _case['stdout'])
        else:
            self.error_stdout = cmp1(out, '')
        if 'stderr' in _case:
            self.error_stderr = cmp2(err, _case['stderr'])
        else:
            self.error_stderr = cmp2(err, '')
        if 'exit_code' in _case:
            self.error_exit_code = status != _case['exit_code']
        else:
            self.error_exit_code = status != 0
        self.passed = not (
            self.error_stdout or
            self.error_stderr or
            self.error_exit_code)


ComparatorType = Callable[[str, str], bool]


class TestArgs(TypedDict):
    popen_params: List[str]
    cases: Optional[List[TestCase]]
    path_to_cases_json: Optional[str]
    comparator: Optional[ComparatorType]
    stdout_comparator: Optional[ComparatorType]
    stderr_comparator: Optional[ComparatorType]
    result_handler: Optional[Callable[[TestResult], bool]]


def _get_cases(kwargs: TestArgs) -> List[TestCase]:
    if 'cases' in kwargs:
        if 'path_to_cases_json' in kwargs:
            raise ValueError('Multiple cases given')
        return kwargs['cases']
    if 'path_to_cases_json' in kwargs:
        if 'cases' in kwargs:
            raise ValueError('Multiple cases given')
        f = open(kwargs['path_to_cases_json'])
        cases = json.load(f)
        f.close()
        return cases
    raise ValueError('Neither cases nor path_to_cases_json given')


def _default_comparator(expected: str, actual: str) -> bool:
    return expected != actual


def _get_comparators(kwargs: TestArgs) -> Tuple[ComparatorType, ComparatorType]:
    if all(k not in kwargs for k in ('stdout_comparator', 'stderr_comparator')):
        if 'comparator' not in kwargs:
            return (_default_comparator, _default_comparator)
        return (kwargs['comparator'], kwargs['comparator'])
    if 'comparator' in kwargs:
        raise ValueError(
            'Stream specific comparator and default comparator are both given')
    stdout_comparator = _default_comparator
    if 'stdout_comparator' in kwargs:
        stdout_comparator = kwargs['stdout_comparator']
    stderr_comparator = _default_comparator
    if 'stderr_comparator' in kwargs:
        stderr_comparator = kwargs['stderr_comparator']
    return (stdout_comparator, stderr_comparator)


def _format_line(str: str, format: str) -> str:
    return '\n'.join(map(lambda line: format.format(line), str.split('\n')))


def _default_result_handler(result: TestResult, index: int) -> bool:
    if result.passed:
        return False
    case = result.case
    if 'name' in case:
        print('Failed: case {}'.format(case['name']))
    else:
        print('Failed: unnamed case #{}'.format(index + 1))
    if 'stdin' in case:
        print('stdin start\n{}\nstdin end'.format(
            _format_line(case['stdin'], 'stdin\t{}$')))
    else:
        print('empty stdin')
    if result.error_stdout:
        if 'stdout' in case:
            print('\nexpected stdout start\n{}\nexpected stdout end'.format(
                _format_line(case['stdout'], 'expected stdout\t{}$')))
        else:
            print('\nexpected stdout start\nexpected stdout\t$\nexpected stdout end')
        print('[result] stdout start\n{}\n[result] stdout end'.format(
            _format_line(result.stdout, '[result] stdout\t{}$')))
    if result.error_stderr:
        if 'stderr' in case:
            print('\nexpected stderr start\n{}\nexpected stderr end'.format(
                _format_line(case['stderr'], 'expected stderr\t{}$')))
        else:
            print('\nexpected stderr start\nexpected stderr\t$\nexpected stderr end')
        print('[result] stderr start\n{}\n[result] stderr end'.format(
            _format_line(result.stderr, '[result] stderr\t{}$')))
    if result.error_exit_code:
        if 'exit_code' in case:
            print('\nexpected exit code: {}\n[result] exit code: {}'.format(
                case['exit_code'], result.exit_code))
        else:
            print('\nexpected exit code: {}\n[result] exit code: {}'.format(
                0, result.exit_code))
    return True


encoding = 'utf-8'


def test(**kwargs) -> bool:
    """test by compare output

    :param cases: exception type
    :type
    :param limit: maximum number of stack frames to show
    :return: true on no error, false otherwise
    """

    if 'popen_params' not in kwargs:
        raise TypeError('Required parameter popen_params not given')
    popen_params = kwargs['popen_params']
    result_handler = _default_result_handler
    if 'result_handler' in kwargs:
        result_handler = kwargs['result_handler']
    cases = _get_cases(kwargs)
    (stdout_comparator, stderr_comparator) = _get_comparators(kwargs)

    if 'prelaunch_tasks' in kwargs:
        for index, task in enumerate(kwargs['prelaunch_tasks']):
            if Popen(task).wait():
                raise RuntimeError(
                    'Failed to launch task {} ({:?})'.format(index + 1, task))
    succeeded_all = True

    for index, case in enumerate(cases):
        pipe = Popen(popen_params, stdin=PIPE, stdout=PIPE, stderr=PIPE)
        pipe.stdin.write(bytes(case['stdin'].encode(encoding)))
        pipe.stdin.close()
        exit_code = pipe.wait()
        stdout = pipe.stdout.read().decode(encoding)
        stderr = pipe.stderr.read().decode(encoding)
        result = TestResult(case, stdout, stderr, exit_code,
                            stdout_comparator, stderr_comparator)
        if not result.passed:
            succeeded_all = False
        if result_handler(result, index):
            return succeeded_all
    return succeeded_all
