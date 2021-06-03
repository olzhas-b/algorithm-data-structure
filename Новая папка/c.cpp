#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct segmentTree {
    int size;
    vector<int> tree;
    segmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.assign(size * 2, 0);
        
    }
    void set(int i, int value, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = value;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, value, 2 * x + 1, lx, m);
        } else {
            set(i, value, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(int i, int value) {
        set(i, value, 0, 0, size);
    }
    int sum(int l, int r, int x, int lx, int rx) {
        if(l >= rx || r <= lx) {
            return 0;
        }
        if(l <= lx && rx <= r) {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        int sum1 = sum(l, r, 2 * x + 1, lx, m);
        int sum2 = sum(l, r, 2 * x + 2, m, rx);
        return sum1 + sum2;
    }
    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
    void print() {
        for(int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};
    
signed main(){
    int n, t; cin >> n;
    segmentTree st(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        st.set(i, x);
    }
    // while(t--) 
    // {
    //     int x; cin >> x;
    //     if(x == 1) {
    //         int i, value; cin >> i >> value;
    //         st.set(i, value);
    //     } else {
    //         int l, r; cin >> l >> r;
    //         cout << st.sum(l, r) << endl;
    //     }
    // }
    st.print();
}