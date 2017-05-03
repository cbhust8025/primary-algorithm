```C++
#pragma once
//
// Created by CB on 03/05-2017
//
#include"VectorHelper.h"

namespace DynamicProgrammingHelper 
{
	int combinationSum4(vector<int>& nums, int target) {
		/* Accepted
		377. Combination Sum IV Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 32163
		Total Submissions: 77168
		Difficulty: Medium
		Contributor: LeetCode
		Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

		Example:

		nums = [1, 2, 3]
		target = 4

		The possible combination ways are:
		(1, 1, 1, 1)
		(1, 1, 2)
		(1, 2, 1)
		(1, 3)
		(2, 1, 1)
		(2, 2)
		(3, 1)

		Note that different sequences are counted as different combinations.

		Therefore the output is 7.
		Follow up:
		What if negative numbers are allowed in the given array?
		How does it change the problem?
		What limitation we need to add to the question to allow negative numbers?
		*/
		//数量巨大，考虑使用dp方法求解，类似跳台阶。
		//nums[1,2,3]代表的是每次跳台阶，可以跳多少阶台阶
		//target，代表目标的台阶数
		//dp[i] 0<=i<=target 代表跳到第i阶台阶所有的情况或者组合。
		int n = nums.size();
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1;i <= target;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (i - nums[j] >= 0)
				{
					dp[i] += dp[i - nums[j]];
				}
			}
		}
		return dp[target];
	}
	int maxSubArray(vector<int>& nums) {
		/* Accepted
		53. Maximum Subarray Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 186647
		Total Submissions: 475818
		Difficulty: Easy
		Contributor: LeetCode
		Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

		For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
		the contiguous subarray [4,-1,2,1] has the largest sum = 6.

		click to show more practice.

		More practice:
		If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
		*/
		//经典DP问题，从第一个元素依次往后找并加到当前子序列和中
		//若子序列和小于等于0，则表示子序列不应加入当前元素，将子序列进行重置，并将之前计算的子序列和与已知最大的子序列和比较，并存入
		//若子序列和大于0，说明可加入子序列中，并继续向后找。
		if (nums.empty())
			return 0;
		int MaxSum = nums[0];
		int subMaxSum = nums[0];
		for (int i = 1;i < nums.size();i++)
		{//从第一个元素找到最后一个元素，不遗漏。
			if (subMaxSum < 0)
				//如果之前的子序列和小于0，那么将成为后面的子序列的负担
				//则将子序列清空，将当前元素当做新子序列的第一个元素
				subMaxSum = nums[i];
			else
				//如果之前的子序列不小于0，则可以继续维持子序列，将当前元素添加到当前子序列中，进行求和
				subMaxSum += nums[i];
			MaxSum = max(MaxSum, subMaxSum);//每次修改子序列和的同时，保存最大值
		}
		return MaxSum;
	}
	int uniquePaths(int m, int n) {
		/*  Accepted
		62. Unique Paths Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 132269
		Total Submissions: 328958
		Difficulty: Medium
		Contributor: LeetCode
		A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

		The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

		How many possible unique paths are there?


		Above is a 3 x 7 grid. How many possible unique paths are there?

		Note: m and n will be at most 100.
		*/
		//动态规划可解，初始化一个m*n的矩阵，表示路径数，dp[i][j]代表从(0,0)到(i,j)的所有不同路径数
		//动态规划核心：递推关系式
		//if(i == 0 || j == 0)dp[0][j+1] = dp[0][j] + 1 || dp[i+1][0] = dp[i][0] + 1;
		//else dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j]
		vector<vector<int>> dp(m, vector<int>(n, 1));
		VectorHelper::printMatrix(dp);
		for (int i = 1;i < m;i++)
		{
			for (int j = 1;j < n;j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		VectorHelper::printMatrix(dp);
		return dp[m - 1][n - 1];
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		/*  Accepted
		63. Unique Paths II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 98127
		Total Submissions: 313189
		Difficulty: Medium
		Contributor: LeetCode
		Follow up for "Unique Paths":

		Now consider if some obstacles are added to the grids. How many unique paths would there be?

		An obstacle and empty space is marked as 1 and 0 respectively in the grid.

		For example,
		There is one obstacle in the middle of a 3x3 grid as illustrated below.

		[
		[0,0,0],
		[0,1,0],
		[0,0,0]
		]
		The total number of unique paths is 2.

		Note: m and n will be at most 100.
		*/
		//动态规划解决，注意当前位置为障碍，注意能到达当前位置的位置可能为障碍，注意初始位置可能为障碍.
		if (obstacleGrid[0][0] == 1)
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 1));
		for (int i = 1;i < m;i++)
		{
			dp[i][0] = dp[i - 1][0] * (1 - obstacleGrid[i][0]);
		}
		for (int j = 1;j < n;j++)
		{
			dp[0][j] = dp[0][j - 1] * (1 - obstacleGrid[0][j]);
		}
		for (int i = 1;i < m;i++)
		{
			for (int j = 1;j < n;j++)
			{
				dp[i][j] = (dp[i - 1][j] * (1 - obstacleGrid[i - 1][j]) + dp[i][j - 1] * (1 - obstacleGrid[i][j - 1]))*(1 - obstacleGrid[i][j]);
			}
		}
		printMatrix(dp);
		return dp[m - 1][n - 1];
	}
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
```
