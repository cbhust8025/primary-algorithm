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
	
}
```


