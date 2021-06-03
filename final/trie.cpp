#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;

const int MID = 1e5 + 3;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
int vn = 1;
int to[26][MID];
int cnt[MID];

void add(string &s){
  int n = s.size();
  int v = 1;
  for(int i = 0; i < n; ++i){
    char c = s[i] - 'a';
    if(to[c][v] == 0){
      to[c][v] = ++vn;
    }
    v = to[c][v];
    cnt[v]++;
  }
}

int countPrefix(string &t){
  int m = t.size();
  int v = 1;
  for(int i = 0; i < m; ++i){
    char c = t[i] - 'a';
    if(to[c][v] == 0){
      return 0;
    }
    v = to[c][v];
  }
  return cnt[v];
}

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    add(s);
  }
  for(int i = 0; i < m; ++i){
    string t;
    cin >> t;
    cout << countPrefix(t) << "\n";
  }
}