<pre>
Shivansh singla
Ue203109
CSE 2
</pre>

## dry runs at depth 1 to 4 on input 6 8 3 1 if possible
depth = 1
6 8 3 1 2 and user wins
<pre>
enter depth
1
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
6
_ _ _ 
_ _ X 
_ _ O 
enter your move here with 1 based indexing
8
_ _ _ 
_ _ X 
O X O 
enter your move here with 1 based indexing
3
_ _ X 
_ O X 
O X O 
enter your move here with 1 based indexing
1
X _ X 
O O X 
O X O 
enter your move here with 1 based indexing
2
you won
X X X 
O O X 
O X O 
</pre>
depth=2
6 8 3 1 4 and it is a draw
<pre>
enter depth
2
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
6
_ _ _ 
_ _ X 
_ _ O 
enter your move here with 1 based indexing
8
_ _ _ 
_ _ X 
O X O 
enter your move here with 1 based indexing
3
_ _ X 
_ O X 
O X O 
enter your move here with 1 based indexing
1
X O X 
_ O X 
O X O 
enter your move here with 1 based indexing
4
X O X 
X O X 
O X O 
it is a draw
</pre>
depth=3
6 8 3 4 (4 because 1 wasn't possible) and computer won
<pre>
enter depth
3
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
6
_ _ _ 
_ _ X 
_ _ O 
enter your move here with 1 based indexing
8
_ _ _ 
_ _ X 
O X O 
enter your move here with 1 based indexing
3
O _ X 
_ _ X 
O X O 
enter your move here with 1 based indexing
4
computer won
O _ X 
X O X 
O X O 
</pre>
depth=4
6 8 3 and computer won
<pre>
enter depth
4
computer will always play circle
Enter 0 if you want to play first else enter 1
0
_ _ _ 
_ _ _ 
_ _ _ 
enter your move here with 1 based indexing
6
_ _ _ 
_ _ X 
_ _ O 
enter your move here with 1 based indexing
8
_ _ _ 
_ O X 
_ X O 
enter your move here with 1 based indexing
3
computer won
O _ X 
_ O X 
_ X O 
</pre>

