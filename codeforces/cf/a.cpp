#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
const ll mod = (ll)1e9 + 7;
	
int main(){
	speed;
	int n, k; cin >> n >> k;
	vector<tuple<long double,int,int>> v;
	stack<int> st_a;
	stack<int> st_b;
	int cnta = 0, cntb = 0;
	forn(n) {
		long double t;
		int a, b; cin >> t >> a >> b;
		if(a == 1) cnta++;
		if(b == 1) cntb++;
		if(a + b == 2) {
			v.push_back({t / 2, a , b});
		}
		else if(a == 1 || b == 1) {
			v.push_back({t, a, b});
		}
	}	
	if(cnta >= k && cntb >= k) {
		sort(all(v));
		ll res = 0;
		cnta = k;
		cntb = k;
		for(int i = 0; i < v.size(); i++) {
			long double t = get<0>(v[i]);
			int a = get<1>(v[i]);
			int b = get<2>(v[i]);
			if(a + b == 2) {
				res += t * 2;
				cnta--;
				cntb--;
				if(cnta < 0 && !st_a.empty()) {
					res -= st_a.top();
					cnta++;
					st_a.pop();
				}
				if(cntb < 0 && !st_b.empty()) {
					cntb++;
					res -= st_b.top();
					st_b.pop();
				}
			}
			else if(a == 1 && cnta > 0) {
				res += t;
				cnta--;
				st_a.push(t);
			}
			else if(b == 1 && cntb > 0) {
				res += t;
				cntb--;
				st_b.push(t);
			}
			if(cnta <= 0 && cntb <= 0) { 	
				break;
			}
		}

		cout << res << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}