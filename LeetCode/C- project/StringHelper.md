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
}
```


