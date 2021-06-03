#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, b) for(int i = 0; i < b; i++)
#define repr(i, b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
const ll mod = (ll)1e9 + 7;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
int main(){
    speed;
    int n, k; cin >> n >> k;
    vi v(n + 1);
    Tree<pii> t;
    rep(i, n) {
      cin >> v[i + 1];
      t.insert({v[i + 1], i + 1});
    } 
    rep(i, k) {
      char c; cin >> c;
      if(c == '!') {
        int ind, value; cin >> ind >> value;
        t.erase({v[ind], ind});
        v[ind] = value;
        t.insert({v[ind], ind});
      } else {
        int l, r; cin >> l >> r;
        cout << t.order_of_key({r + 1, 0}) - t.order_of_key({l, 0}) << endl;
      }
    }
    unordered_map<int, int> kk;
    return 0;
}