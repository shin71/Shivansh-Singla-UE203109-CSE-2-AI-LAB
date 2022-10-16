<pre>
Shivansh singla
Ue203109
CSE 2
</pre>
<ul>
<li> rating gives us the score 10 if the computer aka maximizer wins that is reaches a +10 leaf node</li>
<li> rating gives us the score -10 if the user aka minimizer wins that is reaches a -10 leaf node</li>
<li> rating gives us +8 if the call is made from maximizer and there is possible win for maximizer and not for minimizer</li>
<li> rating gives us -8 if the call is made from minimizer and there is possible win for minimizer and not for maximizer</li>
<li> rating returns 0 if no one wins or we finish early before reaching any depth node </li>
</ul>

## dry runs at depth 1 to 4 on input 6 8 1 3 if possible
depth = 1<br>
6 8 1 3 2 and you won
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
_ O X 
_ X O 
enter your move here with 1 based indexing
1
X _ _ 
_ O X 
O X O 
enter your move here with 1 based indexing
3
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
depth=2<br>
6 8 1 3 4 and it is a draw
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
_ O X 
_ X O 
enter your move here with 1 based indexing
1
X _ _ 
_ O X 
O X O 
enter your move here with 1 based indexing
3
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
depth=3<br>
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
depth=4<br>
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

