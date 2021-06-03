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
        int n, k; cin >> n >> k;
        char a[n];
        vi m(26);
        forn(n) {
            cin >> a[i];
            m[a[i] - 'a']++;
        }
        int mx1 = 0, mx2 = 0, mx3 = 0;
        for(int i = n; i >= 0; i--) {
            if(k % i == 0) {
                mx1 = i;
                break;
            }
        }
        for(int i = 0; i < 25; i++) {
            mx2 = max(mx2, m[i]);
        }
        if(k < 25) {
            sort(all(m));
            mx3 = m[26 - k] * k;
        }
        cout << max(mx1, max(mx2, mx3)) << endl;
     }   
    return 0;
}