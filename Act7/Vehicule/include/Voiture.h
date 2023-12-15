#ifndef VOITURE_H
#define VOITURE_H

#include "Vehicule.h"

class Voiture : public Vehicule
{
    public:
        Voiture(string _marque, int _dateAchat,
                double _prixA,
                double _cylinder,
                unsigned int _doorsNumber,
                double _horsePower,
            unsigned int _kilometrage
                );
        virtual ~Voiture();
        void affiche(ostream& out);

        unsigned int getDoorsNumber();
        unsigned int getKilometrage();
        double getCylinder();
        double getHorsePower();

        void setDoorsNumber(unsigned int _doorsNumber);
        void setKilometrage(unsigned int _kilometrage);
        void setCylinder(double _cylinder);
        void setHorsePower(double _horsePower);
        void calculePrixCourant();

    protected:

    private:
        unsigned int doorsNumber;
        unsigned int kilometrage;
        double cylinder;
        double horsePower;

};

#endif // VOITURE_H
