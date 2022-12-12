/*
=== A3 =======================================
A3. Dots naturāls skaitlis n. 
Noskaidrot šī skaitļa pirmā un pēdējā cipara summu. 
Skaitļa dalīšana ciparos jāveic skaitliski.
*/

#include <iostream>
using namespace std;

int get_first_n(int n){     // Naturāla skaitļa pirmais cipars
    while (n >= 10){
        n = n / 10;         //int dalīšana dala līdz veselam skaitlim
    }
    return n;
}

int get_last_n(int n){      // Naturāļa skaitļa pēdējais cipars
    return n % 10;          // Dalījuma 10 atlikums (0-9)
}

int first_last_sum(int n){  // skaitļa pirmā un pēdējā cipara summu
    if (n < 0) n = n * -1;
    return get_first_n(n) + get_last_n(n);
}

int main()
{
    char opt, yn;
    do
    {
        int x;
        cout << "Please enter a number: ";
        cin >> x;
        if (cin.fail())     // x nav int
        {
            cin.clear();
            cout << "That was not a valid number!\n ";
        }
        else                // x ir int
            cout << first_last_sum(x) << endl;

        cout << "Try again? (y/n): "; 
        do                  // Try again loop sagaida tikai vēr†ības (y,n)
        {
            cin >> opt; yn = opt;
        } while (yn != 'y' && yn != 'n');
        //opt='n';

    } while (opt == 'y');
    return 0;
}
/*
    "test_input,expected",
    [
        (3456, 9),
        (0, 0),
        (8, 16),
        (-3456, 9),
        (987654328, 17),
    ],
*/
