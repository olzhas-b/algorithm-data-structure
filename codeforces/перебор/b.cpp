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
#define rforn(b) for(int i = b - 1 ;b >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
const ll mod = (ll)1e9 + 7;
vector<char> s;
int n;
void out() {
	forn(s.size()) {
		cout << s[i] <<" ";
	}
	cout << endl;
}
void rec(int idx, int bal) {
	if(idx == n) {
		if(bal == 0) out();
		return;
	}
	else {
		s[idx] = '(';
		rec(idx + 1, bal + 1);
		if(bal == 0) return;
		s[idx] = ')';
		rec(idx + 1, bal - 1);
	}
}	
int main(){
	speed;
	cin >> n;
	s = vector <char> (n);
	rec(0, 0);
	return 0;
}