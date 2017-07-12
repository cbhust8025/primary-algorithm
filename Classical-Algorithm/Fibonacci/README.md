# 斐波那契数列-- 费式数列
> 斐波那契数列是一个经典的问题。

## 斐波那契数列

### 1、起源
斐波那契数列（Fibonacci sequence），又称黄金分割数列、因数学家列昂纳多·斐波那契（Leonardoda Fibonacci）以兔子繁殖为例子而引入，故又称为“兔子数列”，指的是这样一个数列：```1、1、2、3、5、8、13、21、34、……```在数学上，斐波纳契数列以如下被以递归的方法定义：```F(0)=0，F(1)=1, F(n)=F(n-1)+F(n-2)（n>=2，n∈N*）```在现代物理、准晶体结构、化学等领域，斐波纳契数列都有直接的应用，为此，美国数学会从1963起出版了以《斐波纳契数列季刊》为名的一份数学杂志，用于专门刊载这方面的研究成果。

## 2、实例
斐波那契数列：```1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...```
如果设F(n）为该数列的第n项（n∈N*），那么这句话可以写成如下形式：```F(n)=F(n-1)+F(n-2)```
显然这是一个线性递推数列。 


## 3、解决思路：
> 按照递推关系式，依次计算即可。

## 4、实现源码：
```C++
#include <iostream>
#include <vector>

using namespace std;

#define N 10

void printVector(vector<int>& vi)
{
	for (int i = 0;i < vi.size();i++)
	{
		cout << vi[i] << ((i == vi.size() - 1) ? " " : "->");
	}
	cout << endl;
	return;
}

int main()
{
	vector<int> viFibonacci( N, 0 );

	viFibonacci[0] = 1;
	viFibonacci[1] = 2;
	for (int i = 2; i < N;i++)
	{
		viFibonacci[i] = viFibonacci[i - 1] + viFibonacci[i - 2];
	}
	printVector(viFibonacci);
	system("pause");
	return 0;
}
```
