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
vector<vector<int>> v;
int n, m;
int check(int i, int j) {
    if(i >= 0 && j >= 0 && i < n && j < m) {
        return v[i][j];
    }
    return -1;
}   
int main(){
    speed;
    int t; cin >> t;
    for(int w = 1; w <= t; w++) {
        cin >> n >> m;
        v = vector<vector<int>> (n, vector<int> (m));
        vector<vector<bool>> visited(n, vector<bool> (m));
        int ans = 0;
        vector<tuple<int, int, int>> nums;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool yes = false;
                int k = v[i][j] - 1;
                if(k == 0) continue;
                int k1 = check(i - 1, j);
                if(k1 == -1) k1 = k - 1;
                int k2 = check(i + 1, j);
                if(k2 == -1) k2 = k - 1;
                int k3 = check(i, j - 1);
                if(k3 == -1) k3 = k - 1;
                int k4 = check(i, j + 1);
                if(k4 == -1) k4 = k - 1;
                if(k > k1 && k > k2 && k > k3 && k > k4) yes = true;
                if(yes) nums.push_back({v[i][j], i, j});
            }
        }
        sort(all(nums));
        queue<pair<int, int>> q;
        for(int i = nums.size() - 1; i >= 0; i--) {
            q.push({s(nums[i]), t(nums[i])});
        }
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(v[i][j] > 1) {
                int k1 = check(i - 1, j);
                if(k1 != -1) {
                    if(k1 < v[i][j] - 1) {
                        ans += v[i][j] - 1 - k1;
                        v[i-1][j] = v[i][j] - 1;
                        visited[i][j] = true;
                        q.push({i - 1, j});
                    }
                }
                k1 = check(i + 1, j);
                if(k1 != -1) {
                    if(k1 < v[i][j] - 1) {
                        ans += v[i][j] - 1 - k1;
                        v[i + 1][j] = v[i][j] - 1;
                        visited[i][j] = true;
                        q.push({i + 1, j});
                    }
                }
                k1 = check(i, j - 1);
                if(k1 != -1) {
                    if(k1 < v[i][j] - 1) {
                        ans += v[i][j] - 1 - k1;
                        v[i][j - 1] = v[i][j] - 1;
                        visited[i][j] = true;
                        q.push({i, j - 1});
                    }
                }
                k1 = check(i, j + 1);
                if(k1 != -1) {
                    if(k1 < v[i][j] - 1) {
                        ans += v[i][j] - 1 - k1;
                        v[i][j + 1] = v[i][j] - 1;
                        visited[i][j] = true;
                        q.push({i, j + 1});
                    }
                }
            }
        }
        printf("Case #%d: %d\n", w, ans);

    }   
    return 0;
}