//
// Created by cb on 17-5-13.
//

#ifndef LEETCODE_STRINGHELPER_H
#define LEETCODE_STRINGHELPER_H

#endif //LEETCODE_STRINGHELPER_H
#pragma once
//
// Created by CB on 04/18-2007
//
#include "head.h"
#include"VectorHelper.h"
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
    int lengthOfLastWord(string s) {
        /*   Accepted
        58. Length of Last Word Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 138976
        Total Submissions: 440687
        Difficulty: Easy
        Contributor: LeetCode
        Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

        If the last word does not exist, return 0.

        Note: A word is defined as a character sequence consists of non-space characters only.

        For example,
        Given s = "Hello World",
        return 5.
        */
        int length = 0;
        while (s[s.size() - 1] == ' ')
        {
            s.pop_back();
        }
        for (int i = 0;i < s.size();i++)
        {
            if (s[i] != ' ')
                length++;
            else if(i != s.size() - 1)
                length = 0;
        }
        return length;
    }

    string getPermutation(int n, int k) {
        /*
        60. Permutation Sequence Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 79223
        Total Submissions: 284901
        Difficulty: Medium
        Contributor: LeetCode
        The set [1,2,3,…,n] contains a total of n! unique permutations.

        By listing and labeling all of the permutations in order,
        We get the following sequence (ie, for n = 3):

        "123"
        "132"
        "213"
        "231"
        "312"
        "321"
        Given n and k, return the kth permutation sequence.

        Note: Given n will be between 1 and 9 inclusive.
        */
        string sRes;
        if (n < 1 && n > 9)
            return sRes;
        vector<int> vi;
        int fac = 1;
        for (int i = 1;i <= n;i++)
        {
            vi.push_back(i);
            fac *= i;
        }
        fac /= n;
        int round = n - 1;
        k--;
        while (round >= 0)
        {
            int index = k / fac;
            k %= fac;
            sRes.push_back(vi[index] + '0');
            vi.erase(vi.begin() + index);
            if (round)
                fac /= round;
            round--;
        }
        return sRes;
    }
    string addBinary(string a, string b) {
        /*   Accepted
        67. Add Binary Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 136371
        Total Submissions: 432573
        Difficulty: Easy
        Contributor: LeetCode
        Given two binary strings, return their sum (also a binary string).

        For example,
        a = "11"
        b = "1"
        Return "100".
        */
        if (a.empty() || b.empty())
            return a + b;
        string res;
        int CarryBit = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() != b.size())
            if (a.size() > b.size())
                b.push_back('0');
            else
                a.push_back('0');
        for (int i = 0;i < a.size();i++)
        {
            int r = int(a[i] - '0') + int(b[i] - '0') + CarryBit;
            res.push_back((r % 2) + '0');
            CarryBit = r / 2;
        }
        if (CarryBit != 0)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }

    string simplifyPath(string path) {
        /*  Accepted
        71. Simplify Path Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 82147
        Total Submissions: 332474
        Difficulty: Medium
        Contributor: LeetCode
        Given an absolute path for a file (Unix-style), simplify it.

        For example,
        path = "/home/", => "/home"
        path = "/a/./b/../../c/", => "/c"
        click to show corner cases.

        Corner Cases:
        Did you consider the case where path = "/../"?
        In this case, you should return "/".
        Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
        In this case, you should ignore redundant slashes and return "/home/foo".
        */
        stack<string> ss;
        for (int i = 0;i < path.size();)
        {
            //每次找到一个单词后，过滤掉所有的'/'
            while (i < path.size() && path[i] == '/')
                i++;
            //找到第一个不是'/'的字符之后，将当前的字符串保存下来。
            string s;
            //一直向后搜寻直到'/'结束
            while (i < path.size() && path[i] != '/')
            {
                s.push_back(path[i]);
                i++;
            }
            //如果栈不为空，且当前字符串为".."，则需进行弹出栈顶元素
            if (s == ".." && !ss.empty())
                ss.pop();
                //将所有满足要求的字符串压入栈
            else if (s != ".." && s != "." && s != "")
                ss.push(s);
        }
        //结束后，如果栈为空，则表示目录为空，则返回"/"目录
        if (ss.empty())
            return "/";
        string sRes = "";
        while (!ss.empty())
        {
            sRes = "/" + ss.top() + sRes;
            ss.pop();
        }
        return sRes;
    }
    bool isPalindrome(string s) {
        /*
        125. Valid Palindrome Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 155413
        Total Submissions: 600120
        Difficulty: Easy
        Contributor: LeetCode
        Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

        For example,
        "A man, a plan, a canal: Panama" is a palindrome.
        "race a car" is not a palindrome.

        Note:
        Have you consider that the string might be empty? This is a good question to ask during an interview.

        For the purpose of this problem, we define empty string as valid palindrome.
        */
        if (s.empty())//如果是空串，我们认为是可用的回文串
            return true;
        int n = s.size();
        //设置两个指向s头尾的指针
        int head = 0;//指向第一个字母
        int tail = s.size() - 1;//指向最后一个字母
        while (true)
        {
            while (head < s.size() && !isalnum(s[head]))head++;
            while (tail >= 0  && !isalnum(s[tail]))tail--;
            if (tail <= head)
                return true;
            if (tolower(s[head]) == tolower(s[tail]))
            {
                head++;
                tail--;
            }
            else
                return false;
        }
    }

    void reverseWords(string &s) {
        /*
         * 151. Reverse Words in a String Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 152509
        Total Submissions: 970712
        Difficulty: Medium
        Contributor: LeetCode
        Given an input string, reverse the string word by word.

        For example,
        Given s = "the sky is blue",
        return "blue is sky the".

        Update (2015-02-12):
        For C programmers: Try to solve it in-place in O(1) space.

        click to show clarification.

        Clarification:
        What constitutes a word?
        A sequence of non-space characters constitutes a word.
        Could the input string contain leading or trailing spaces?
        Yes. However, your reversed string should not contain leading or trailing spaces.
        How about multiple spaces between two words?
        Reduce them to a single space in the reversed string.
         */
        //题目说明：
        //1.翻转后的字符串前后无空字符
        //2.翻转后的字符串不存在连续的空字符
        //3.对字符串每一段连续非空字符不进行操作，整个字符串进行翻转
        //4.使用常量空间复杂度-（O(1)）
        //初步思路，若要使用常量的空间复杂度，则只能在字符串内部进行调换元素，借助中间元素来实现调换，内置有swap，reverse方法
        //第一步，首先对字符串实现滤除多余的空字符
        //利用两个指针slow和fast，均从头开始，若都遇到空格，则都前进一步，直到从第一个字符开始，遇到字符，将fast指向的字符赋给slow
        //遇到空格，slow只动一步，fast动到直到fast指向的不是空格
//        if(s.size() == 1 && s != " ")
//            return;
        auto slow = s.begin();
        auto fast = s.begin();
        int length = 0;//有效字符串的长度
        int start = 0;
        while(*fast == ' '){
            slow++;
            fast++;
            start++;
        }
        //从第一个有效字符开始
        while(fast != s.end()){
            if(*fast != ' '){
                length++;
                *slow++ = *fast++;
            }
            else{
                length++;
                *slow++ = *fast++;
                while(*fast == ' ')fast++;
            }
        }
        s = s.substr(start, length);
        reverse(s.begin(), s.end());
        auto it_1 = s.begin();
        auto it_2 = s.begin();
        while(it_1 != s.end()) {
            while(it_2 != s.end() && *it_2 != ' ')it_2++;
            reverse(it_1, it_2);
            if(it_2 == s.end())
                break;
            it_2++;
            it_1 = it_2;
        }
        if(s[0] == ' ')s.erase(s.begin());
    }

    vector<int> versionParser(string& version){
        vector<int> viVer;
        string temp;
        for(int i = 0;i < version.size();i++){
            //对版本号1进行转换成数字
            if(version[i] == '0') {
                if(temp.empty())
                    continue;
                else
                    temp.push_back('0');
            }
            else if(version[i] == '.'){
                viVer.push_back(BackTrackingHelper::parseStringToInt(temp));
                temp.clear();
            }
            else{
                temp.push_back(version[i]);
            }
        }
        viVer.push_back(BackTrackingHelper::parseStringToInt(temp));
        return viVer;
    }

    int compareVersion(string version1, string version2) {
        /* Accepted
         * 165. Compare Version Numbers Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 81786
        Total Submissions: 414855
        Difficulty: Medium
        Contributor: LeetCode
        Compare two version numbers version1 and version2.
        If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

        You may assume that the version strings are non-empty and contain only digits and the . character.
        The . character does not represent a decimal point and is used to separate number sequences.
        For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

        Here is an example of version numbers ordering:

        0.1 < 1.1 < 1.2 < 13.37
        Credits:
        Special thanks to @ts for adding this problem and creating all test cases.
         */
        //比较版本信息，点号进行分隔，将字符串变成版本信息号，前面带0的版本号一律按照去0处理（1.03 > 1.2）,注意单独的0版本号
        //1.0.2 1.2     1.0 1
        vector<int> viVer1;
        vector<int> viVer2;
        //比较字符串前面的公共部分，若相等再看哪个字符串比较长，若长度也相等，则返回0
        viVer1 = versionParser(version1);
        viVer2 = versionParser(version2);
        reverse(viVer1.begin(), viVer1.end());
        reverse(viVer2.begin(), viVer2.end());
        while(!(viVer1.empty() || viVer2.empty())){
            if(viVer1[viVer1.size() - 1] > viVer2[viVer2.size() - 1]){
                return 1;
            }
            else if(viVer1[viVer1.size() - 1] < viVer2[viVer2.size() - 1]){
                return -1;
            }
            else{
                viVer1.pop_back();
                viVer2.pop_back();
            }
        }
        while(!viVer1.empty() && viVer1[viVer1.size() - 1] == 0)viVer1.pop_back();
        while(!viVer2.empty() && viVer2[viVer2.size() - 1] == 0)viVer2.pop_back();
        if(viVer1.size() == viVer2.size())return 0;
        cout << "viVer1.size：" << viVer1.size() << " viVer2.size:" << viVer2.size() << endl;
        return (viVer1.size() > viVer2.size())? 1 : -1;
    }
}