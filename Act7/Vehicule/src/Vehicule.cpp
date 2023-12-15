#include "Vehicule.h"

#include <string>

using namespace std;


#define CURRYEAR 2023

Vehicule::Vehicule(string _marque, int _dateAchat, double _prixA)
 : prixAchat(_prixA), marque(_marque), dateAchat(_dateAchat), prixCourant(0)
{

}

Vehicule::~Vehicule()
{

}

string Vehicule::getMarque(){
    return this->marque;
}
int Vehicule::getDateAchat(){
    return this->dateAchat;
}
double Vehicule::getPrixAchat(){
    return this->prixAchat;
}
double Vehicule::getPrixCourant(){
    return this->prixCourant;
}

void Vehicule::setMarque(string _marque){
    this->marque = _marque;
}
void Vehicule::setDateAchat(int _dateAchat){
    this->dateAchat = _dateAchat;
}
void Vehicule::setPrixAchat(double _prixAchat){
    this->prixAchat = _prixAchat;
}

void Vehicule::calculePrixCourant(){
    unsigned short yEcoule = 2023 - this->dateAchat;
    this->prixCourant = this->prixAchat - this->prixAchat*yEcoule/100;
}


void Vehicule::affiche(ostream& out) {
    out << "C'est une véhicule: " << "\n";
    out << "Marque: " << this->getMarque() << "\n";
    out << "Date d'Achat: " << this->getDateAchat() << "\n" ;
    out << "Prix d'achat: " << this->getPrixAchat() << "\n";
    out << "Prix courant: " << this->getPrixCourant() << "\n";
}
