#include <bits/stdc++.h>
#include <array>
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
int n, m;
int path[7][8];
void recout(int i, int j) {
    if(i == 0 && j == 0) {
        return;
    }
    if(path[i][j] == 0) {
        recout(i - 1, j);
        cout << "D";
    }
    if(path[i][j] == 1) {
        recout(i, j - 1);
        cout << "R";
    }
}
// int t; cin >> t;
//     while(t--) {
//         int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
//         unsigned long long x = abs(x2 - x1) + 1;
//         unsigned long long y = abs(y2 - y1) + 1;
//         unsigned ll answer = ((x * y) - (x + y)) + 2;
//         cout << answer << endl;
//     } 
int main(){
    speed; 
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            path[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }   
    int dp[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = a[i][j];
            if(i > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
                path[i][j] = 0;
            }
            if(j > 0) {
                int k = dp[i][j];
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
                if(dp[i][j] > k)
                    path[i][j] = 1;
            }
        
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    recout(n - 1, m -  1);
    return 0;
}