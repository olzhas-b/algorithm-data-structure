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
int cnt = 0;
vector<char> v;
const ll mod = (ll)1e9 + 7;
void rec(int idx, int bal) {
    if(idx == n) {
        if(bal == 0) {
            cnt++;
            if(cnt == 8644) {
                forn(n) {
                    cout << v[i];
                }
                cout << endl;
            }
        }
        return;
    }
    else {
        v[idx] = '(';
        rec(idx + 1, bal + 1);
        if(bal == 0) return;
        v[idx] = ')';
        rec(idx + 1, bal - 1);
    }
}  

int main(){
    speed;
    cin >> n;
    v = vector<char> (n);
    rec(0, 0);
    return 0;
}