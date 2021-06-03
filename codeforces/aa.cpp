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
int NO_OPERATION = INT_MIN;
struct segment {
    int sz;
    vector<int> tree;
    void build(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        tree.assign(sz * 2, 0);
    }
   
    void propagate(int x, int lx, int rx) {
        if(rx - lx == 1) return;
        if(tree[x] == NO_OPERATION) return;
        tree[2 * x + 1] = tree[x];
        tree[2 * x + 2] = tree[x];
        tree[x] = NO_OPERATION;
    }
    void modify(int l, int r, int value, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(r <= lx || l >= rx) {
            return;
        }
        int mid = (lx + rx) / 2;
        if(l <= lx && r >= rx) {
            tree[x] = value;
            return;
        } else {
            modify(l, r, value, 2 * x + 1, lx, mid);
            modify(l, r, value, 2 * x + 2, mid, rx);
        }
    }
    void modify(int l, int r, int value) {
        modify(l, r, value, 0, 0, sz);
    } 
    int get(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            return tree[x];
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            return get(i, 2 * x + 1, lx, mid);
        } else {
            return get(i, 2 * x + 2, mid, rx);
        }
    }
    int get(int i) {
        return get(i, 0, 0, sz);
    }
    void print() {
        for(int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
    
};
signed main(){
    speed;
    int n, k; cin >> n >> k;
    segment st;
    st.build(n);
    int cnt = 1;
    rep(i, k) {
        int x; cin >> x;
        if(x == 1) {
            int l, r, value; cin >> l >> r >> value;
            st.modify(l, r, value);
            cnt++;
        } else {
            int pos; cin >> pos;
            cout << st.get(pos) << endl;
        }
    }
    return 0;
}   