#include <bits/stdc++.h>
using namespace std;
struct Heap {
    vector<int> v;
    int sz = 1;
    int limit = 1;
    void build(vector<int> data) {
        v.assign(data.size() + 1, INT_MIN);
        sz = data.size() + 1;
        limit = data.size() + 1;
        for(int i = 0; i < data.size(); i++) {
            v[i + 1] = data[i];
        }
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
        int left = 2 * i;
        int right = 2 * i + 1;
        if(left >= sz) return;
        int mxIndex = i;
        if(v[i] < v[left]) {
            mxIndex = left; 
        }
        if(right < sz && v[mxIndex] < v[right]) {
            mxIndex = right;
        }
        if(mxIndex != i) {
            swap(v[i], v[mxIndex]);
            sift_down(mxIndex);
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
            //cout << -1 << endl;
        } else {
            int mx = v[1];
            swap(v[1], v[--sz]);
            sift_down(1);
            //cout << mx << endl;
        }
    }
    int getMax() {
        return v[1];
    }
    void build_heap_siftdown() {
        for(int i = sz / 2; i >= 1; i--) {
            sift_down(i);
        }
    }
    void print(int n) {
        for(int i = 1; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    int n; cin >> n;
    Heap h;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    h.build(v);       
    h.build_heap_siftdown();
    for(int i = 0; i < n; i++) {
        h.print(n - i + 1);
        h.extract_max();
    }
    h.print(n + 1);
    
    return 0;
}