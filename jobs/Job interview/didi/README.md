# 滴滴出行 笔试
> 2017-0422 19:00-21:00 记录笔试相关题目
## 选填题
* 1、12瓶药，一个天平，有一瓶重量不等于其他瓶，其余瓶重量相等，至少称多少次可以找出这瓶异常药瓶？
* 2、哈夫曼树的带权长度的求解。
* 3、“堆排序” 的平均时间复杂度和最坏时间复杂度都是O(nlogn)。
* 4、先序+后序，先序+中序，中序+后序，三种情况下，只有先序+后序不能重建二叉树。[参考](http://blog.csdn.net/zhaojinjia/article/details/9314989)

## 编程题
> AC解附后
### 01、字符串单词逆序
* 时间限制：C/C++语言 2000MS；其他语言 4000MS
* 内存限制：C/C++语言 65536KB；其他语言 589824KB
### 题目描述：
对于一个若干单词组成的字符串，对其中的每个单词进行翻转，其中标点符号算作某个单词的一部分（为简单起见）。
##### 输入  
>输入一个字符串。
##### 输出  
>输出每个单词都逆序后的字符串。

#### 样例输入
```
I have a dream!
```
#### 样例输出
```
I evah a !maerd
```

### 02、娃娃嵌套
* 时间限制：C/C++语言 2000MS；其他语言 4000MS
* 内存限制：C/C++语言 65536KB；其他语言 589824KB
### 题目描述：
对于若干大小不一的娃娃，将其进行嵌套，嵌套的前提是一个娃娃的长宽都“大于”另一个娃娃。输出最大嵌套层数。
##### 输入  
>输入第一行是娃娃个数N，剩下N行分别是每个娃娃的长和宽。
##### 输出  
>输出可以使用最多多少个娃娃进行嵌套。

#### 样例输入
```
5
5 4
6 4
6 5
7 6
2 3
```
#### 样例输出
```
4
```
# 滴滴出行 面试
## 一面
* RCNN - Faster-RCNN的变化情况
* 树的深度求解代码现场编写（递归实现）
* 树深度的非递归实现。
* 长方形内中有圆，画一条线平分之
## 二面

* 已知input矩阵，和卷积核，求解输出矩阵（说出前两个即可）。
* SGD算法中T(w+1) = T(w) + a* delta(w)的a是什么含义
* 矩阵乘法时间复杂度 -- n^3
* 下面两段计算矩阵乘法的代码辨析：

```C++
*****************************************************
for (int i = 0;i < n;i++)
	for (int j = 0;j < n;j++)
		for (int k = 0;k < n;k++)
			c[i][j] = a[i][k] + b[k][j];
*****************************************************
*****************************************************
for (int i = 0;i < n;i++)
	for (int k = 0;k < n;k++)
		for (int j = 0;j < n;j++)
			c[i][j] = a[i][k] + b[k][j];
******************************************************
```
* class与struct
* 单链表push_back 和析构两个方法的实现。
* 飞机离黑盒子越近，接受的信号越强，如果已知飞机接受到了信号，如何规划飞机的飞行线路来找到黑盒子。


## 编程题AC解
```python
#!/usr/bin/env python
# encoding: gbk
#01
import sys

if __name__ == "__main__":
    n = sys.stdin.readline().rstrip("\n").split(' ')
    res = ""
    for i in range(len(n)):
        temp = list(n[i])
        temp.reverse()
        temp = "".join(temp)
        if(i != (len(n)-1)):
            res += temp +' '
        else:
            res += temp
    print res
```
```C++
// 02 嵌套娃娃
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> wawa;
	for (int i = 0;i < n;i++)
	{
		vector<int> temp(2, 0);
		cin >> temp[0] >> temp[1];
		wawa.push_back(temp);
	}
	sort(wawa.begin(), wawa.end(), [](const vector<int>a, const vector<int> b) {return a[0] != b[0]?a[0]<b[0]:a[1]<b[1];});
	vector<int> dp(n + 1, 0);
	int maxL = 0;
	int maxH = 0;
	for (int i = 1;i <= n;i++)
	{
		if (wawa[i - 1][0] > maxL && wawa[i - 1][1] > maxH)
		{
			dp[i] = dp[i - 1] + 1;
			maxL = wawa[i - 1][0];
			maxH = wawa[i - 1][1];
		}
		else
			dp[i] = dp[i - 1];
	}
	cout << dp[n] << endl;
	system("pause");
	return 0;
}
```
