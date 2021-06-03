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
    int n; cin >> n;
    int k = n - 1;
    int t = 7;
    t += k * 3;
    cout << t << endl;
    int i = 1; int j = 1;
    printf("%d %d\n", i, j);
    printf("%d %d\n", i, j + 1);
    printf("%d %d\n", i + 1, j);
    printf("%d %d\n", i + 1, j + 1);
    i++;
    j++;
    while(n--) {
        printf("%d %d\n", i, j + 1);
        printf("%d %d\n", i + 1, j);
        printf("%d %d\n", i + 1, j + 1);
        i++;
        j++;
    }
    return 0;
}