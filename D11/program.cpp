#include <iostream>
using namespace std;

#define MAX_SIZE 5
#include "program.h"

BurtuRinda::BurtuRinda() // Constructor
{
  rinda = new char[MAX_SIZE];
  front = 0;
  rear = 0;
}

bool BurtuRinda::VaiPilna() // metode ""VaiPilna"" - isFull, kas noskaidro, vai rinda ir pilna.
{
  return (rear - front == MAX_SIZE) ? true : false;
}

bool BurtuRinda::VaiTukša() // metode ""VaiTukša"" - isEmpty, kas noskaidro, vai rinda ir tukša.
{
  return (rear - front == 0) ? true : false;
}

int BurtuRinda::CikElementu() // metode ""CikElementu"" - count, kas atgriež elementu skaitu rindā,
{
  // cout << endl << "Elementu skaits: " <<  (rear - front);
  return (rear - front);
}

void BurtuRinda::Ielikt(char value) // metode ""Ielikt"" - enqueue, kas pievieno rindai elementu, ja tā nav pilna,
{

  if (VaiPilna()) {
    cout << endl << "BurtuRinda ir pilna!!";
  } else {
    rinda[rear] = value;
    // cout << endl << "Ielikt: " << value << " rindā";
    rear++;
  }
}

char BurtuRinda::Izņemt() // metode ""Izņemt"" - dequeue, kas izņem no rindas elementu un atgriež tā vērtību,
{
  char value;
  if (VaiTukša()) {
    cout << endl << "BurtuRinda ir Tukša!!";
    return ('');
  } else {
    value = rinda[front];
    for (int i = front; i <= rear - 1; i++) {
      rinda[i] = rinda[i + 1];
    }
    rear--;
    cout << endl << "Izņemts: " << value << " no rindas";
    return (value);
  }
}

/* Function to display elements of BurtuRinda */
void BurtuRinda::ParādiRindu() {
  if (VaiTukša()) {
    cout << endl << "BurtuRinda ir Tukša!!" << endl;
  } else {
    cout << endl << "BurtuRindas elementi : ";
    for (int i = front; i <= rear - 1; i++)
      cout << rinda[i] << " ";
  }
}

// Destruktors
BurtuRinda::~BurtuRinda() {
  // Izdzēst Rindu no atmiņas
  if (VaiTukša()) {
    cout << endl << "BurtuRinda ir Tukša!!";
  } else {
    cout << endl << "Elementu skaits: " << CikElementu();
  }
  cout << endl << "Rinda tiek likvidēta!" << endl;
  delete[] rinda;
}