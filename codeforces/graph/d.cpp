# include <bits/stdc++.h>
# define sz(x) (int)x.size()
# define f first
# define s second

using namespace std;
using ll = long long;

int n;
int ask(int l, int r) {
  if (l == r) return l;
  cout << "? " << l << ' ' << r << endl;
  int x;
  cin >> x;
  return x;
} 
// vector<int> v = {1, 2};
// int ask(int l, int r) {
//     // cout << l << " " << r << endl;
//     vector<pair<int, int>> w;
//     for(int i = l - 1; i < r; i++) {
//         w.push_back({v[i], i + 1});
//     }
//     sort(w.begin(), w.end());
//     return w[w.size() - 2].second;
// }
 

void out(int x) {
  cout << "! " << x << endl;
  exit(0); 
}

void calc(int l, int r) {
    int general = ask(l ,r);
    while (l < r) {
        int mid = l + (r - l) / 2;
        //cout << l <<" " << r << endl;
        if(r - l == 1) {
            if(ask(l, r) == l) {
                out(r);
                fflush(stdout);
                exit(0);
            } else {
                out(l);
                fflush(stdout);
                exit(0);
            }
        }
        int res_left = 0;
        int res_right = 0;
        if(l <= general && general <= mid) {
            res_left = ask(l, mid);
            if(general == res_left) {
                r = mid;
            }  else {
                l = mid;
                general = ask(mid, r);
            }
        } else {
            res_right = ask(mid, r);
            if(general == res_right) {
                l = mid;
            } else {
                r = mid;
                general = ask(l, mid);
            }
        }
        
    }
}

void solve() {
  cin >> n;
  calc(1, n);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}