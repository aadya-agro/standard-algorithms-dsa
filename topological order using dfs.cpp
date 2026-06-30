#include<bits/stdc++.h>
using namespace std;
//topological order using dfs 

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;

void dfs(int node){
    vis[node] = 1;
    for(auto v : g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i =0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i =1; i<= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(node.begin(), node.end());
    for(auto v : topo){
        cout << v << " ";
    }
    
}