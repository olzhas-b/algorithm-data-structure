#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int i =0; i < n; i++) {
		cin >> v[i];
	}
	int n1 = k, n2 = n - k;
	int L[n1], R[n2];
	int j = 0;
	for(int i = 0; i < n; i++) {
		if(i < k) {
			L[i] = v[i];
		}
		else {
			R[j] = v[i];
			j++;
		}
	}
	int i = 0;
	j = 0;
	k = 0;
	while(i < n1 && j < n2) {
		if(L[i] < R[j]) {
			v[k] = L[i];
			i++;
		} 
		else {
			v[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		v[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		v[k] = R[j];
		j++;
		k++;
	}
	for(int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	return 0;
}