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
		//��¥�ݣ���̨�ף��Ǿ����DP���⣨Ҳ���Կ�����״̬ת�����⣩������DP���⣬һ��Ľ��˼·�����㣺
		//1��ȷ����ʼ״̬��ȷ������״̬��һ��������״̬������DP���������Ҳ��һ��ά�ȡ�
		//2��ȷ�����ƹ�ϵʽ��Ҳ��״̬ת�Ʒ��̣���δ����е�һ��״̬��ǰ�ƽ����������ƽ������з�����ÿ�����������������
		//������ƹ�ϵʽһ�������DP��������⼸��ά�ȡ�
		//�Ӵ������������DP�����������Ľ��з�����
		//1����ʼ״̬��n = 0,Ҳ��û�п�ʼ����ʱ�����ǽ�dp[0]��ʼ��Ϊ1����ʾ��ǰ״ֻ̬��һ�������
		//2������״̬��i = n��������̨�ף�������dp[n]
		//dp[i] i = 1,2....,n��ʾ��0��ʼ������i��̨�׵�distinct ways��
		//���ƹ�ϵʽ����Ҫ������i��̨�ף���ֻ�������������������һ���Ǵ�i - 1����i,һ����i - 2����i����һ�׳��⣩
		//dp[i] = dp[i - 1] + dp[i - 2];i = 2,3,...,n
		if (n <= 0)//���n<= 0����ֱ�ӷ���1
			return 1;
		//�����������ʼ��dp����
		vector<int> dp(n + 1, 1);//��dp[0]��ʼ��Ϊ1��������dp[1,2,..,n]�����ں�������޸ģ����Գ�ʼ��Ϊ���ٶ�����Ӱ�졣
		for (int i = 1;i <= n;i++)
		{//����Ҫ�ӳ�ʼ״̬�����������ҵ���1,2,...,n�����й�n��״̬������i = [1,n]
			if (i == 1)
				dp[i] = dp[i - 1];
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];//���ص�n���ǳ�ʼ״̬����Ϊ�����ֵ
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
		//ʹ�ö�̬�滮���н���������⿼��״̬ת�ƵĹ��̣�dp[i][j]��ʾword1ǰi���ַ���ɵ��ַ�����word2��ǰj���ַ�
		//��ɵ��ַ����ľ��롣
		//������Ҫ�㣺1��ʼ��״̬��dp[0][0] = 0(�����մ��ľ���Ϊ0���޿�����);dp[m][n]��Ϊ��������վ��롣
		//2��ת�Ʒ��̣�Ҫ�ҵ�dp[i][j]��word1[0,...,i - 1]��word2[0,...,j - 1]�����ַ����ľ��룬Ҫ��֮ǰ��״̬ת�Ƶ���ǰ״̬�Ĺ����У��ҵ���С���Ǹ�����
		//������word1[i - 1]!= word2[j - 1],��ǰƥ��������ַ�����ȣ�
		//dp[i][j]_1 =dp[i - 1][j - 1] + 1, ����ǰ�ַ�����ȣ����滻
		//��word1[i - 1] == word2[j - 1]����ǰƥ��������ַ���ȣ�dp[i][j]_2 = dp[i - 1][j - 1]
		//�ۺ����������dp[i][j]_replace = min(dp[i][j]_1, dp[i][j]_2)
		//dp[i][j]_insert = dp[i - 1][j] + 1
		//dp[i][j]_delete = dp[i][j - 1] + 1
		//�ۺ������������ѡ����Сֵ��Ϊ��ǰ��dp[i][j]
		if (word1.empty() || word2.empty())//�������ַ���������һ��Ϊ�գ���ֱ�ӿ�����������Ϊ�ַ�������֮��
			return word1.size() + word2.size();
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));//����(m+1)*(n+1)DP���󣬳�ʼ��Ϊ0
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