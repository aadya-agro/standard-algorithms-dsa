#include <bits/stdc++.h>
using namespace std;

#define F first  
#define S second

//node of the graph is i,j create a seperate data type that is state//

/*
6 6
S.#...
..#...
#.#.#.
....#.
####..
F.....
*/
// when you have space between them use vector<vector<char>> otherwise use vector<string> when space is not given in the input BEWARE OF THE SPACES 



int n,m;
vector<string> arr;
 
using state = pair<int,int>;
vector<vector<int>> vis;
vector<vector<int>> dis;  // can use map here but it uses extra logn


/* {0,0,0,0,....0} m times
{0,0,0,0,....0},
{0,0,0,0,....0},
{0,0,0,0,....0}
..... n times */


// same logic bas ye 2d grid h so we came up with neighbours and all that's it
// validity and all state kr dena according to que like wall mai nhi jana chaiyeh and all

vector<state> neighbours(state node){

}

void bfs(state st_node){
    vis.resize(n,vector<int>(m,0));
    dis.resize(n,vector<int>(m,1e9));

    queue<state> q;
    vis[st_node.F][st_node.S] = 1;
    dis[st_node.F][st_node.S] = 0;
    q.push(st_node);
    while(!q.empty()){
        state node = q.front();
        q.pop();

        for(state v : neighbours(node)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S] = 1;
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
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
    arr.resize(n);

    state st,en;
    for(int i =0; i<n; i++){
        arr[i].resize(m);
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'S'){
                st == {i,j};
            }
            else if(arr[i][j] == 'F'){
                en == {i,j};
            }
        }  
    }
    bfs(st);
    cout << dis[en.F][en.S] << endl;

    
}
