#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define int long long
#define pii pair<int,int>
#define f(x) get<0>(x)
#define s(x) get<1>(x)
#define t(x) get<2>(x)
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
//cout.setf(ios::fixed);cout.precision(9);
    
const ll mod = (ll)1e9 + 7;
bool palindrome(string &s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}
signed main(){
    speed;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += (s[i] == '0');
        }
        bool palin = palindrome(s);
        if(n % 2 == 0 || (n % 2 == 1 and s[n / 2] == '1')) {
            if(palin) {
                cout << "BOB\n"; 
            } else {
                cout << "ALICE\n";
            }
        } else {
            if(palin) {
                if(cnt == 1) {
                    cout << "BOB\n";
                } else {
                    cout << "ALICE\n";
                }
            } else {
                cout << "ALICE\n";
            }
        }
    }
    return 0;
}