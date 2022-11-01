/* Shivansh Singla
    UE203109
    CSE 2*/
#include <iostream>
#include<chrono>
#include <vector>
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
vector<int> dx = {+2,-2};
vector<int> dy = {+1,-1};
int n,m,k;
int ans = 0;
bool print = false;
void place(int curr_row,int curr_col,int k,auto &board)
{
    if(k == 0)
    {
        ans++;
        for(int i=2;i<=n+1 && print;i++)
        {
            for(int j=2;j<=m+1 && print;j++)
            {
                cout<<(board[i][j] == 'K' ? 'K':'E')<<" ";
            }
            cout<<endl;
        }
        if(print){cout<<"......"<<endl;}
        return;
    }
    for(int i = curr_row;i<=n+1;i++)
    {
        for(int j = curr_col;j<=m+1;j++)
        {
            if(board[i][j] != 'E'){continue;}
            auto temp_board = board;
            temp_board[i][j] = 'K';
            for(auto a1:dx)
            {
                for(auto a2:dy)
                {
                    temp_board[i + a1][j + a2] = 'A';
                    temp_board[i + a2][j + a1] = 'A';
                }
            }
            place(i,j,k-1,temp_board);
        }
        curr_col = 2;
    }
    
}
void soln()
{
    
    vector<vector<char>> board(n+4,vector<char>(m+4,'E'));
    place(2,2,k,board);
    
    cout<<"number of possible configs are:"<<endl;
    cout<<ans<<endl;
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
cout<<"enter board dimensions n*m and k i.e number of knights"<<endl;
cin>>n>>m>>k;
cout<<"do you want to print enter 1 for yes and 0 for no"<<endl;
cin>>print;
auto start = std::chrono::high_resolution_clock::now();
while(t--)  
{
 soln();  
}
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
cout << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
return 0;
}
