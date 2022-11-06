/*
=== B26 =======================================
B26. 
Dots naturāls skaitlis n. Noskaidrot, vai doto skaitli var izteikt kā trīs naturālu skaitļu kvadrātu summu. 
Izdrukāt visus  šādus naturālu skaitļu trijniekus. 
Risinājumā izmantot funkciju, kas aprēķina trīs skaitļu kvadrātu summu.
*/

#include <iostream>
using namespace std;

int sq(int x){              // skaitļa kvadarāts
    return x * x;
}

int three_n_sqd_sum(int i, int j, int k){   // 3 skaitļa kvadarātu summa
    return sq(i) + sq(j) + sq(k);
}

void find_combinations_wo_formula(int x){
    int cnt = 0;
    for (int i=1; sq(i)<=x; i++){
        for (int j=1; sq(j)<=x-sq(i); j++){
            for (int k=1; sq(k)<=x-(sq(i)+sq(j)); k++){
                //if (sq(k)==x-(sq(i)+sq(j))){ // alternativa rezultātu meklēšana
                if (three_n_sqd_sum(i, j, k) == x){ //Izmantojot formulu 
                    cout << "Numbers " << i << ", " << j << ", " << k << ", " << "sum: " << x << "\n";
                    cnt++;
                }
            }  
        }  
    }
    if (cnt == 0) cout << "This number has no valid combinations." << "\n";
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
        else if (x <= 0) cout << "That was not a valid number!\n ";
        else                // x ir int
            find_combinations_wo_formula(x);

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
        (234, "numbers 1,8,13  squared: 1,64,169 sum: 234"),
        (0, "That was not a valid number."),
        (k, "That was not a valid number."),
        (10, "This number has no valid combinations.""),
        (-10, "That was not a valid number."),
    ],
*/
