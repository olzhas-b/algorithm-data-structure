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
#define rep(i, b) for(int i = 0; i < b; i++)
#define repr(i, b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
struct node {
    int val = 0;
    int bonus = 0;
};

struct segment {
    int sz;
    vector<node> tree;
    void build(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        tree.assign(sz * 2 - 1, {0, 0});
    }
    void insert(int i, int val, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x].val = val;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            insert(i, val, 2 * x + 1, lx, mid);
        } else {
            insert(i, val, 2 * x + 2, mid, rx);
        }
    }
    void insert(int i, int val) {
        insert(i, val, 0, 0, sz);
    }   
    void add(int l, int r, int value, int x, int lx, int rx) {
        if(r <= lx || l >= rx) {
            return;
        }
        int mid = (lx + rx) / 2;
        if(l <= lx && r >= rx) {
            tree[x].bonus += value;
        } else {
            add(l, r, value, 2 * x + 1, lx, mid);
            add(l, r, value, 2 * x + 2, mid, rx);
        }
    }
    void add(int l, int r, int value) {
        add(l, r, value, 0, 0, sz);
    } 
    int getSum(int i, int x, int lx, int rx, int sum) {
        if(rx - lx == 1) {
            return tree[x].val + sum + tree[x].bonus;
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            return getSum(i, 2 * x + 1, lx, mid, sum + tree[x].bonus);
        } else {
            return getSum(i, 2 * x + 2, mid, rx, sum + tree[x].bonus);
        }
    }
    int getSum(int i) {
        return getSum(i, 0, 0, sz, 0);
    }
    void print() {
        for(int i = 0; i < tree.size(); i++) {
            cout << tree[i].val << " ";
        }
        cout << endl;
    }
    
};
signed main(){
    speed;
    int n, k; cin >> n >> k;
    segment st;
    st.build(n);
    rep(i, n) {
        int x; cin >> x;
        st.insert(i, x);
    }
    rep(i, k) {
        int x; cin >> x;
        if(x == 1) {
            int l, r, value; cin >> l >> r >> value;
            st.add(l - 1, r, value);
        } else {
            int pos; cin >> pos;
            cout << st.getSum(pos - 1) << endl;
        }
    }
    return 0;
}