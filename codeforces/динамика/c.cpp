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
int result = 0;
int rec(int i, int j) {
    if(min(i, j) == 0 && max(i, j) == 1) {
        return 1;
    }
    else {
        if(i > 0 && j > 0) {
            result = rec(i - 1, j) + rec(i, j - 1);   
        }
        else if(i == 0) {
            result = rec(i, j - 1);
        }
        else {
            result = rec(i - 1, j);
        }   
        return result;   
    }
}
int main(){
    speed;
    int n, m; cin >> n >> m;
    cout << rec(n, m);
}