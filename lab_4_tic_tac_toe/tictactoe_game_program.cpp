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
int poss_win(int turn_char)
{
    int val = turn_char*turn_char*2;
    for(int i=0;i<3;i++)
    {
        int x = board[i*3] * board[i*3 + 1] * board[i*3 + 2];
        int y = board[i] * board[i + 3] * board[i + 6];
    
        if(x == val || y==val )
        {
          for(int j=0;j<3;j++)
          {
            if(board[(i*3) + j] == 2 && x==val){return (i*3) + j;}
            if(board[i + (3*j)] == 2 && y==val){return i + (3*j);}
          }
        }
    }
    int z1 = board[4]*board[0]*board[8];
    int z2 = board[4]*board[2]*board[6];
    if(z1 == val || z2 == val)
    {
      for(int j=0;j<3;j++)
      {
        if(board[4*j] == 2 && z1 == val){return 4*j;}
        if(board[2 + (2*j)] == 2 && z2 == val){return 2 + (2*j);}
      }
    }
    return 0;
}
int check_win()
{
    for(int i=0;i<3;i++)
    {
        int x = board[i*3] * board[i*3 + 1] * board[i*3 + 2];
        int y = board[i] * board[i + 3] * board[i + 6];
    
        if(x == 27 || y==27){return 1;}
        if(x == 125 || y==125){return 2;}
    }
    int z1 = board[4]*board[0]*board[8];
    int z2 = board[4]*board[2]*board[6];
    if(z1 == 27 || z2 == 27){return 1;}
    if(z1 == 125 || z2 == 125){return 2;}
    return 0;
}
void user_move()
{
    print_board();
    cout<<"enter your move here with 1 based indexing"<<endl;
    int position;
    cin>>position;
    board[position-1] = 3;
}
int make2()
{
    for(int i=1;i<=7;i+=2)
    {
      if(board[i] == 2){return i;}
    }
}
void comp_move(int turn)
{
  switch (turn)
  {
    case 1 : 
      board[0] = 5;break;
    case 2 : 
      board[4] == 2 ? board[4] = 5 : board[0] = 5;break;
    case 3 :
      board[8] == 2 ? board[8] = 5 : board[2] = 5;break;
    default:
      if(poss_win(5)!=0)
      {
        board[poss_win(5)] = 5;
        break;
      }
      if(poss_win(3)!=0)
      {
        board[poss_win(3)] = 5;
        break;
      }
      if(turn == 5)
      {
        board[6] == 2 ? board[6] = 5 : board[2] = 5;break;
      }
      else
      {
          board[make2()] = 5;break;
      }

    }
}

void soln()
{
    cout<<"computer will always play circle"<<endl;
    cout<<"Enter 0 if you want to play first else enter 1"<<endl;
    int start;
    cin>>start;
    for(int turn = 1;turn<=9;turn++)
    {
        if(turn%2 == start)
        {
            comp_move(turn);
        }
        else
        {
            user_move();
        }

        if(check_win() == 1){cout<<"you won"<<endl;}
        if(check_win() == 2){cout<<"computer won"<<endl;}
        if(check_win() != 0)
        {
            print_board();
            return;
        }
    }
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
