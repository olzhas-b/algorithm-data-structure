#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <string>
#include <map>
#include <set>
#include <deque>
using namespace std;
struct Heap {
    vector<int> v;
    int sz = 0;
    void build(vector<int> arr) {
        v.assign(arr.size() + 1, 0);
        sz = v.size();
        for(int i = 0; i < arr.size(); i++) {
            v[i + 1] = arr[i];
        }
    }
    void sift_up(int i) {
        if(i / 2 >= 1 && v[i / 2] < v[i]) {
            swap(v[i / 2], v[i]);
            sift_up(i / 2);
        } else {
            cout << i << endl;
        }
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
                cout << i << endl;
            }
        } else if(2 * i < sz && v[2 * i] > v[i]) {
            swap(v[i], v[2 * i]);
            sift_down(2 * i);
        } else {
            cout << i << endl;
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
    void extract_max() {
        
    }
    void print() {
        for(int i = 1; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    Heap h; h.build(v);
    int k; cin >> k;
    while(k--) {
        int ind, value; cin >> ind >> value;
        //h.update1(ind, value);
        h.update2(ind, value);
    }
    h.print();
    return 0;
}