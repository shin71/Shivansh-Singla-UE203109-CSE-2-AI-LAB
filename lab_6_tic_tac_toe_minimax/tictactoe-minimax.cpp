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
int check_win(int val_for_maximizer)
{
    for(int i=0;i<3;i++)
    {
        int x = board[i*3] * board[i*3 + 1] * board[i*3 + 2];
        int y = board[i] * board[i + 3] * board[i + 6];
    
        if(x == 27 || y==27){return -val_for_maximizer;}
        if(x == 125 || y==125){return val_for_maximizer;}
    }
    int z1 = board[4]*board[0]*board[8];
    int z2 = board[4]*board[2]*board[6];
    if(z1 == 27 || z2 == 27){return -val_for_maximizer;}
    if(z1 == 125 || z2 == 125){return val_for_maximizer;}
    return 0;
}
int rating(int turn_char)
{
    int x = check_win(10);
    if(x!=0){return x;}
    int maxy = -10,miny = 10;
    for(int i=0;i<=8;i++)
    {
        if(board[i]!=2){continue;}
        board[i] = turn_char;
        int r = check_win(8);
        board[i] = 2;
        maxy = max(r,maxy);
        miny = min(r,miny);
    }
    if(turn_char == 3 && maxy == 8){return maxy;}
    if(turn_char == 3 && maxy < 8){return miny;}
    if(turn_char == 5 && miny==-8){return miny;}
    if(turn_char == 5 && miny>-8){return maxy;}
    return 0;
    
}
int minimax(bool maximizer,int depth)
{
    bool con = true;
    for(int i=0;i<=8;i++)
    {
        if(board[i]!=2){continue;}
        con = false;//means we have reached the leaf node
        break;
    }
    if(con){return check_win(10);}
    if(depth==0)
    {   int turn_char = ((!maximizer)*5) + (maximizer*3);//this tells where was the last call from
        return rating(turn_char);
    }
    if(maximizer)
    {
        int score = -10;
        for(int i=0;i<=8;i++)
        {
            if(board[i]!=2){continue;}
            board[i]  = 5;
            score = max(score,minimax(false,depth - 1));
            board[i] = 2;
        }
        return score;
    }
    else
    {
        int score = 10;
        for(int i=0;i<=8;i++)
        {
            if(board[i]!=2){continue;}
            board[i]  = 3;
            score = min(score,minimax(true,depth - 1));
            board[i] = 2;
        }
        return score;
    }

}

void comp_move(int depth)
{
    pair<int,int> score_move = {-1000,-1000};
    for(int i=0;i<=8;i++)
    {
        if(board[i] != 2){continue;}
        board[i] = 5;
        int score = minimax(false,depth - 1);
        board[i] = 2;
        score_move = max(score_move,make_pair(score,i));
    }
    board[score_move.second] = 5; 
}

void soln()
{
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
            comp_move(depth);
        }
        else
        {
            user_move();
        }
        if(check_win(10) == -10){cout<<"you won"<<endl;}
        if(check_win(10) == 10){cout<<"computer won"<<endl;}
        if(check_win(10) != 0 )
        {
            print_board();
            return;
        }
    }
    print_board();
    cout<<"it is a draw"<<endl;
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
