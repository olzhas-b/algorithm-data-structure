#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
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
    
char a[1001][1001];
int main(){
    speed;
    int n, m; cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    map<pair<int,int>, bool> visited;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(a[i][j] == '.' && visited[{i, j}] == false) {
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int,int> cur = q.front();
                    visited[cur] = true;
                    int i1 = cur.first;
                    int j1 = cur.second;
                    q.pop();
                    if(i1 > 0 && a[i1 - 1][j1] == '.' && visited[{i1 - 1, j1}] == false) {
                         q.push({i1 - 1, j1});
                         visited[{i1 - 1, j1}] = true; 
                    }
                    if(j1 > 0 && a[i1][j1 - 1] == '.' && visited[{i1, j1 - 1}] == false) {
                        q.push({i1, j1 - 1});
                        visited[{i1, j1 - 1}] = true;
                    } 
                    if(i1 < n - 1 && a[i1 + 1][j1] == '.' && visited[{i1 + 1, j1}] == false) {
                        q.push({i1 + 1, j1});
                        visited[{i1 + 1, j1}] = true;    
                    }
                    if(j1 < m - 1 && a[i1][j1 + 1] == '.' && visited[{i1, j1 + 1}] == false) {
                        q.push({i1, j1 + 1});
                        visited[{i1, j1 + 1}] = true;
                    } 
                }
            }
        }
    }
    cout << cnt;
    return 0;
}