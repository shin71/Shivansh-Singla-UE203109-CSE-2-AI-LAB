# Some implementation details
<ul>
<li>we will keep the list of moves made by user and computer in moves vector</li>
<li>board is only used to keep track of placement of X,O and empty spaces</li>
<li>To check for a win we will run a 3rd order nested loop if any 3 moves made by a player sum upto 15 that means winner</li>
<li>poss_win() -> to check for a winning position we will try moves which have empty spaces and if they result in a win we will place computer's circle there</li>
<li>poss_num_of_wins() -> used to detect places where putting a cross will lead to 2 winning indexes meaning it will be impossible to block such a win</li>
<li> 
 <pre>
  example of 2 winning indexes
  _ _ _
  x o o
  x x _
  </pre>
</ul>

# A test run

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
1
computer won
X _ O 
X O _ 
O X _ 
</pre>
