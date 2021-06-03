#include <bits/stdc++.h>
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

struct segmentTree {
    vector<int> tree;
    int sz;
    void build(int n) {
        sz = 1;
        while(sz < n) {
            sz *= 2;
        }
        tree.assign(2 * sz, 0);
    }
    // void insert(int i, int val, int x, int l, int r) {
    //     if(r - l == 1) {
    //         tree[x] = val;
    //         return;
    //     }
    //     int mid = (l + r) / 2;
    //     if(i < mid) {
    //         insert(i, val, 2 * x + 1, l, mid);
    //     } else {
    //         insert(i, val, 2 * x + 2, mid, r);
    //     }
    //     tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    // }
    void add(int l, int r, int x, int lx, int rx) {
        if(r <= lx || l >= rx) {
            return;
        }
        int mid = (lx + rx) / 2;
        if(l <= lx && rx <= r) {
            tree[x] += 1;
        } else {
            add(l, r, 2 * x + 1, lx, mid);
            add(l, r, 2 * x + 2, mid, r);
        }
    }
    void add(int l, int r) {
        add(l, r, 0, 0, sz);
    }
    int get(int i, int sum, int x, int lx, int rx) {
        if(rx - lx == 1) {
            return tree[x] + sum;
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            return get(i, sum + tree[x], 2 * x + 1, lx, mid);
        } else {
            return get(i, sum + tree[x], 2 * x + 2, mid, rx);
        }
    }
    int get(int i) {
        return get(i, 0, 0, 0, sz);
    }
    // void insert(int i, int val) {
    //     insert(i, val, 0, 0, sz);
    // }
    void print() {
        rep(i, 0, tree.size()) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
    
};
int main(){
    speed;
    segmentTree t;
    int n; cin >> n;
    vi v(n);
    t.build(n);
    rep(i, 0, n) {
        int l, r; cin >> l >> r;
        // t.insert(i, v[i]);
    }
    t.print();
    return 0;
}