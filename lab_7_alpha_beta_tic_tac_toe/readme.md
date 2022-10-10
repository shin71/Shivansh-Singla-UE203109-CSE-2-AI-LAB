# implementation points

<ul>
<li>The program is same for both alpha-beta pruning minimax and naive minimax</li>
<li>The program will take depth as input which we will enter as 100 which wiil be max and big enough to traverse the whole game tree here</li>
<li>the program will also take input of whether we want it to run <b>naive minimax</b> or <b>alpha-beta pruning minimax</b></li>
<li>input 1 as response to question <i>do you want alpha beta pruning</i></li>
<li>according to the response we will get the number of calls</li>
</ul>

## input move sequence - 6 8 9 2
## depth - 100

### naive minimax calls -> 21362

<pre>
do you want alpha beta pruning enter 1 for yes
0
enter depth
100
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
6
_ _ _ 
_ O X 
_ _ _ 
enter your move here with 1 based indexing
8
O _ _ 
_ O X 
_ X _ 
enter your move here with 1 based indexing
9
O _ O 
_ O X 
_ X X 
enter your move here with 1 based indexing
2
computer won
O X O 
_ O X 
O X X 
calls to minimax function(inclusive of comp_move)
21362
</pre>

### alpha_beta_pruning minimax calls -> 20697

<pre>
do you want alpha beta pruning enter 1 for yes
1
enter depth
100
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
6
_ _ _ 
_ O X 
_ _ _ 
enter your move here with 1 based indexing
8
O _ _ 
_ O X 
_ X _ 
enter your move here with 1 based indexing
9
O _ O 
_ O X 
_ X X 
enter your move here with 1 based indexing
2
computer won
O X O 
_ O X 
O X X 
calls to minimax function(inclusive of comp_move)
20697
</pre>
