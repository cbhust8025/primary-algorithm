#  Valid Number
## 描述：
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:  
Only one letter can be changed at a time  
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
>### Note:
* Return an empty list if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* You may assume no duplicates in the word list.
* You may assume beginWord and endWord are non-empty and are not the same.
>input:
```C++
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
```
>output:
```C++
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
```
## 接口：
```C++
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    }
};
```
## 分析：
### 1、解析：暴力搜索
对于给出的单词列表以及起始单词，使用每次只改变一个字母的方法，从起始单词经过单词列表中的单词达到目的单词。
对于这个题目，首先想到的方法就是暴力搜索，从起始单词开始，找到所有距离起始单词为1且未被搜索过的单词列表中的单词，以这些单词为起始单词，目的单词保持不变，继续向下进行搜索：19 / 39 test cases passed.（leetcode）
```C++
int GetWordsDistance(string& a, string& b)
	{
		if (a.size() != b.size())
			return false;
		int count = 0;
		for (int i = 0;i < a.size();i++)
		{
			if (a[i] != b[i])
				count++;
		}
		return count;
	}
	void FindLadders(vector<vector<string>>& vvsRes, map<string, vector<string>>& vviDistance, vector<string>& wordList, vector<string>& vsPath, map<string, bool>& flag, string beginWord, string endWord)
	{
		//回溯法两大要素：
		//1、何时追溯，找到当前wordList中没有遍历过的，并且与beginWord的距离为1（仅需改变一个字母即可变成beginWord）的单词，并压入路径中，追溯
		//2、何时回溯：1）找完wordList，自然回溯，2）beginWord == endWord，达到目的地，保存路径，回溯
		if (beginWord == endWord)//如果找到了目标的单词，保存路径并回溯
		{
			if (vvsRes.empty())//如果当前未保存路径，则将当前路径保存进去
				vvsRes.push_back(vsPath);
			else if (vvsRes[0].size() == vsPath.size())//如果当前路径等于已经保存的路径长度，则保存当前路径
				vvsRes.push_back(vsPath);
			else if (vvsRes[0].size() > vsPath.size())//如果当前路径长度较小，清空已经保存的路径集合，重新保存
			{
				vvsRes.clear();
				vvsRes.push_back(vsPath);
			}
			VectorHelper::printMatrix(vvsRes);
			return;//其他情况不进行操作，直接进行回溯
		}
		vector<string> distance = vviDistance[beginWord];
		for (int i = 0;i < distance.size();i++)
		{//从wordList里面进行挑选与当前beginWord距离为1的所有未遍历过的单词
			if (!flag[distance[i]])
			{//找到距离为1的单词，进行追溯
				flag[distance[i]] = true;
				vsPath.push_back(distance[i]); 
				FindLadders(vvsRes, vviDistance, wordList, vsPath, flag, distance[i], endWord);//追溯
				flag[distance[i]] = false;
				vsPath.pop_back();//回溯完的重置操作
			}
		}
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//回溯法，但是分支太多，然而还是超时
		vector<vector<string>> vvsRes;//保存所有的路径结果
		vector<string> vsPath;//保存某一条路径
		vsPath.push_back(beginWord);//保存路径起点
		//保存wordList距离每个单词为1的单词集合
		map<string,vector<string>> vviDistance;
		map<string, bool>flag;//对已经遍历过得结果进行标记
		for (int i = 0;i <= wordList.size();i++)
		{
			pair<string, vector<string>>temp;
			if (i == 0)
				temp.first = beginWord;
			else
			{
				temp.first = wordList[i - 1];
				flag.insert(flag.end(), pair<string, bool>{wordList[i - 1], false});
			}
			for (int j = 0;j < wordList.size();j++)
			{
				if (i - 1 == j)
					continue;
				else
					if (GetWordsDistance(temp.first, wordList[j]) == 1)
						temp.second.push_back(wordList[j]);
			}
			vviDistance.insert(temp);
		}
		FindLadders(vvsRes, vviDistance,wordList, vsPath, flag, beginWord, endWord);
		VectorHelper::printMatrix(vvsRes);
		return vvsRes;
	}
```
### 2、解析：优化数据结构
   暴力搜索无法解决，主要原因是我们在进行搜索的时候，会遇到太多无用的分支，但是为了保证我们不遗漏任何一种情况，必须要进行搜索该分支，因而浪费了大量的时间，对于树形结构的该问题，我们无法继续进行解决，所以考虑在数据结构上进行优化，我们将树中的所有距离为1的节点进行连接，并将重复的节点进行删除，我们可以得到如下图一样的结构：
![图1](https://github.com/cbhust8025/primary-algorithm/blob/master/LeetCode/ValuableHP/JpgSave/126_1.jpg)  
   对于无权边图，我们使用简单的广度优先搜索算法即可，第一次找到目标节点的路径一定是最短的路径，时间复杂度也下降至O(|V| + |E|)。对于此种结构，我们可以使用邻接表进行保存图，体现在stl库中即为```map<string,vector<string>>```
### 4、AC代码：
```C++

```
### 5、参考:
[leetcode解题报告](http://www.cnblogs.com/ShaneZhang/p/3748494.html)
