#include<bits/stdc++.h>
using namespace std;
vector<int> kmp (string s) {
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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pi1 = kmp(s);
    string ans = "";
    int last = pi1[n - 1];
    if(last > 0){
        for(int i = 0; i < last; i++){
            ans += s[i];
        }
        string pattern = "";
        for(int i = last; i < n - last; i++){
            pattern += s[i];
        }
        string s2 = pattern;
        pattern = ans + '#' + s2;
        int n = pattern.size();
        vector<int> pi2  = kmp(ans + '#' + s2);
        for(int i = 0; i < n; i++) {
            if(ans.size() == pi2[i]) {
                cout << ans;
                return 0;
            }
        }
    }
    cout << "Just a legend";  
    
}