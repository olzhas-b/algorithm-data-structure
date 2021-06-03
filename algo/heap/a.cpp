#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long 
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
signed main(){
    speed;
    string s; cin >> s;
    map<int, int> m;
    rep(i, 0, s.size()) {
        m[s[i] - '0']++;
    }
    bool yes = false;
    if(s.size() == 1) {
        if(s[0] == '8') {
            yes = true;
        }
    }
    vector<int> v1, v2, v3;
    iter(m) {
        if(it->second > 0) {
           v1.push_back(it->first);  
           it->second--;
        } 
        if(it->second > 0) {
           v2.push_back(it->first);  
           it->second--;
        } 
        if(it->second > 0) {
           v3.push_back(it->first);  
           it->second--;
        } 
    }
    rep(i, 0, v1.size()) {
        rep(j, 0, v2.size()) {
            rep(k, 0, v3.size()) {
                if(v1[i] != 0) {
                    int sum = (v1[i] * 100) + (v2[j] * 10) + v3[k];
                    if(sum % 8 == 0) yes = true;
                }
            }
        }
    }
    
    cout << (yes ? "Yes" : "No");
    return 0;
}