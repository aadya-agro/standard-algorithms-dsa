#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;
void dfs(int node){
    vis[node] = 1;
    for(auto v : g[node]){
            if(!v[node]){
                dfs(v);
            }
        
    }
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n+1,0);
  
    for(int i =1; i<=n ;i++){
        if(!vis[i]){
            dfs(i);
         
        }

    }
    cout << << endl;
   
       return 0;
}