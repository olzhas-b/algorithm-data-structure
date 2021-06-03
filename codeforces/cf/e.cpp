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
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        char a[n][m];
        vector<pii> w(n + m - 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int jj = 0;
        int ii = 0;
        for(int i = 0; i < n + m - 1; i++) {
            int cnt1 = 0;
            int cnt0 = 0;
            if(ii != n) {
                int i1 = ii;
                int j1 = jj;
                while(true) {
                    if(i1 == -1 || m == j1) break;
                    if(a[i1][j1] == '1') cnt1++;
                    else cnt0++;
                    i1--;
                    j1++;
                }
                ii++;
            }
            else {
                int i1 = ii - 1;
                int j1 = jj + 1;
                while(true) {
                    if(i1 == -1 || m == j1) break;
                    if(a[i1][j1] == '1') cnt1++;
                    else cnt0++;
                    i1--;
                    j1++;
                }
                jj++;
            }
            w[i].first = cnt0;
            w[i].second = cnt1;
        }
        int res = 0;
        for(int i = 0; i < w.size() / 2; i++) {
            int sum =  w[i].first + w[i].second + w[w.size() - i - 1].first + w[w.size() - i - 1].second;
            int mx = max(w[i].first + w[w.size() - i - 1].first, w[i].second + w[w.size() - i - 1].second);
            res += sum - mx; 
        }
        cout << res << endl;
        
    }   
    return 0;
}