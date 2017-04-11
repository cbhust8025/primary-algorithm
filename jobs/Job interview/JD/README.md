# 京东笔试
>记录编程题,ac代码附最后。
## 01 站队
* 时间限制：C/C++语言 2000MS；其他语言 4000MS
* 内存限制：C/C++语言 65536KB；其他语言 589824KB
### 题目描述：
有一条很长的队伍，队伍里面一共有n个人。所有的人分为三类：警察，小偷和普通人。将队伍里面的人从前到后由1到n编号，编号为i的人与编号为j的人的距离为i与j之差的绝对值。
每一个警察有一个能力值x，表示他能够监视与他距离不超过x的所有人，小偷被警察发现当且仅当他被一个或多个警察监视到。你知道在整条队伍中，一共有多少个小偷会被警察发现吗？
##### 输入  
>输入有两行，第一行一个数n(1<=n<=100000)，接下来一行有一个长度为n的字符串，依次表示队伍中的每一个人。如果某一位是1-9的某个数字x，表示这一位是一个能力值为
x的警察；如果某一位是字符X表示这一位是小偷；如果某一位是字符#表示这是一个普通人。输入保证不会出现其它字符。
##### 输出  
>输出一个数，整条队伍中被警察发现的小偷总数。

#### 样例输入
```
9
X1X#2X#XX
```
#### 样例输出
```
3
```

## 02 通过考试
* 时间限制：C/C++语言 1000MS；其他语言 3000MS
* 内存限制：C/C++语言 65536KB；其他语言 589824KB
### 题目描述：
小明同学要参加一场考试，考试一共有n道题目，小明必须做对至少60%的题目才能通过考试。考试结束后，小明估算出每题做对的概率，p1,p2,...,pn。你能帮他算出他通过考试的概率吗？
##### 输入
>输入第一行一个数n（1<=n<=100），表示题目的个数。第二行n个整数，p1,p2,...,pn。表示小明有pi%的概率做对第i题。（0<=pi<=100）
##### 输出  
>小明通过考试的概率，最后结果四舍五入，保留小数点后五位。

#### 样例输入  
```
4
50 50 50 50
```
#### 样例输出  
```
0.31250
```

## 03 射穿车的子弹
* 时间限制：C/C++语言 1000MS；其他语言 3000MS
* 内存限制：C/C++语言 65536KB；其他语言 589824KB
### 题目描述：
无限长的横轴上有很多量车 每辆车有一个起点xi   和长度 leni 小明有两发子弹只能沿着y轴方向发射，每一发子弹可以打穿该方向的所有车辆
现在给定n辆车的 起始xi和该车的长度leni  求两发子弹最多能打穿多少辆车

#### 样例输入  
```
4
2 2
3 1
5 2
7 1
```
#### 样例输出  
```
4
```

```
//JD01.cpp
#include <iostream> 
#include<vector>
#include<stdlib.h>
using namespace std;
#define min(a,b) ((a>b)?(b):(a))
#define max(a,b) ((a>b)?(a):(b))
/*
站队
时间限制：C/C++语言 2000MS；其他语言 4000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
有一条很长的队伍，队伍里面一共有n个人。所有的人分为三类：警察，小偷和普通人。将队伍里面的人从前到后由1到n编号，编号为i的人与编号为j的人的距离为i与j之差的绝对值。
每一个警察有一个能力值x，表示他能够监视与他距离不超过x的所有人，小偷被警察发现当且仅当他被一个或多个警察监视到。你知道在整条队伍中，一共有多少个小偷会被警察发现吗？
输入
输入有两行，第一行一个数n(1<=n<=100000)，接下来一行有一个长度为n的字符串，依次表示队伍中的每一个人。如果某一位是1-9的某个数字x，表示这一位是一个能力值为
x的警察；如果某一位是字符X表示这一位是小偷；如果某一位是字符#表示这是一个普通人。输入保证不会出现其它字符。
输出
输出一个数，整条队伍中被警察发现的小偷总数。

样例输入
9
X1X#2X#XX
样例输出
3

Hint
在第一组样例中，一共有9个人，第2位是一个能力值为1的警察，他可以发现位置1,3的两个小偷，第5位是一个能力值为2的警察，他可以发现位置3,6的两个小偷。所以本
题中，位置为1,3,6的三个小偷被警察发现了，总个数为3。
*/
int main()
{
	int n;
	cin >> n;
	vector<char> army(n,'0');
	for (int i = 0;i < n;i++)
	{
		cin >> army[i];
	}
	vector<int> dp(n + 1, 0);
	int count = 0;
	cout << min(4, 1) << endl;
	vector<bool> flag(n, false);
	for (int i = 0;i < n;i++)
	{
		if (army[i] == '#' || army[i] == 'X')
			continue;
		else
		{
			int len = int(army[i] - '0');
			int begin = max(0, i - len);
			int end = min(n - 1, i + len);
			//cout << len << begin << end << endl;
			for (int j = begin;j < end + 1;j++)
			{
				if (army[j] == 'X' && flag[j]==false)
				{
					count++;
					flag[j] = true;
				}
			}
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
```

```
//JD02.cpp
#include <iostream> 
#include<vector>
#include <math.h>
#include<stdlib.h>
#include <iomanip>
using namespace std;
/*
通过考试
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
小明同学要参加一场考试，考试一共有n道题目，小明必须做对至少60%的题目才能通过考试。考试结束后，小明估算出每题做对的概率，p1,p2,...,pn。你能帮他算出他通过考试的概率吗？
输入
输入第一行一个数n（1<=n<=100），表示题目的个数。第二行n个整数，p1,p2,...,pn。表示小明有pi%的概率做对第i题。（0<=pi<=100）
输出
小明通过考试的概率，最后结果四舍五入，保留小数点后五位。

样例输入
4
50 50 50 50
样例输出
0.31250

Hint
第一个样例中，每道题做对的概率都是0.5，想要通过考试至少要做对三题。所以最后的答案就是。

*/
#define min(a,b) ((a>b)?(b):(a))
#define max(a,b) ((a>b)?(a):(b))

int main()
{
	int n;
	cin >> n;
	vector<float> probability(n, 0);
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		probability[i] = temp / 100.0;
	}
	for (int i = 0;i < n;i++)
	{
		cout << probability[i] << endl;
	}
	int m = ceil(n*0.6);
	cout << m << endl;
	vector<vector<float>> dp;
	for (int i = 0;i < n + 1;i++)
	{
		vector<float> te;
		te.push_back(1);
		for (int j = 0;j < m;j++)
		{
			te.push_back(0);
		}
		dp.push_back(te);
	}
	for (int i = 1;i < n + 1;i++)
	{
		float tem = 1;
		for (int j = 1;j < m + 1;j++)
		{
			dp[i][j] = dp[i - 1][j] * (1 - probability[i - 1]) + dp[i - 1][j - 1] * probability[i - 1];
		}
	}
	for (int i = 0;i < n + 1;i++)
	{
		for (int j = 0;j < m + 1;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout.setf(ios::fixed);
	cout << fixed <<setprecision(5) << dp[n][m] << endl;
	system("pause");
	return 0;
}
```

```
//JD03.cpp
#include <iostream> 
#include<vector>
#include <math.h>
#include<stdlib.h>
#include <iomanip>
using namespace std;

/* 无限长的横轴上有很多量车 每辆车有一个起点xi   和长度 leni 小明有两发子弹只能沿着y轴方向发射，每一发子弹可以打穿该方向的所有车辆
现在给定n辆车的 起始xi和该车的长度leni  求两发子弹最多能打穿多少辆车
4
2 2
3 1
5 2
7 1
最多在3,、7位置打，各能摧毁两辆。
*/

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> cars;
	for (int i = 0;i < n;i++)
	{
		vector<int> temp(2, 0);
		cin >> temp[0] >> temp[1];
		cars.push_back(temp);
	}
	for (int i = 0;i < n;i++)
	{
		cout << cars[i][0] << ":" << cars[i][1] << endl;
	}
	int start = cars[0][0];
	int end = cars[0][0]+cars[0][1];
	for (int i = 0;i < n;i++)
	{
		if (cars[i][0] < start)
		{
			start = cars[i][0];
		}
		if (cars[i][0] + cars[i][1] > end)
		{
			end = cars[i][0] + cars[i][1];
		}
	}
	cout << start << ":" << end << endl;
	vector<int> dp;//保存每个位置所能射穿的车辆数
	vector<vector<int>> dpp;//第一行为dp,第二行到最后一行保存：在去除当前列对应位置所能射穿车辆的剩余车辆中，行数对应位置能够射穿的车辆数。
	for (int i = start;i <= end;i++)
	{
		dp.push_back(0);
	}
	for (int i = 0;i < dp.size();i++)
	{
		cout << dp[i] << " ";
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = cars[i][0];j <= cars[i][0] + cars[i][1];j++)
		{
			cout << j << "..";
			dp[j-start]++;
		}
	}
	cout << endl;
	for (int i = 0;i < dp.size();i++)
	{
		cout << dp[i] << " ";
	}
	dpp.push_back(dp);
	for (int j = start;j <= end;j++)
	{
		vector<int> temp = dp;
		for (int i = 0;i < n;i++)
		{
			if (cars[i][0] <= j && j <= cars[i][0] + cars[i][1])
			{
				for (int k = cars[i][0];k <= cars[i][0] + cars[i][1];k++)
				{
					temp[k - start]--;
				}
			}
		}
		dpp.push_back(temp);
	}
	cout << endl;
	for (int i = 0;i <= end - start + 1;i++)
	{
		for (int j = 0;j < dp.size();j++)
		{
			cout << dpp[i][j] << "..";
		}
		cout << endl;
	}
	int maxcount = 0;
	for (int i = 1;i < end-start+1;i++)
	{
		int max = dpp[i][0];
		for (int j = 0;j < dpp[i].size();j++)
		{
			if (dpp[i][j] > max)
			{
				max = dpp[i][j];
			}
		}
		if (max + dp[i-1] > maxcount)
		{
			cout << max << "," << dp[i - 1] << endl;
			maxcount = max + dp[i-1];
		}
	}
	cout << maxcount << endl;
	system("pause");
	return 0;
}
```
