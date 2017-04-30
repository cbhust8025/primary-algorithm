```C++
#pragma once
//
// Created by CB on 04/18-2007
//
#include<iostream>
#include<cassert>
#include<ctime>
//#include<string>
using namespace std;
namespace mathHelper
{
	long long int divideL(long long dividend, long long divisor)
	{
		if (divisor == 0)
			return INT_MAX;
		if (dividend == 0)
			return 0;
		long long  res = 0;
		long long divid = abs(dividend);
		long long divis = abs(divisor);
		cout << divid << " " << divis << endl;
		while (divid > divis)
		{
			int shift = 0;
			long long part = 1;
			while (divid > (divis << shift))
			{
				part <<= 1;
				shift++;
			}
			if (divid == (divis << shift))
			{
				res += part;
				break;
			}
			else
			{//divid < (divis<<shift)
				part >>= 1;
				shift--;
			}
			res += part;
			divid -= (divis << shift);
		}
		if (divid == divis)res++;
		if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
		{
			return res;
		}
		else return -res;
	}
	int divide(int dividend, int divisor) {
		/* Accepted
		29. Divide Two Integers Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 96895
		Total Submissions: 606899
		Difficulty: Medium
		Contributor: LeetCode
		Divide two integers without using multiplication, division and mod operator.

		If it is overflow, return MAX_INT.
		*/
		long long res = divideL(dividend, divisor);
		if (res < INT_MIN || res > INT_MAX)
			return INT_MAX;
		return res;
	}
	int countBitDiff(int m, int n) {
		/* Accepted
		时间限制：1秒 空间限制：32768K 热度指数：7774
		算法知识视频讲解
		题目描述
		世界上有10种人，一种懂二进制，一种不懂。那么你知道两个int32整数m和n的二进制表达，有多少个位(bit)不同么？
		输入例子:
		1999 2299

		输出例子:
		7
		*/
		int count = 0;
		while (m != 0 || n != 0)
		{
			if ((m & 0x1) != (n & 0x1))
			{
				count++;
			}
			m >>= 1;
			n >>= 1;
		}
		return count;
	}
	double myPow(double x, int n) {
		/* Accepted
		50. Pow(x, n) Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 144598
		Total Submissions: 542549
		Difficulty: Medium
		Contributor: LeetCode
		Implement pow(x, n).

		Subscribe to see which companies asked this question.
		*/
		if (n == 0)
			//x^0 = 1
			return 1.0;
		if (n == 1)
			return x;
		if (n == -1)
			return 1.0 / x;
		if (n == INT_MIN)
			return 1.0 / (myPow(x, INT_MAX)*x);//特殊情况3的处理办法
		if (n % 2 == 0)
		{
			double temp = myPow(x, n / 2);
			return temp*temp;
		}
		else
		{
			double temp = myPow(x, (n - 1) / 2);
			return temp*temp*x;
		}
	}
}
```


