#include <bits/stdc++.h>
#include <fstream>
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
    ifstream cin("input.txt");
    int n; cin >> n;
    vector<int> v;
    vector<pii> w(n);
    unordered_map<int, int> m;
    unordered_map<int, int> ml;
    unordered_map<int, int> mr;
    int mx = -1;
    forn(n) {
        int l, r; cin >> l >> r;
        mx = max(mx, l);
    }
    cout << mx;

    return 0;
}