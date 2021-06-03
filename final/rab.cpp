#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int p = 31;
    vector<int> pw(n + 1, 0), h(n + 1, 0);
    pw[0] = 1;
    pw[1] = p;
    for(int i = 2; i <= n; ++i){
        pw[i] = 1ll * pw[i - 1] * p % MOD;
        // cout << pw[i] << " ";
    }
    for(int i = 1; i <= n; ++i){
        h[i] = (h[i - 1] + 1ll * (s[i - 1] - 'a' + 1) * pw[i - 1]) % MOD;
        // cout << h[i] << " ";
    }
    long long hash_value = 0;
    for(int i = 0; i < m; ++i){
        hash_value = (hash_value + 1ll * (t[i] - 'a' + 1) * pw[i]) % MOD;
    }
    for(int i = 0; i <= n - m; ++i){
        long long hs = (h[m + i] - h[i] + MOD) % MOD;
        long long ht = 1ll * hash_value * pw[i] % MOD;
        if(hs == ht){
            cout << i << " ";
        }
    }
}
