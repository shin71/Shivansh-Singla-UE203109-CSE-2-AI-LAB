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
int n,start;
vector<vector<int>> adj;
vector<bool> visited;
void BFS()
{
    cout<<"BFS processing order"<<endl;
    
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(q.size()!=0)
    {
        int ver = q.front();q.pop();
        cout<<"father "<<ver<<endl;
        for(auto child:adj[ver])
        {
            if(visited[child]){continue;}
            visited[child] = true;
            cout<<"non visited child of "<<ver<<" is "<<child<<endl;
            q.push(child);
        }
    }
}
void dfs(int u = start)
{
    visited[u] = true;
    cout<<u<<"->";
    for(auto v:adj[u])
    {
        if(visited[v]){continue;}
        dfs(v);
    }
}
void soln()
{
    int e;
    cout<<"Input the number of nodes and edges"<<endl;
    cin>>n>>e;
    adj = vector<vector<int>> (n);
    visited  = vector<bool> (n,false);
    for(int i=0;i<e;i++)
    {
        cout<<"enter an edge"<<endl;
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){sort(all(adj[i]));}
    cout<<"input starting node b/w 0 and "<<n-1<<endl;
    cin>>start;

    string func;
    cout<<"enter the order of processing bfs or dfs in lowercase"<<endl;
    cin>>func;
    (func == "bfs") ? BFS():dfs();
    if(func == "dfs"){cout<<endl<<"ignore the last arrow in case of dfs"<<endl;}
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
