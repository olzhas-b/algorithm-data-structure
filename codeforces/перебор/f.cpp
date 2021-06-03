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
#define rforn(b) for(int i = b - 1 ;b >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
vector<vector<int>> a;
vector<int> v;
vector<vector<int>> answer;
vector<bool> used;
int mn = INT_MAX;
const ll mod = (ll)1e9 + 7;
void rec(int idx) {
    if(idx == n) {
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += a[v[i]][v[i + 1]];
        }
        sum += a[v[n - 1]][v[0]];
        mn = min(mn, sum);
        return;
    }
    else {
        for(int i = 0; i < n; i++) {
            if(used[i]) continue;
            v[idx] = i;
            used[i] = true;
            rec(idx + 1);
            used[i] = false;
        }
    }

}

int main(){
    speed;
    cin >> n;
    used = vector<bool> (n + 1);
    v = vector<int> (n);
    a = vector<vector<int> > (n, vector<int>(n, 0));
    forn(n) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    rec(0);
    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    cout << mn;
    return 0;
}