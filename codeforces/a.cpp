#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define int long long
#define pii pair<int,int>
#define f(x) get<0>(x)
#define s(x) get<1>(x)
#define t(x) get<2>(x)
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
//cout.setf(ios::fixed);cout.precision(9);
	
const ll mod = (ll)1e9 + 7;
	
signed main(){
	speed;
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vi v(n);
		rep(i, 0, n) cin >> v[i];
		stack<int> st;
		sort(all(v));
		int sum = 0;
		bool out = false;
		for(int i = 0; i < n; i++) {
			int sum = 0;
			bool ans = true;
			for(int j = 0; j < n; j++) {
				if(i == j) continue;
				sum += v[j];
				if(sum == k) ans = false;
			}
			sum += v[i];
			if(sum == k) ans = false;
			if(ans) {
				out = true;
				cout << "YES" << endl;
				for(int j = 0; j < n; j++) {
					if(i != j) cout << v[j] << " ";
				}
				cout << v[i] << endl;
				break;
			}
			if(out) break;
		}
		if(out == false) {
			cout << "NO" << endl;
		}
	}
	return 0;
}