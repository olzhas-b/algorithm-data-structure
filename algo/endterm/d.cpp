#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v(n);
    vector<long long> mx(3);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < min(3, n); i++) {
        mx[i] = v[i];
    }
    for (int j = 0; j < 2; j++)      
        for (int k = 0; k < 2; k++)  
            if (mx[k] > mx[k+1])  
                swap(mx[k], mx[k+1]); 
    for(int i = 0; i < n; i++) {
        if(i < 2) {
            cout << -1 << endl;
        } else {
            if(i == 2) {
                cout << mx[0] * mx[1] * mx[2] << endl;
            } else {
                if(v[i] >= mx[0]) {
                    mx[0] = v[i];
                    for (int j = 0; j < 2; j++)      
                        for (int k = 0; k < 2; k++)  
                            if (mx[k] > mx[k+1])  
                                swap(mx[k], mx[k+1]);  
                }
                cout << mx[0] * mx[1] * mx[2] << endl;
            }
        }
    }
    return 0;
}