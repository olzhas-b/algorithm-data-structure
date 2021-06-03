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
    ll k; cin >> k;
    string s = "codeforces";
    vector<int> v(10, 1);
    ll res = 1;
    int j = 0;
    while(res < k) {
        res = 1;
        v[j] += 1;
        for(int i = 0; i < 10; i++) {
            res *= v[i];
            if(res >= k) break;
        }
        j++;
        if(j == 10) j = 0;
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < v[i]; j++) {
            cout << s[i];
        }
    }
    return 0;
}