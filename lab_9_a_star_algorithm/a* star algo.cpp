/* Shivansh Singla
    UE203109
    CSE 2*/
#include <iostream>
#include <map>
#include <vector>
#include <set>
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
                    
                    if (g[v] > g[curr] + weight)
                    {
                        g[v]  = g[curr] + weight;
                        parent[v] = curr;
                        closed.erase(v);
                        open.insert(v);
                    }
                    
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
    cout<<"path not found"<<endl;

}
void soln()
{
    vector<vector<int>> graph ={{0, 6, 3, 1, 0, 0, 0, 0, 0, 0}, 
        {6, 0, 2, 6, 3, 4, 0, 0, 0, 0}, 
        {3, 2, 0, 0, 4, 5, 0, 0, 0, 0}, 
        {1, 6, 0, 0, 7, 8, 9, 0, 0, 0}, 
        {0, 3, 4, 7, 0, 6, 9, 9, 0, 0}, 
        {0, 4, 5, 8, 6, 0, 8, 9, 0, 0}, 
        {0, 0, 0, 9, 9, 8, 0, 11, 12, 14}, 
        {0, 0, 0, 0, 9, 9, 11, 0, 14, 15}, 
        {0, 0, 0, 0, 0, 0, 12, 14, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 14, 15, 0, 0}};
    
    adj = vector<vector<pii>> (graph.size() + 1);
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph.size();j++)
        {
            if(graph[i][j] == 0){continue;}
            adj[i+1].push_back( {j+1,graph[i][j]} );
        }
    }
    h = {{1,15},{2,13},{3,13},{4,12},{5,10},{6,9},{7,7},{8,6},{9,5},{10,0}};
    
    //This code is for interaction if want to use for custom graphs
    /*cout<<"enter number of nodes and edges"<<endl;
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
    h[goal] = 0;*/
    a_star_algo(1,10);
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
