# 阿里巴巴笔试
## 编程题
### 01、全知炒股
* 编译器版本: gcc 4.8.4 请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
* 内存限制: 64M (C/C++以外的语言为: 576 M)
* 时间限制: 1S (C/C++以外的语言为: 3 S)  
#### 题目描述：
* 做股票的人总会忍不住幻想：如果知道明天怎样就好了。那么问题来了，如果打开上帝视角，你最好能做到怎样？   
* 真实世界的股票交易规则太复杂，我们这里做一些简化。首先我们假设有N个股票和M个交易期。可以认为在单个交易期内所有股票的价格都是恒定的。股票卖出需要缴纳交易额的P倍的印花税。股票可以零碎地买卖，即，你买个0.01股也是可以的。我们这个市场里没有停牌，没有休市，没有涨停跌停，没有买空卖空，没有分红，而且股票价格也不会跌到零。   
* 举个例子，假设你用手里的一元钱买了个股票。这个股票第一期价格1元/股，你买入之后手上有1股股票和0元现金。这个股票在第二期涨到2元/股，那么你这时卖出1股就获得了2元（税前），扣除10%的印花税，你手上没有股票却有1.8元现金。   
* 如果你在一开始有1元现金，在M个交易期之后，你最多能持有多少现金？
#### 输入:
* 第一行是两个正整数N和M以及一个浮点数P。随后是M行，每行N个浮点数，代码某期（行）内某股票（列）的价格。
#### 输出:
* M期后你持有的现金，一个精确到小数点后一位的浮点数。
#### 输入样例：
```C++
1 2 0.1
1
2
```
#### 输出样例：
```C++
1.8
```

### 02、小火车调度
* 编译器版本: gcc 4.8.4 请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
* 内存限制: 64M (C/C++以外的语言为: 576 M)
* 时间限制: 1S (C/C++以外的语言为: 3 S)  
#### 题目描述：
* 多多岛上有很多小火车, 在提茅斯机房由原来的放射性火车库排列改成了新的车库，每个车库只能存放一辆小火车，每个小火车进到车库只能是单行。每个小火车出车库由一个天车把移动钢轨放到车库前，然后该列上的小火车从下而上优先出库。你能帮胖总管实现火车出站调度吗？
* 
```C++
     a
    /  \
   b      c
 /  \   /  \
d    e f    g
 \    / \
  h  j   i
          \
           k
            \
             l
a:托马斯（Thomas）
b:艾德华（Edward）
c:亨利（Henry）
d:高登（Gordon）
e:詹姆士（James）
f:培西（Percy）
g:托比（Toby）
h:达克（Duke）
j:唐纳德&道格拉斯（Donald&Douglas）
j:奥利佛（Oliver）
k:亚瑟（Arthur）
l:艾蜜莉（Emily）
```
#### 输入:
* 第几个出站
#### 输出:
* 出站火车名字
#### 输入样例：
```C++
1
```
#### 输出样例：
```C++
艾蜜莉
```

# 参考代码：
```C++
//01.炒股
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include "VectorHelper.h"
using namespace std;
/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
{
	vector<pair<int, double>> minPrice;
	for (int i = 0;i < n;i++)
	{
		pair<int, double> temp(0, prices[0][i]);
		minPrice.push_back(temp);//初始化第0天的股价为最低股价
	}
	vector<double> dpCash(m, 0);
	dpCash[0] = 1.0;
	for (int i = 1;i < m;i++)
	{
		double max = 0;
		//从第二期开始计算最大cash，此时找出最大的股价差值和cash数
		for (int j = 0;j < n;j++)
		{
			//当前天的最大cash是当前股票减去之前股票最低价然后乘以股票最低价对应的cash值
			if (dpCash[minPrice[j].first] * (prices[i][j] - minPrice[j].second) > max)
			{
				max = dpCash[minPrice[j].first]/ minPrice[j].second * prices[i][j];
			}
		}
		//找到了最大cash后，记录进dpCash
		dpCash[i] = max * (1 - p);
		//最后更新最小股价
		for (int j = 0;j < n;j++)
		{
			if (minPrice[j].second >= prices[i][j])
			{
				minPrice[j].first = i;
				minPrice[j].second = prices[i][j];
			}
		}
	}
	return dpCash[m-1];
}
/******************************结束写代码******************************/


int main()
{
	int n = 0;
	int m = 0;
	double p = 0;
	cin >> n >> m >> p;

	vector<vector<double>> prices;
	for (int i = 0; i < m; ++i) {
		prices.push_back(vector<double>());
		for (int j = 0; j < n; ++j) {
			double x = 0;
			cin >> x;
			prices.back().push_back(x);
		}
	}

	double final = StockGod(n, m, p, prices);
	printf("%.1f\n", final);
	system("pause");
	return 0;
}
```

```C++
#include <map>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include<string>
using namespace std;
struct BT
{
	int key;
	BT *l, *r;
	BT(int x) :key(x), l(NULL), r(NULL) {};
};

BT* create_n(int key)
{
	return new BT(key);
}

bool train_schedule(BT* rt, int index)
{
	if (!rt)
		return false;

	map<int, string> m_train;
	m_train[0] = "Thomas";
	m_train[1] = "Edward";
	m_train[2] = "Henry";
	m_train[3] = "Gordon";

	m_train[4] = "James";
	m_train[5] = "Percy";
	m_train[6] = "Toby";
	m_train[7] = "Duke";

	m_train[8] = "Donald&Douglas";
	m_train[9] = "Oliver";
	m_train[10] = "Arthur";
	m_train[11] = "Emily";
	//TODO:write the real train schedule code here 
	vector<char> schedule;
	queue<BT*> qB;
	qB.push(rt);
	while (!qB.empty())
	{
		BT* q = qB.front();
		qB.pop();
		schedule.push_back(q->key);
		if (q->l)
			qB.push(q->l);
		if (q->r)
			qB.push(q->r);
	}
	reverse(schedule.begin(), schedule.end());
	for (int i = 0;i < schedule.size();i++)
	{
		cout << schedule[i] << " ";
	}
	cout << endl;
	cout << m_train[(schedule[index - 1] - 'a')] << endl;
	return true;
}
int main()
{
	int i = 0;
	BT *rt = create_n('a');
	rt->l = create_n('b');
	rt->r = create_n('c');
	rt->l->l = create_n('d');
	rt->l->r = create_n('e');
	rt->r->l = create_n('f');
	rt->r->r = create_n('g');
	rt->r->l->r = create_n('h');
	rt->r->r->r = create_n('i');
	rt->r->r->l = create_n('j');
	rt->r->r->l->r = create_n('k');
	rt->r->r->l->r->r = create_n('l');
	std::cin >> i;

	train_schedule(rt, i);
	system("pause");
	return 0;
}
```
