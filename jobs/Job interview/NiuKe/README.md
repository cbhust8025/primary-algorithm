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

## 03 神奇数
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
给出一个区间[a, b]，计算区间内“神奇数”的个数。
神奇数的定义：存在不同位置的两个数位，组成一个两位数（且不含前导0），且这个两位数为质数。
比如：153，可以使用数字3和数字1组成13，13是质数，满足神奇数。同样153可以找到31和53也为质数，只要找到一个质数即满足神奇数。 
##### 输入  
>输入为两个整数a和b，代表[a, b]区间 (1 ≤ a ≤ b ≤ 10000)。
##### 输出  
>输出为一个整数，表示区间内满足条件的整数个数

#### 样例输入
```
11 20
```
#### 样例输出
```
6
```

## 04 添加字符
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
牛牛手里有一个字符串A，羊羊的手里有一个字符串B，B的长度大于等于A，所以牛牛想把A串变得和B串一样长，这样羊羊就愿意和牛牛一起玩了。
而且A的长度增加到和B串一样长的时候，对应的每一位相等的越多，羊羊就越喜欢。比如"abc"和"abd"对应相等的位数为2，为前两位。
牛牛可以在A的开头或者结尾添加任意字符，使得长度和B一样。现在问牛牛对A串添加完字符之后，不相等的位数最少有多少位？  
##### 输入  
>第一行为字符串A，第二行为字符串B，A的场地小于等于B的长度，B的长度小于等于50.字符均为小写字母。
##### 输出  
>输出一个整数表示A串添加完字符之后，不相等的位数最少有多少位？

#### 样例输入
```
abe
cabc
```
#### 样例输出
```
1
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

## 03 神奇数
```C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

set<int> getPermution(int n) {
//找到数字n的所有两位数非前导0组合
	vector<int> vi;
	while (n != 0) {
		vi.push_back(n % 10);
		n /= 10;
	}
	set<int> siRes;
	for (int i = 0;i < vi.size();i++) {
		for (int j = i + 1;j < vi.size();j++) {
			//注意过滤前导0
			if(vi[i] != 0)siRes.insert(vi[i] * 10 + vi[j]);
			if (vi[j] != 0)siRes.insert(vi[j] * 10 + vi[i]);
		}
	}
	return siRes;
}

bool IsPrimeNumber(int n) {
	//判断n是否为质数，n 如果是合数，那么它的所有的因子不超过sqrt(n)--n的开方
	for (int i = 2;i <= sqrt(n);i++) {
		if (n%i == 0) return false;
	}
	return true;
}
bool IsMagicNumber(int n) {
	//判断n是否为神奇数，当n <= 10,直接返回false
	if (n <= 10)
		return false;
	//当n > 10时，找到所有不含前导0的组合数，由于组合数是两位数，所以我们可以先将所有的10-99的结果进行解析保存
	map<int, bool> mibMap;
	for (int i = 10;i < 100;i++) {
		mibMap[i] = IsPrimeNumber(i);
	}
	//找到所有n的两位组合数
	set<int> si = getPermution(n);
	for (auto it : si) {
		if (mibMap[it])
			return true;
	}
	return false;
}

int main() {
	int a,b;
	cin >> a >> b;//输入正整数区间
	int count = 0;//统计神奇数个数
	//对于这一题，我们要找到区间内每一个神奇数，所以对每个数都需要进行一次判断，所以对于神奇数的判断我们需要封装成一个外置函数
	//对于神奇数的判断，我们分为两步，首先找到当前的数可以有多少种非前导零的组合，需要对每一种组合起来的数分别判断是否是质数
	//其中只有一个地方可以优化，即是对已经判断是否为质数的组合可以进行结果的保存，利用map查找便捷的特性进行保存，其他的操作必须执行，也就是常规意义的暴力破解
	while (a <= b) {//a,b只有这里有一次用处，所以不用管修改了a是否有别的后果
		if (IsMagicNumber(a)) {
			count++;
		}
		a++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}
```

## 04 添加字符
```C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	//输入字符串a,b
	string sa, sb;
	cin >> sa >> sb;
	if (sa.empty())
	{
		cout << sb.size() << endl;
		return 0;
	}
	//要找到最少的不相等位数，则就需要用a串包含在b串中尽可能匹配相等的字符
	//字符串在另一个字符串里面的匹配结果可以使用动态规划的方法来进行解决
	//注意，不能超出了边界，所以要从sa的第一个字符和sb的第一个字符进行匹配开始修正dp数组，其他的值均为0
	//dp矩阵的大小为(sa.size() + 1) * (sb.size() + 1)
	vector<vector<int>> dp(sa.size() + 1, vector<int>(sb.size() + 1, 0));
	pair<int, int> maxRes(0,0);//存放最大匹配结果，first存放sb的index，second存放从sb的index往前多少个字符进行了匹配
	for (int i = 1;i < dp.size();i++) {
		for (int j = i;j < dp[0].size() - (sa.size() - i);j++) {//j的范围确保让a串始终包含在b串中
			if (sa[i - 1] == sb[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = dp[i - 1][j - 1];
			}
			if (dp[i][j] > maxRes.second) {
				maxRes.first = j - 1;//更新最大的结果
				maxRes.second = dp[i][j];
			}
		}
	}
	cout << sa.size() - maxRes.second << endl;//实质上这里换成dp数组中的dp[sa.size()][sb.size()]也行
	system("pause");
	return 0;
}
```
