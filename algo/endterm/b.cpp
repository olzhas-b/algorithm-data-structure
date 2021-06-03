#include <bits/stdc++.h>
using namespace std;

void merge(tuple<int, int, int> arr[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;
  tuple<int, int, int> L[n1];
    tuple<int, int, int> R[n2];

  for(int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for(int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];
  int i = 0; 
  int j = 0; 
  int k = l;
  while (i < n1 && j < n2)
  {
    int l1 = get<0>(L[i]);
    int l2 = get<1>(L[i]);
    int l3 = get<2>(L[i]);
    int r1 = get<0>(R[j]);
    int r2 = get<1>(R[j]);
    int r3 = get<2>(R[j]);
    if ( (l1 < r1) || (l1 == r1 && l2 < r2) || (l1 == r1 && l2 == r2 && l3 <= r3)) 
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) 
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(tuple<int, int, int> arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}


int main() {
    int n; cin >> n;

    tuple<int, int, int> v[n];
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b>> c;
        cin >> a >> b >> c;
        v[i] = make_tuple(c, b, a);
    }
    mergeSort(v, 0, n - 1);
    for(int i = 0; i < n; i++) {
        int l1 = get<0>(v[i]);
        int l2 = get<1>(v[i]);
        int l3 = get<2>(v[i]);
        cout << l3 << " " << l2 << " " << l1 << endl; 
    }
}