#include <iostream>
#include <vector>
#include <set>

typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
ll  dp[5005], fact[5005];

ll bp(ll a, ll n){
  ll res = 1;
  while(n){
    if(n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll C[5005][5005];


int main() {
    fact[0] = 1;
    for(int i = 1; i <= 5000; ++i){
      fact[i] = fact[i - 1] * i % mod;
    }
    dp[0] = 1;
    C[0][0] = 1;
    for(int n = 1; n <= 5000; n++) {
      C[n][0] = C[n][n] = 1;
      for(int k = 1; k <= n; k++) {
        C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;
      }
    }

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
      dp[i] = bp(2, i * (i - 1) / 2);
      for(int j = 0; j < i; ++j){
        dp[i] -= dp[j] * C[i][j] % mod;
        if(dp[i] < 0) dp[i] += mod;
      }
    }
    cout << dp[n - 1] * n % mod;
}