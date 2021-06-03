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
int n;
void rec(int idx) {
    if(idx == n) {
        for(int i = 0; i < n; i++) {
            cout << s[v[i] - 1];
        }
        cout << endl;
        return;
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(used[i] == true) continue;
            v[idx] = i;
            used[i] = true;
            rec(idx + 1);
            used[i] = false;
        }
    }
}   
int main(){
    speed;
    cin >> s;
    n = s.size();
    v = vector<int> (n);
    used = vector<bool> (n + 1);
    rec(0);
    return 0;
}