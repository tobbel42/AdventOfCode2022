# Day02
## 1st Star
Today we playing Rock-Paper-Scissor. To prevent any if-else madness, I found a nice Solution online(https://stackoverflow.com/questions/41457556/rock-paper-scissors-get-winner-mathematically) to claculate the winner mathematically. First we normalize Rock, Paper and Scissors to 0, 1, 2 respectivly, then we make it a circle using the modulo Operator. If a player is in front of the other, they win, else it is a draw.
<br/>
   0
<br/>
  / \
<br/>
 2---1

## 2nd Star
Now we need to get the right outcome for each round. To do this, we utilize the same clock module as before, and choosing the Shape before or behind our opponents shape to get the right output.