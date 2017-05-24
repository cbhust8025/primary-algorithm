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

## 05 数组变换
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
牛牛有一个数组，里面的数可能不相等，现在他想把数组变为：所有的数都相等。问是否可行。
牛牛可以进行的操作是：将数组中的任意一个数改为这个数的两倍。
这个操作的使用次数不限，也可以不使用，并且可以对同一个位置使用多次。
##### 输入  
>输入一个正整数N (N <= 50)
接下来一行输入N个正整数，每个数均小于等于1e9.
##### 输出  
>假如经过若干次操作可以使得N个数都相等，那么输出"YES", 否则输出"NO"

#### 样例输入
```
2
1 2
```
#### 样例输出
```
YES
```
## 06 排序子序列
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2 
##### 输入  
>输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。
##### 输出  
>输出一个整数表示牛牛可以将A最少划分为多少段排序子序列

#### 样例输入
```
6
1 2 3 2 2 1
```
#### 样例输出
```
2
```

## 07 组队竞赛
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
牛牛举办了一次编程比赛,参加比赛的有3 * n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。  
例如:  
* 一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
* 一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
* 一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2  
> 让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。 
如样例所示:  
如果牛牛把6个队员划分到两个队伍  
##### 如果方案为:
* team1:{1,2,5}, team2:{5,5,8} 
* 候水平值总和为7.
##### 而如果方案为:
* team1:{2,5,8}, team2:{1,5,5},
* 时候水平值总和为10.  
* 总和为10更大的方案,所以输出10.

##### 输入  
>输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
##### 输出  
>输出一个整数表示所有队伍的水平值总和最大值.

#### 样例输入
```
2
5 2 8 5 1 5
```
#### 样例输出
```
10
``` 
## 08 训练部队
* 时间限制：1秒
* 内存限制：32768K
### 题目描述：
小牛牛是牛牛王国的将军,为了训练出精锐的部队,他会对新兵进行训练。部队进入了n个新兵,每个新兵有一个战斗力值和潜力值,当两个新兵进行决斗时,总是战斗力值高的获胜。获胜的新兵的战斗力值就会变成对手的潜力值 + 自己的战斗力值 - 对手的战斗力值。败者将会被淘汰。若两者战斗力值一样,则会同归于尽,双双被淘汰(除了考察的那个新兵之外，其他新兵之间不会发生战斗) 。小牛牛想知道通过互相决斗之后新兵中战斗力值+潜力值最高的一个可能达到多少,你能帮助小牛牛将军求出来吗? 
##### 输入  
>输入包括n+1行,第一行包括一个整数n(1 ≤ n ≤ 10^5);
接下来的n行,每行两个整数x和y(1 ≤ x,y ≤ 10^9)
##### 输出  
>输出一个整数,表示新兵中战斗力值+潜力值最高的一个能达到多少。

#### 样例输入
```
2
1 2
2 1
```
#### 样例输出
```
4
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
	//找到数字n的所有位置的数字
	vector<int> vi;
	while (n != 0) {
		vi.push_back(n % 10);
		n /= 10;
	}
	//找到数字n中的所有非前导0的两位数，并进行质数判断
	for (int i = 0;i < vi.size();i++) {
		for (int j = i + 1;j < vi.size();j++) {
			//注意过滤前导0
			if (vi[i] != 0 && IsPrimeNumber(vi[i] * 10 + vi[j]))
				return true;
			if (vi[j] != 0 && IsPrimeNumber(vi[j] * 10 + vi[i]))
				return true;
		}
	}
	return false;
}

int main() {
	int a, b;
	cin >> a >> b;//输入正整数区间
	int count = 0;//统计神奇数个数
	//对于这一题，我们要找到区间内每一个神奇数，所以对每个数都需要进行一次判断，所以对于神奇数的判断我们需要封装成一个外置函数
	//对于神奇数的判断，我们分为两步，首先找到当前的数可以有多少种非前导零的组合，需要对每一种组合起来的数分别判断是否是质数
	//对于每一个数字的神奇数判断中间操作必须执行，也就是常规意义的暴力破解
	while (a <= b) {//a,b只有这里有一次用处，所以不用管修改了a是否有别的后果
		if (IsMagicNumber(a)) {
			count++;
		}
		a++;
	}
	cout << count << endl;
	//system("pause");
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
## 05 数组变换
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> vi(N, 0);
	for (int i = 0;i < vi.size();i++)cin >> vi[i];
	sort(vi.begin(), vi.end(), [](int a, int b) {return a > b;});
	while (vi.size() > 1) {
		if (vi[vi.size() - 1] * 2 < vi[vi.size() - 2]) {
			vi[vi.size() - 1] *= 2;
		}
		else if ((vi[vi.size() - 1] * 2 == vi[vi.size() - 2]) || (vi[vi.size() - 1] == vi[vi.size() - 2])) {
			vi.pop_back();
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	system("pause");
	return 0;
}
```

## 06 排序子序列
```C++
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> vi(N, 0);
	for (int i = 0;i < vi.size();i++)cin >> vi[i];
	int count = 0;//计数总共有多少个排序子序列
	int flag = 0;//flag = 0表示开始统计，flag = 1表示严格递增序列，flag = 2表示严格递减序列，若出现相等的数，我们的flag保持不变
	for (int i = 0;i < vi.size() - 1;i++) {
		if (flag == 0) {//如果刚开始统计，开始变化flag
			if (vi[i] < vi[i + 1]) {
				flag = 1;//严格递增
			}
			else if (vi[i] > vi[i + 1]) {
				flag = 2;//严格递减
			}
		}
		else if (flag == 1) {//如果之前是严格递增序列，所以出现严格递减情况，则应该重置flag ，并令计数器+1
			if (vi[i] > vi[i + 1]) {
				flag = 0;
				count++;
			}
		}
		else if (flag == 2) {//如果之前是严格递减序列，出现严格递增情况，则应该重置flag，并令计数器+1
			if (vi[i] < vi[i + 1]) {
				flag = 0;
				count++;
			}
		}
	}
	cout << ++count << endl;
	system("pause");
	return 0;
}
```

## 07 组队竞赛
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	//由于每支队伍的水平值等于第二大的队员水平值，则将3n个数进行排序，按照从大到小的顺序，依次挑出第二个数作为一支队伍的水平值
	int N;
	cin >> N;
	vector<int> vi(3 * N, 0);
	for (int i = 0;i < vi.size();i++) cin >> vi[i];
	sort(vi.begin(), vi.end(), [](int a, int b) {return a > b;});
	long long int res = 0;
	for (int i = 1;i < 2 * N;i+=2) {
		res += vi[i];
	}
	cout << res << endl;
	//stem("pause");
	return 0;
}
```

## 08 训练部队
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
	int N;
	cin >> N;
	//pair<int,int> first 保存攻击值，second保存潜力值
	vector<pair<int, int>> potential;//潜力组，保存所有潜力大于攻击的新兵，这里面的兵被别人击败可以增加攻击力
	vector<pair<int, int>> attack;//攻击组，保存所有攻击大于等于潜力的新兵，这里面的兵一般用于击败潜力组的兵
	for (int i = 0;i < N;i++) {
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		if (temp.first >= temp.second)attack.push_back(temp);
		else potential.push_back(temp);
	}
	//我们考虑,首先攻击组里面的人不会互相攻击，因为没有任何收益，哪怕赢了，攻击力最好也只是不增加
	//然后考虑潜力组，我们想要获得最大的攻击+潜力，在潜力组内部进行战斗，因为潜力是大于攻击的，所以攻击越大的，潜力越大
	//我们让攻击最大的去一一战胜其他的潜力组新兵，可以获得最大攻击的同时也获得了最大的潜力保存
	//在潜力组里面的战斗结束后，我们尝试用攻击组能够击败潜力组最后的那个胜者之中的攻击+潜力最大的一个新兵去尝试击败，看获得的潜力+攻击是否变大
	//注意潜力组中可能没有新兵，或者潜力组中的所有人攻击均相同，同归于尽
	//第一步，将攻击组按照攻击+潜力降序排序，潜力组按照攻击进行降序排序
	sort(potential.begin(), potential.end(), 
		[](pair<int, int> a, pair<int, int> b) {return (a.first == b.first)?(a.second > b.second):(a.first > b.first);});
	sort(attack.begin(), attack.end(), 
		[](pair<int, int> a, pair<int, int> b) 
			{return (a.first + a.second == b.first + b.second)?(a.first > b.first):(a.first + a.second > b.first + b.second);});
	cout << "potential:" << endl;
	for (auto it : potential) cout << it.first << " " << it.second << endl;
	cout << "attack:" << endl;
	for (auto it : attack) cout << it.first << " " << it.second << endl;
	//第二步，排序一些边界条件
	if (potential.empty())//潜力组中没有人
	{//直接输出攻击组中攻击+潜力中最大的一个值
		cout << attack[0].first + attack[0].second << endl;
		return 0;
	}
	if (potential.size() > 1 && potential[0].first == potential[potential.size() - 1].first)//如果潜力组人数在两个以上并且所有人攻击相同
	{//判断攻击组是否有人，若有人，则输出攻击组中潜力+攻击的最大一个；若没有人，则输出潜力组中的攻击最大的一个
		if (!attack.empty()) 
		{
			//如果攻击组不空，则将所有的潜力组潜力加到攻击组的第一个人身上
			for (auto it : potential)attack[0].first += it.second - it.first;
			cout << attack[0].first + attack[0].second << endl;
			return 0;
		}
		else
		{
			cout << potential[0].first + potential[0].second << endl;
			return 0;
		}
	}
	//此时潜力组至少有一个人，且当有两个人以上是不会出现所有人攻击相同
	//我们先将潜力组的胜负统计，最后潜力组剩余的那个人攻击力保存到潜力组第一个人
	//考虑第一大攻击，和第二大攻击的两个人攻击相等，由于不会出现所有人攻击相同，所以第一大攻击的人可以先去击败另外攻击小于他的人，再来击败这个第二大攻击的
	//所以此种情况下，直接将第二大攻击的潜力值- 攻击累加到第一个人即可
	long int maxPair = potential[0].second - potential[0].first;
	for (int i = 1;i < potential.size();i++) 
	{//从第二个人开始，依次累加到第一个人的攻击上
		maxPair += potential[i].second - potential[i].first;
	}
	long int maxNum = maxPair +  2 * potential[0].first;
	//累加出了潜力组第一人，从攻击组里面找攻击力+潜力最大的来挑战此人
	//累加出了潜力组第一人，从攻击组里面找攻击力+潜力最大的来挑战此人
	if (maxPair + attack[0].first + attack[0].second > maxNum)
	{//如果攻击组最厉害击败所有潜力组新兵，收益更大
		maxNum = maxPair + attack[0].first + attack[0].second;
	}
	cout << maxNum << endl;
	system("pause");
	return 0;
}
```
