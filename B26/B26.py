'''
=== B26 =======================================
B26. 
Dots naturāls skaitlis n. Noskaidrot, vai doto skaitli var izteikt kā trīs naturālu skaitļu kvadrātu summu. 
Izdrukāt visus  šādus naturālu skaitļu trijniekus. 
Risinājumā izmantot funkciju, kas aprēķina trīs skaitļu kvadrātu summu.
'''

def three_n_squared_sum(i,j,k): # 3 skaitļa kvadarātu summa
    sum = i**2 + j**2 + k**2
    return sum

def return_all_combinations(x): # 
    max = int(x**(1/2))                                 # max ir summas kvadråtsakne
    cnt = 0
    for i in range(1, (max + 1)):
        for j in range(1, (x - i**2 + 1)):
            for k in range(1, (x - (i**2 + j**2) + 1)):     # Var iztikt bez 3 for loop, bet prasība ir izmantot minēto funkciju
                if three_n_squared_sum(i,j,k) == x:
                    print(f'Numbers {i},{j},{k} sum: {three_n_squared_sum(i,j,k)}')
                    cnt += 1
    if cnt == 0:                                                # Nav tādu kombināciju
        print("This number has no valid combinations.")


def menu():
    opt = "y"
    while opt == "y":
        try:
            x = int(input("Please enter a number: "))   # x ir int
            if x > 0:                                   # nav 0 vai negatīvs
                return_all_combinations(x)              # Aloritma izsaukums
            else:
                print("That was not a valid number.")   
            opt = input("Try again? (y/n)\n")           # Try again loop sagaida tikai vēr†ības (y,n)
        except ValueError:                              # x nav int
            print("That was not a valid number.")
            opt = input("Try again? (y/n)\n")           # Try again loop sagaida tikai vēr†ības (y,n)


if __name__ == "__main__":
    menu()
"""
    "test_input,expected",
    [
        (3, "Numbers 1, 1, 1, sum: 3"),
        (0, "That was not a valid number."),
        (k, "That was not a valid number."),
        (10, "This number has no valid combinations.""),
        (-10, "That was not a valid number."),
        (234, "
Numbers 1,8,13 sum: 234
Numbers 1,13,8 sum: 234
Numbers 3,9,12 sum: 234
Numbers 3,12,9 sum: 234
Numbers 4,7,13 sum: 234
Numbers 4,13,7 sum: 234
Numbers 7,4,13 sum: 234
Numbers 7,8,11 sum: 234
Numbers 7,11,8 sum: 234
Numbers 7,13,4 sum: 234
Numbers 8,1,13 sum: 234
Numbers 8,7,11 sum: 234
Numbers 8,11,7 sum: 234
Numbers 8,13,1 sum: 234
Numbers 9,3,12 sum: 234
Numbers 9,12,3 sum: 234
Numbers 11,7,8 sum: 234
Numbers 11,8,7 sum: 234
Numbers 12,3,9 sum: 234
Numbers 12,9,3 sum: 234
Numbers 13,1,8 sum: 234
Numbers 13,4,7 sum: 234
Numbers 13,7,4 sum: 234
Numbers 13,8,1 sum: 234"),
    ],
"""