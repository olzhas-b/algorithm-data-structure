#include <bits/stdc++.h>
using namespace std;

const long long mod = (long long)1e9 + 7;
const int N = 505;    

vector<int> g1[N], g2[N], ans[N], result[N];
vector<int> vTopSort, current;
int n;
int c[N], csize[N];
int d[N][N];
int visited[N];

char a[N][N];

void dfsWithTopSort(int x) {
    visited[x] = true;
    for(int i = 0; i < g1[x].size(); i++) {
        if(visited[g1[x][i]] == false) {
            dfsWithTopSort(g1[x][i]);
        }
    }
    vTopSort.push_back(x);
}
void dfs(int x) {
    visited[x] = true;
    current.push_back(x);
    for(int i = 0; i < g2[x].size(); i++) {
        int to = g2[x][i];
        if(visited[to] == false) {
            dfs(to);
        }
    }
}
bool check(int i, int j, char ch) {
    if(ch == '!') {
        for(int k = 0; k < result[i].size(); k++) {
            int to = result[i][k];
            if(d[j][to] == false) return true;
        }
        return false;
    } else if(ch == '^') {
        for(int k = 0; k < result[j].size(); k++) {
            int to = result[j][k];
            if(d[i][to] == false) return true;
        }
        return false;
    } else if(ch == '=') {
        if(result[i] == result[j]) return true;
        return false;
    } else if(ch == '<'){
        for(int k = 0; k < result[i].size(); k++) {
            int to = result[i][k];
            if(d[j][to] == false) return false;
        }
        return true;
    } else if(ch == '>') {
        for(int k = 0; k < result[j].size(); k++) {
            int to = result[j][k];
            if(d[i][to] == false) return false;
        }
        return true;
    }  
    return true;
}
int main() {
    cin >> n;
    vector<pair<int, int>> e;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == '<') {
                e.push_back({j, i});
                g1[j].push_back(i);
                g2[i].push_back(j);
            } else if(a[i][j] == '>') {
                e.push_back({i, j});
                g1[i].push_back(j);
                g2[j].push_back(i);
            } else if(a[i][j] == '=') {
                g1[i].push_back(j);
                g1[j].push_back(i);
                g2[i].push_back(j);
                g2[j].push_back(i);
                e.push_back({i, j});
                e.push_back({j, i});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] == false) {
            dfsWithTopSort(i);
        }
    }
    


    reverse(begin(vTopSort), end(vTopSort));
    int position = 0;
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        g1[i].clear();
    }
    for(int k = 0; k < vTopSort.size(); k++) {
        int tar = vTopSort[k];
        if(visited[tar] == false) {
            position++;
            dfs(tar);
            for(int q = 0; q < current.size(); q++) {
                int to = current[q];
                c[to] = position;
                csize[position] = current.size();
                current.clear();
            }
        }
    }
    vTopSort.clear();
    map<pair<int, int>, bool> used;
    vector<int> degree(n + 1);

    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        g1[i].clear();
        g2[i].clear();
    }
    for(int i = 0; i < e.size(); i++) {
        int u = c[e[i].first];
        int v = c[e[i].second];
        if(used[{u, v}] == false && u != v) {
            degree[u]++;
            used[{u, v}] = true;
            g1[u].push_back(v);
            g2[v].push_back(u);
        }
    }
    int loc = 1;

    vector<int> q;
    for(int i = 0; i <= position; i++) {
        if(degree[i] == false) {
            q.push_back(i);
        }
    }

    while(!q.empty()) {
        int f = q.back();
        q.pop_back();
        int next = loc + 1;
        for(int i = loc; i < next; i++) {
            ans[f].push_back(i);
        }
        for(int i = 0; i < g1[f].size(); i++) {
            int to = g1[f][i];
            for(int j = 0; j < ans[to].size(); j++) {
                ans[f].push_back(ans[to][j]);
            }
        }
    
        sort(begin(ans[f]), end(ans[f]));
        ans[f].resize(unique(begin(ans[f]), end(ans[f])) - begin(ans[f]));
        loc = next;


        for(int i = 0; i < g2[f].size(); i++) {
            degree[g2[f][i]]--;
            if(degree[g2[f][i]] == false) {
                q.push_back(g2[f][i]);
            } 
        }
    }
 

    for(int i = 1; i <= n; i++) {
        for(int j: ans[c[i]]) {
            result[i].push_back(j);
            d[i][j] = true;
        }
    }

    bool yes = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(check(i, j, a[i][j]) == false) {
                yes = false;
                cout << "No" << endl;
                return 0;
            }
        }
    }
  
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++) {
        cout << result[i].size() << " ";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
