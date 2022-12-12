// Galvene
#include <iostream>
using namespace std;


class BurtuRinda
{
private: // Klases dati
    char* rinda;
    int front, rear;

public: // Metodes
    BurtuRinda();
    bool VaiPilna();
    bool VaiTukša();
    int CikElementu();
    void Ielikt(char value);
    char Izņemt();
    void ParādiRindu();
    ~BurtuRinda();
};
