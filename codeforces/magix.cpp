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
int n, m; 
char matrix[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x - 1 >= 1) {
            if(matrix[x - 1][y] == '.' && dist[x][y] < dist[x - 1][y]) {
                dist[x - 1][y] = dist[x][y];
                q.push({x - 1, y}); 
            } else {
                if(x - 2 >= 1 && matrix[x - 2][y] == '.' && dist[x][y] + 1 < dist[x - 2][y]) {
                    dist[x - 2][y] = dist[x][y] + 1;
                    q.push({x - 2, y});
                }
            }
        }
        if(x + 1 <= n) {
            if(matrix[x + 1][y] == '.' && dist[x][y] < dist[x + 1][y]) {
                dist[x + 1][y] = dist[x][y];
                q.push({x + 1, y}); 
            } else {
                if(x + 2 <= n && matrix[x + 2][y] == '.' && dist[x][y] + 1 < dist[x + 2][y]) {
                    dist[x + 2][y] = dist[x][y] + 1;
                    q.push({x + 2, y});
                }
            }
        }
        if(y - 1 >= 1) {
            if(matrix[x][y - 1] == '.' && dist[x][y] < dist[x][y - 1]) {
                dist[x][y - 1] = dist[x][y];
                q.push({x, y - 1}); 
            } else {
                if(y - 2 >= 1 && matrix[x][y - 2] == '.' && dist[x][y] + 1 < dist[x][y - 2]) {
                    dist[x][y - 2] = dist[x][y] + 1;
                    q.push({x, y - 2});
                }
            }
        }
        if(y + 1 <= m) {
            if(matrix[x][y + 1] == '.' && dist[x][y] < dist[x][y + 1]) {
                dist[x][y + 1] = dist[x][y];
                q.push({x, y + 1}); 
            } else {
                if(y + 2 <= m && matrix[x][y + 2] == '.' && dist[x][y] + 1 < dist[x][y + 2]) {
                    dist[x][y + 2] = dist[x][y] + 1;
                    q.push({x, y + 2});
                }
            }
        }
        
    }
}
int main(){
    cin >> n >> m;
    int loc_x, loc_y; cin >> loc_x >> loc_y;
    int target_x, target_y; cin >> target_x >> target_y;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            cin >> matrix[i][j];
            dist[i][j] = INT_MAX;
        }
    }
    dist[loc_x][loc_y] = 0;
    bfs(loc_x, loc_y);
    if(dist[target_x][target_y] == INT_MAX) dist[target_x][target_y] = -1;
    cout << dist[target_x][target_y];
    return 0;
}