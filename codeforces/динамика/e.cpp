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
        vi dp(s.size());
        vi pref(s.size());
        vi pref2(s.size());
        int cnt1 = 0;
        int cnt0 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') cnt1++;
            else cnt0++;
            pref2[i] = cnt0;
            pref[i] = cnt1;
        }
        int mn = INT_MAX;
        int n = s.size();
        for(int i = 0; i < s.size(); i++) {
                mn = min(mn, pref[i] + cnt0 - pref2[i]);
        }
        for(int i = 0; i < s.size(); i++) {
            mn = min(mn, pref2[i] + cnt1 - pref[i]);
        }
        cout << mn  << endl;
    }   
    return 0;
}