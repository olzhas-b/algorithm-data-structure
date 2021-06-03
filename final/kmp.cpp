#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int main(){
    string s; cin >> s;
    vector<int> prefix_sum = prefix_function(s);
    int counter = 0;
    int size = 0;
    int n = prefix_sum.size() - 1;
    for(int i = 0; i < n; i++) {
        if((prefix_sum[i] - size) * 2 == i + 1) {
            counter++;
            size = (i +  1) / 2;
        } else if(prefix_sum[i] * 2 == i + 1) {
            counter++;
            size = (i + 1) / 2;
        }
    }
    cout << counter << endl;
    return 0;
}