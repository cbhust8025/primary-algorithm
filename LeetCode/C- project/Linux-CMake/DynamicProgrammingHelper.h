//
// Created by cb on 17-5-13.
//

#ifndef LEETCODE_DYNAMICPROGRAMMINGHELPER_H
#define LEETCODE_DYNAMICPROGRAMMINGHELPER_H

#endif //LEETCODE_DYNAMICPROGRAMMINGHELPER_H
#pragma once
//
// Created by CB on 03/05-2017
//
#include "head.h"
#include"VectorHelper.h"


namespace DynamicProgrammingHelper
{
    using namespace VectorHelper;
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

    bool judge(const char a, const char b)
    {
        if (a == '1') return true;
        else if (a == '2' && b <= '6') return true;
        return false;
    }

    int numDecodings(string s) {
        /*  Accepted
        91. Decode Ways Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 115053
        Total Submissions: 595966
        Difficulty: Medium
        Contributor: LeetCode
        A message containing letters from A-Z is being encoded to numbers using the following mapping:

        'A' -> 1
        'B' -> 2
        ...
        'Z' -> 26
        Given an encoded message containing digits, determine the total number of ways to decode it.

        For example,
        Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

        The number of ways decoding "12" is 2.
        */
        //动态规划可以解，显然，建立dp[0,1,...,s.size()]共s.size()+1长度的dp向量。
        //dp[i]表示前i个字符可以解码的方式总数
        //递推关系，因为最多解码两位数字为一个字母，考虑当前数字和前一个数字
        //前一个数字为0时，dp[i] = dp[i - 2];
        //当前数字不为0时，如果能和前面的一个数字合并能进行正常解码（1-26），则dp[i] += dp[i - 1];
        if (s.empty())
            return 0;
        vector<int> dp(s.size() + 1, 0);
        if (s[0] == '0')
            return 0;
        dp[0] = 1;//为了后面的便利，将此值设为1
        dp[1] = 1;//至少有一种解法
        for (int i = 2;i < dp.size();i++)
        {
            if (s[i - 1] == '0' && (s[i - 2] == '0' || s[i - 2] >= '3'))//对于出现‘00’，‘40’这样的情况，直接返回0
                return 0;
            if (s[i - 1] != '0')
            {
                dp[i] = dp[i - 1];//如果当前数字不为0，则总解法中至少有一部分是前i - 1所能得到的解法
            }
            cout << dp[i] << endl;
            if(s[i - 2] != '0')//如果前一个数字仍然不为 0，且和当前数字可以正常解码，则视为一体，所以总解法另一部分则为前i - 2个字符所有的解法。
            {
                if (judge(s[i - 2], s[i - 1]))
                    dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
    int numTrees(int n) {
        /*
        96. Unique Binary Search Trees Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 116432
        Total Submissions: 288161
        Difficulty: Medium
        Contributor: LeetCode
        Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

        For example,
        Given n = 3, there are a total of 5 unique BST's.

        1         3     3      2      1
         \       /     /      / \      \
          3     2     1      1   3      2
         /     /       \                 \
        2     1         2                 3
        */
        //二叉搜索树：每个节点的左子树的节点均小于此节点，右子树的节点均大于此节点
        //当k作为根节点时，小于k的只能在左子树，大于k的只能在右子树
        //所以利用DP解决，可以充分利用之前求出的DP数组信息来解决后面需要求解的dp[k]
        //总共n个节点，所以建立的dp数组长度为n + 1,包含初始状态和所需要求解的n个状态
        //显然dp[0] = dp[1] = 1;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        VectorHelper::printVector(dp);
        for (int i = 2;i <= n;i++)
        {//依次求解从1-n的n种状态，dp方法的经典过程
            if (i == 2)
                dp[i] = i;
            else
            {
                for (int j = 1;j <= i;j++)
                {//以j作为根节点，i个点总共多少种二叉搜索树的排列方式
                    //j作为根节点，1,2,...,j-1肯定在左子树，共j-1个点，j+1,j+2,...,i总共i- j个点在右子树，分别统计两个子树的排列总数，乘积即为dp[i]
                    dp[i] += dp[j - 1] * dp[i - j];
                }
            }
        }
        return dp[n];
    }

    bool isInterleave(string s1, string s2, string s3) {
        /*
        97. Interleaving String Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 67593
        Total Submissions: 278413
        Difficulty: Hard
        Contributor: LeetCode
        Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

        For example,
        Given:
        s1 = "aabcc",
        s2 = "dbbca",

        When s3 = "aadbbcbcac", return true.
        When s3 = "aadbbbaccc", return false.
        */
        //判断字符串s3是否为字符串s1和s2的交错
        //此处的交错是并集的关系，意味着s3 = s1 + s2,而不是s3 > s1 + s2
        //由于此时字符串s3的前i+j个字符串与s1的i个，s2的j个匹配结果只和s3的前i+j-1个字符匹配结果相关，
        //所以dp矩阵从m*n*h(m = s1.size() + 1,后面同理)退化成m*n(s1*s2)的维度
        //同样可以理解从原点开始前进，匹配s2中一个字符则向右走，匹配一个s1的字符，则向下走，最后能走到最右下方，则表示能够匹配成功
        if (s1.size() + s2.size() != s3.size())
            return false;
        int m = s1.size();
        int n = s2.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));//匹配成功返回true
        //dp矩阵第一行和第一列分别代表s1为空串，s2为空串的两种初始情况。
        //dp[0][0]代表两个空串去匹配空串，此时返回true
        dp[0][0] = true;
        //s1为空串---dp第一行 s2非空
        for (int i = 1;i <= n;i++)
        {
            dp[0][i] = (s2[i - 1] == s3[i - 1]) & dp[0][i - 1];
        }
        //s2为空串---dp第一列 s1非空
        for (int i = 1;i <= m;i++)
        {
            dp[i][0] = (s1[i - 1] == s3[i - 1]) & dp[i - 1][0];
        }
        for (int i = 1;i <= m;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                int k = i + j;//匹配字符串3的第k-1个字符
                if (s3[k - 1] == s1[i - 1])//若字符串的第k - 1个字符等于字符串1中的第i- 1个
                    //此时的匹配结果，与前k-2个字符的匹配结果有关（k - 1 = (i-1) + (j) ）
                    dp[i][j] = dp[i - 1][j] || dp[i][j]; //若某次匹配成功，后面根据自身的值将一直成功
                if (s3[k - 1] == s2[j - 1])//匹配字符串的k-1个字符
                    dp[i][j] = dp[i][j - 1] || dp[i][j];
            }
        }
        VectorHelper::printMatrix(dp);
        return dp[m][n];
    }
    int numDistinct(string s, string t) {
        /*
        115. Distinct Subsequences Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 67956
        Total Submissions: 218530
        Difficulty: Hard
        Contributor: LeetCode
        Given a string S and a string T, count the number of distinct subsequences of T in S.

        A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

        Here is an example:
        S = "rabbbit", T = "rabbit"

        Return 3.
        */
        //由于在中间比较的时候，会大量重复之前已经比较过的前半部分的比较，所以采用动态规划的方法，存储之前已经比较的结果
        //字符串t匹配字符串s中，所以以s的字符个数为列数，t的字符个数为行数，一行一行的填充dp数组，表示的也是一个一个增添t中的字符来进行匹配，
        //所以DP数组的大小为m+1(t)* n+1(s)
        //dp[i][j]的含义是t字符串中的前i-1个字符匹配s字符串中的j-1个字符的匹配结果
        int m = t.size();
        int n = s.size();
        if (m > n)//如果当前的字符串长于s字符串，直接返回0,即不可能实现匹配。
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //由于空字符串去匹配任何s字符串，都至少有一种子串情况，所以将dp数组第一行置为1
        dp[0] = vector<int>(n + 1, 1);
        //开始求解dp数组
        //递推关系，当前字符如果相等，则dp[i][j] = dp[i - 1][j - 1]（使用当前字符去匹配）+ dp[i][j - 1](不使用当前字符匹配)
        //如果当前字符如果不相等，dp[i][j] = dp[i][j - 1](不使用当前字符去匹配)
        for (int i = 1;i <= m;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        VectorHelper::printMatrix(dp);
        return dp[m][n];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        /*
        120. Triangle Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 100698
        Total Submissions: 303735
        Difficulty: Medium
        Contributor: LeetCode
        Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

        For example, given the following triangle
        [
           [2],
          [3,4],
         [6,5,7],
        [4,1,8,3]
        ]
        The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

        Note:
        Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

        Subscribe to see which companies asked this question.
        */
        //使用自底向上的动态规划，由于每一层的dp值只和下一层的值有关，所以可以压缩dp矩阵维度，使用一维dp矩阵，矩阵长度是最下面一行的长度
        if (triangle.empty())
            return 0;
        vector<int> dp(triangle[triangle.size() - 1]);//直接使用最下面一行初始化dp矩阵，后面对于dp矩阵进行修正
        for (int i = triangle.size() - 2;i >= 0;i--)
        {//自底向上进行计算dp矩阵值
            for (int j = 0;j < triangle[i].size();j++)//每一行修改的dp矩阵中元素个数等于当前行的元素总个数
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }

    int maxProfitI(vector<int>& prices) {
        /*  Accepted
        121. Best Time to Buy and Sell Stock Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 184364
        Total Submissions: 456446
        Difficulty: Easy
        Contributor: LeetCode
        Say you have an array for which the ith element is the price of a given stock on day i.

        If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

        Example 1:
        Input: [7, 1, 5, 3, 6, 4]
        Output: 5

        max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
        Example 2:
        Input: [7, 6, 4, 3, 1]
        Output: 0

        In this case, no transaction is done, i.e. max profit = 0.
        */
        //由于需要找到最大利润， 则需在每一天都尝试卖出，并比较当前卖出之前所有天数买进所能获得的利润，取得最大的利润，放在这一天
        //设置动态规划矩阵，保存每天所能获得的最大利润，转移方程dp[i] = max(0, dp[i-1]+prices[i]-prices[i-1])
        vector<int> dp(prices.size(), 0);//第一天肯定是0，所以只需要找到prices.size() - 1种状态即可
        int maxProfit = 0;//存储已经找到的最大利润
        for (int i = 1;i < dp.size();i++)
        {
            dp[i] = max(0, dp[i - 1] + prices[i] - prices[i - 1]);
            if (dp[i] > maxProfit)
                maxProfit = dp[i];
        }
        return maxProfit;
    }

    int maxProfitII(vector<int>& prices) {
        /*
        122. Best Time to Buy and Sell Stock II Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 137778
        Total Submissions: 297218
        Difficulty: Easy
        Contributor: LeetCode
        Say you have an array for which the ith element is the price of a given stock on day i.

        Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
        However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
        */
        int maxProfit = 0;
        for (int i = 1;i < prices.size();i++)
        {
            maxProfit += max(0, prices[i] - prices[i - 1]);//只要当天股价高于前一天就当前一天买了股票，并且于当天卖光，
        }
        return maxProfit;
    }

    int maxProfitIII(vector<int>& prices) {
        /*
        123. Best Time to Buy and Sell Stock III Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 82713
        Total Submissions: 286984
        Difficulty: Hard
        Contributor: LeetCode
        Say you have an array for which the ith element is the price of a given stock on day i.

        Design an algorithm to find the maximum profit. You may complete at most two transactions.

        Note:
        You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

        Subscribe to see which companies asked this question.
        */
        //超时答案，最大case超时
        ////同理，只能进行两次交易，由于只能同时持有一只股票，所以两次交易不能重叠，可以将prices分为两部分，分别求两部分的最大收益和
        //int maxProfit = 0;
        //int leftProfit, rightProfit, nowProfit;
        //for (int i = 0;i < prices.size();i++)
        //{//从第i天进行划分，i = 1,2,3,...,prices.size() - 1
        //	//第i天将prices分为两部分：[0,i),[i,end())
        //	vector<int> left = vector<int>(prices.begin(), prices.begin() + i);//第一部分
        //	vector<int> right = vector<int>(prices.begin() + i, prices.end());//第二部分
        //	leftProfit = maxProfitI(left);
        //	rightProfit = maxProfitI(right);
        //	nowProfit = leftProfit + rightProfit;
        //	if (maxProfit < nowProfit)
        //		maxProfit = nowProfit;
        //}
        //return maxProfit;
        if (prices.empty())
            return 0;
        //由于我们在循环调用maxProfitI(prices[0,3]),maxProfitI(prices[0,4])这样的过程中时，在其中计算会有大量重复计算I中的那个dp矩阵
        //所以我们为了节省这个dp矩阵的计算，设置两个max矩阵保存每一天极其之前的最大收益，还有每一天极其以后的最大收益(我们可以在同一天先卖出再买入)
        //每一天极其之前的最大收益
        VectorHelper::printVector(prices);
        vector<int> maxpostProfit(prices.size(), 0);
        for (int i = 1;i < prices.size();i++)
        {
            maxpostProfit[i] = max(0, maxpostProfit[i - 1] + prices[i] - prices[i - 1]);
        }
        //每一天极其之后的最大收益
        vector<int> maxpreProfit(prices.size(), 0);
        int maxprePf = 0;
        int maxPrice = prices[prices.size() - 1];
        for (int i = prices.size() - 2;i >= 0;i--)
        {
            maxprePf = max(maxprePf, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
            maxpreProfit[i] = maxprePf;
        }
        int maxProfit = 0;
        VectorHelper::printVector(maxpostProfit);
        VectorHelper::printVector(maxpreProfit);
        for (int i = 0;i < prices.size();i++)
        {
            //将第i天极其以后的最大收益+第i天极其之前的最大收益加起来就是第i天的最大收益（只进行两次操作），找到其中的最大值
            maxProfit = max(maxProfit, maxpostProfit[i] + maxpreProfit[i]);
        }
        return maxProfit;
    }

    int maxProduct(vector<int>& nums) {
        /*  A
         * 152. Maximum Product Subarray Add to List
            DescriptionHintsSubmissionsSolutions
            Total Accepted: 96218
            Total Submissions: 382554
            Difficulty: Medium
            Contributor: LeetCode
            Find the contiguous subarray within an array (containing at least one number) which has the largest product.

            For example, given the array [2,3,-2,4],
            the contiguous subarray [2,3] has the largest product = 6.
         */
        if(nums.empty())
            return 0;
        //找到连续子序列的最大乘积
        int iMaxProduct = nums[0];
        //维护一个连续乘积最大的数
        //再维护一个连续乘积最小的数
        vector<int> dpMax(nums.size(), 0);
        vector<int> dpMin(nums.size(), 0);
        dpMax[0] = nums[0];
        dpMax[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            dpMax[i] = max(max(dpMax[i - 1] * nums[i], nums[i]),dpMin[i - 1] * nums[i]);
            dpMin[i] = min(min(dpMin[i - 1] * nums[i], nums[i]),dpMax[i - 1] * nums[i]);
            iMaxProduct = max(iMaxProduct,dpMax[i]);
        }
//        printVector(nums);
//        printVector(dpMax);
//        printVector(dpMin);
        return iMaxProduct;
    }
}