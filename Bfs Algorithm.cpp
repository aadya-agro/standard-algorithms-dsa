#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;
void bfs(int sc_node){
    queue<int> q;
    vis[sc_node] = 1;
    q.push(sc_node);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto v : g[node]){
            if(!vis[v]){
                vis[v] =1;
                q.push(v);
            }
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
            bfs(i);
         
        }

    }
    cout << << endl;
   
       return 0;
}