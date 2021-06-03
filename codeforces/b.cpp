
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
    vector<int> tree;
    void build(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        tree.assign(sz * 2, 0);
    }
    void set(bool add, int i, int x, int l, int r) {
        if(r - l == 1) {
            if(add)
                tree[x] = 1;
            else 
                tree[x] = 0;
            return;
        }
        int mid = (l + r) / 2;
        if(i < mid) {
            set(add, i, 2 * x + 1, l, mid);
        } else {
            set(add, i, 2 * x + 2, mid, r);
        }
       
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        
    }
    void set(bool add, int i) {
        set(add, i, 0,  0, sz);
    }
    int getIndex(int val, int x, int lx, int rx) {
        if(rx - lx == 1) {
            set(false, lx);
            return lx;
        } 
        int mid = (lx + rx) / 2;
        if(tree[2 * x + 1] >= val) {
            getIndex(val, 2 * x + 1, lx, mid);
        } else {
            getIndex(val - tree[2 * x + 1], 2 * x + 2, mid, rx);
        }
    } 
    int getIndex(int val) {
        return getIndex(val, 0, 0, sz);
    }
    int size() { return sz; }
    int  getMax() { return tree[0]; }
    void print() {
        rep(i, tree.size()) cout << tree[i] << " ";
        cout << endl;
    }
}; 
int main(){
    speed;
    int n; cin >> n;
    tree t;
    t.build(n);
    vi v(n), ans(n);
    for(int i = 0; i < n; i++) {
        t.set(true, i);
        cin >> v[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        int k = t.getMax() - v[i];
        ans[i] = t.getIndex(k) + 1;
    }
    rep(i, n) cout << ans[i] << " ";
    return 0;
}

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

struct segment {
    int sz;
    struct node {
        int prefix;
        int suffix;
        int sum;
        int segment;
    };
    vector<node> tree;
    void build(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        tree.assign(sz * 2, {0, 0, 0, 0});
    }
    node combine(node a, node b) {
        int pref = max(a.prefix, a.sum + b.prefix);
        int suff = max(b.suffix, a.suffix + b.sum);
        int seg = max(a.segment, max(b.segment, a.suffix + b.prefix));
        // pref = max(0LL, pref);
        // suff = max(0LL, suff);
        seg = max(0LL, seg);
        return {pref, suff, a.sum + b.sum, seg};
    }
    void insert(int i, int val, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = {val, val, val, val};
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            insert(i, val, 2 * x + 1, lx, mid);
        } else {
            insert(i, val, 2 * x + 2, mid, rx);
        }
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void insert(int i, int val) {
        insert(i, val, 0, 0, sz);
    }   

    node getValue(int l, int r, int x, int lx, int rx) {
        if(r <= lx || l >= rx) {
            return {0, 0, 0, 0};
        }
        int mid = (lx + rx) / 2;
        if(l <= lx && r >= rx) {
            return tree[x];
        } else {
            node s1 = getValue(l, r, 2 * x + 1, lx, mid);
            node s2 = getValue(l, r, 2 * x + 2, mid, rx);
            return combine(s1, s2);
        }
    }
    node getValue(int l, int r) {
        return getValue(l, r, 0, 0, sz);
    }
    int getMax() {
        return max(tree[0].segment, 0LL);
    }
    void print() {
        for(int i = 0; i < tree.size(); i++) {
            cout << tree[i].segment << " ";
        }
            cout << " --- " << endl;
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
    cout << st.getMax() << endl;
    rep(i, k) {
        int ind, val; cin >> ind >> val;
        st.insert(ind, val);
        cout << st.getMax() << endl;
    }
    return 0;
}