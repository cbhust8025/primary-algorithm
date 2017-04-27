```C++
#pragma once
//
// Created by CB on 04/18-2007
//
#include<iostream>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
namespace StringHelper
{
	string vsTostring(const vector<string>& words)
	{
		if (words.empty())
		{
			return "";
		}
		string res = "";
		for (auto it = words.cbegin();it != words.cend();it++)
		{
			res += *it;
		}
		return res;
	}

	int strStr(string haystack, string needle) {
		/*
		28. Implement strStr() Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 171774
		Total Submissions: 624405
		Difficulty: Easy
		Contributor: LeetCode
		Implement strStr().

		Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
		*/
		int flag = -1;
		if (haystack.size() < needle.size())
		{
			return flag;
		}
		for (int i = 0;i <= haystack.size() - needle.size();i++)
		{
			int j = 0;
			while (j<needle.size())
			{
				if (haystack[i + j] == needle[j])
				{
					j++;
				}
				else break;
			}
			if (j == needle.size())return i;
		}
		return flag;
	}
	vector<int> strAllStr(string haystack, string needle) {
		vector<int> flag;
		if (haystack.size() < needle.size())
		{
			return flag;
		}
		for (int i = 0;i <= haystack.size() - needle.size();i)
		{
			int j = 0;
			while (j<needle.size())
			{
				if (haystack[i + j] == needle[j])
				{
					j++;
				}
				else break;
			}
			if (j == needle.size())flag.push_back(i);
		}
		return flag;
	}
	vector<int> findSubstring(string s, vector<string>& words) {
		/* Accepted
		30. Substring with Concatenation of All Words Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 75877
		Total Submissions: 348096
		Difficulty: Hard
		Contributor: LeetCode
		You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

		For example, given:
		s: "barfoothefoobarman"
		words: ["foo", "bar"]

		You should return the indices: [0,9].
		(order does not matter).
		*/
		vector<int> res;
		if (words.empty())
		{
			return res;
		}
		int k = words[0].size();
		//sort(words.begin(), words.end(), [](const string a, const string b) {return a < b;});
		map<string, int> strmap, temp;
		for (int i = 0;i < words.size();i++)
		{
			strmap[words[i]]++;
		}

		for (int i = 0;i <= int(s.size() - words.size()*k);i++)
		{
			temp.clear();
			int j = 0;
			for (;j < words.size();j++)
			{
				string sub = s.substr(i + j*k, k);
				if (strmap.find(sub) == strmap.end())break;
				temp[sub] ++;
				if (strmap[sub] < temp[sub])break;
			}
			if (j >= words.size())res.push_back(i);
			
		}
		return res;
	}
	int longestValidParentheses(string s) {
		/*
		32. Longest Valid Parentheses Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 90784
		Total Submissions: 394571
		Difficulty: Hard
		Contributor: LeetCode
		Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

		For "(()", the longest valid parentheses substring is "()", which has length = 2.

		Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
		*/
		vector<int> dp(s.size() + 1, 0);
		int max = 0;
		for (int i = s.size() - 2;i >= 0;i--)
		{
			if (s[i] == '(')
			{
				int j = i + 1 + dp[i + 1];
				if (j < s.size() && s[j] == ')')
				{
					dp[i] = dp[i + 1] + 2;
					if (j + 1 < s.size())
					{
						dp[i] += dp[j + 1];
					}
				}
			}
			if (dp[i] > max)
				max = dp[i];
		}
		return  max;
	}
	string countAndSay(int n) {
		/* Accepted
		38. Count and Say Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 128288
		Total Submissions: 382187
		Difficulty: Easy
		Contributor: LeetCode
		The count-and-say sequence is the sequence of integers beginning as follows:
		1, 11, 21, 1211, 111221, ...

		1 is read off as "one 1" or 11.
		11 is read off as "two 1s" or 21.
		21 is read off as "one 2, then one 1" or 1211.
		Given an integer n, generate the nth sequence.

		Note: The sequence of integers will be represented as a string.
		*/
		//统计n-1时候字符的字符情况 n=1时返回1,n=2时因为n=1是1所以统计到了11
		if (n == 1)
			return "1";
		string ss = countAndSay(n - 1) + "*";
		string res = "";
		int count = 1;
		for (int i = 0;i < ss.size() -1 ;i++)
		{
			if (ss[i] == ss[i + 1])
			{
				count++;
			}
			else
			{
				char c = '0' + count;
				res.push_back(c);
				res.push_back(ss[i]);
				count = 1;
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
	
	string multiply(string num1, string num2) {
		/* Accepted
		43. Multiply Strings Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 96975
		Total Submissions: 365748
		Difficulty: Medium
		Contributor: LeetCode
		Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

		Note:

		The length of both num1 and num2 is < 110.
		Both num1 and num2 contains only digits 0-9.
		Both num1 and num2 does not contain any leading zero.
		You must not use any built-in BigInteger library or convert the inputs to integer directly.
		*/
		//大数乘法，两个数以字符串形式存在，字符串第一个数字不会是0，且字符串只会包含0-9十个字符。
		//如果有个字符串为空，则直接返回空字符串
		if (num1.empty() || num2.empty())
			return "";
		//如果有字符串为"0"，则直接返回"0"
		if (num1 == "0" || num2 == "0")
			return "0";
		//将两个字符串逆序，从个位开始进行乘积
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		//长度m的字符串乘以长度为n的字符串，乘积的长度最长为m+n
		string res;
		for (int i = 0;i < num1.size() + num2.size();i++)
		{
			res.push_back('0');
		}
		for (int i = 0;i < num1.size();i++)
		{//每次从第一个字符串拿出一位数，乘以第二个字符串,然后存入结果字符串中
			int CarryBit = 0;//初始化进位为0
			int j = 0;
			for (;j < num2.size();j++)
			{//num1[i] 依次乘以num2[j]，注意进位和保存结果到res中，i也即当前的计算结果保存的偏移值。
				int r = (res[i+j] - '0') + (num1[i] - '0') * (num2[j] - '0') + CarryBit;//计算两个字符串中两个字符的乘积并累加到res的对应位上,注意加上进位
				//对乘积进行对10取余为计算结果，取商为进位，分别保存
				CarryBit = r / 10;
				res[i + j] = '0' + r % 10;
			}
			while (j<res.size() && CarryBit != 0)
			{
				int r = (res[i + j] - '0') + CarryBit;
				if (r < 10)
				{
					res[i + j] = '0' + r;
					break;
				}
				else
				{
					CarryBit = r / 10;
					res[i + j] = '0' + r % 10;
					j++;
				}
			}
			cout << res << endl;
		}
		while (res[res.size() - 1] == '0')
		{
			res.pop_back();
		}
		reverse(res.begin(), res.end());
		
		return res;
	}
}
```


