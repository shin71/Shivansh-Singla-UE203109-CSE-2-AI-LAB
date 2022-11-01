<pre>
Shivansh singla
Ue203109
CSE 2
</pre>

# implementation points

<ul>
<li>the program asks if you want to print the boards or not</li>
<li>board has been given dimension (n + 4)  * (m+4) extra +4 so that we can mark positions in board without worrying about bounds</li>
  <li>Actual board start row 2 to n+1 and col 2 to m+1</li>
</ul>

## some runs with and without prints time is given at end of a run with number of configs
<pre>
enter board dimensions n*m and k i.e number of knights
8 8 4
do you want to print enter 1 for yes and 0 for no
0
number of possible configs are:
376560
Time taken : 2.98748s 
</pre>
<br>
<pre>
enter board dimensions n*m and k i.e number of knights
3 3 3
do you want to print enter 1 for yes and 0 for no
1
K K K 
E E E 
E E E 
......
K K E 
K E E 
E E E 
......
K K E 
E K E 
E E E 
......
K E K 
E K E 
E E E 
......
K E K 
E E E 
K E E 
......
K E K 
E E E 
E E K 
......
K E E 
K K E 
E E E 
......
K E E 
K E E 
K E E 
......
K E E 
E K E 
K E E 
......
K E E 
E K E 
E E K 
......
K E E 
E E E 
K E K 
......
E K K 
E K E 
E E E 
......
E K K 
E E K 
E E E 
......
E K E 
K K E 
E E E 
......
E K E 
K E K 
E E E 
......
E K E 
K E E 
E K E 
......
E K E 
E K K 
E E E 
......
E K E 
E K E 
E K E 
......
E K E 
E E K 
E K E 
......
E E K 
E K K 
E E E 
......
E E K 
E K E 
K E E 
......
E E K 
E K E 
E E K 
......
E E K 
E E K 
E E K 
......
E E K 
E E E 
K E K 
......
E E E 
K K K 
E E E 
......
E E E 
K K E 
K E E 
......
E E E 
K K E 
E K E 
......
E E E 
K E K 
E K E 
......
E E E 
K E E 
K K E 
......
E E E 
E K K 
E K E 
......
E E E 
E K K 
E E K 
......
E E E 
E K E 
K K E 
......
E E E 
E K E 
K E K 
......
E E E 
E K E 
E K K 
......
E E E 
E E K 
E K K 
......
E E E 
E E E 
K K K 
......
number of possible configs are:
36
Time taken : 0.004235s 
</pre>
