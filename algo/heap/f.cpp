#include <bits/stdc++.h>
using namespace std;
struct Heap {
    vector<int> v;
    int sz = 1;
    int limit = 1;
    void build(int n) {
        v.assign(n + 1, INT_MIN);
        limit = n + 1;
    }
    void sift_up(int i) {
        if(i / 2 >= 1 && v[i / 2] < v[i]) {
            swap(v[i / 2], v[i]);
            sift_up(i / 2);
        }
        // else {
        //     cout << i << endl;
        // }
    }
    void sift_down(int i) {
        if(2 * i + 1 < sz) {
            if(v[2 * i] < v[2 * i + 1] && v[2 * i + 1] > v[i]) {
                swap(v[i], v[2 * i + 1]);
                sift_down(2 * i + 1);
            } else if(v[2 * i] > v[i]) {
                swap(v[i], v[2 * i]);
                sift_down(2 * i);
            }
            else {
                cout << i << " ";
            }
        } else if(2 * i < sz && v[2 * i] > v[i]) {
            swap(v[i], v[2 * i]);
            sift_down(2 * i);
        } 
        else {
            cout << i << " ";
        }
    }
    void update1(int i, int value) {
        v[i] += value;
        sift_up(i);
    }
    void update2(int i, int value) {
        v[i] -= value;
        sift_down(i);
    }
    void insert(int value) {
        if(sz == limit) {
            cout << -1 << endl;
        } else {
            v[sz] = value;
            sift_up(sz++);
        }
    }
    void extract_max() {
        if(sz == 1) {
            cout << -1 << endl;
        } else {
            int mx = v[1];
            swap(v[1], v[--sz]);
            sift_down(1);
            cout << mx << endl;
        }
    }
    void print() {
        for(int i = 1; i < sz; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    int n; cin >> n;
    Heap h; h.build(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        h.insert(x);
    }
    h.print();
    
    return 0;
}