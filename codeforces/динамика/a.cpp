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
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int res = 0;
        for(int i = 0; i < 100000; i++) {
            int cur = i;
            bool ok = true;
            for(int j = 0; j < s.size(); j++ ) {
                res++;
                cout << i << " " << j << " "  << cur << " " << res << endl;
                if(s[j] == '+') {
                    cur++;
                }
                else cur--;
                if(cur < 0) {
                    ok = false;
                    break;
                }
            }
            if(ok) break;
        }
        cout << res << endl;
    }   
    return 0;
}