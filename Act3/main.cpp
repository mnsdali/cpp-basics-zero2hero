#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cout << "Donner une chaine: ";
    getline(cin, s);

    int idx=0;
    cout << "les mots de " << s <<" sont:" <<endl;
    while(true){
        int pos = s.substr(idx).find(" ");
        if (pos==-1){
            cout << s.substr(idx) <<endl;
            break;
        }
     //   cout << pos << endl;
        cout << s.substr(idx, pos) <<endl;
        idx=idx+pos+1;


    }


    return 0;
}
