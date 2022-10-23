/* Shivansh Singla
    UE203109
    CSE 2*/
#include <iostream>
#include <map>
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
int calls = 0;
vector<int> board(9,2);
void print_board()
{
    map<int,char> mp;
    mp[2] = '_',mp[3] = 'X',mp[5] = 'O';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<mp[board[3*i + j]]<<" ";
        }
        cout<<endl;
    }
}
void user_move()
{
    print_board();
    cout<<"enter your move here with 1 based indexing"<<endl;
    int position;
    cin>>position;
    board[position-1] = 3;
}
int check_win()
{
    for(int i=0;i<3;i++)
    {
        int x = board[i*3] * board[i*3 + 1] * board[i*3 + 2];
        int y = board[i] * board[i + 3] * board[i + 6];
    
        if(x == 27 || y==27){return -10;}
        if(x == 125 || y==125){return 10;}
    }
    int z1 = board[4]*board[0]*board[8];
    int z2 = board[4]*board[2]*board[6];
    if(z1 == 27 || z2 == 27){return -10;}
    if(z1 == 125 || z2 == 125){return 10;}
    return 0;
}

pii minimax(bool maximizer,int alpha,int beta,int depth,bool alpha_beta_pruning)
{
    calls++;
    //this means someone has won i.e we have reached a leaf node
    if(check_win()!=0){return make_pair(check_win(),-1);}
    bool con = true;
    for(int i=0;i<=8;i++)
    {
        if(board[i]!=2){continue;}
        con = false;
        break;
    }
    if(con || depth==0)
    {   //this means leaf node or we reached our max depth allowed
        return make_pair(check_win(),-1);
    }
    
    if(maximizer)
    {
        int fin_mov = -1;
        for(int i=0;i<9;i++)
        {
            if(board[i]!=2){continue;}
            board[i] = 5;
            auto [score,move] = minimax(false,alpha,beta,depth-1,alpha_beta_pruning);
            board[i] = 2;
            if(score > alpha){fin_mov = i;}
            alpha = max(alpha,score);
            if((alpha >= beta) && alpha_beta_pruning)
            {
                return make_pair(alpha,fin_mov);
            }
        }
        return make_pair(alpha,fin_mov);
    }
    else
    {
        int fin_mov = -1;
        for(int i=0;i<9;i++)
        {
            if(board[i]!=2){continue;}
            board[i] = 3;
            auto [score,move] = minimax(true,alpha,beta,depth-1,alpha_beta_pruning);
            board[i] = 2;
            if(score < beta){fin_mov = i;}
            beta = min(beta,score);
            if((alpha >= beta) && alpha_beta_pruning)
            {
                return make_pair(beta,fin_mov);
            }
        }
        return make_pair(beta,fin_mov);
    }
    
}

void soln()
{
    bool alpha_beta_pruning = false;int in=0;
    cout<<"do you want alpha beta pruning enter 1 for yes"<<endl;
    cin>>in;if(in==1){alpha_beta_pruning = true;}
    cout<<"enter depth"<<endl;
    int depth;
    cin>>depth;
    
    cout<<"computer will always play circle"<<endl;
    cout<<"Enter 0 if you want to play first else enter 1"<<endl;
    int start;
    cin>>start;
    
    for(int turn = 1;turn<=9;turn++)
    {
        if(turn%2 == start)
        {
            board[minimax(true,-10,10,depth,alpha_beta_pruning).second] = 5;
        }
        else
        {
            user_move();
        }
        if(check_win() == -10){cout<<"you won"<<endl;}
        if(check_win() == 10){cout<<"computer won"<<endl;}
        if(check_win() != 0)
        {
            print_board();
            cout<<"calls to minimax function"<<endl;
            cout<<calls<<endl;
            return;
        }
    }
    print_board();
    cout<<"it is a draw"<<endl;
    cout<<"calls to minimax function"<<endl;
    cout<<calls<<endl;
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
