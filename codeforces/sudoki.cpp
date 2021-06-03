#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, b) for(int i = 0; i < b; i++)
#define repr(i, b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<vector<vector<int>>> data(9, vector<vector<int>>(9));
vector<vector<int>> ans(9, vector<int>(9));
vector<vector<int>> v(9, vector<int>(9));
vector<vector<bool>> constant(9, vector<bool>(9, false));
pair<int, int> last;
void rec(int i, int j, vector<map<int, bool>> row, vector<map<int, bool>> column, vector<vector<map<int, bool>>> rc) {
    if(j == 9) {
        j = 0;
        i++;
    }
    if(i == 9) return;
    if(constant[i][j]) {
        rec(i, j + 1, row, column, rc);
    }
    else {
            // for(int k = 0; k < data[i][j].size(); k++) {
            int val = data[i][j][k];
            int k1 = i / 3;
            int k2 = j / 3;
            //cout << i <<" " << j << " (1) " << data[i][j][k] << " r:" << row[i][val] << " c:" << column[j][val] << " " << rc[i / 3][j / 3][val] << endl;
            
            if(row[i][val] == false && column[j][val] == false && rc[k1][k2][val] == false) {
              //cout << i <<" " << j << " [2] " << data[i][j][k] << " r:" << row[i][val] << " c:" << column[j][val] << " " << rc[i / 3][j / 3][val] << endl;
                ans[i][j] = val;
                row[i][val] = true;
                column[j][val] = true;
                rc[k1][k2][val] = true;
                rec(i, j + 1, row, column, rc);
                if(ans[last.first][last.second] != 0) return;
                ans[i][j] = 0;
                row[i][val] = false;
                column[j][val] = false;
                rc[k1][k2][val] = false;

            }
        }
    }
}
signed main(){
    vector<map<int, bool>> row(9);
    vector<map<int, bool>> column(9);
    vector<vector<map<int, bool>>> threeTotree(3, vector<map<int, bool>>(3));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> v[i][j];
            int val = v[i][j];
            if(val != 0) {
                constant[i][j] = true;
            } else {
                last.first = i;
                last.second = j;
            }
            column[j][val] = true;
            row[i][val] = true;
            int k1 = i / 3;
            int k2 = j / 3;
            threeTotree[k1][k2][val] = true;
        }
    }
    ans = v;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(v[i][j] == 0) {
                for(int k = 1; k <= 9; k++) {
                    int k1 = i / 3;
                    int k2 = j / 3;
                    if(column[j][k] == false && row[i][k] == false && threeTotree[k1][k2][k] == false) {
                        data[i][j].push_back(k);
                    }
                }
            }
        }
    }

    rec(0, 0, row, column, threeTotree);
    cout << "--------" << endl;
    for(int i = 0; i < 9; i++) {
        cout << "{";
        for(int j = 0; j < 9; j++) {
            cout << ans[i][j] << ", ";
        }
        cout << "},";
        cout << endl;
    }

}