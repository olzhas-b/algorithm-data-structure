#include <bits/stdc++.h>
using namespace std;
struct Heap {
    vector<int> v;
    int sz = 0;
    int limit = 0;
    void build(int n) {
        v.assign(n + 1, INT_MIN);
        limit = n;
    }
    void sift_up(int i) {
        if(i / 2 >= 1 && v[i / 2] < v[i]) {
            swap(v[i / 2], v[i]);
            sift_up(i / 2);
        }
        else {
            cout << i << "\n";
        }
    }
    
    void sift_down(int i) { 
        int left = 2 * i;
        int right = 2 * i + 1;
        int mxIndex = i;
        if(left < sz && v[i] < v[left]) {
            mxIndex = left; 
        }
        if(right < sz && v[mxIndex] < v[right]) {
            mxIndex = right;
        }
        if(mxIndex != i) {
            swap(v[i], v[mxIndex]);
            sift_down(mxIndex);
        } else {
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
            cout << -1 << "\n";
        } else {
            v[++sz] = value;
            sift_up(sz);
        }
    }
    void extract_max() {
        if(sz == 0) {
            cout << -1 << "\n";
        } else {
            int mx = v[1];
            v[1] = v[sz--];
            v[sz + 1] = INT_MIN;
            sift_down(1);
            cout << mx << "\n";
        }
    }
    void print() {
        for(int i = 1; i <= sz; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
};
int main(){
    int n, k; cin >> n >> k;   
    Heap h;
    h.build(n);
    while(k--) {
        int x; cin >> x;
        if(x == 1) {
            h.extract_max();
        } else {
            int value; cin >> value;
            h.insert(value);
        }
    }
    h.print();

    
    return 0;
}