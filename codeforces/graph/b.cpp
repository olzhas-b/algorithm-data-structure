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
    
const ll mod = (ll)1e9 + 7;
int p[N + 1];   
void retto() {
    for(int i = 2; i <= N; i++) {
        if(p[i]) continue;
        p[i] = i;
        for(int j = i + i; j <= N; j += i) {
            if(p[j]) continue;
            p[j] = i;
        } 
    }
    p[1] = 1;
}
signed main(){
    speed;
    retto();
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        while(p[x] != x) {
            cout << p[x] << " ";
            x /= p[x];
        }
        if(x != 1) cout << x;
        cout << endl;
    }
    return 0;
}