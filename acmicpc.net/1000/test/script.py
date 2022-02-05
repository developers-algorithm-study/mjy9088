import json
from subprocess import Popen, PIPE

f = open('test/cases.json')
cases = json.load(f)
f.close()


for case in cases:
	pipe = Popen(['target/debug/acmicpc_1000'], stdin=PIPE, stdout=PIPE, stderr=PIPE)
	pipe.stdin.write(case['input']);
	pipe.stdin.close();
	status = pipe.wait()
	stdout = pipe.stdout.read();
	stderr = pipe.stderr.read();
	if stdout != case['output'] or stderr != '':
		print('Failed: case {}'.format(case['name']));
		exit();
print('Passed all cases')
