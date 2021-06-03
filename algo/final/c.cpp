#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

struct HEAP {
		int size;
		int h[N];
        HEAP() {
            size = 0;
        }
		void siftUp(int pos) {
			int nextpos = pos / 2;
			while (nextpos && h[pos] > h[nextpos]) {
				swap(h[pos], h[nextpos]);
				pos = nextpos;
				nextpos = pos / 2;
			}
		}

		void siftDown(int pos, int a[], int sz) {
			while (pos <= sz) {
				int l = pos + pos;
				int r = l + 1;
				if (l > sz) break;
				else if (r > sz) {
					if (a[l] > a[pos])
						swap(a[l], a[pos]);
					break;
				}

				if (a[l] <= a[pos] && a[r] <= a[pos]) break;
				if (a[l] > a[pos] && a[r] > a[pos]) {
					if (a[r] > a[l]) {
						swap(a[pos], a[r]);
						pos = r;
					} else {
						swap(a[pos], a[l]);
						pos = l;
					}
				} else if (a[l] > a[pos]) {
					swap(a[pos], a[l]);
					pos = l;
				} else if (a[r] > a[pos]) {
					swap(a[pos], a[r]);
					pos = r;
				}
			}
		}

		void siftDown(int pos) { siftDown(pos, h, size); }

		void insert(int x) {
			size++;
			h[size] = x;
			siftUp(size);
		}

		void build(int a[], int n) {
			for (int i = 0; i < n; i++)
				insert(a[i]);
		}

		int getMax() { 
            return h[1];
        }

		void delMax() {
			size--;
			h[1] = h[size];
			siftDown(1);
		}
};

int main() {

    HEAP h;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int x; cin >> x;
        if(x == 1) {
            int val; cin >> val;
            h.insert(val);
        }
        else {
            cout << h.getMax() << endl;
            h.delMax();
        }
    }
    
}