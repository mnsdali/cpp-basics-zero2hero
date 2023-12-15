#include <iostream>
#include <vector>
#include "Voiture.h"
#include "Avion.h"
#include <string>

using namespace std;

int main()
{

    vector<Voiture> garage;
    vector<Avion> hangar;

    garage.push_back(Voiture((string)"Peugeot", 1998, 147326, 2.5, 5, 180.0, 12000));
    garage.push_back(Voiture((string)"Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
    garage.push_back(Voiture((string)"Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000));

    hangar.push_back(Avion((string)"Cessna", 1972, 1230673.90, HELICES, 250));
    hangar.push_back(Avion((string)"Nain Connu", 1992, 4321098.00, REACTION, 1300));

    for (auto voiture : garage) {
        voiture.calculePrixCourant();
        voiture.affiche(cout);
    }
    for (auto avion : hangar) {
        avion.calculePrixCourant();
        avion.affiche(cout);
    }

    return 0;
}
//Mohamed Ali Mnassar , Amine Abid , Mohamed Ben Rhouma : GI3 S4
