#include <bits/stdc++.h>

using namespace std;

int sommeMaxConsec(vector<int> &vect){
    int _max=-1, x=0;
    for(int&elem : vect){
        if (elem==0){
            x=0;
        }else{
            x+=elem;
        }
        _max = max(_max, x);
    }
    return _max;
}

vector<int> lignesMax(vector<vector<int>> &mat){
    vector<int> v;
    int _max = sommeMaxConsec(mat[0]);
    if (_max != -1) v.push_back(0); // insert if row is not empty!
    for(int i=1; i<mat.size(); i++){
        int m = sommeMaxConsec(mat[i]);
        if (_max < m){
            v.clear();
            v.push_back(i);
            _max=m;
        }else if( _max == m && _max != -1){
            v.push_back(i);
        }
    }
    return v;
}

vector<vector<int>> tranchesMax(vector<vector<int>> &mat){
    vector<int> l_max= lignesMax(mat);
    vector<vector<int>> result;
    for (int &index: l_max){
        result.push_back(mat[index]);
    }
    return result;
}

int main(){
    vector<vector<int>> mat;
    vector<int> v;
    int n;
    cout << "donner une matrice: " << endl;
    cout << "taper -1 pour allez à la ligne suivante..." <<endl;
    cout << "taper -3 pour soumettre la résultat..." << endl;
    while(true){
        cin >> n;
        if(n==-3) {
                if (!v.empty()){
                    mat.push_back(v);
                }
                break;

        }
        if (n == -1){
            mat.push_back(v);
            v.clear();
            /*cout << "taper -1 pour allez à la ligne suivante..." <<endl;
            cout << "taper -3 pour soumettre la résultat..." << endl;*/
        }else{
            v.push_back(n);
        }
    }

    vector<vector<int>> target =  tranchesMax(mat);
    cout << "la tranche resultat est: "<< endl;

    if (target.empty()) cout << "vide" << endl;
    else{
        for (auto &vect : target){

            for (auto &elem : vect){
                cout << " " << elem ;
            }
            cout<<endl;

        }
    }


    return 0;
}



/*
 ### essai meme taille;
int main()
{
    int n,m;
    cout << "donner la taille de la matrice " << endl;
    cout << "lignes: ";
    cin >> n;
    cout << "colonnes: ";
    cin >> m;


    vector<vector<int>> mat(n);
    for (int i = 0 ; i < n ; i++) {
        mat[i].resize(m);
    }

    map<int, int> mp;

    cout << "donner la matrice" << endl;

    int _max=0;
    for(int i = 0; i<n; i++){
        int x=0;
        for (int j=0; j<m; j++){
            cin >> mat[i][j];
            if (mat[i][j]==0){
                x=0;
            }else{
                x+=mat[i][j];
            }
            mp[i] = max(mp[i], x);
        }
        _max = max(_max, mp[i]);
        cout << _max << " " << i << ": " << mp[i] << endl;
    }

    vector<vector<int>> target;

    if (_max==0){
        target = mat;
    } else{
        for (int i=0; i<n; i++){
            if (mp[i]==_max){
                target.push_back(mat[i]);
            }
        }
    }

    cout << "resultat: " << endl;
    for (auto &vect : target){
        cout << "(";
        for (auto &elem : vect){
            cout << " " << elem ;
        }
        cout << " )" << endl;
    }

    return 0;
}*/
