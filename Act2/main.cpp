#include <bits/stdc++.h>

using namespace std;
vector<int> tab;


int main()
{
    int n, x, i=0;
    cout << "donner la taille du tab: \n";
    cin >> n;
    while(i<n){
        cout << "entrer la valeur " << i <<": ";
        cin >> x;
        if (x>0){
            tab.push_back(x);
            i++;
        }else if(x==0){
            tab.clear();
            i=0;
        }else if (!tab.empty()){
            tab.pop_back();
            i--;

        }
    }
    for(auto &elem : tab){
        cout << elem <<" ";
    }
    return 0;
}
