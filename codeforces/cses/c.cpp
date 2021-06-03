#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
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
const int MAX = 1e8;
int main(){
    speed;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> hor(n, vector<int> (m - 1));
    vector<vector<int>> ver(n - 1, vector<int> (m));
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>> (m + 1, {MAX, MAX}));
    auto check = [&](int i1, int j1, bool cond) {
        if(cond) {
            if(j1 < 0 || j1 >= m - 1) return false;
            return true;
        } else {
            if(i1 < 0 || i1 >= n - 1) return false;
            return true;
        }
        return true;
    };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            cin >> hor[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ver[i][j];
        }
    }
    if(k % 2 == 0) {
        k /= 2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) { 
                dp[i][j] = {0, 0};
                int w = k;
                while(w--) {
                    for(int x = max(0, i - k); x < min(n, k + i); x++) {
                        for(int y = max(0, j - k); y < min(m, k + j); y++) {
                            int mx1 = MAX, mx2 = MAX, mx3 = MAX, mx4 = MAX;
                            if(check(x, y, 1)) {
                                mx1 = dp[x][y + 1].first + hor[x][y];
                            }
                            if(check(x, y - 1, 1)) {
                                mx2 = dp[x][y - 1].first + hor[x][y - 1];
                            }
                            if(check(x, y, 0)) {
                                mx3 = dp[x + 1][y].first + ver[x][y];
                            }
                            if(check(x - 1, y, 0)) {
                                mx4 = dp[x - 1][y].first + ver[x - 1][y];
                            }
                            dp[x][y].second = min(mx1, min(mx2, min(mx3, mx4)));
                        }
                    }
                    for(int x = max(0, i - k); x < min(n, k + i); x++) {
                        for(int y = max(0, j - k); y < min(m, k + j); y++) {
                            dp[x][y].first = dp[x][y].second;
                        }
                    }
                }
                int mx = MAX;
                for(int x = max(0, i - k); x < min(n, k + i); x++) {
                    for(int y = max(0, j - k); y < min(m, k + j); y++) {
                        mx = min(mx, dp[x][y].first);
                        dp[x][y] = {MAX, MAX};
                    }
                }
                cout << mx * 2 << ' ';
            }
           cout << '\n';
        }
    } else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << -1 << " ";
            }
            cout << '\n';
        }
    } 
    return 0;
} 