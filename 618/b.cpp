#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m; cin >> m;
    for(int q = 0; q < m; q++){
        int n; cin >> n;
        int a[2 * n];
        for(int i = 0; i < 2 * n; i++){
            cin >> a[i];
        }
        sort(a, a + (2 * n));
        cout << a[n] - a[n-1] << endl; 
    }   
}