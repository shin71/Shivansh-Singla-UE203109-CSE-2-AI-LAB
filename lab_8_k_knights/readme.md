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

## note - i am running these programs using -O3 flag in compilation command which improves runtime a lot

### eg - n=m=6,k=17 without prints takes 40 seconds to run without any optimization flag whereas it takes only 0.7 seconds on -O3 flag

<!--### n=m=8,k=31 is unable to give any solution due to memory and time constraints so using n=m=8,k=6 without prints because there are a lot of configs-->
### lot of configs in 8 8 6 so unable to print that many

### some runs with and without prints time is given at end of a run with number of configs
<br>
without prints
<pre>
enter board dimensions n*m and k i.e number of knights
8 8 6
do you want to print enter 1 for yes and 0 for no
0
number of possible configs are:
20202298
Time taken : 37.3208s 
</pre>
<pre>
enter board dimensions n*m and k i.e number of knights
6 6 17
do you want to print enter 1 for yes and 0 for no
0
number of possible configs are:
40
Time taken : 0.744675s 
</pre>
<br>
with prints
<br>
<pre>
enter board dimensions n*m and k i.e number of knights
6 6 17
do you want to print enter 1 for yes and 0 for no
1
K K E K E K 
K E E E K E 
E E E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
K E K E K K 
E K E E E K 
K E K E E E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E E 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E E E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E E E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E E E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E E E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
E E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E E 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E K E E E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E E E K E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E K E K E 
E E E K E K 
K E E E K E 
K K E K E K 
......
K E K E K E 
E K E K E K 
K E K E E E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
K E E E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E K 
E E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E K E E 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E K E E E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E K E K E 
E E E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E K E E E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
K E E E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E E E 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E E E K E 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
E E K E K E 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E E 
K E K E K E 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E E E K 
K E K E K E 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E E E K E K 
K E K E K E 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E E E 
E K E K E K 
K E K E K E 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E K E E E 
E K E E E K 
K E K E K K 
......
E K E K E K 
K E K E K E 
E K E K E K 
K E E E K E 
E K E K E K 
K E K E K E 
......
E K E K E K 
K E K E K E 
E K E K E K 
E E K E K E 
E K E K E K 
K E K E K E 
......
E K E K E K 
K E K E K E 
E K E K E E 
K E K E K E 
E K E K E K 
K E K E K E 
......
E K E K E K 
K E K E K E 
E K E E E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
E K E K E K 
K E K E K E 
E E E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
E K E K E K 
K E K E E E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
E K E K E K 
K E E E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
E K E K E K 
E E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
E K E K E E 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
E K E E E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
E E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
......
E E E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
E K E K E K 
K E K E K E 
......
number of possible configs are:
40
Time taken : 1.31622s 
</pre>
