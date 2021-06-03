#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix;
vector<bool> visited;
vector<set<int>> answer;
set<int> st;
void dfs(int v) {
    visited[v] = true;
    st.insert(v);
    for(int i = 1; i <= matrix[v].size(); i++) {
        if(visited[i] == false && matrix[v][i] == 1) {
            st.insert(i);
            dfs(i);
        }
    }
}
int main(){
    int n, m; cin >> n >> m;
    matrix = vector<vector<int>> (n + 1, vector<int> (n + 1));
    visited = vector<bool> (n + 1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] == false) {
            dfs(i);
            answer.push_back(st);
            st.clear();
        }
    }
    cout << answer.size() << endl;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == false) {
            set<int> s;
            s.insert(i);
            answer.push_back(s);
        }
    }
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].size() << " ";
        for(auto it = answer[i].begin(); it != answer[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}