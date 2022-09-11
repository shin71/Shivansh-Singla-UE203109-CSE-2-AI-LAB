## shivansh singla ue203109 cse 2
### notes on simple implementation where loss is possible tictactoe_game_program.cpp
<ul>
  <li> <b>In my implementation computer is always playing A circle whether it starts first or second</b>

  <li> <b>go function is within the computer move there is no need for a separate function just for putting values</b> 
  <li> <b> poss_win takes the character value 3 for cross or 5 for circle to find any index which results in the win for that character</b>
</ul>

### shortcoming and fix
<ul>
  <li> <b>Algorithm only determines if there is one index which results in users win but fails to include the case where there may be 2 indexes resulting in a win</b>
  <li> <b>we will also test every non empty index where putting cross by opponent may result in 2 winning indexes this is only possible if user has turn 5 or more so we will have to check at turn 4 or more for such a condition</b>
</ul>

### notes on modified implementation tictactoe_game_program_with_modification_for_never_losing.cpp
<ul>
  <li> <b>we first always check for the new case in turns >= 4</b>

  <li> <b>we first check for win in direct turn before testing indexes for two winnings</b> 
  <li> <b> poss_num_of_wins checks if there are 2 or more possible winning indexes we know which index will be that because we are running a loop where try every empty index by placing a cross on them</b>
</ul>

### a sample run of tictactoe_game_program.cpp
<pre>
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
2
_ X _ 
_ O _ 
_ _ _ 
enter your move here with 1 based indexing
9
_ X _ 
O O _ 
_ _ X 
enter your move here with 1 based indexing
6
_ X O 
O O X 
_ _ X 
enter your move here with 1 based indexing
7
_ X O 
O O X 
X O X 
enter your move here with 1 based indexing
1
X X O 
O O X 
X O X 
it is a draw
</pre>

### a sample run of tictactoe_game_program.cpp where i win to determine shortcomings in algorithm
<pre>
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
4
_ _ _ 
X O _ 
_ _ _ 
enter your move here with 1 based indexing
8
_ O _ 
X O _ 
_ X _ 
enter your move here with 1 based indexing
7
_ O _ 
X O O 
X X _ 
enter your move here with 1 based indexing
9
you won
_ O _ 
X O O 
X X X 
</pre>

### a sample run of tictactoe_game_program_with_modification_for_never_losing.cpp where we run try to run case where previous algorithm failed
<pre>
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
4
_ _ _ 
X O _ 
_ _ _ 
enter your move here with 1 based indexing
8
_ _ _ 
X O _ 
O X _ 
enter your move here with 1 based indexing
3
_ O X 
X O _ 
O X _ 
enter your move here with 1 based indexing
9
_ O X 
X O O 
O X X 
enter your move here with 1 based indexing
1
it is a draw
</pre>
