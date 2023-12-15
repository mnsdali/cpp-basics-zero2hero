#include "Avion.h"
#include "Vehicule.h"

#include <string>
#include <iostream>

using namespace std;

Avion::Avion(string _marque, int _dateAchat, double _prixA,
                avionType _type, unsigned int _flightHoursNumber)
    : Vehicule(_marque, _dateAchat, _prixA),
      type(_type), flightHoursNumber(_flightHoursNumber)
{

}

Avion::~Avion()
{

}


avionType Avion::getType(){
    return this->type;
}

unsigned int Avion::getFlightHoursNumber(){
    return this->flightHoursNumber;
}

void Avion::setType(avionType _type){
    this->type = _type;
}

void Avion::setFlightHoursNumber(unsigned int _flightHoursNumber){
    this->flightHoursNumber = _flightHoursNumber;
}

void Avion::affiche(ostream& out){
    string type = this->getType() == 0 ? "Reaction" : "Helices";
    out << "---- Avion : " << type  << " ----" "\n";
    out << "Marque: " << this->getMarque() << ", ";
    out << "Date d'Achat: " << this->getDateAchat() << ", " ;
    out << "Prix d'achat: " << this->getPrixAchat() << ", ";
    out << "Prix actuel: " << this->getPrixCourant() << "\n";
    out <<  this->getFlightHoursNumber() << " heures de voles. \n\n";
}

void Avion::calculePrixCourant(){
    double trancheHrs;

    if (this->type == 0){
        trancheHrs = this->flightHoursNumber * 0.001;
        cout<< "Reaction" <<endl;
    }else if (this->type == 1){
        trancheHrs = this->flightHoursNumber *0.01;
        cout<< "helices" <<endl;
    }

    this->prixCourant = this->prixAchat - this->prixAchat*trancheHrs*10/100;

    if (this->prixCourant < 0)
       this->prixCourant = 0;
}


