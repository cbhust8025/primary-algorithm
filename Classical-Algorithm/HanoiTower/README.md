# Tower of Hanoi -- 汉诺塔问题
> 汉诺塔是一个经典的递归问题求解模型，其向上变种会有双色汉诺塔问题、三色汉诺塔问题。

## 基本汉诺塔

### 1、起源
大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。一天移动一个圆盘，当圆盘全部移动另一个柱子上时宇宙就将毁灭。

## 2、实例
有三根相邻的柱子，标号为A,B,C，A柱子上从下到上按金字塔状叠放着n个不同大小的圆盘，要把所有盘子一个一个移动到柱子B上，并且每次移动同一根柱子上都不能出现大盘子在小盘子上方，请问至少需要多少次移动，设移动次数为H(n）。  
**要求:**
* 对于指定的n，我们可以求出移动次数H(n)，并且给出每一次移动的起点和终点。

## 3、解决思路：
> 因为问题的复杂性，我们将其逐步分解就可以清晰的看到我们应该如何去做。  
* 当n = m时： 
>* 首先将1-(m-1)总共m-1个圆盘从A->C
>* 然后将最大的m圆盘从A->B
>* 最后将1-(m-1)总共(m-1)个圆盘从C->B
* 然后我们问题变成了如何将n = m-1时的A C B 以及 C B A 两个子问题。
* 根据这些我们需要设计一个函数，这个函数是为了解决A B C三个柱子将A上面的若干个(n个)圆盘移动到B这样的问题。
* 在每次移动的时候输出步数即可满足要求（设计一个步数移动函数即可）。

## 4、实现源码：
```C++
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define A 'A'
#define B 'B'
#define C 'C'
#define N 2

void Moving(const char ch1, const char ch2)
{
	// 将ch1移动到ch2，输出对应的步数
	cout << ch1 << " -> " << ch2 << endl;
}

int Hanoi(const char ch1, const char ch2, const char ch3, int n)
{
	// 将ch1 对应的n个圆盘移动到ch2上，返回值为所需要的步数
	// 如果n = 1 时，直接有 Moving(ch1, ch2)
	if (n == 1)
	{
		Moving(ch1, ch2);
		return 1;
	}
	int iCount = 0;
	// 如果n > 1，则我们需要先移动n - 1从ch1 -> ch3
	iCount += Hanoi(ch1, ch3, ch2, n - 1);
	// 再移动最大的圆盘从ch1 -> ch2
	Moving(ch1, ch2);
	iCount++;
	// 最后将n - 1个圆盘从ch3 -> ch2
	iCount += Hanoi(ch3, ch2, ch1, n - 1);

	return iCount;
}

int main()
{
	cout << Hanoi(A, B, C, N) << endl;
	system("pause");
	return 0;
}
```



## 双色汉诺塔（三色汉诺塔同理）

### 1、实例
有三根相邻的柱子，标号为A,B,C，A柱子上从下到上按金字塔状叠放着2n个两种颜色从小到大依次向下交错摆放的圆盘，要把所有盘子按照颜色分别摆布到B、C两个柱子上，并且每次移动同一根柱子上都不能出现大盘子在小盘子上方，请问至少需要多少次移动，设移动次数为H2(n）。  
>![双色汉诺塔](http://img.blog.csdn.net/20140929221331915)  
**要求:**
* 对于指定的n，我们可以求出移动次数H2(n)，并且给出每一次移动的起点和终点。

## 2、解决思路：
> 因为问题的复杂性，我们将其逐步分解就可以清晰的看到我们应该如何去做。  
* 当n = m时： 
>* 首先将1-(m-1)总共m-1个圆盘从A->C
>* 然后将最大的m圆盘从A->B
>* 最后将1-(m-2)总共(m-2)个圆盘从C->A,留下次大的那个圆盘在C上，这样就能顺利将两种颜色的盘子放到对应的柱子上。
* 然后我们循环上述过程分别每次将最大的两个圆盘分离到B、C柱子上。
* 根据这些我们需要设计一个函数，这个函数是为了解决A B C三个柱子将A上面的若干个(n个)圆盘的两个最大圆盘分离到B、C上这样的问题。然后循环调用此递归入口即可。
* 在每次移动的时候输出步数即可满足要求（设计一个步数移动函数即可）。

## 3、实现源码：
```C++
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define A 'A'
#define B 'B'
#define C 'C'
#define N 2

void Moving(const char ch1, const char ch2)
{
	// 将ch1移动到ch2，输出对应的步数
	cout << ch1 << " -> " << ch2 << endl;
}

int Hanoi(const char ch1, const char ch2, const char ch3, int n)
{
	// 将ch1 对应的n个圆盘最大的两个圆盘分离到ch2,ch3上，并将剩下的n - 2个圆盘放到ch1上，返回值为所需要的步数
	//　如果n == 0，则直接返回即可。
	if (n == 0)
	{
		return 0;
	}
	// 如果n = 1 时，直接有 Moving(ch1, ch2)
	if (n == 1)
	{
		Moving(ch1, ch2);
		return 1;
	}
	int iCount = 0;
	// 如果n > 1，则我们需要先移动n - 1从ch1 -> ch3
	iCount += Hanoi(ch1, ch3, ch2, n - 1);
	// 再移动最大的圆盘从ch1 -> ch2
	Moving(ch1, ch2);
	iCount++;
	// 最后将n - 2个圆盘从ch3 -> ch1
	iCount += Hanoi(ch3, ch1, ch2, n - 2);

	return iCount;
}

int main()
{
	// 双色汉诺塔会有一个分离的过程，所以首先将最下面两个最大的分离开来
	// 这时会回到最初的A(1 ~ n - 2) B(n) C(n - 1)的状态 ，这时我们需要循环调用递归入口
	int iCount = 0;
	for(int i = 2 * N;i > 0;i -= 2)
	{
		// 不断将A 最下面的最大两个圆盘分离到BC两个柱子上
		iCount += Hanoi(A, B, C, i); 
	}
	cout << "总共需要移动：" << iCount << "步" << endl;
	system("pause");
	return 0;
}
```
