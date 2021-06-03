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
struct dsu {
    vector<int> p;
    vector<vector<int>> l;
    int sz = 0;
    dsu(int n) {
        sz = n + 1;
        p.resize(sz, 0);
        l.resize(sz, {});
        for(int i = 1; i < sz; i++) {
            p[i] = i;
            l[i] = {i};
        }
    }
    int get(int a) {
        return p[a];
    }
    void union_dsu(int a, int b) {
        a = p[a];
        b = p[b];
        if(l[a].size() > l[b].size()) {
            int temp = a;
            a = b;
            b = temp;
        }
        for(auto e : l[a]) {
            l[b].push_back(e);
            p[e] = b;
        }

    }

};
signed main(){
    speed;
    int n, m; cin >> n >> m;
    dsu d(n);
    while(m--) {
        string s; cin >> s;
        int a, b; cin >> a >> b;
        if(s[0] == 'g') cout << (d.get(a) == d.get(b) ? "YES" : "NO") << endl;
        else d.union_dsu(a, b);
    }
    return 0;
}