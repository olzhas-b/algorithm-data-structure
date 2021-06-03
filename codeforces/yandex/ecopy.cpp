# include <bits/stdc++.h>
# define sz(x) (int)x.size()
# define f first
# define s second

using namespace std;
using ll = long long;

const int N = 505;

vector<int> g[N], G[N], tops, cur, ans[N], res[N];
int used[N], comp[N], compsz[N], cont[N][N], n;
char c[N][N];

void dfs(int x){
  used[x] = 1;
  for(auto to : g[x])
      if(!used[to])
        dfs(to);
  tops.push_back(x);
}

void dfs2(int x){
    used[x] = 1;
    cur.push_back(x);
    for(int to : G[x]){
      if(!used[to])
        dfs2(to);
    }
}

void solve() {
  cin >> n;
  vector<pair<int, int> > edges;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
        cin >> c[i][j];
        if(c[i][j] == '='){
            g[i].push_back(j);
            g[j].push_back(i);
            G[i].push_back(j);
            G[j].push_back(i);
            edges.push_back({i, j});
            edges.push_back({j, i});
        
        }
        else if(c[i][j] == '<'){
          g[j].push_back(i);
          G[i].push_back(j);
          edges.push_back({j, i});
        
        }
        else if(c[i][j] == '>'){
          g[i].push_back(j);
          G[j].push_back(i);
          edges.push_back({i, j});
        }
    }
  }
  auto isGood = [&](int i, int j, char c){
    if(c == '=') return (res[i] == res[j]);
    if(c == '<'){
      for(int x : res[i])
        if(!cont[j][x])
          return false;
      return true;
    }
    if(c == '>'){
      for(int x : res[j])
        if(!cont[i][x])
          return false;
      return true;
    }
    if(c == '!'){
      for(int x : res[i])
        if(!cont[j][x])
          return true;
      return false;
    }
    if(c == '^'){
      for(int x : res[j])
       if(!cont[i][x])
          return true;
      return false;
    }
    return true;
  };
  for(int i = 1; i <= n; ++i)
    if(!used[i])
      dfs(i);
  reverse(begin(tops), end(tops));

  int p = 0;
  for(int i = 1; i <= n; ++i)
    used[i] = 0, g[i].clear();
    for(int v : tops){
      if(!used[v]){
        p++; 
        dfs2(v);
        for(int to : cur)
          comp[to] = p;
          compsz[p] = cur.size();
          cur.clear();
        }
      }
      tops.clear();
      map<pair<int, int>, bool> u;
      vector<int> deg(n + 1);
      tops.clear();
      for(int i = 1; i <= n; ++i)
        used[i] = 0, g[i].clear(), G[i].clear();
      for(pair<int, int> &e : edges){
        int x = comp[e.first];
        int y = comp[e.second];
        if(!u[make_pair(x, y)] and x != y){
          deg[x]++;
          u[make_pair(x, y)] = 1;
          g[x].push_back(y);
          G[y].push_back(x);
        }
      }
      int pre = 1;
      vector<int> d;
      for(int i = 1; i <= p; ++i){
        if(!deg[i]){
          d.push_back(i);
        }
      }
      while(!d.empty()){
        int c = d.back();
        d.pop_back();
        int nxt = pre + 1;
        for(int j = pre; j < nxt; ++j){
          ans[c].push_back(j);
        }
        for(int to : g[c]){
          for(int u : ans[to])
            ans[c].push_back(u);
        }
        sort(begin(ans[c]), end(ans[c]));
        ans[c].resize(unique(begin(ans[c]), end(ans[c])) - begin(ans[c]));
        pre = nxt;
        for(int par : G[c]){
          deg[par]--;
          if(!deg[par]){
            d.push_back(par);
          }
        }
    }
    for(int i = 1; i <= n; ++i){
      for(int j : ans[comp[i]]){
        res[i].push_back(j);
        cont[i][j] = 1;
      }
    }

    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        if(!isGood(i, j, c[i][j])){
          cout << "No\n";
          return;
        }
      }
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; ++i){
      cout << res[i].size() << ' ';
      for(int j : res[i]){
        cout << j << ' ';
      }
      cout << '\n';
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //int t; cin >> t; while (t--) 
  solve();
}