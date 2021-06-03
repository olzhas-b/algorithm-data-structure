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
    
const ll mod = (ll)1e9 + 7;
vector<int> v;
vector<bool> used;
string s;
int n, m;
int cnt = 0;
void rec(int idx, int sum, int last) {
    if(sum == n) {
        cnt++;
        if(cnt == 13672 ) {
            for(int i = 0; i < idx; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    else {
        for(int i = last; i <= n - sum; i++) {
            v[idx] = i;
            rec(idx + 1, sum + i, i);
        }
    }
}   
int main(){
    speed;
    cin >> n;
    v = vector<int> (n);
    used = vector<bool> (n + 1);
    rec(0, 0, 1);
    return 0;
}