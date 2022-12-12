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

int num(char x) { // num(a[i])
  return (x - '0');
}

char *remove_zero(char *x) {
  while (((x[0] == 0 + '0') || (x[0] == 45) || (x[0] == 43)) && (x[1] != '\0')){ //; 43 (+); 45 (-) remove additional 0,+,- in front
    // cout << "x[0]" << x[0] << "x[1]" << x[1] << endl;
    int lenX = strlen(x);
    for (int i = 0; i <= lenX; i++) {
      // cout << x[i] << endl;
      x[i] = x[i + 1];
    }
  }
  return x;
}

bool isnegative(char *c) { // Find if char array has minus sign in front
  if (c[0] == 45) {
    return true;
  }
  return false;
}

bool isValid(char *a) { // Validate input
  int lenA = strlen(a);
  for (int i = 0; i < (lenA); i++) {
    if ((i == 0) &&
        ((a[i] < 48 || a[i] > 57) && ((a[i] != 10) && (a[i] != 45) &&
                                      (a[i] != 43)))) { // 48-57 (‘0’..‘9’);  10 (‘\n’ (jauna rindiņa)); 43 (+); 45 (-)
      return false;
    } else if ((i > 0) && (a[i] < 48 || a[i] > 57) &&
               (a[i] != 10)) { // 48-57 (‘0’..‘9’);  10 (‘\n’ (jauna rindiņa)); 43 (+); 45 (-)
      return false;
    }
  }
  return true;
}

bool isLargerOrEqual(char *a, char *b) { // True if a >= b, false if a < b
  int lenA = strlen(a);
  int lenB = strlen(b);
  if (lenA > lenB)
    return true;
  else if (lenA < lenB)
    return false;
  else{ //if (lenA == lenB) {
    for (int i = 0; i < (lenA); i++) {
      if (num(a[i]) > num(b[i]))
        return true;
      else if (num(a[i]) < num(b[i]))
        return false;
    }
    return true;
  }
}

char *addNegative(char *c) { // add minus sign in front of array
  int lenC = strlen(c);
  if ((lenC <= 1) && (c[0] == (0 + '0'))){
    return c;
  }
  //char *d = (char *)malloc(lenC + 1);
  char *d = new char[lenC + 1];
  memset(d, '0', lenC + 1); // set the cult to all zeros
  d[lenC + 1] = '\0';
  d[0] = 45;
  for (int i = 0; i < (lenC); i++) {
    d[i + 1] = c[i];
  }
  return d;
}

char *cSum(char *a, char *b) { // char array value sum one by one
  int lenA = strlen(a);
  int lenB = strlen(b);
  int max = lenA > lenB ? lenA : lenB;
  //char *c = (char *)malloc(max + 2);
  char *c = new char[(max+2)];
  memset(c, '0', max + 1); // set the cult to all zeros
  c[max + 1] = '\0';
  for (int i = lenA - 1, j = lenB - 1, k = max; i >= 0 || j >= 0; --i, --j, --k) {
    int sum = 0;
    if (i >= 0 && j >= 0) {
      sum = num(a[i]) + num(b[j]) + num(c[k]); // add using carry
    } else if (j >= 0) {
      sum = num(b[j]) + num(c[k]); // add the carry with remaining
    } else if (i >= 0) {
      sum = num(a[i]) + num(c[k]);
    }
    c[k] = sum % 10 + '0';
    c[k - 1] = sum / 10 + '0';
  }
  c = remove_zero(c);
  return c;
}

char *cSubstract(char *a, char *b) { // char array value substraction one by one
  int lenA = strlen(a);
  int lenB = strlen(b);
  int max = lenA > lenB ? lenA : lenB;
  //char *c = (char *)malloc(max + 2);
  char *c = new char[(max+2)];
  memset(c, '0', max + 1); // set the cult to all zeros
  c[max + 1] = '\0';
  for (int i = lenA - 1, j = lenB - 1, k = max; i >= 0 || j >= 0; --i, --j, --k) {
    int sum = 0;
    if (i >= 0 && j >= 0) {
      sum = num(a[i]) - num(b[j]) - num(c[k]); // add using carry
      //cout << " a: " << a[i]<< " b: "<< b[j] << " c: "<< c[k] << endl;
      //cout << " strlen a: " << strlen(a)<< " b: "<< strlen(b) << " c: "<< strlen(c) << endl;
    } else if (j >= 0) {
      sum = num(b[j]) - num(c[k]); // add the carry with remaining
    } else if (i >= 0) {
      sum = num(a[i]) - num(c[k]);
    }
    //cout << "sum:" << sum << endl;
    if (sum < 0) {
      c[k] = (10 + sum) + '0';
      c[k - 1] = 1 + '0';
    } else {
      c[k] = sum % 10 + '0';
      c[k - 1] = sum / 10 + '0';
    }
    //cout << "k: " << c[k]<< "k-1: "<< c[k-1] << endl;
  }
  c = remove_zero(c);
  return c;
}

char *calculate(char *a, char *b) { // function that organizes the flow of sum & substraction
  bool signA = !isnegative(a);
  bool signB = !isnegative(b);

  a = remove_zero(a);
  b = remove_zero(b);

  if (signA && signB)
    return cSum(a, b);
  else if (signA && !signB) {
    if (isLargerOrEqual(a, b)) {
      return cSubstract(a, b);
    } else {
      return addNegative(cSubstract(b, a));
    }
  } else if (!signA && signB) {
    if (isLargerOrEqual(a, b)) {
      return addNegative(cSubstract(a, b));
    } else {
      return cSubstract(b, a);
    }
  } else 
    return addNegative(cSum(a, b));// { else if (!signA && !signB)
}

int main() {
  char opt, yn;
  int n = 101;
  do {
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
    } else {
      cout << "a & b sum = " << calculate(a, b) << endl;
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
        (23, 43, "66"),
        (0, 0, "0"),
        (1234, -46993, "-45727"),
        (-10, 12 "2"),
        (1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 1, "1 x
   googol and 1"),
        10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000123
    ],
*/
