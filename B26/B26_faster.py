'''
=== B26 =======================================
B26. 
Dots naturāls skaitlis n. Noskaidrot, vai doto skaitli var izteikt kā trīs naturālu skaitļu kvadrātu summu. 
Izdrukāt visus  šādus naturālu skaitļu trijniekus. 
Risinājumā izmantot funkciju, kas aprēķina trīs skaitļu kvadrātu summu.
'''

def three_n_squared_sum(i,j,k):
    sum = i**2 + j**2 + k**2
    return sum

def return_all_combinations(x):
    cnt = 0
    max = int(x**(1/2))
    for i in range(1,(max + 1)):
        for j in range(1,(max + 2 - i)):
            k = (x - (i**2 + j**2))**(1/2)
            if k%1 == 0:
                k = int(k)
                if three_n_squared_sum(i,j,k) == x:
                    print(f'numbers {i},{j},{k}  squared: {i**2},{j**2},{k**2} sum: {three_n_squared_sum(i,j,k)}')
                    cnt += 1
    if cnt == 0:                                            # Nav tādu kombināciju
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


""" TEST """

"""
    "test_input,expected",
    [
        (3, "Numbers 1, 1, 1, sum: 3"),
        (234, "Numbers 1,8,13  squared: 1,64,169 sum: 234"),
        (0, "That was not a valid number."),
        (k, "That was not a valid number."),
        (10, "This number has no valid combinations.""),
        (-10, "That was not a valid number."),
    ],
"""
