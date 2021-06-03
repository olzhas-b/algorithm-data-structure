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
    
signed main(){
    speed;
    int n, m; cin >> m >> n;
    vector<vector<int>> v(n, vector<int> (m));
    vector<vector<int>> dp(n, vector<int> (m, INT_MAX));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }   
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) continue;
            if(i == 0) {
                dp[i][j] = dp[i][j - 1] + abs(v[i][j] - v[i][j - 1]);
            }
            else if(j == 0) {
                dp[i][j] = dp[i - 1][j] + abs(v[i][j] - v[i - 1][j]);
            } else {
                int k1 = dp[i - 1][j] + abs(v[i][j] - v[i - 1][j]);
                int k2 = dp[i][j - 1] + abs(v[i][j] - v[i][j - 1]);
                dp[i][j] = min(k1, k2);
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}