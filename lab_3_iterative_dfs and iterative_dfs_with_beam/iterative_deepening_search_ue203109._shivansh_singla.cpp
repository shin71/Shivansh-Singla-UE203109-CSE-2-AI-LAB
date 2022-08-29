/*shivansh singla
    ue203109
    cse 2*/
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define output(a) cout<<a<<endl;
#define outputv(arr) for(auto i:arr){cout<<i<<" ";}cout<<endl;
#define outputp(a) cout<<a.first<<" "<<a.second<<endl;
#define all(v) v.begin(), v.end()
#define yes cout<<"YES"<<endl;return;
#define no cout<<"NO"<<endl;return;
#define pii pair<int,int>
using ll = long long;
const ll MOD = 1e9 + 7;
using namespace std;
void iterative_deepening_search(auto &adj,int u,int depth,auto &visited)
{
    if(depth<=0){return;}
    visited[u] = true;
    cout<<u<<" ";
    for(auto child:adj[u])
    {
        if(visited[child]){continue;}
        iterative_deepening_search(adj,child,depth - 1,visited);
    }
    return;
}
void soln()
{
    int n,edges;
    cin>>n>>edges;
    vector<vector<int>> adj(n);
    while(edges--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int depth = 1;depth<=3;depth++)
    {
        cout<<"depth of search here is"<<endl;
        cout<<depth <<endl;
        cout<<"order of processing here is"<<endl;
        vector<bool> visited(n,false);
        iterative_deepening_search(adj,0,depth,visited);
        cout<<endl<<".........."<<endl;
    }
  

}

signed main() {
#ifdef LOCAL_PROJECT
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 freopen("error.txt", "w", stderr);
#endif
IOS
ll t;
t=1;
//cin>>t;  
while(t--)  
{
 soln();  
}
return 0;
}
