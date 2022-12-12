import pytest

"""
=== A3 =======================================
A3. Dots naturāls skaitlis n. 
Noskaidrot šī skaitļa pirmā un pēdējā cipara summu. 
Skaitļa dalīšana ciparos jāveic skaitliski.
"""


def get_first_n(n):     # Naturāla skaitļa pirmais cipars
    while n >= 10:
        n = n // 10     # int dalīšana dala līdz veselam skaitlim
    return n


def get_last_n(n):      # Naturāļa skaitļa pēdējais cipars
    return n % 10       # Dalījuma 10 atlikums (0-9)


def first_last_sum(n):  # skaitļa pirmā un pēdējā cipara summu
    if n < 0:
        n = -n
    return get_first_n(n) + get_last_n(n)


def menu():
    opt = "y"
    while opt == "y":   #
        try:
            x = int(input("Please enter a number: "))   # Ievadi skaitli
            print(first_last_sum(x))                    # Izsauc algortimu
        except ValueError:                              # Ja nav int, izmet kļūdas paziņojumu
            print("That was not a valid number!")
        opt = ''
        opt = input("Try again? (y/n): ")
        while opt!='n' and opt!='y':                    # Try again loop sagaida tikai vēr†ības (y,n)
            opt = input("Try again? (y/n): ")


if __name__ == "__main__": # __main__ hook
    menu()
