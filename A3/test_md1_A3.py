import pytest
import ctypes
from subprocess import Popen, PIPE, run
import A3

'''
=== A3 =======================================

Izveidot programmu gan C++, gan Python.
Ievadot loģiski nepareizus datus, programmai jāizdod atbilstošs paziņojums. 
Jābūt iespējai programmu izpildīt atkārtoti. Atrādot programmu, jāatrāda:
  a) programmas teksts,  
  b) testa piemēri,  
  c) programma darbībā.
Precīzākas prasības sk. Laboratorijas darbu noteikumos.

A3. Dots naturāls skaitlis n. 
Noskaidrot šī skaitļa pirmā un pēdējā cipara summu. Skaitļa dalīšana ciparos jāveic skaitliski.
'''

''' TEST '''
#beach = "./a.out"
#a3cpp = ctypes.cdll.LoadLibrary(beach)
#
#a3cpp.main()



@pytest.mark.parametrize("test_input,expected", [
    (3456, 9), (0, 0), (8, 16), (-1234, 5),
    ('a', 'That was not a valid number!'),
    (' ', 'That was not a valid number!'),
    ('1,4', 'That was not a valid number!'),
    ('1.4', 'That was not a valid number!'),
    ('-', 'That was not a valid number!'),])
def test_A3py(monkeypatch, capfd, test_input, expected):
    monkeypatch.setattr('builtins.input', lambda _: test_input)
    #subprocess.check_output("./a.out")
    result = A3.menu()
    out, err = capfd.readouterr()
    assert out == str(expected) + '\n'
    monkeypatch.setattr('builtins.input', next(responses, 'n'))




#@pytest.mark.parametrize("test_input,expected", [
#    (3456, 9), (0, 0), (8, 16), (-1234, 5),
#    ('a', 'That was not a valid number!'),
#    (' ', 'That was not a valid number!'),
#    ('1,4', 'That was not a valid number!'),
#    ('1.4', 'That was not a valid number!'),
#    ('-', 'That was not a valid number!'),])
#def test_A3cpp(test_input, expected):
#    p = run(['./a.out'], stdout=PIPE, input="3456", encoding='ascii')
#    print(p.returncode)
#    print(p.stdout)
#    #p = Popen(['./a.out'], shell=True, stdout=PIPE, stdin=PIPE)
#    print(p)
#    #my_text = test_input.encode('utf-8')
#    #value = bytes(my_text, 'utf-8')  # Needed in Python 3.
#    #p.stdin.write('{}'.format(test_input).encode('utf-8'))
#    #kinit.stdin.write('{}\n'.format(password).encode('utf-8'))
#    out,err = p.communicate(input=b'3456\n')[0]
#    out = str(out)
#    assert str(expected) + '\\n' in out
#    #p.stdin.flush()
#    #result = p.stdout.readline().strip()
#    #print(result)
#    #assert result == bytes(str(expected) + '\n', 'UTF-8')





@pytest.mark.parametrize("test_input,expected", [
    (3456, 9), (0, 0), (8, 16), (-1234, 5),
    #('a', 'That was not a valid number!'),
    #(' ', 'That was not a valid number!'),
    #('1,4', 'That was not a valid number!'),
    #('1.4', 'That was not a valid number!'),
    #('-', 'That was not a valid number!'),
    ])
def test_A3cpp(test_input, expected):
    #p = run(['./a.out'], stdout=PIPE, input=bytes(test_input, 'utf-8'))
    #print(p.returncode)
    #print(p.stdout)
    p = Popen(['a.out'], shell=True, stdout=PIPE, stdin=PIPE)
    p.stdin.flush()
    #p.wait()
    #print(p)
    #my_text = test_input.encode('utf-8')
    #value = bytes(my_text, 'utf-8')  # Needed in Python 3.
    #p.stdin.write('{}'.format(test_input).encode('utf-8'))
    #kinit.stdin.write('{}\n'.format(password).encode('utf-8'))
    out,err = p.communicate(input=bytes(test_input, 'utf-8'))
    #out = str(out)
    #assert str(expected) + '\\n' in out
    #p.stdin.flush()
    result = str(p.stdout)
    #print(result)
    assert str(result) == bytes(str(expected) + '\n', 'UTF-8')