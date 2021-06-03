#include <bits/stdc++.h>
#include <fstream>
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
    ifstream cin("input.txt");
    int n, pos; cin >> n >> pos;
    vi v(n);
    forn(n) {
        cin >> v[i];
    }
    sort(all(v));
    unsigned ll res = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(pos >= v[i]) {
            pos -= v[i];
            cnt++;
            res += res + v[i];
        }
        else {
            break;
        }
    }
    cout << cnt << " " << res;

    return 0;
}