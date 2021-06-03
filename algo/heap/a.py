#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
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
    
const ll mod = (ll)1e9 + 7;
    
int main(){
    speed;
    int t; cin >> t;
    while(t-- ){
        int n; cin >> n;
        map<int, bool> m;
        vector<char> v(n);
        rep(i, 0, n) cin >> v[i];
        map<int, bool> st;
        rep(i, 0, n) {
            if(v[i] == '-') {
                m[i] = true;
                m[(i + 1) % n] = true;
            } else if(v[i] == '>') {
                st[i] = true;
            } else {
                st.clear();
            }
        }
        if(v[0] == '<') st.clear();
        iter(st) { 
            m[it->first] = true;
        }
        cout << st.size() << endl;
        st.clear();
        for(int i = 0; i < n; i++) {
            if(v[i] == '-') {
                m[i] = true;
                m[(i + 1) % n] = true;
            } else if(v[i] == '<') {
                st[i - 1] = true;
            } else {
                st.clear();
            }
        }
        if(v[0] == '>') st.clear();
        iter(st) {
            m[it->first] = true;
        }
        int cnt = 0;
        iter(m) {
            if(it->second == true) cnt++;
        }

        cout << cnt << endl;
    }

}