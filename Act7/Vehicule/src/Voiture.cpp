#include "Voiture.h"
#include "Vehicule.h"

#include <string>
#include <iostream>

#define CURRYEAR 2023

using namespace std;

Voiture::Voiture(string _marque, int _dateAchat,
                double _prixA,
                double _cylinder,
                unsigned int _doorsNumber,
                double _horsePower,
            unsigned int _kilometrage)
    :Vehicule(_marque, _dateAchat, _prixA),
      doorsNumber(_doorsNumber), cylinder(_cylinder),
      horsePower(_horsePower), kilometrage(_kilometrage)
{

}

Voiture::~Voiture()
{

}

unsigned int Voiture::getDoorsNumber(){
    return this->doorsNumber;
}
unsigned int Voiture::getKilometrage(){
    return this->kilometrage;
}
double Voiture::getCylinder(){
    return this->cylinder;
}
double Voiture::getHorsePower(){
    return this->horsePower;
}

void Voiture::setDoorsNumber(unsigned int _doorsNumber){
    this->doorsNumber = _doorsNumber;
}
void Voiture::setKilometrage(unsigned int _kilometrage){
    this->kilometrage = _kilometrage;
}
void Voiture::setCylinder(double _cylinder){
    this->cylinder = _cylinder;
}
void Voiture::setHorsePower(double _horsePower){
    this->horsePower = _horsePower;
}

void Voiture::affiche(ostream& out){
    out << "---- Voiture ---- " << "\n";
    out << "Marque: " << this->getMarque() << ", ";
    out << "Date d'Achat: " << this->getDateAchat()<< ", " ;
    out << "Prix d'achat: " << this->getPrixAchat() << ", ";
    out << "Prix actuel: " << this->getPrixCourant() << "\n ";
    out <<  this->getDoorsNumber() << " portes, ";
    out << this->getCylinder() << " litres, ";
    out << this->getHorsePower() << " CV, ";
    out << this->getKilometrage() << " km. \n\n";
}

void Voiture::calculePrixCourant(){
    int yEcoule = CURRYEAR - this->dateAchat;
    double result = this->prixAchat * yEcoule* 0.02;


    double trancheKm = this->kilometrage * 0.0001;
    result += this->prixAchat * trancheKm *0.05;

    if (this->marque == "Renault" || this->marque == "Fiat")
    {
    //    cout << "renault or fiat";
        result += this->prixAchat *0.1;
    }
    else if (this->marque == "Ferrari" || this->marque == "Porsche")
    {
        result += this->prixAchat *0.2;

    }

    this->prixCourant = this->prixAchat - result;
    if (this->prixCourant < 0) this->prixCourant=0;

}

