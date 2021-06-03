#include <bits/stdc++.h>
#include <fstream>
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
    ifstream input("input.txt");
    int n, cap; input >> n >> cap;
    map<pair<double, int>, pii> m;
    vector<tuple<double, int, int>> v(n);
    forn(n) {
        int x, y; input >> x >> y;
        double k = (double)y / (double)x;
        v[i] = {k, x, y};
    }
    sort(all(v));
    double answer = 0;
    for(int i = n - 1; i >= 0; i--) {
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << endl;
        if(cap >= get<1>(v[i])) {
            cap -= get<1>(v[i]);
            answer += get<2>(v[i]);
        } 
        else {
            answer += ( (double)cap * get<2>(v[i]) )/ (double)get<1>(v[i]);
            break;
        }
    }
    cout << printf("%0.10f", answer);

    return 0;
}