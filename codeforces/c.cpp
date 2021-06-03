#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, n) for(int i = 0; i < n; i++)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    
signed main(){
    speed;
    int n; cin >> n;
    int ans = 0;
    map<string, bool> m;
    vi v(n);
    rep(i, n) cin >> v[i];
    rep(i, n - 2) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                vector<int> t = {v[i], v[j], v[k]};
                sort(all(t));
                if(t[0] + t[1] > t[2] && t[0] != t[1] && t[1] != t[2] && t[2] != t[0]) {
                    if(i != j && j != k && i != k) {
                        string s = "";
                        s += '#';
                        s += t[0] + '0';
                        s += '#';
                        s += t[1] + '0';
                        s += '#';
                        s += t[2] + '0';
                        s += '#';
                        s += i + '0';
                        s += '#';
                        s += j + '0';
                        s += '#';
                        s += k + '0';
                        m[s] = true;
                    }
                }
            }
        }
    }
    // iter(m) {
    //     cout << it->first << " " << it->second << endl;
    // }
    cout << m.size();
    return 0;
}