/*
=== C11 =======================================

Izveidot programmu valodā C++, obligāti izmantojot norādītās vai kādas citas funkcijas.
Prasības tādas pašas kā iepriekšējā uzdevumā, precīzāk sk. Laboratorijas darbu noteikumos.

C11.
- Dotas divas (zema līmeņa) simbolu virknes a un b (sastāv no cipariem un neobligāti mīnusa zīmes),
- kas reprezentē divus veselus skaitļus.
- Izveidot funkciju, kas izveido trešo simbolu virkni c,
- kas reprezentē skaitli un ir simbolu virkņu a un b reprezentēto skaitļu summa.
- Saskaitīšana vai atņemšana jāveic pa vienam ciparam (kā to dara uz papīra).
- Funkcijai jāspēj apstrādāt simbolu virknes līdz garumam 100 ieskaitot.
*/

#include <iostream>
using namespace std;

char *remove_zero(char *x)
{
    while ((x[0] == 0 + '0') || (x[0] == 45) || (x[0] == 43))//; 43 (+); 45 (-)
    { // remove additional 0 in front
        int lenX = strlen(x);
        for (int i = 0; i < lenX; i++)
        {
            x[i] = x[i + 1];
        }
    }
    return x;
}

bool isnegative(char *c)
{
    if (c[0] == 45)
    {
        return true;
    }
    return false;
}

bool isValid(char *a)
{
    int lenA = strlen(a);
    for (int i = 0; i < (lenA); i++)
    {
        if ((i == 0) && ((a[i] < 48 || a[i] > 57) && ((a[i] != 10) && (a[i] != 45) && (a[i] != 43))))
        { // 48-57 (‘0’..‘9’);  10 (‘\n’ (jauna rindiņa)); 43 (+); 45 (-)
            return false;
        }
        else if ((i > 0) && (a[i] < 48 || a[i] > 57) && (a[i] != 10))
        { // 48-57 (‘0’..‘9’);  10 (‘\n’ (jauna rindiņa)); 43 (+); 45 (-)
            return false;
        }
    }
    return true;
}

char *a_b_summa(char *a, char *b)
{
    int signA = (isnegative(a) && !isnegative(b)) ? 1 : (-1);
    int signB = (!isnegative(a) && isnegative(b)) ? 1 : (-1);
    int signC = (isnegative(a) && isnegative(b)) ? 1 : (-1);

    a = remove_zero(a);
    b = remove_zero(b);

    int lenA = strlen(a);
    int lenB = strlen(b);
    int max = lenA > lenB ? lenA : lenB; // Get the max for allocation
    char *c = (char *)malloc(max + 112);
    memset(c, '0', max + 1); // set the cult to all zeros
    c[max + 1] = '\0';
    // int i = lenA - 1, j = lenB - 1, k = max;
    for (int i = lenA - 1, j = lenB - 1, k = max; i >= 0 || j >= 0; --i, --j, --k)
    {
        int sum = 0;
        if (i >= 0 && j >= 0)
            sum = a[i] - '0' + b[j] - '0' + (c[k] - '0'); // add using carry
        else if (j >= 0)
            sum = b[j] - '0' + c[k] - '0'; // add the carry with remaining
        else if (i >= 0)
            sum = a[i] - '0' + c[k] - '0';
        c[k] = sum % 10 + '0';
        c[k - 1] = sum / 10 + '0';
    }
    c = remove_zero(c);
    return c;
}

int main()
{
    char opt, yn;
    int n = 101;
    do
    {
        n = 101;
        char a[n]; // izveido masiivus
        char b[n];
        cout << "Ievadiet a simbolu virknes 'a' skaitli: ";
        cin.getline(a, n);
        cout << "Ievadiet a simbolu virknes 'b' skaitli: ";
        cin.getline(b, n);
        cout << endl;
        if (cin.fail() || !isValid(a) || !isValid(b)) // x nav int vai '+' or '-'
        {
            cin.clear();
            cout << "That was not a valid number!\n "; // x nav 0
        }
        else
        {
            cout << "a & b sum = " << a_b_summa(a, b) << endl;
        }
        cout << "Try again? (y/n): ";
        do // Try again loop sagaida tikai vēr†ības (y,n)
        {
            cin >> opt;
            yn = opt;
            cin.ignore(256, '\n');
        } while (yn != 'y' && yn != 'n');
    } while (opt == 'y');
    return 0;
}

/*
    "test_input,expected",
    [
        (23, 43, "63"),
        (0, 0, "0"),
        (-10, 12 "2"),
        (10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 1, "1 x googol and 1"),
        10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000123
    ],
*/
