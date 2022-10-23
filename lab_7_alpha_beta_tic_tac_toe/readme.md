<pre>
Shivansh singla
Ue203109
CSE 2
</pre>

# implementation points

<ul>
<li>The program is same for both alpha-beta pruning minimax and naive minimax</li>
<li>The program will take depth as input which we will enter as 100 which wiil be max and big enough to traverse the whole game tree here</li>
<li>the program will also take input of whether we want it to run <b>naive minimax</b> or <b>alpha-beta pruning minimax</b></li>
<li>input 1 as response to question <i>do you want alpha beta pruning</i></li>
<li>according to the response we will get the number of calls</li>
</ul>

## input move sequence - 9 8 3 4 2
## depth - 100

### naive minimax calls -> 60692

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
9
_ _ _ 
_ O _ 
_ _ X 
enter your move here with 1 based indexing
8
_ _ _ 
_ O _ 
O X X 
enter your move here with 1 based indexing
3
_ _ X 
_ O O 
O X X 
enter your move here with 1 based indexing
4
O _ X 
X O O 
O X X 
enter your move here with 1 based indexing
2
O X X 
X O O 
O X X 
it is a draw
calls to minimax function
60692
</pre>

### alpha_beta_pruning minimax calls -> 4169

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
9
_ _ _ 
_ O _ 
_ _ X 
enter your move here with 1 based indexing
8
_ _ _ 
_ O _ 
O X X 
enter your move here with 1 based indexing
3
_ _ X 
_ O O 
O X X 
enter your move here with 1 based indexing
4
O _ X 
X O O 
O X X 
enter your move here with 1 based indexing
2
O X X 
X O O 
O X X 
it is a draw
calls to minimax function
4169
</pre>
