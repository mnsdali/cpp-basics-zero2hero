#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
    fstream file;
    string line;
    srand(time(0));
    file.open("Mots.txt", ios::in);

    vector<string> mots;

    while(getline(file,line)){
        mots.push_back(line);
    }

    int n = mots.size();

    int random = rand() %  n;
    while(true){
        cout << "Quel est ce mot ? " ;
        string mot = mots[random];

        random_shuffle(mot.begin(), mot.end());
        cout << mot <<endl;
        string trial;
        cin >> trial;
        if (trial == mots[random]){
            cout << "Bravo!" <<endl <<endl;
            break;
        }else{
            cout << "Ce n'est pas le mot!" <<endl<<endl;
        }
    }

    return 0;
}
