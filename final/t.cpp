#include <vector>
#include <exception>

using namespace std;

void Heapify(vector<int>& A, size_t length, size_t i) {
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    size_t largest = i;
    if (l < length && A[l] > A[largest])
        largest = l;
    if (r < length && A[r] > A[largest])
        largest = r;
    if (largest != i) {
        swap(A[i], A[largest]);
        Heapify(A, length, largest);
    }
}

void Build_Heap(vector<int>& A, size_t length) {
    for (size_t i = length / 2 - 1; i != (size_t)(-1); i--)
        Heapify(A, length, i);
}

void Heapsort(vector<int>& A) {
    Build_Heap(A, A.size());
    for (size_t i = A.size() - 1; i > 0; i--) {
        swap(A[0], A[i]);
        Heapify(A, i, 0);
    }
}

void Heap_Increase_Key(vector<int>& A, size_t length, size_t i, int key) {
	if (key < A[i])
            throw exception("Новый ключ меньше предыдущего");
    A[i] = key;
    while (i > 0 && A[(i-1)/2] < A[i]) {
        swap(A[(i-1)/2], A[i]);
        i = (i-1)/2;
    }
}

void Heap_Insert(vector<int>& A, size_t length, int key) {
    length++;
    if (length > A.size())
        A.resize(length);
    Heap_Increase_Key(A, length, length - 1, key);
}

int Heap_Extract(vector<int>& A, size_t length) {
    if (length == 0) return -1;
    int max_element = A[0];
    A[0] = A[length - 1];
    length--;
    Heapify(A, length, 0);
    return max_element;
}