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
bool comp1(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    if(f(a) > f(b)) return true;
    if(f(a) == f(b)) return s(a) < s(b);
    return false;
}
bool comp2(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    if(s(a) < s(b)) return true;
    if(s(a) == s(b)) return f(a) > f(b);
    return false;
}
 
signed main(){
    speed;
    int n; cin >> n;
    vector<tuple<int, int, int>> v(n);
    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        v[i] = {y, x, i};
    }   
    sort(all(v), comp1);
    vector<int> ans1(n), ans2(n);
    tuple<int, int, int> prev = {-1, -1, -1};
    // rep(i, 0, n) {
    //     tuple<int, int, int> curr = v[i];
    //     if(t(prev) == -1) {
    //         prev = v[i];
    //         continue;
    //     }
    //     if(s(curr) >= s(prev)) {
    //         ans1[t(prev)] = 1;
    //         ans2[t(curr)] = 1;
    //     }
    //     prev = v[i];
    // }
    sort(all(v), comp2);
    prev = {-1, -1, -1};
    rep(i, 0, n) {
        tuple<int, int, int> curr = v[i];
        if(t(prev) == -1) {
            prev = v[i];
            continue;
        }
        if(f(prev) >= f(curr)) {
            ans2[t(curr)] = 1;
            ans1[t(prev)] = 1;
        } else {
            prev = curr;
        }
    }
 
    rep(i, 0, n) {
        cout << ans1[i] << " ";
    }
    cout << endl;
    rep(i, 0, n) {
        cout << ans2[i] << " ";
    }
    return 0;
}