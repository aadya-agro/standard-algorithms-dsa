//dfs cycle detection code
#include <bits/stdc++.h>  
using namespace std;

vector<vector<int>> g;
vector<int>col;
vector<int> parent;
bool is_cycle = 0;
vector<int> any_cycle;


void dfs(int node, int par){
    col[node] = 2;
    for(auto v : g[node]){
        if(col[v] == 1){
            parent[v] = node;
            // node--v is a forward edge
            dfs(v,node);
        }
        else if(col[v] == 2){
            // node--v is a back edge
            //we found a cycle
            if(is_cycle == 0){
                int temp = node;
                while(temp != v){
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
            }
            is_cycle = 1;
        }else if(col[v] == 3){
            //node--v is a cross edge
            //unimportant
        }
    }
    col[node] = 3;
}



int main(){
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i =0; i<m; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);

    }
    for(int i =1; i<=n; i++){
        if(col[i] == 1){
            dfs(i,0);
        }
    }
    
}
