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
int n;
vector<char> v;
int cnt = 0;
void rec(int idx, int bal1, int bal2) {
    if(idx == n) {
        if(bal1 == 0 && bal2 == 0) {
            bool check = true;
            stack<char> s;
            forn(n) {
                if(v[i] == '(' || v[i] == '[') s.push(v[i]);
                else {
                    if(s.empty()) {
                        check = false;
                        break;
                    }
                    if(s.top() == '(' && v[i] == ')') {
                        s.pop();
                    }
                    else if(s.top() == '[' && v[i] == ']') {
                        s.pop();
                    }
                    else {
                        check = false;
                        break;
                    }
                 }
            }
            if(check && s.empty()) {
                cnt++;
                if(cnt == 8233) {
                    forn(n) {
                        cout << v[i];
                    }
                    cout << endl;
                }
            }
        }
        return;
    }
    else {
        if(bal1 == -1 || bal2 == -1) return;
        v[idx] = '(';
        rec(idx + 1, bal1 + 1, bal2);
       
        if(bal1 == 0); 
        v[idx] = ')';
        rec(idx + 1, bal1 - 1, bal2);

        v[idx] = '[';
        rec(idx + 1, bal1, bal2 + 1);

        if(bal2 == 0) return; 
        v[idx] = ']';
        rec(idx + 1, bal1, bal2 - 1);
    }
}   
int main(){
    speed;
    cin >> n;
    v = vector<char>(n);
    rec(0, 0, 0);
    return 0;
}