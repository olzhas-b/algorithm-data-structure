#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <string>
#include <map>
#include <set>
#include <deque>
using namespace std;
int main(){
 
    int n; cin >> n;
    // vector<bool> prime(n + 1, true);
    // vector<int> data(n + 1);
    // prime[0] = false;
    // prime[1] = false;
    // for(int i = 2; i <= n; i++) {
    //     if(prime[i]) {
    //         for(int j = 2 * i; j <= n; j+=i) {
    //             data[j]++;
    //             prime[j] = false;
    //         }
    //     }
    // }
    // int cnt =0;
    // for(int i = 4; i <= n; i++) {
    //     cout << i << " " << data[i] << endl;
    // }
    int cnt = 0;
    for(int i = 4; i <= n; i++) {
        int k = i;
        int sum  = 0;
        map<int, int> m;
        for(int j = 2; j <= k; j++) {
            if(k % j == 0) {
                while(k % j == 0) {
                    k /= j;
                    m[j]++;
                    sum++;
                }
                if(m.size() > 2) break; 
            }
        }
        if(k != 1) {
            sum++;
            m[k]++;
        } 
        if(m.size() == 1 || (m.size() == 2 && sum == 2)) {
            cnt++;
            cout << i << endl;
        }
    }
    cout << cnt;
}