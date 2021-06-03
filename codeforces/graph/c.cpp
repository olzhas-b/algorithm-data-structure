#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
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
    
    
int main(){
    speed;
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        unordered_map<string, int> m;
        int mx = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mm;
            int x; cin >> x;
            for(int j = 2; j * j <= x; j++) {
                while(x % j == 0) {
                    x /= j;
                    mm[j]++;
                }
            }
            if(x != 1) mm[x]++;
            string s = "";
            iter(mm) {
                if(it->second % 2) {
                    s += to_string(it->first);
                    s += '_';
                }
            }
            if(m[s]) {
                m.clear();
                mx++;
                m[s]++;
            } else {
                m[s]++;
            }
           
        }
        if(m.size() != 0) mx++;
        cout << mx << endl;

    }   
    return 0;
}