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
vector<int> magicSquare = {8,1,6,3,5,7,4,9,2};
vector<vector<int>> moves(6);
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
int check_win(vector<int> &prev_moves)
{
    for(int i=0;i+1<prev_moves.size();i++)
    {
        for(int j=i+1;j+1<prev_moves.size();j++)
        {
            for(int k=j+1;k<prev_moves.size();k++)
            {
                if(prev_moves[i] + prev_moves[j] + prev_moves[k] == 15)
                {
                    return true;
                }
            }
        
            
        }
    }
    return false;
}
int poss_win(int turn_char)
{
    for(int i=0;i<9;i++)
    {
        if(board[i] != 2){continue;}
        moves[turn_char].push_back(magicSquare[i]);
        if(check_win(moves[turn_char]))
        {
            moves[turn_char].pop_back();
            return i;
        }
        moves[turn_char].pop_back();
    }
    return -1;
}
int poss_num_of_wins(int turn_char)
{
    for(int i=0;i<9;i++)
    {
        if(board[i]!=2){continue;}
        board[i] = 3;
        moves[turn_char].push_back(magicSquare[i]);
        int m1 = poss_win(turn_char);
        if(m1 == -1){moves[turn_char].pop_back();board[i]=2;continue;}
        board[m1] = 5;
        int m2 = poss_win(turn_char);
        moves[turn_char].pop_back();
        board[m1] = 2;
        board[i] = 2;
        if(m2 != -1)
        {
           return i;
        }

    }
    return -1; 
    
}
int make2()
{
    for(int i=1;i<=7;i+=2)
    {
      if(board[i] == 2){return i;}
    }
    for(int i=0;i<=8;i+=2)
    {
        if(board[i] == 2){return i;}
    }
}
int comp_move(int turn)
{
  int move=-1;
  switch (turn)
  {
    case 1 : 
      board[0] = 5,move=0;break;
    case 2 : 
      board[4] == 2 ? move=4: move=0;board[move]=5;break;
    case 3 :
      board[8] == 2 ? move=8 : move=2;board[move]=5;break;
    default:
      //cout<<poss_win(3)<<endl;
      if(poss_win(5)!=-1)
      {
        move = poss_win(5);
        board[move] = 5;
        return move;
      }
      else if(poss_win(3)!=-1)
      {
        move = poss_win(3);
        board[move] = 5;
        return move;
      }
      else if(poss_num_of_wins(3)!=-1)
      {
          move = poss_num_of_wins(3);
          board[move] = 5;
          return move;
      }
      if(turn == 5)
      {
        board[6] == 2 ? move=6 : move=2;board[move]=5;return move;
      }
      else
      {
          move = make2();
          board[move] = 5;return move;
      }

    }
    return move;
}
int user_move()
{
    print_board();
    cout<<"enter your move here with 1 based indexing"<<endl;
    int position;
    cin>>position;
    board[position-1] = 3;
    return position-1;
}

void soln()
{
    cout<<"computer will always play circle"<<endl;
    cout<<"Enter 0 if you want to play first else enter 1"<<endl;
    int start;
    cin>>start;
    for(int turn = 1;turn<=9;turn++)
    {
        int mv = -1;
        if(turn%2 == start)
        {
            mv = comp_move(turn);
            moves[5].push_back(magicSquare[mv]);
            if(check_win(moves[5])){cout<<"computer won"<<endl;print_board();return;}
            
        }
        else
        {
            mv = user_move();
            moves[3].push_back(magicSquare[mv]);
            if(check_win(moves[3])){cout<<"you won"<<endl;print_board();return;}
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
