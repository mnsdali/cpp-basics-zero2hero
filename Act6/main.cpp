#include <iostream>

using namespace std;

class Duree{
private:
 int heure, minute, seconde;
public:

    Duree(int h=0, int m=0, int s=0){
        seconde = s%60;
        minute = (s/60 + m%60)%60;
       heure = h + (s/60 + m%60)/60 + m/60;
    }

   Duree operator+(Duree const& obj) {
        Duree res;
        res.seconde = (seconde + obj.seconde)%60;
        res.minute = (minute + obj.minute + (seconde + obj.seconde)/60)%60;
        res.heure = heure + obj.heure + (minute + obj.minute + (seconde + obj.seconde)/60)/60;


        return res;
    }

    Duree operator+(int secondes) {
        Duree res;
        res.seconde = (seconde + secondes)%60;
        res.minute = (minute +  (seconde + secondes)/60)%60;
        res.heure = heure + (minute + (seconde + secondes)/60)/60;


        return res;
    }
    void operator++() {
        seconde = (seconde + 1)%60;
        minute =( minute + (seconde+1)/60)%60;
        heure = heure + (minute + (seconde+1)/60)/60;

    }

    bool operator==(Duree const& obj1){
        return heure == obj1.heure && minute == obj1.minute && seconde == obj1.seconde;
    }

     bool operator!=(Duree const& obj1){
        return heure != obj1.heure && minute != obj1.minute && seconde != obj1.seconde;
    }

    friend ostream& operator<<(ostream& output, Duree d){
        output <<d.heure <<":" <<  d.minute << ":" << d.seconde;
        return output;
    }

     friend istream& operator>>(istream& input, Duree d){
         int x,y,z;
        input >>x >>  y >> z;
        d.heure = x;
        d.minute = y;
        d.seconde = z;

        return input;
    }


};

int main()
{
    Duree h1 = Duree(0, 70, 70);
    Duree h2 = Duree(1, 11, 10);
    bool t = h1 == h2;
    cout << t;
    Duree h3 = h1+h2;


    Duree h4;
    cin >> h4;
    cout << h4;
    return 0;
}
