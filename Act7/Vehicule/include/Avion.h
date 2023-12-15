#ifndef AVION_H
#define AVION_H

#include "Vehicule.h"

enum avionType{
    REACTION,
    HELICES

};

class Avion : public Vehicule
{
    public:
        Avion(string _marque, int _dateAchat,
                double _prixA,
                avionType _type,
                unsigned int _flightHoursNumber);
        virtual ~Avion();
        void affiche(ostream& out);

        avionType getType();
        unsigned int getFlightHoursNumber();

        void setType(avionType _type);
        void setFlightHoursNumber(unsigned int _flightHoursNumber);
        void calculePrixCourant();

    protected:

    private:
        avionType type;
        unsigned int flightHoursNumber;
};

#endif // AVION_H
