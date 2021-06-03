#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define int long long
#define pii pair<int,int>
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
    int t; cin >> t;
    while(t--) {
        vi r(9), c(9);
        int a[9][9];
        int data[3][3];
        memset(data, 0, sizeof(data));
        rep(i, 0, 9){
            rep(j, 0, 9) {;
                char ch; cin >> ch;
                a[i][j] = ch - '0';
            }
        } 
        int k = a[0][0];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(data[i / 3][j / 3]) {
                    continue;
                }
                if(r[i] == 0 && c[j] == 0 && a[i][j] != k) {
                    a[i][j] = k;
                    r[i] = 1;
                    c[j] = 1;
                    data[i / 3][j / 3] = 1;
                }
            }
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(data[i / 3][j / 3]) {
                    continue;
                }
                if( (r[i] == 0 || c[j] == 0) && a[i][j] != k) {
                    a[i][j] = k;
                    r[i] = 1;
                    c[j] = 1;
                    data[i / 3][j / 3] = 1;
                }
            }
        }
        rep(i, 0, 9) {
            rep(j, 0, 9) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }

}