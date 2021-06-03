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
int n, m;
int cnt = 0;
vector<char> v;  
void rec(int idx, bool pos, int count) {
    if(idx == n || count == m) {
        if(count == m) {
            cnt++;
            if(cnt == 24008 ) {
                for(int i = 0; i < n; i++) {
                    cout << v[i];
                }
                cout << endl;
            }
        }
        return;
    }
    else {
        if(pos == false) {
            v[idx] = '*';
            rec(idx + 1, true, count + 1);
            v[idx] = '.';
            rec(idx + 1, false, count);
        }
        else {
            v[idx] = '.';
            rec(idx + 1, false, count);
        }
    }
}
int main(){
    speed;
    cin >> n >> m;   
    v = vector<char> (n);
    rec(0, false, 0);
    return 0;
}