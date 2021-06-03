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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m, 0));
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];
    dp[0][0] = v[0][0];
    for(int i = 1; i < m; i++) {
        dp[0][i] += v[0][i] + dp[0][i - 1];
    }
    for(int i = 1; i < n; i++) {
        dp[i][0] =  v[i][0] + dp[i - 1][0];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i][j]; 
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int q; cin >> q;
    while(q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int answer = dp[x2][y2] - dp[x2][y1] - dp[x1][y2] + dp[x1][y1];
        cout << answer << endl;
        cout << dp[x2][y2] << endl;
    }
       
    return 0;
}