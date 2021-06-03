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
    }
    int getMax() {
        int k = v[1];
        v[1] -=1;
        sift_down(1);
        return k;
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
    void update(int i, int value) {
        v[i] -= value;
        sift_down(i);
    }
    void build_heap_siftdown() {
        for(int i = sz / 2; i >= 1; i--) {
            sift_down(i);
        }
    }
};
int main(){
    int n, k; cin >> n >> k;
    long long x = 0;
    Heap h;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        x  += v[i];
    }
    h.build(v);
    h.build_heap_siftdown();
    long long ans = 0;
    while(k != 0 && x != 0) {
        int value = h.getMax();
        if(value < 0) break;
        ans += value;
        k--;
        x--;
    }  
    cout << ans << endl;
    
    
    return 0;
}