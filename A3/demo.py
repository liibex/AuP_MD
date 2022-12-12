from subprocess import Popen, PIPE, run

p = run(['a.out'], stdout=PIPE, input="3456", encoding='ascii')
print(p)