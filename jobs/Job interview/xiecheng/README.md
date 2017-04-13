# 携程笔试
>记录编程题
## 01 乘积最大
* 时间限制：C/C++语言 3MS；其他语言 2003MS
* 内存限制：C/C++语言 65536KB；其他语言 589824KB
### 题目描述：
有一个整数n，将n分解成若干个不同自然数之和，问如何分解能使这些数的乘积最大，输出这个乘积m
输入
一个整数，不超过50
输出
一个整数

#### 样例输入
```
15
```
#### 样例输出
```
144
```

## 02 拼图
* 时间限制：C/C++语言 3000MS；其他语言 5000MS
* 内存限制：C/C++语言 10240KB；其他语言 534528KB
### 题目描述：
拼图，是一个老少皆宜的益智游戏，在打乱的3*3的范围中，玩家只能每次将空格(0)和相邻的数字格（上、下、左、右）交换，最终调整出一个完整的拼图。
完整拼图为：
```
1 2 3  
4 5 6  
7 8 0 
```
输出:还原完整拼图的最少移动次数。如不需要调整，则输出0；如无解，则输出-1。  
输出:一个整数  
例如：  
```
0 1 3  
4 2 5  
7 8 6
```
依次移动1,2,5,6，即可还原为正确拼图，移动次数为4。
#### 样例输入  
```
0 1 3  
4 2 5  
7 8 6
```
#### 样例输出  
```
4
```

```C++
//携程第一题ac解
#include <iostream> 
#include<vector>
#include <math.h>
#include<stdlib.h>
#include <iomanip>
using namespace std;
int maxNum(int k) {
	if (k <= 2)
	{
		return k;
	}
	if (k == 3)
	{
		return 2;
	}
	if (k == 4)
	{
		return 3;
	}
	int i = 0;
	int res = 1;
	int in = 2;
	vector<int> arr(30,0);
	while (k >= in)
	{
		arr[i++] = in;
		k -= in;
		in++;
	}
	if (k>0)
	{
		if (k == arr[i - 1])
		{
			arr[i - 1]+=1;
			k--;
		}
		for(int j = 0;j < k;j++)
		{
			arr[i - 1 - j]+=1;
		}
	}
	for (int j = 0;j < arr.size();j++)
	{
		if (arr[j] != 0)
		{
			res *= arr[j];
		}
	}
	return res;
}
int main() {
	int res;
	int k;
	//cin >> k;
	for (int i = 1;i < 20;i++)
	{
		res = maxNum(i);
		cout << i<<":"<<res << endl;
	}
	
	//system("pause");
	return 0;
}
```

