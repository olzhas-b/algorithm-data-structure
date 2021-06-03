#include <bits/stdc++.h>
using namespace std;

int main(){
   
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int n1 = n;
    if(n1 % 2 == 1) n1--;
    for(int i = n1 - 1; i >= 1; i--) {
        for(int j = n1 - 1; j >= 1; j -= 2) {
            if(v[j] > v[j - 2]) {
                swap(v[j], v[j - 2]);
            }
        }
    }
    int n2 = n;
    if(n2 % 2 == 0) n2--;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 2; j+=2) {
            if(v[j] > v[j + 2]) {
                swap(v[j], v[j + 2]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}