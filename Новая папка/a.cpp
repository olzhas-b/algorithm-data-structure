#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
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
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    vector<bool> m(200, false);
    vector<int> index(200);
    int ans = 0;
    int begin = 0;
    int sz = 0;
    for(int i = 0; i < n; i++) {
        cout << i;
        if(m[s[i]]) {
            int end = index[s[i]];
            for(int j = begin; j <= end; j++) {
                m[s[j]] = false;
                sz--;
            }
            begin = end;
        } else {
            m[s[i]] = true;
            index[s[i]] = i;
            sz++;
        }
        ans = max(ans, sz);
    }
    return ans;
}  
signed main(){
    speed;
    while(true) {
        string s; cin >> s;
        cout << lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}