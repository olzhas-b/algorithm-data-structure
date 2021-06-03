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
    ifstream myfile("input.txt");
    ll n, dis, cap;
    myfile >> n >> dis >> cap;
    vector<ll> v(n + 2);
    v[0] = 0;
    for(int i = 1; i < n + 1; i++) {
        myfile >> v[i];
    }
    v[n + 1] = dis;
    ll cnt = 0;
    ll current = cap;
    for(int i = 0; i < n + 1; i++) {
        //cout << v[i] << " ";
        if(v[i + 1] - v[i] > current) {
            cnt++;
            current = cap - (v[i + 1] - v[i]);
        }
        else {
            current = current - (v[i + 1] - v[i]);
        }
        //cout << current <<  " ";
    }
    cout << cnt;
    return 0;
}