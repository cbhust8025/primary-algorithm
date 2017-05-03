#pragma once
//
// Created by CB on 03/05-2017
//
#include"VectorHelper.h"

namespace DynamicProgrammingHelper 
{
	int climbStairs(int n) {
		/*  Accepted
		70. Climbing Stairs Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 167020
		Total Submissions: 424464
		Difficulty: Easy
		Contributor: LeetCode
		You are climbing a stair case. It takes n steps to reach to the top.

		Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

		Note: Given n will be a positive integer.
		*/
		//爬楼梯，跳台阶，是经典的DP问题（也可以看做是状态转移问题），对于DP问题，一般的解决思路是两点：
		//1、确定初始状态，确定结束状态，一般这两个状态决定了DP数组的列数也即一个维度。
		//2、确定递推关系式，也即状态转移方程，如何从其中的一个状态向前推进或者逆向推进，其中发生的每种情况必须分析清楚。
		//这个递推关系式一般决定了DP数组的另外几个维度。
		//从此题出发，来从DP问题两个核心进行分析：
		//1、初始状态：n = 0,也即没有开始跳的时候，我们将dp[0]初始化为1，表示当前状态只有一种情况。
		//2、结束状态：i = n，结束跳台阶，迭代出dp[n]
		//dp[i] i = 1,2....,n表示从0开始跳到第i阶台阶的distinct ways。
		//递推关系式：若要跳到第i阶台阶，则只有两种情况可以跳到，一种是从i - 1跳到i,一种是i - 2跳到i（第一阶除外）
		//dp[i] = dp[i - 1] + dp[i - 2];i = 2,3,...,n
		if (n <= 0)//如果n<= 0，则直接返回1
			return 1;
		//其余情况，初始化dp数组
		vector<int> dp(n + 1, 1);//将dp[0]初始化为1，其他的dp[1,2,..,n]将会在后面进行修改，所以初始化为多少都不会影响。
		for (int i = 1;i <= n;i++)
		{//我们要从初始状态出发，依次找到第1,2,...,n阶所有共n个状态。所以i = [1,n]
			if (i == 1)
				dp[i] = dp[i - 1];
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];//返回第n个非初始状态，即为所求的值
	}

	int minDistance(string word1, string word2) {
		/*  Accepted
		72. Edit Distance Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 84118
		Total Submissions: 270011
		Difficulty: Hard
		Contributor: LeetCode
		Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

		You have the following 3 operations permitted on a word:

		a) Insert a character
		b) Delete a character
		c) Replace a character
		*/
		//使用动态规划进行解决。此问题考察状态转移的过程，dp[i][j]表示word1前i个字符组成的字符串到word2的前j个字符
		//组成的字符串的距离。
		//两核心要点：1、始终状态，dp[0][0] = 0(两个空串的距离为0，无可争议);dp[m][n]即为所求的最终距离。
		//2、转移方程：要找到dp[i][j]即word1[0,...,i - 1]和word2[0,...,j - 1]两个字符串的距离，要从之前的状态转移到当前状态的过程中，找到最小的那个距离
		//首先若word1[i - 1]!= word2[j - 1],则当前匹配的两个字符不相等，
		//dp[i][j]_1 =dp[i - 1][j - 1] + 1, 若当前字符不相等，则替换
		//若word1[i - 1] == word2[j - 1]，则当前匹配的两个字符相等，dp[i][j]_2 = dp[i - 1][j - 1]
		//综合两种情况，dp[i][j]_replace = min(dp[i][j]_1, dp[i][j]_2)
		//dp[i][j]_insert = dp[i - 1][j] + 1
		//dp[i][j]_delete = dp[i][j - 1] + 1
		//综合三种情况，挑选其最小值作为当前的dp[i][j]
		if (word1.empty() || word2.empty())//若两个字符串至少有一个为空，则直接可以求出其距离为字符串长度之和
			return word1.size() + word2.size();
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));//构造(m+1)*(n+1)DP矩阵，初始化为0
		for (int i = 0;i <= m ;i++)
			dp[i][0] = i;
		for (int j = 0;j <= n;j++)
			dp[0][j] = j;
		for (int i = 1;i <= m;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
				dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
		VectorHelper::printMatrix(dp);
		return dp[m][n];
	}
}