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
    int cnt = 0;
    map<int, int> m;
    for(int i = 2; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(i * j <= n) {
                m[i * j]++;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(m[i] == 1) cnt++;
    }
    cout << cnt;
}