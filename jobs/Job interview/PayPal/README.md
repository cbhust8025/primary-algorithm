# PayPal笔试
>记录编程题,暂无AC代码。
## 01
### 题目描述：
Given two zero-indexed arrays A and B consisting of N (N >= 0) integers, which represent N fishes in a river, ordered from west to east. 
The fish are numbered from 0 to N-1, and Fish number X is represented by A[X] and B[X]. Array A contains the sizes of the fishes, while array B contains the directions they swim, which can be 1 (from west to east) or -1 (from east to west).

If two fishes move in opposite directions meet each other, the larger fish will eat the smaller one, and the survival will still follow its original direction.

We assume that all fishes are in different sizes and swimming at the same speed. The goal is to calculate the number of fishes that will stay alive.

For example:
```
A is [3, 5, 9, 1, 2]
B is [1, -1, 1, 1, -1]
```
Fish number 1 will eat Fish number 0, Fish number 4 will eat Fish number 3 and be eaten by Fish number 2. Therefore the output should be 2 (Fish number 1 and Fish number 2 are still alive)
##### 输入  
>Array A and B as described above
##### 输出  
>The number of fishes that will stay alive

#### 样例输入
```
3 5 9 1 2
1 -1 1 1 -1
```
#### 样例输出
```
2
```

## 02
### 题目描述：
Give a undirected graph, each edge’s length is 1, each node has a numeric ID. There are some special nodes in the graph, node’s the minimum distance to the special node is the length of shortest path to the nearest special node. Please calculate all the nodes’ minimum distance to special node. If a node could not reach any special node the distance is –1.
##### 输入  
>First line is a number N means that the next N lines are the N edges in the graph. Each of the N lines has two value v1 v2 which are the two nodes’ ID linked by this edge. 0 < N < 10000000
After that there is a single line with a number M which means the next M lines are the M special nodes. Each of the M lines has one value v which means the node’s ID. 0 <= M <= N/2
##### 输出  
>Sum of All nodes' minimum distance

#### 样例输入
```
2
1 2
2 3
1
2
```
#### 样例输出
```
2
```

## 03
### 题目描述：
The boss of P company plays an interesting game with employees.At the beginning, the boss gives a very long string with length
m.The boss invites n employees to reorder the string with command a,s,e, where a in {0,1} denotes the type of operation,
s and e are positions in  the string. If a = 0, all characters from s to e are ordered in non-increasing order.If a = 1, all
characters from s to e are ordered in non-decreasing order.After n times operation,the boss wants to know the fina string.
##### 输入  
>The first line contains two integers m,(1<= m<= 100000),n,(0<= n<= 50000)-the length of the string and the number of operations.
The next line contains a string with length m.Next n lines contain operation command a,s,e, where a in {0,1} and 1<= s<= e<=m.
##### 输出  
>One line contains the final string.
#### 样例输入
```
10 3
naitdocexv
1 1 3
0 9 10
1 7 9
```
#### 样例输出
```
aintdocexy
```

## 04
### 题目描述：
Given two zero-indexed arrays A and B consisting of M and N(M>0,N>0)strings,which represent M and N variables in two different models P
and Q.Each variable is a string, which contains letters "a-z" in lower case only. Variables in arrays A and B are initially
sorted by their contribution to the model,from large to small,which means, A[0] has the largest contribution to model P,while A[M-1] has
the smallest contribution to model P.If there are X variables existing in same order in both A and B. they form a "soild variable group"
of which the length is X.The goal is to calculate the length of the longest "soild variable group".If there are more than 1 longest "soild
 variable group", find out the one which has the largest contribution to model P.
##### 输入  
>Array A and B as described above
##### 输出  
>The first line should be the length of the longest "soild varible group",while the second line should be the longest "soild variable group"
which has the largest contribution to model P.If there's no longest "soild variable group" available, the second line should be a blank line.
#### 样例输入
```
paypel business money innovation strong
innovation paypel strong inclusion
```
#### 样例输出
```
2
paypel strong
```


