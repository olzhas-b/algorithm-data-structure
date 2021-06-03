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
    ll n, x; cin >> n >> x;
    vector<ll> v(n);
    ll sum = 0;
    ll mx = -1;
    forn(n) {
        cin >> v[i];
        mx = max(mx, v[i]); 
        sum += v[i];
    }  
    ll res = 0;
    if(x > sum) {
        res = x - (x % sum);
        x %= sum;
    }
    if(x <= mx) {
        ll l = mx - x + 1;
        ll r = mx;
        ll m = r - l + 1;
        res += ((l + r) * m) / 2;
        x = 0;
    }   
    else {
        
    }

    cout << res << endl;



    return 0;
}