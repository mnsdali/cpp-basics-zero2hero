#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <iostream>

using namespace std;


class Vehicule
{
    public:
        Vehicule(string _marque, int _dateAchat,
                double _prixA);
        virtual ~Vehicule();
        void affiche(ostream& out);

        string getMarque();
        int getDateAchat();
        double getPrixAchat();
        double getPrixCourant();

        void setMarque(string _marque);
        void setDateAchat(int _dateAchat);
        void setPrixAchat(double _prixAchat);
        void calculePrixCourant();

    protected:
        string marque;
        int dateAchat;
        double prixAchat;
        double prixCourant;
    private:



};

#endif // VEHICULE_H
