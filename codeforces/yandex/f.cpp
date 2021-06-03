#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define int long long

#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
signed main(){
    speed;
    int n, m; cin >> m >> n;
    vector<vector<int>> v(n, vector<int> (m));
    vector<vector<int>> d(n, vector<int> (m, INT_MAX));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }   

    d[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            
            if(i == 0 and j == 0) continue;
            
            if(i == 0) {
                d[i][j] = d[i][j - 1] + abs(v[i][j] - v[i][j - 1]);
            }
            else if(j == 0) {
                d[i][j] = d[i - 1][j] + abs(v[i][j] - v[i - 1][j]);
            } else {
                int k1 = d[i - 1][j] + abs(v[i][j] - v[i - 1][j]);
                int k2 = d[i][j - 1] + abs(v[i][j] - v[i][j - 1]);
                d[i][j] = min(k1, k2);
            }
        }
    }
    cout << d[n - 1][m - 1] << endl;
    return 0;
}