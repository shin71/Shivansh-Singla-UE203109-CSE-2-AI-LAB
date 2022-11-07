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
vector<vector<pii>> adj;
map<int,int> h;
void a_star_algo(int start,int goal)
{
    set<int> open = {start};
    set<int> closed;
    map<int,int> g;
    map<int,int> parent;

    g[start] = 0;
    parent[start] = -1;

    while( open.size() > 0)
    {
        int curr = -1;
        for(auto v:open)
        {
            if(curr==-1)
            {
                curr = v;
            }
            else if(g[v] + h[v] < g[curr] + h[curr])
            {
                curr = v;
            }
        }
        if(curr == goal)
        {
            cout<<"path found"<<endl;
            while(true)
            {
                cout<<curr;
                curr = parent[curr];
                if(curr == -1){cout<<endl;return;}
                cout<<"<-";
            }
            
        }
        else
        {
            for(auto [v,weight]:adj[curr])
            {
                if(closed.find(v)!=closed.end())
                {
                    closed.erase(v);
                    if (g[v] > g[curr] + weight)
                    {
                        g[v]  = g[curr] + weight;
                        parent[v] = curr;
                    }
                    open.insert(v);
                }
                else if(open.find(v)!=open.end())
                {
                    if (g[v] > g[curr] + weight)
                    {
                        g[v]  = g[curr] + weight;
                        parent[v] = curr;
                    }
                }
                else
                {
                    open.insert(v);
                    g[v] = g[curr] + weight;
                    parent[v] = curr;
                }
                
            }
        }
        open.erase(curr);
        closed.insert(curr);

    } 

}
void soln()
{
    cout<<"enter number of nodes and edges"<<endl;
    int n,e;
    cin>>n>>e;
    cout<<"enter nodes of edges and weight in u v w format"<<endl;
    adj  = vector<vector<pii>> (n+1);
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    cout<<"enter start and goal node"<<endl;
    int start,goal;cin>>start>>goal;
    cout<<"enter nodes and their heuristic values to goal,press -1 -1 to stop the input"<<endl;
    for(int i=1;i<=n;i++){h[i] = INT_MAX;}
    while(true)
    {
        int u,he;
        cin>>u>>he;
        if(u==-1){break;}
        h[u] = he;
    }
    h[goal] = 0;
    a_star_algo(start,goal);
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
