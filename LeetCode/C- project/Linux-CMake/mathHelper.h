//
// Created by cb on 17-5-13.
//

#ifndef LEETCODE_MATHHELPER_H
#define LEETCODE_MATHHELPER_H

#endif //LEETCODE_MATHHELPER_H
#pragma once
//
// Created by CB on 04/18-2007
//
#include "head.h"
//#include<string>
using namespace std;
namespace mathHelper
{
    long long int divideL(long long dividend, long long divisor)
    {
        if (divisor == 0)
            return INT32_MAX;
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
        if (res < INT32_MIN || res > INT32_MAX)
            return INT32_MAX;
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
        if (n == INT32_MIN)
            return 1.0 / (myPow(x, INT32_MAX)*x);//特殊情况3的处理办法
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
    int mySqrt(int x) {
        /*  Accepted
        69. Sqrt(x) Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 147332
        Total Submissions: 536548
        Difficulty: Easy
        Contributor: LeetCode
        Implement int sqrt(int x).

        Compute and return the square root of x.
        */
        //牛顿法求解
        //（res+x/res）/2 >= sqrt(x)
        //逼近求解
        long long res = x;
        while (res * res > x)
            res = (res + x / res) / 2;
        return res;
    }

    bool isPerfectSquare(int num) {
        /*  Accepted
        367. Valid Perfect Square Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 38909
        Total Submissions: 102714
        Difficulty: Easy
        Contributor: LeetCode
        Given a positive integer num, write a function which returns True if num is a perfect square else False.

        Note: Do not use any built-in library function such as sqrt.

        Example 1:

        Input: 16
        Returns: True
        Example 2:

        Input: 14
        Returns: False
        Credits:
        Special thanks to @elmirap for adding this problem and creating all test cases.
        */
        int sNum = mySqrt(num);
        return (sNum * sNum == num) ? true : false;
    }
}