#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    public:
    vector<int> a;
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int k) {
        a.push_back(k);
        size++;
    }

    void siftDown(int i) {
        if (left(i) > size - 1)
            return;
        int j = left(i);
        if (right(i) < size && a[j] < a[right(i)])
            j = right(i);
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            siftDown(j);
        }
    }

    void ans() {
        for (int i = 0; i < size; i++) 
            cout << a[i] << " ";
        cout << endl;
    }
    
    void heapel() {
        int index = a.size() / 2 - 1;
        for (int j = index; j >= 0; j--) 
            siftDown(j);
    }

    void heapSort() {
        heapel();
        int temp = size;
        for (int i = temp - 1; i >= 0; i--) {
            ans();
            swap(a[0], a[i]);
            size--;
            siftDown(0);
        }
    }
};

int main() {
    MaxHeap *heap = new MaxHeap();
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        heap->insert(k);
    }
    heap->heapSort();
    for (int i = 0; i < n; i++)
        cout << heap->a[i] << " ";
    return 0;
}