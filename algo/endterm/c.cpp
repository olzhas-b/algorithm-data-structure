#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v(200);
    for(int i= 0 ; i < n; i++) {
        char c; cin >> c;
        v[c]++;
    }
    map<int, int> m;
    m['a'] = true;
    m['e'] = true;
    m['i'] = true;
    m['o'] = true;
    m['u'] = true;
    for(int i = 0; i < 200; i++) {
        if(m[i] == true) {
            for(int j = 0; j < v[i]; j++) {
                cout << (char)i;
            }
        }
    }
    for(int i = 0; i < 200; i++) {
        if(m[i] == false) {
            for(int j = 0; j < v[i]; j++) {
                cout << (char)i;
            }
        }
    }  
    return 0;
}