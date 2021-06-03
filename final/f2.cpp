#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
using namespace std;


int main(){
    string target; cin >> target;
    int n; cin >> n;
    unordered_map<string, int> sozdyk; 
    for(int i = 0; i < n; i++) {
        string soz; cin >> soz;
        sozdyk[soz]++;
    }
    bool possible = false;
    string left = "";
    for(int i = 0; i < target.size() - 1; i++) {
        left += target[i];
        if(sozdyk[left] && sozdyk[target.substr(i + 1, target.size())]) possible = true;
    }
    if(possible) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}