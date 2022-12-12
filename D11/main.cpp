/* === D11 =======================================

Izveidot programmu valodā C++, izmantojot objektorientētās programmēšanas līdzekļus
un strukturējot programmu vismaz trīs failos.
Klases hederi obligāti novietot atsevišķā hedera failā (program.h).
Visas metodes realizēt ārpus hedera faila – speciālā C++ failā (program.cpp).
Funkcija main ievietojama vēl citā C++ failā (main.cpp).
Klases dati pēc noklusēšanas ir slēpti (private), bet metodes atklātas (public).
Šīs programmas ietvaros NAV obligāti jānodrošina tāda lietotāja saskarne,
kāda tika prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst “cieti” iekodēt).
Citas prasības sk. Laboratorijas darbu noteikumos.

D11. "Izveidot klasi ""Burtu rinda"" - Cqueue (queue, pa vienu pusi ieliek, pa otru izņem!),
kurā glabājas masīvs ar burtiem (char) garumā pieci un rindas elementu skaits.
Klasei izveidot šādas metodes:
(1) konstruktors,
(2) destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī rinda nav tukša),
(3) metode ""Ielikt"" - enqueue, kas pievieno rindai elementu, ja tā nav pilna,
(4) metode ""Izņemt"" - dequeue, kas izņem no rindas elementu un atgriež tā vērtību,
(5) metode ""CikElementu"" - count, kas atgriež elementu skaitu rindā,
(6) metode ""VaiTukša"" - VaiTukša, kas noskaidro, vai rinda ir tukša.
 Pirms uzdevuma veikšanas precīzi noskaidrot, ko nozīmē jēdziens rinda (queue)." */

// Emīls Lībeks
// student id: el22074

#include <iostream>
using namespace std;

#include "program.h"


int main()
{
    //Deklarēt jaunas BurtuRindas
    BurtuRinda lielie_burti;
    BurtuRinda mazie_burti;

    //Mēģināt izņemt elementu no tukšas rindas,
    lielie_burti.Izņemt(); // Izņemt

    //Mēģināt Pilikt elementus "A","B","C","D","E" lielie_butri rindai
    for (int i = 0; i <= 4; i++){
        cout << endl << "LielieBurti elementu skaits:" << lielie_burti.CikElementu() << endl;
        lielie_burti.Ielikt('A' + i);
        lielie_burti.ParādiRindu();
    }
    //Mēģināt Pilikt elementus "a","b","c","d","e" mazie_butri rindai
    for (int i = 0; i <= 2; i++){
        cout << endl << "LielieBurti elementu skaits:" << lielie_burti.CikElementu() << endl;
        mazie_burti.Ielikt('a' + i);
        mazie_burti.ParādiRindu();
    }
    //Mēģināt Pilikt elementu "F" lielie_butri rindai, lai gan tā ir pilna
    lielie_burti.Ielikt('F');
    lielie_burti.ParādiRindu();

    // Izņemt "A" no lielie_burti
    lielie_burti.Izņemt();

    // queue after dequeue
    lielie_burti.Ielikt('G');
    lielie_burti.ParādiRindu();
    lielie_burti.Ielikt('H');
    lielie_burti.ParādiRindu();

    // Izņemt 5 elementus no lielie burti
    for (int i = 0; i <= 5; i++){
        cout << endl << "LielieBurti elementu skaits:" << lielie_burti.CikElementu() << endl;
        lielie_burti.Izņemt();
        lielie_burti.ParādiRindu();
    }
    lielie_burti.ParādiRindu();

    lielie_burti.CikElementu();
    cout << lielie_burti.VaiPilna() << endl;
    cout << lielie_burti.VaiTukša() << endl;
    cout << lielie_burti.Izņemt() << endl;



    mazie_burti.ParādiRindu();


    return 0;
}