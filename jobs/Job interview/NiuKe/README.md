# 牛客网模拟笔试 2017-0519
>记录编程题,ac代码附最后。
## 01 牛牛的数列
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
牛牛现在有一个n个数组成的数列,牛牛现在想取一个连续的子序列,并且这个子序列还必须得满足:最多只改变一个数,就可以使得这个连续的子序列是一个严格上升的子序列,牛牛想知道这个连续子序列最长的长度是多少。 
##### 输入  
>输入包括两行,第一行包括一个整数n(1 ≤ n ≤ 10^5),即数列的长度;
第二行n个整数a_i, 表示数列中的每个数(1 ≤ a_i ≤ 10^9),以空格分割。
##### 输出  
>输出一个整数,表示最长的长度。

#### 样例输入
```
6 
7 2 3 1 5 6
```
#### 样例输出
```
5
```

## 02 变换次数
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
牛牛想对一个数做若干次变换，直到这个数只剩下一位数字。
变换的规则是：将这个数变成 所有位数上的数字的乘积。比如285经过一次变换后转化成2*8*5=80.
问题是，要做多少次变换，使得这个数变成个位数。 
##### 输入  
>输入一个整数。小于等于2,000,000,000。
##### 输出  
>输出一个整数，表示变换次数。

#### 样例输入
```
285
```
#### 样例输出
```
2
```

# 牛客网模拟笔试 2017-0519 AC代码：
## 01 牛牛的数列
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
//解题思路：动态规划
//注意细节：初始条件，递推关系
	int N;
	cin >> N;//输入正整数个数
	vector<int> vi(N, 0);
	for (int i = 0;i < vi.size();i++) {
		cin >> vi[i];
	}
	if (N <= 2)
	{		
		cout << N << endl;
		return 0;
	}
	vector<pair<int,int>> dp(N + 1, pair<int,int>(0,0));
	int maxR = 0;
	dp[1] = pair<int, int>(1, 1);//first表示不修改的升序个数，second 表示修改一个数的升序个数
	dp[2] = pair<int, int>((vi[1] > vi[0] ? 2 : 1), 2);
	for (int i = 3; i < dp.size();i++) {
		int j = i - 1;
		if (vi[j] > vi[j - 1] && vi[j - 1] > vi[j - 2])//本身就是一个严格递增
		{
			dp[i].first = dp[i - 1].first + 1;
			dp[i].second = dp[i - 1].second + 1;
		}
		else if (vi[j] > vi[j - 1] && vi[j - 1] <= vi[j - 2] && vi[j] > vi[j - 2] + 1)//改变vi[i - 1]可以变成严格递增
		{
			dp[i].first = dp[i - 1].first + 1;
			dp[i].second = dp[i - 2].first + 2;
		}
		else if (vi[j] > vi[j - 1]) {
			dp[i].first = dp[i - 1].first + 1;
			dp[i].second = dp[i - 1].second + 1;
		}
		else if (vi[j] <= vi[j - 1] && vi[j] > vi[j - 2] + 1){//必须改变vi[i - 1]
			dp[i].first = 1;
			dp[i].second = dp[i - 2].first + 2;
		}
		else{
			dp[i].first = 1;
			dp[i].second = 1;
		}
		maxR = max(maxR, dp[i].second);
	}
	cout << maxR << endl;
	system("pause");
	return 0;

}
```

## 02 变换次数
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int process(int N) {
	int res = 1;
	while (N != 0) {
		res *= (N % 10);
		N /= 10;
	}
	return res;
}
int main() {
	int N;
	cin >> N;//输入正整数个数
	//暴力计算即可，对于重复进行的操作我们将其封装成外置函数
	int count = 0;
	while (N > 9) {
		N = process(N);
		count++;
	}
	cout << count << endl;
	//system("pause");
	return 0;
}
```
