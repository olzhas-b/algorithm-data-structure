#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <string>
#include <map>
#include <set>
#include <deque>
using namespace std;
vector<int> v;
int calculate(int x) {
    int l = 0; 
    int r = v.size() - 1;
    while(l < r) {
        int m = l + (r - l) / 2;
        if(v[m] == x) {
            l = m + 1;
        }
        else if(v[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main(){
    int n, k; cin >> n >> k;
    v = vector<int> (n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++) {
        int ans = 0;
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        if( (l2 <= l1 && r1 <= r2) || (l1 <= l2 && l2 <= r1) || (l1 <= r2 && r2 <= r1) || (l1 <= l2 && r2 <= r1))  {
            l1 = min(l1, l2);
            r1 = max(r1, r2);
            int cnt1 = calculate(l1);
             if(v[cnt1] <= l1) cnt1++;
            int cnt2 = calculate(r1);
             if(v[cnt2] <= r1) cnt2++;
            ans += cnt2 - cnt1 + 1; 
        }
        else {
            int cnt1 = calculate(l1);
            if(v[cnt1] <= l1) cnt1++;
            int cnt2 = calculate(r1);
            if(v[cnt2] <= r1) cnt2++;
            ans += cnt2 - cnt1 + 1;
            int cnt3 = calculate(l2);
            if(v[cnt3] <= l2) cnt3++;
            int cnt4 = calculate(r1);
            if(v[cnt4] <= r2) cnt4++;;
            ans += cnt4 - cnt3 + 1;
        }
        cout << ans << endl;
    }
    return 0;
}