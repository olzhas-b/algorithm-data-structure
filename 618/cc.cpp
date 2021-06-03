#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }   
    int cnt = 0;
    while(true){
        vector<int> a;
        bool yes = true;
        int ind = 0;
        for(int i = 0; i < v.size() - 1; i++){
            //cout << i;
            if(v[i] <= v[i + 1]){

            }
            else{
                yes = false;
                ind = i;
                cnt++;
                break;
            }
        }
        if(yes == false){
            vector<int> a;
            if(ind < v.size() / 2){
                for(int i = 0; i < v.size() / 2; i++){
                    a.push_back(v[i]);
                }
            }
            else{
                for(int i = v.size() / 2; i < v.size(); i++){
                    a.push_back(v[i]);
                }
            }
            v = a;
        }
        else{
            break;
        }
    }
    cout << v.size();
    return 0;
}