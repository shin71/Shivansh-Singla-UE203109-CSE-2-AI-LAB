## shivansh singla ue203109 cse 2
### note
<ul>
  <li> <b>In my implementation computer is always playing A circle whether it starts first or second</b>

  <li> <b>go function is within the computer move there is no need for a separate function just for putting values</b> 
  <li> <b> poss_win takes the character value 3 for cross or 5 for circle to find any index which results in the win for that character</b>
</ul>
### shortcoming
<ul>
  <li> <b>Algorithm only determines if there is one index which results in users win but fails to include the case where there may be 2 indexes resulting in a win</b>

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
