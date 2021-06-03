#include <bits/stdc++.h>
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
struct tree {
    int sz;
    vector<int> sum;
    void build(int n) {
        sz = n + 1;
        sum = vector<int> (sz, 1);
    }
    int getSum(int i) { 
        int res = 1;
        while(i > 0) {
            res *= sum[i];
            i -= (i) & (-i);
        }
        return res;
    }
    void update(int i, int value) {
        while(i < sz) {
            sum[i] *= value;
            i += (i) & (-i);
        }   
    }
    int getSum(int l, int r) {
        return getSum(r) / getSum(l - 1);
    }
    void print() {
        rep(i, sum.size()) {
            cout << sum[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    speed;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    tree t;
    t.build(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        t.update(i + 1, a[i]);
    }
    t.print();
    while(k--) {
        int l, r; cin >> l >> r;
        cout << t.getSum(l, r) << endl;
    }
    return 0;
}