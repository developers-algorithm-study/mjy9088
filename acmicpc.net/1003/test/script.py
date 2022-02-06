import json
from subprocess import Popen, PIPE

f = open('test/cases.json')
cases = json.load(f)
f.close()

for case in cases:
    pipe = Popen(['target/debug/acmicpc_1003'],
                 stdin=PIPE, stdout=PIPE, stderr=PIPE)
    pipe.stdin.write(case['input'])
    pipe.stdin.close()
    status = pipe.wait()
    stdout = pipe.stdout.read()
    stderr = pipe.stderr.read()
    if stdout != case['output'] or stderr != '':
        print('Failed: case {}'.format(case['name']))
        print('expected output:\n\t{}'.format(
            "\n\t".join(case['output'].split('\n'))))
        print('  your   output:\n\t{}'.format("\n\t".join(stdout.split('\n'))))
        exit()
print('Passed all cases')
