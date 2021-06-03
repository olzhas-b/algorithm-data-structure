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
	
const ll mod = (ll)1e9 + 7;
	
signed main(){
	speed;
	int n, k; cin >> n >> k;
	vi v(n);
	int sum = 0;
	rep(i, 0, n) {
		cin >> v[i];
		sum += v[i];
	}
	
	int avg = sum / k;
	k--;
	sum = 0;
	int ans = LONG_LONG_MIN;
	vector<vector<int>> data(k + 1, vector<int> ());
	map<int, int> prefix_sum;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(sum + v[i] > avg && k) {
			k--;
			prefix_sum[cnt] = sum;
			cnt++;
			data[cnt].push_back(v[i]);
			sum = v[i];
		} else {
			sum += v[i];
			data[cnt].push_back(v[i]);
		}
		ans = max(ans, sum);
	}
	prefix_sum[cnt] = sum;
	// for(int i = 0; i < data.size(); i++) {
	// 	for(int j = 0; j < data[i].size(); j++) {
	// 		cout << data[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	k = data.size();
	for(int i = 0; i < k - 1; i++) {
		
	}
	cout << ans;
	return 0;
}