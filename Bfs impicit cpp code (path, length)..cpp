#include<bits/stdc++.h>
using namespace std;

using state = pair<int,int>;
#define F first
#define S second


int n,m;
vector<string> arr;

bool valid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!='#')return 1;
    return 0;
}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<state> neighbours(state cur){
    vector<state> neigh;
    for(int dir=0;dir<4;dir++){
        int nx = cur.F + dx[dir];
        int ny = cur.S + dy[dir];
        if(valid(nx,ny)){
            neigh.push_back({nx,ny});
        }
    }
    return neigh;
}

#define INF 100
queue<state> q;
vector<vector<int>> vis, dist;
vector<vector<state>> par;

void bfs(state st){
    vis.assign(n,vector<int>(m,0));
    dist.assign(n,vector<int>(m,INF));
    par.assign(n,vector<state>(m,{-1,-1}));

    // Add the source
    dist[st.F][st.S]=0;
    q.push(st);

    while(!q.empty()){
        // Pop from queue and mark visited.
        state cur = q.front();
        q.pop();

        if(vis[cur.F][cur.S])continue;
        vis[cur.F][cur.S]=1;

        // Relax the neighbours.
        for(auto v:neighbours(cur)){
            if(!vis[v.F][v.S] && dist[v.F][v.S] > dist[cur.F][cur.S] + 1){
                dist[v.F][v.S] = dist[cur.F][cur.S] + 1;
                par[v.F][v.S] = cur;
                q.push(v);
            }
        }
    }
}


void solve(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    state st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                st = {i,j};
            }else if(arr[i][j]=='B'){
                en = {i,j};
            }
        }
    }

    bfs(st); // SSSP
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }

    if(vis[en.F][en.S]){
        cout<<"YES\n";
        cout<<dist[en.F][en.S]<<endl;

        // find the path
        state cur=en;
        vector<state> path;
        while(cur!=make_pair(-1,-1)){
            path.push_back(cur);
            cur = par[cur.F][cur.S];
        }
        reverse(path.begin(),path.end());
        for(auto v:path){
            cout<<v.F<<" "<<v.S<<endl;
        }

    }else{
        cout<<"NO\n";
    }



    // cout<<st.F<<" "<<st.S<<endl;
    // cout<<en.F<<" "<<en.S<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
