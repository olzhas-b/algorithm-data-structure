#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
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
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);

const long long mod = (long long)1e9 + 7;
const int N = 5001;
long long dp[N], CN[N][N];
long long binaryPower(long long x, long long n) {
    long long ans = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}   
void calculateCN() {
    CN[0][0] = 1;
    for(int i = 1; i < N; i++) {
        CN[i][0] = 1;
        for(int j = 1; j < N; j++) {
            CN[i][j] = CN[i - 1][j - 1] + CN[i - 1][j];
            CN[i][j] %= mod;
        }
    }
}
int main(){
    calculateCN();
    dp[0] = 1;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int k = i * (i - 1) / 2;
        int res = binaryPower(2, k);
        for(int j = 0; j < i; j++) {
            res -= dp[j] * CN[i][j] % mod;
            if(res < 0) {
                res += mod;
            }
        }
        dp[i] = res;
    }
    long long ans = dp[n - 1] * n % mod;
    cout << ans;
    return 0;
}