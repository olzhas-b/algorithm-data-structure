#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
int main(){
    speed;
    int n; cin >> n;
    vi v(n);
    forn(n) cin >> v[i];
    vector<string> data(n, "000000000000000000000");
    ll res = 0;
    map<int, map<int, bool>> m;
    sort(all(v));
    for(int i = 0; i < n; i++) {
        int k = v[i];
        int j = 0;
        while(k != 0) {
            if(k % 2) {
                data[i][j] = '1';
                m[j][i] = true;
            } 
            k /= 2;
            j++;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 21; j++) {
            if(data[i][j] == '0' && m[j].size() != 0) {
                auto l = m[j].begin()->first;
                if(l < i) {
                    for(int i1 = 0; i1 < 21; i1++) {
                        if(data[l][i1] == '1' && data[i][i1] == '0') {
                            m[j].erase(i1);
                            data[i][i1] = '1';
                            data[l][i1] = '0';
                        }
                    }
                }
            }
        }
    }
    forn(n) {
        ll k = 0;
        for(int j = 0; j < 21; j++) {
            if(data[i][j] == '1') {
                k += pow(2, j);
            }
        }
        res += (k * k);
    }
    cout << res;

    return 0;
}