/* shivansh singla
    ue203109
    cse 2
*/
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
void beam(auto &adj,int n,int max_search)
{
    vector<bool> visited(n,false);
    int root = 0;
    queue<int> q;
    q.push(root);
    visited[root] = true;
    cout<<"order of processing"<<endl;
    while(q.size()!=0)
    {
        int node = q.front();
        q.pop();
        
        int added = 0;
        cout<<node<<" ";
        for(auto child:adj[node])
        {
            if(visited[child]){continue;}
            visited[child] = true;
            q.push(child);
            added++;
            if(added == max_search){break;}
        }
    }

}
void soln()
{
    vector<vector<int>> graph ={{0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
                             {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 
         {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, 
         {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, 
         {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, 
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}};
    int n = graph.size();
    vector<vector<int>> adj(graph.size());
    
    for(int u=0;u<n;u++)
    {
        for(int v=0;v<n;v++)
        {
            if(graph[u][v] == 0){continue;}
            adj[u].push_back(v);
        }
    }

    int max_search  = 3;
    while(max_search)
    {
        cout<<"width of beam "<<max_search<<endl;
        beam(adj,n,max_search);
        cout<<endl<<"......."<<endl;
        max_search--;
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
