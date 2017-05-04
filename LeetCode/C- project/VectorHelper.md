```C++
#pragma once
//
// Created by CB on 04/18-2017
//
#include<iostream>
#include<cassert>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<vector>
#include<iomanip> 
#include<functional>
#include<windows.h>
#include"ListHelper.h"
//#include<string>
using namespace std;
namespace VectorHelper
{

	//生成n个节点的随机vector，每个元素的随机范围为[rangeL,rangeR]
	vector<int> generateRandomVector(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		ListHelper::ListNode* p1 = ListHelper::generateRandomList(n, rangeL, rangeR);
		vector<int> vi = ListHelper::translateList(p1);
		return vi;
	}

	//生成n个节点的随机有序vector，元素的起始值为[begin,begin+step),每两个相邻元素之间的步长在[0,step)
	vector<int> generateSortVector(int n, int begin, int step)
	{
		assert(begin > 0);
		ListHelper::ListNode* p1 = ListHelper::generateSortList(n, begin, step);
		vector<int> vi = ListHelper::translateList(p1);
		return vi;
	}


	//模板，打印Vector
	template <typename T>
	void printVector(const vector<T>& vi)
	{
		for (auto it = vi.begin();it != vi.end();it++)
		{
			cout << setw(3) << *it << " ";
		}
		cout << "NULL" << endl;
		return;
	}

	template <typename T>
	void printMatrix(const vector<vector<T>>& vi)
	{
		for (auto it = vi.begin();it != vi.end();it++)
		{
			for (auto it2 = (*it).begin();it2 != (*it).end();it2++)
			{
				cout << setw(3) << *it2 << " ";
			}
			cout << endl;
		}
		cout << "NULL" << endl;
		return;
	}


	int removeDuplicates(vector<int>& nums) {
		/* Accepted
		26. Remove Duplicates from Sorted Array Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 215412
		Total Submissions: 607081
		Difficulty: Easy
		Contributor: LeetCode
		Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

		Do not allocate extra space for another array, you must do this in place with constant memory.

		For example,
		Given input array nums = [1,1,2],

		Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

		Subscribe to see which companies asked this question.
		*/
		if (nums.size() <= 1)
		{
			return nums.size();
		}
		int iN = nums[0];
		int count = 1;
		for (int i = 1;i < nums.size();i++)
		{
			if (nums[i] != iN)
			{
				nums[count] = nums[i];
				count++;
				iN = nums[i];
			}
		}
		return count;
	}

	int removeElement(vector<int>& nums, int val) {
		/*    Accepted
		27. Remove Element Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 186459
		Total Submissions: 491057
		Difficulty: Easy
		Contributor: LeetCode
		Given an array and a value, remove all instances of that value in place and return the new length.

		Do not allocate extra space for another array, you must do this in place with constant memory.

		The order of elements can be changed. It doesn't matter what you leave beyond the new length.

		Example:
		Given input array nums = [3,2,2,3], val = 3

		Your function should return length = 2, with the first two elements of nums being 2.
		*/
		if (nums.size() == 0)
		{
			return nums.size();
		}
		int count = 0;
		for (int i = 0;i < nums.size();i++)
		{
			if (nums[i] != val)
			{
				nums[count] = nums[i];
				count++;
			}
		}
		if (count == 0)
		{
			nums.clear();
			return 0;
		}
		return count;
	}
	void nextPermutation(vector<int>& nums) {
		/* Aceepted
		31. Next Permutation Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 103891
		Total Submissions: 364359
		Difficulty: Medium
		Contributor: LeetCode
		Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

		If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

		The replacement must be in-place, do not allocate extra memory.

		Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
		1,2,3 → 1,3,2
		3,2,1 → 1,2,3
		1,1,5 → 1,5,1
		*/
		if (nums.size() <= 1)return;
		auto it = nums.end();
		int j = 1;
		while (j < nums.size() && *(it - j) <= *(it - j - 1))j++;
		if (j == 1)
		{
			int temp = *(it - 1);
			*(it - 1) = *(it - 2);
			*(it - 2) = temp;
		}
		else if (j == nums.size())
		{
			reverse(nums.begin(), nums.end());
		}
		else
		{
			int i = j;
			while (i > 0 && *(it - i) > *(it - j - 1))i--;
			int temp = *(it - i - 1);
			*(it - i - 1) = *(it - j - 1);
			*(it - j - 1) = temp;
			reverse(it - j, it);
		}
	}
	int search(vector<int>& nums, int target) {
		/*
		33. Search in Rotated Sorted Array Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 160291
		Total Submissions: 499044
		Difficulty: Medium
		Contributor: LeetCode
		Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

		(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

		You are given a target value to search. If found in the array return its index, otherwise return -1.

		You may assume no duplicate exists in the array.
		*/
		if (nums.empty())
		{
			return -1;
		}
		int im = 0;
		while (im < nums.size() - 1 && nums[im] < nums[im + 1])im++;
		if (target == nums[0])
		{
			return 0;
		}
		else if (target > nums[0])
		{//[begin,end] serach
			int begin = 0;
			int end = im;
			while (begin <= end)
			{
				int mid = begin + (end - begin) / 2;
				if (nums[mid] < target)
				{
					begin = mid + 1;
				}
				else if (nums[mid] == target)
				{
					return mid;
				}
				else if (nums[mid] > target)
				{
					end = mid - 1;
				}
			}
		}
		else if (target < nums[0])
		{
			int begin = im + 1;
			int end = nums.size() - 1;
			while (begin <= end)
			{
				int mid = begin + (end - begin) / 2;
				if (nums[mid] < target)
				{
					begin = mid + 1;
				}
				else if (nums[mid] == target)
				{
					return mid;
				}
				else if (nums[mid] > target)
				{
					end = mid - 1;
				}
			}
		}
		return -1;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		/*
		34. Search for a Range Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 128355
		Total Submissions: 412474
		Difficulty: Medium
		Contributor: LeetCode
		Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

		Your algorithm's runtime complexity must be in the order of O(log n).

		If the target is not found in the array, return [-1, -1].

		For example,
		Given [5, 7, 7, 8, 8, 10] and target value 8,
		return [3, 4].
		*/

		if (nums.empty())
		{
			return vector<int>{-1, -1};
		}
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end)
		{//[begin,end] binary tree search
			int mid = begin + (end - begin) / 2;
			if (nums[mid] < target)
			{
				begin = mid + 1;
			}
			else if (nums[mid] == target)
			{
				vector<int> res{ mid,mid };
				while (res[0] > 0 && nums[res[0] - 1] == nums[mid])res[0]--;
				while (res[1] < nums.size() - 1 && nums[res[1] + 1] == nums[mid])res[1]++;
				return res;
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
		}
		return vector<int>{-1, -1};
	}

	int searchInsert(vector<int>& nums, int target) {
		/*
		35. Search Insert Position Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 162470
		Total Submissions: 413207
		Difficulty: Easy
		Contributor: LeetCode
		Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

		You may assume no duplicates in the array.

		Here are few examples.
		[1,3,5,6], 5 → 2
		[1,3,5,6], 2 → 1
		[1,3,5,6], 7 → 4
		[1,3,5,6], 0 → 0
		*/
		if (nums.empty())
		{
			return 0;
		}
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end)
		{//[begin,end] binary tree search
			int mid = begin + (end - begin) / 2;
			if (nums[mid] < target)
			{
				begin = mid + 1;
			}
			else if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
		}
		if (begin >= nums.size())
		{
			return nums.size();
		}
		if (nums[begin] > target)
		{
			return begin;
		}
		else
			return begin + 1;
	}

	bool judgeSudoku(vector<vector<char>>& board, int row, int col)
	{
		if (row < 0 || row > 8 || col < 0 || col > 8)
			return false;
		for (int i = 0;i < board.size();i++)
		{
			if (i != col && board[row][i] == board[row][col])
			{
				return false;
			}
		}
		for (int i = 0;i < board.size();i++)
		{
			if (i != row && board[i][col] == board[row][col])
			{
				return false;
			}
		}
		int r = 3 * (row / 3);
		int c = 3 * (col / 3);
		for(int i = 0;i<3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				if (r + i == row && c + j == col)
					continue;
				if (board[r + i][c + j] == board[row][col])
					return false;
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		/*   Accepted
		36. Valid Sudoku Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 113428
		Total Submissions: 325981
		Difficulty: Medium
		Contributor: LeetCode
		Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

		The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


		A partially filled sudoku which is valid.

		Note:
		A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

		input:
		[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]
		*/
		for (int i = 0;i < board.size();i++)
		{
			printVector(board[i]);
		}
		for (int i = 0;i < board.size();i++)
		{
			for (int j = 0;j < board[0].size();j++)
			{
				if (board[i][j] == '.')
					continue;
				if (!judgeSudoku(board, i, j))
					return false;
			}
		}
		return true;
	}



	vector<char> CanPlaceNumber(vector<vector<char>> &board, int row, int col)
	{//搜集当前格子所能放置的所有数字，并存入vector<int> 中返回
		vector<char> res;
		char ci[9]{ '1','2','3','4','5','6','7','8','9' };
		for (int i = 0;i < 9;i++)
		{
			board[row][col] = ci[i];
			if (judgeSudoku(board, row, col))
				res.push_back(ci[i]);
		}
		board[row][col] = '.';
		return res;
	}

	
	bool SolveSudoku(vector<vector<char>>& board, int row, int col) {
		//数独解法，初步采用回溯的算法来进行解决
		//从row,col行对后面的格子进行操作
		//回溯算法核心在二：
		//1、第一点在何时进行追溯：找到一个未赋值的格子进行赋值，若赋值满足数独定义，则进行追溯
		//2、第二点在于回溯前后的操作，回溯回来之后必须将追溯前的操作进行重置。
		system("cls");
		for (int m = 0;m < board.size();m++)
		{
			printVector(board[m]);
		}
		//Sleep(500);
		int i = row;
		int j = col;
		if (board[i][j] != '.')
		{
			if (j < 8)
			{
				if (SolveSudoku(board, i, j + 1))//如果当前数独满足要求，则进行下一次追溯
					return true;
			}
			else if (i < 8)
			{
				if (SolveSudoku(board, i + 1, 0))//如果当前数独满足要求，则进行下一次追溯
					return true;
			}
			else
			{
				return true;
			}
		}
		else
		{
			vector<char> canC = CanPlaceNumber(board, i, j);
			if ((i != 8 || j != 8) && canC.empty())
				return false;
			for (int k = 0;k < canC.size();k++)
			{//尝试赋1-9 9个数字
				board[i][j] = canC[k];
				if (j < 8)
				{
					if (SolveSudoku(board, i, j + 1))//如果当前数独满足要求，则进行下一次追溯
						return true;
				}
				else if (i < 8)
				{
					if (SolveSudoku(board, i + 1, 0))//如果当前数独满足要求，则进行下一次追溯
						return true;
				}
				else
				{
					return true;
				}
				board[i][j] = '.';
			}
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		/*  Accepted
		37. Sudoku Solver Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 70812
		Total Submissions: 243243
		Difficulty: Hard
		Contributor: LeetCode
		Write a program to solve a Sudoku puzzle by filling the empty cells.

		Empty cells are indicated by the character '.'.

		You may assume that there will be only one unique solution.


		A sudoku puzzle...


		...and its solution numbers marked in red.

		input:
			vector<vector<char>> vvc{
			{ '5','3','.','.','7','.','.','.','.' },
			{ '6','.','.','1','9','5','.','.','.' },
			{ '.','9','8','.','.','.','.','6','.' },
			{ '8','.','.','.','6','.','.','.','3' },
			{ '4','.','.','8','.','3','.','.','1' },
			{ '7','.','.','.','2','.','.','.','6' },
			{ '.','6','.','.','.','.','2','8','.' },
			{ '.','.','.','4','1','9','.','.','5' },
			{ '.','.','.','.','8','.','.','7','9' }
		};
		*/
		SolveSudoku(board, 0, 0);
	}

	void CombinationSum(set<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target)
	{//回溯法
		if (target == 0)
		{//如果target等于0，表示当前的path满足要求，压入res中，并进行回溯
			vector<int> temp(path);
			sort(temp.begin(), temp.end());
			res.insert(temp);
			return;
		}
		if (target < 0)
		{//如果target<0,表示当前的path不满足要求，直接回溯
			return;
		}
		//target> 0 ，表示还需要追溯，所以需要从candidates第一个元素进行追溯。
		for (int i = 0;i < candidates.size();i++)
		{//对每个元素进行试探，假设当前元素可以满足要求，所以需要压入path中，然后进行追溯
			path.push_back(candidates[i]);
			CombinationSum(res, path, candidates, target - candidates[i]);
			//回溯之后，将之前已经判断过的元素弹出（也就是很重要的重置操作），进行下一次的试探。
			path.pop_back();
		}
		//全部试探完毕，返回 or 回溯
		return;
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		/* Accepted
		39. Combination Sum Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 149292
		Total Submissions: 401665
		Difficulty: Medium
		Contributor: LeetCode
		Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

		The same repeated number may be chosen from C unlimited number of times.

		Note:
		All numbers (including target) will be positive integers.
		The solution set must not contain duplicate combinations.
		For example, given candidate set [2, 3, 6, 7] and target 7,
		A solution set is:
		[
		[7],
		[2, 2, 3]
		]
		*/
		//由于需要对每个数重复使用，并且每次进行的操作大部分是相同的，初步采用回溯的算法进行解决
		//回溯两要素：
		//1、何时追溯：依次对candidates中的每个元素进行试探，试探一个就行追溯
		//2、何时回溯：当进入函数之后，target<= 0时进行回溯
		//回溯核心：每次回溯完后对之前进行的操作重置。
		vector<vector<int>> res;
		vector<int> path;
		set<vector<int>> sr;
		CombinationSum(sr, path, candidates, target);
		for (auto it = sr.begin();it != sr.end();it++)
		{
			res.push_back(*it);
		}
		return res;
	}

	void CombinationSum2(set<vector<int>>& res, vector<int>& path, vector<int>::iterator start, vector<int>::iterator end, int target)
	{//回溯法
		if (target == 0)
		{//如果target等于0，表示当前的path满足要求，压入res中，并进行回溯
			vector<int> temp(path);
			sort(temp.begin(), temp.end());
			res.insert(temp);
			return;
		}
		if (target < 0 || start == end)
		{//如果target<0,表示当前的path不满足要求，直接回溯
			//如果start== end，表示元素已用完，还未满足要求，则直接回溯
			return;
		}
		//target> 0 ，表示还需要追溯，所以需要从candidates第一个元素进行追溯。
		while(start!=end)
		{//对candidates[start,end)每个元素进行试探，假设当前元素可以满足要求，所以需要压入path中，然后进行追溯
			path.push_back(*start);
			CombinationSum2(res, path, start + 1, end, target - *start);
			//回溯之后，将之前已经判断过的元素弹出（也就是很重要的重置操作），进行下一次的试探。
			path.pop_back();
			start++;
		}
		//全部试探完毕，返回 or 回溯
		return;
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		/* Accepted
		40. Combination Sum II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 107670
		Total Submissions: 331764
		Difficulty: Medium
		Contributor: LeetCode
		Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

		Each number in C may only be used once in the combination.

		Note:
		All numbers (including target) will be positive integers.
		The solution set must not contain duplicate combinations.
		For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
		A solution set is:
		[
		[1, 7],
		[1, 2, 5],
		[2, 6],
		[1, 1, 6]
		]
		*/
		//解法同T39,在candidates上进行修正，每次尝试过当前数字后，每次追溯时candidates长度减一。
		vector<vector<int>> res;
		vector<int> path;
		set<vector<int>> sr;
		CombinationSum2(sr, path, candidates.begin(), candidates.end(), target);
		for (auto it = sr.begin();it != sr.end();it++)
		{
			res.push_back(*it);
		}
		return res;
	}


	void CombinationSum3(set<vector<int>>& res, vector<int>& path, vector<int>::iterator start, vector<int>::iterator end, int target, int length)
	{//回溯法
		if (target == 0 && length == 0)
		{//如果target等于0并且恰好用完可用次数，表示当前的path满足要求，压入res中，并进行回溯
			vector<int> temp(path);
			sort(temp.begin(), temp.end());
			res.insert(temp);
			return;
		}
		if (target < 0 || start == end || length == 0)
		{//如果target<0,表示当前的path不满足要求，直接回溯
		 //如果start== end，表示元素已用完，还未满足要求，则直接回溯
		//如果length == 0，则表示可用次数已用完，还未满足要求，则直接进行回溯
			return;
		}
		//target> 0 ，表示还需要追溯，所以需要从candidates第一个元素进行追溯。
		while (start != end)
		{//对candidates[start,end)每个元素进行试探，假设当前元素可以满足要求，所以需要压入path中，然后进行追溯
			path.push_back(*start);
			CombinationSum3(res, path, start + 1, end, target - *start,length -1);
			//回溯之后，将之前已经判断过的元素弹出（也就是很重要的重置操作），进行下一次的试探。
			path.pop_back();
			start++;
		}
		//全部试探完毕，返回 or 回溯
		return;
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		/* Accepted
		216. Combination Sum III Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 62890
		Total Submissions: 144363
		Difficulty: Medium
		Contributor: LeetCode
		Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


		Example 1:

		Input: k = 3, n = 7

		Output:

		[[1,2,4]]

		Example 2:

		Input: k = 3, n = 9

		Output:

		[[1,2,6], [1,3,5], [2,3,4]]
		Credits:
		Special thanks to @mithmatt for adding this problem and creating all test cases.

		Subscribe to see which companies asked this question.
		*/
		//同理，回溯算法解之，此时尝试数组固定为[1,...,9]。回溯限定条件变为长度，每次追溯长度减1，长度为0或者大于target时停止回溯。
		vector<vector<int>> res;
		vector<int> path;
		set<vector<int>> sr;
		vector<int> candidates{ 1,2,3,4,5,6,7,8,9 };
		CombinationSum3(sr, path, candidates.begin(), candidates.end(), n, k);
		for (auto it = sr.begin();it != sr.end();it++)
		{
			res.push_back(*it);
		}
		return res;
	}

	

	int firstMissingPositive(vector<int>& nums) {
		/*  Accepted
		41. First Missing Positive Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 93945
		Total Submissions: 372192
		Difficulty: Hard
		Contributor: LeetCode
		Given an unsorted integer array, find the first missing positive integer.

		For example,
		Given [1,2,0] return 3,
		and [3,4,-1,1] return 2.

		Your algorithm should run in O(n) time and uses constant space.
		*/
		if (nums.empty())
		{//如果传入的空数组，则直接返回1。
			return 1;
		}
		//将每个小于nums.size()的正数放到自己合适的位置，由于超出size()的数以及负数都是无效的数，对于我们寻找所想要的missing positive interger 没有任何作用，所以一视同仁。
		for (int i = 0;i < nums.size();i++)
		{
			//若nums[i]为有效数，则将其放到其适合的位置，然后判断交换过来的数是否依旧是合适的数，直到nums[i]存放的数为无效数为止。
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0;i < nums.size();i++)
		{//从头找不符合情况的数，第一个不符合要求的即为所求。
			if (nums[i] != i + 1)
			{
				return i + 1;
			}
		}
		//整个数组都符合要求，则下一个数必然缺失。
		return nums.size() + 1;
	}

	int missingNumber(vector<int>& nums) {
		/*
		268. Missing Number Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 106840
		Total Submissions: 243115
		Difficulty: Easy
		Contributor: LeetCode
		Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

		For example,
		Given nums = [0, 1, 3] return 2.

		Note:
		Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
		*/
		if (nums.empty())
		{//如果传入的空数组，则直接返回1。
			return 0;
		}
		for (int i = 0;i < nums.size();i++)
		{
			while (nums[i] != nums.size() && nums[nums[i]] != nums[i])
			{
				swap(nums[i], nums[nums[i]]);
			}
		}
		for (int i = 0;i < nums.size();i++)
		{//从头找不符合情况的数，第一个不符合要求的即为所求。
			if (nums[i] != i)
			{
				return i;
			}
		}
		//整个数组都符合要求，则下一个数必然缺失。
		return nums.size();
	}
	int findDuplicate(vector<int>& nums) {
		/* Accepted
		287. Find the Duplicate Number Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 63211
		Total Submissions: 148350
		Difficulty: Medium
		Contributor: LeetCode
		Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

		Note:
		You must not modify the array (assume the array is read only).
		You must use only constant, O(1) extra space.
		Your runtime complexity should be less than O(n2).
		There is only one duplicate number in the array, but it could be repeated more than once.	
		*/
		//使用下标-对应值的映射方式进行构造链式结构，如果有重复的数字，意味着此条链状结构有环，则实际上此问题是进行寻找环状结构的入口。
		//使用快慢指针进行找链表的环状结构。
		int slow = 0;
		int fast = 0;//快慢指针在同一起点，快指针一次走两步，慢指针一次走一步
		do
		{
			slow = nums[slow];//走一步
			fast = nums[nums[fast]];//走两步
		} while (slow != fast);
		int target = 0;
		//由于fast与slow相遇后，说明fast走了两倍的slow的路程，如果让target从0出发，slow从当前位置出发，再走一个slow的距离，恰好在起点相遇；
		while (target != slow)
		{
			target = nums[target];
			slow = nums[slow];
		}
		return target;
	}

	int trap(vector<int>& height) {
		/* Accepted
		42. Trapping Rain Water Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 107191
		Total Submissions: 297341
		Difficulty: Hard
		Contributor: LeetCode
		Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

		For example,
		Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


		The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
		*/
		// 找寻最高的一根柱子，从两边往中间进行搜寻，水位肯定是与当前遇到的最高柱子（小于最高高度）持平。依次来逐渐计算总容量。
		if (height.size() <= 1)
			return 0;
		int max = 0;
		int index = -1;
		for (int i = 0;i < height.size();i++)
		{
			if (height[i] > max)
			{
				max = height[i];
				index = i;
			}
		}
		cout << max << " " << index << endl;
		int iVolume = 0;
		int lmax = 0;
		for (int i = 0;i < index;i++)
		{
			if (height[i] > lmax)
			{
				lmax = height[i];
			}
			else if (height[i] < lmax)
			{
				iVolume += lmax - height[i];
			}
		}
		int rmax = 0;
		for (int i = height.size() - 1;i > index;i--)
		{
			if (height[i] > rmax)
			{
				rmax = height[i];
			}
			else if (height[i] < rmax)
			{
				iVolume += rmax - height[i];
			}
		}
		return iVolume;
	}

	void MatrixTranspose(vector<vector<int>>& Matrix, vector<vector<int>>& TMatrix)
	{
		if (Matrix.empty())
		{
			return;
		}
		for (int i = 0;i < Matrix[0].size();i++)
		{
			vector<int> temp;
			for (int j = 0;j < Matrix.size();j++)
			{
				temp.push_back(Matrix[j][i]);
			}
			TMatrix.push_back(temp);
		}
		return;
	}

	
	int trapRainWater(vector<vector<int>>& heightMap) {
		/*
		407. Trapping Rain Water II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 8132
		Total Submissions: 22562
		Difficulty: Hard
		Contributor: LeetCode
		Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

		Note:
		Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

		Example:

		Given the following 3x6 height map:
		[
		[1,4,3,1,3,2],
		[3,2,1,3,2,4],
		[2,3,3,2,3,1]
		]

		Return 4.

		The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
		###https://leetcode.com/problems/trapping-rain-water-ii/#/description

		After the rain, water are trapped between the blocks. The total volume of water trapped is 4.
		*/
		return 0;
		
	}

	int upper_bound(vector<int> vi, int target)
	{
		if (vi.empty() || vi[0] > target)
		{
			return 0;
		}
		if (vi[vi.size() - 1] < target)
			return vi.size();
		//二分查找target,从vi[begin,...,end]找(前闭后闭)
		//mid = begin+(end - begin)/2 比较target/vi[mid]
		//若target > vi[mid],则begin = mid + 1;
		//若target < vi[mid],则end = mid - 1;
		//若相等，则返回mid+1。
		int begin = 0;
		int end = vi.size() - 1;
		int mid;
		while (begin <= end)
		{
			mid = begin + (end - begin) / 2;
			if (target == vi[mid])
				return mid + 1;
			else if (target > vi[mid])
				begin = mid + 1;
			else if (target < vi[mid])
				end = mid - 1;
		}
		return end + 1;
	}

	int jump(vector<int>& nums) {
		/*
		45. Jump Game II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 89045
		Total Submissions: 341099
		Difficulty: Hard
		Contributor: LeetCode
		Given an array of non-negative integers, you are initially positioned at the first index of the array.

		Each element in the array represents your maximum jump length at that position.

		Your goal is to reach the last index in the minimum number of jumps.

		For example:
		Given array A = [2,3,1,1,4]

		The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

		Note:
		You can assume that you can always reach the last index.
		*/
		//
		int count = 0, icPosition = 0, ipPosition = 0, i = 0;
		printVector(nums);
		while (icPosition < nums.size() - 1)
		{//如果当前位置没达到目的地，则继续跳
			ipPosition = icPosition;//保存下我当前位置，或者保存当前位置对应跳的最远距离。
			while (i <= ipPosition)//对跳到当前位置之后能够遍历并且在前一个位置未能遍历到的位置进行判定，看是否能跳的更远。取最远的位置。
			{
				icPosition = max(icPosition, i + nums[i]);
				i++;
			}
			//每次跳完了之后，计数器加一表示跳了一步。
			count++;
			cout << icPosition << " ";
		}
		cout << endl;
		return count;
	}

	void getAllPermution(vector<vector<int>>& res, vector<int>& nums, int begin, int end)
	{//对nums[begin, end]求其所有的排列，并将其排列结果存入res
		if (begin == end)
		{//如果两者相等，表示已经找到一种排列， 将此时的nums存入结果中，进行回溯。
			res.push_back(nums);
			return;
		}
		//如果begin<end,则从将begin对应的数和后面的数一一调换，进行追溯begin+1,end
		for (int i = begin;i <= end;i++)
			//i:[begin, end]，包含begin的原因是，需要找到当前数不变，后面所有数的全排列情况。
			//包含end的原因，是当前数要和后面的每一个数都进行调换，所以需要包含end。
		{
			swap(nums[begin], nums[i]);//调换完，进行追溯
			getAllPermution(res, nums, begin + 1, end);
			swap(nums[begin], nums[i]);//回溯完后重置操作
		}
		return;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		/*  Accepted
		46. Permutations Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 157526
		Total Submissions: 373953
		Difficulty: Medium
		Contributor: LeetCode
		Given a collection of distinct numbers, return all possible permutations.

		For example,
		[1,2,3] have the following permutations:
		[
		[1,2,3],
		[1,3,2],
		[2,1,3],
		[2,3,1],
		[3,1,2],
		[3,2,1]
		]
		*/
		//获得所给数组的全排列，利用回溯算法求之。
		vector<vector<int>> res;
		getAllPermution(res, nums, 0, nums.size() - 1);
		return res;
	}

	void getAllUniPermution(set<vector<int>>& res, vector<int>& nums, int begin, int end)
	{//对nums[begin, end]求其所有的排列，并将其排列结果存入res
		if (begin == end)
		{//如果两者相等，表示已经找到一种排列， 将此时的nums存入结果中，进行回溯。
			res.insert(nums);
			return;
		}
		//如果begin<end,则从将begin对应的数和后面的数一一调换，进行追溯begin+1,end
		for (int i = begin;i <= end;i++)
			//i:[begin, end]，包含begin的原因是，需要找到当前数不变，后面所有数的全排列情况。
			//包含end的原因，是当前数要和后面的每一个数都进行调换，所以需要包含end。
		{
			swap(nums[begin], nums[i]);//调换完，进行追溯
			getAllUniPermution(res, nums, begin + 1, end);
			swap(nums[begin], nums[i]);//回溯完后重置操作
		}
		return;
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		/*   Accepted
		47. Permutations II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 113222
		Total Submissions: 354917
		Difficulty: Medium
		Contributor: LeetCode
		Given a collection of numbers that might contain duplicates, return all possible unique permutations.

		For example,
		[1,1,2] have the following unique permutations:
		[
		[1,1,2],
		[1,2,1],
		[2,1,1]
		]
		*/
		set<vector<int>> res;
		getAllUniPermution(res, nums, 0, nums.size() - 1);
		vector<vector<int>> r;
		for (auto it = res.begin();it != res.end();it++)
		{
			r.push_back(*it);
		}
		return r;
 	}

	void swapForRotate(vector<vector<int>>& matrix, pair<int, int> leftup, pair<int, int> rightup, pair<int, int> rightdown, pair<int, int> leftdown)
	{
		int temp = matrix[leftup.first][leftup.second];
		matrix[leftup.first][leftup.second] = matrix[leftdown.first][leftdown.second];
		matrix[leftdown.first][leftdown.second] = matrix[rightdown.first][rightdown.second];
		matrix[rightdown.first][rightdown.second] = matrix[rightup.first][rightup.second];
		matrix[rightup.first][rightup.second] = temp;
		return;
	}

	void rotate(vector<vector<int>>& matrix) {
		/*   Accepted
		48. Rotate Image Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 107541
		Total Submissions: 283412
		Difficulty: Medium
		Contributor: LeetCode
		You are given an n x n 2D matrix representing an image.

		Rotate the image by 90 degrees (clockwise).

		Follow up:
		Could you do this in-place?
		*/
		//printMatrix(matrix);
		int n = matrix.size();
		for (int i = 0;i < n / 2;i++)
		{
			for (int j = i;j < n - 1 - i;j++)
				swapForRotate(matrix, pair<int, int>(i, j), pair<int, int>(j, n - 1 - i), pair<int, int>(n - 1 - i, n - 1 - j), pair<int, int>(n - 1 - j, i));
		}
		//printMatrix(matrix);
		return;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		/* Accepted
		49. Group Anagrams Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 127422
		Total Submissions: 382873
		Difficulty: Medium
		Contributor: LeetCode
		Given an array of strings, group anagrams together.

		For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
		Return:

		[
		["ate", "eat","tea"],
		["nat","tan"],
		["bat"]
		]
		Note: All inputs will be in lower-case.
		*/
		map<string, vector<string>> mapsv;
		for (int i = 0;i < strs.size();i++)
		{
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			if (mapsv.find(temp) == mapsv.end())
			{
				mapsv[temp] = vector<string>(1,strs[i]);
			}
			else
			{
				mapsv[temp].push_back(strs[i]);
			}
		}
		vector<vector<string>> res;
		for (auto it = mapsv.begin();it != mapsv.end();it++)
		{
			res.push_back((*it).second);
		}
		return res;
	}

	bool CanPlaceQueen(vector<int> qFlag, int row, int col)
	{
		//对于row行，col列能否放置皇后进行判定，如果能则返回true
		for (int i = 0;i < row;i++)//当前位置是row行，则之前肯定已经有[0,...,row-1]行放置了皇后，对于每一个皇后一一进行判定
		{
			//如果两个皇后列数相等， 则直接判定不能放置，返回false
			//如果两个皇后列数差绝对值等于行数差绝对值，则这两个皇后在同一斜线上，也判定为不能放置，返回false
			if (qFlag[i] == col || (abs(row - i) == abs(col - qFlag[i])))
				return false;
		}
		//对于已经放置的row个皇后，如果都不冲突，则当前[row,col]可以放置皇后，返回true
		return true;
	}

	void queen(vector<int> qFlag, vector<vector<int>> &output, int row, int n)
	{
		//N皇后问题，递归实现
		//row[0,...,N-1]表示从第一行到第N行，
		//qFlag为N维向量，索引对应行数[0,...,N-1]，存储的值是皇后放置的列数[0,...,N-1]。
		//output 为X*N维向量， 每一行对应一种解，X未知。
		if (row == n)
		{
			output.push_back(qFlag);//row == N ，表示已经前面N层都放置好了皇后，输出当前解，然后回溯。
		}
		else
		{
			for (int i = 0;i < n;i++)
			{
				if (CanPlaceQueen(qFlag, row, i))//如果当前位置可以放置皇后，则放置皇后并修改flag。
				{
					qFlag[row] = i;//当前位置放置皇后，修改第row行对应的flag为放置的列数。
					queen(qFlag, output, row + 1, n);//往下一行继续搜寻
												  //qFlag[row] = -1;//回溯法核心，在每次探索完之后，重置追溯前的修改。
												  //此种情况下，可以不用进行重置操作，主要原因是当前行修改的值对回溯之后的情况没有任何影响。
				}
			}
		}
		return;
	}
	vector<string> viTovsQueen(vector<int> vi)
	{
		vector<string> res;
		for (int i = 0;i < vi.size();i++)
		{
			string temp(vi.size(), '.');
			temp[vi[i]] = 'Q';
			res.push_back(temp);
		}
		return res;
	}
	vector<vector<string>> solveNQueens(int n) {
		/*  Accepted
		51. N-Queens Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 75862
		Total Submissions: 252807
		Difficulty: Hard
		Contributor: LeetCode
		The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



		Given an integer n, return all distinct solutions to the n-queens puzzle.

		Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

		For example,
		There exist two distinct solutions to the 4-queens puzzle:

		[
		[".Q..",  // Solution 1
		"...Q",
		"Q...",
		"..Q."],

		["..Q.",  // Solution 2
		"Q...",
		"...Q",
		".Q.."]
		]
		*/
		vector<int> qFlag(n, -1);
		vector<vector<int>> res;
		queen(qFlag, res, 0, n);
		vector<vector<string>> vvs;
		for (int i = 0;i < res.size();i++)
		{
			vvs.push_back(viTovsQueen(res[i]));
		}
		return vvs;
	}

	int totalNQueens(int n) {
		/* Accepted
		52. N-Queens II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 60267
		Total Submissions: 137622
		Difficulty: Hard
		Contributor: LeetCode
		Follow up for N-Queens problem.

		Now, instead outputting board configurations, return the total number of distinct solutions.
		*/
		vector<int> qFlag(n, -1);
		vector<vector<int>> res;
		queen(qFlag, res, 0, n);
		return res.size();
	}

	

	vector<int> PeelMatrix(vector<vector<int>>& matrix)
	{
		vector<int> res;
		int m = matrix.size();
		int n = matrix[0].size();
		res.insert(res.end(), matrix[0].begin(), matrix[0].end());
		matrix.erase(matrix.begin());
		for (int i = 0;i < m - 1;i++)
		{
			res.insert(res.end(), matrix[i].back());
			matrix[i].pop_back();
		}
		vector<int> temp = matrix.back();
		matrix.pop_back();
		reverse(temp.begin(), temp.end());
		res.insert(res.end(), temp.begin(), temp.end());
		for (int i = m - 3;i >= 0;i--)
		{
			res.insert(res.end(), matrix[i].front());
			matrix[i].erase(matrix[i].begin());
		}
		return res;
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		/*  Accepted
		54. Spiral Matrix Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 94997
		Total Submissions: 375443
		Difficulty: Medium
		Contributor: LeetCode
		Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

		For example,
		Given the following matrix:

		[
		[ 1, 2, 3 ],
		[ 4, 5, 6 ],
		[ 7, 8, 9 ]
		]
		You should return [1,2,3,6,9,8,7,4,5].
		*/
		//螺旋展示矩形，并将结果保存至一维向量
		vector<int> res;
		if (matrix.empty())
			return res;
		while (!matrix.empty() && matrix.size() != 1 && matrix[0].size() != 1 && matrix[0].size() != 0)
		{
			vector<int> temp = PeelMatrix(matrix);
			res.insert(res.end(), temp.begin(), temp.end());
		}
		if (matrix.empty())
		{
			return res;
		}
		else if (matrix.size() == 1)
		{
			res.insert(res.end(), matrix[0].begin(), matrix[0].end());
		}
		else if(matrix[0].size() == 1)
		{
			for (int i = 0;i < matrix.size();i++)
			{
				res.push_back(matrix[i][0]);
			}
		}
		return res;
	}

	bool canJump(vector<int>& nums) {
		/*   Accepted
		55. Jump Game Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 117124
		Total Submissions: 399039
		Difficulty: Medium
		Contributor: LeetCode
		Given an array of non-negative integers, you are initially positioned at the first index of the array.

		Each element in the array represents your maximum jump length at that position.

		Determine if you are able to reach the last index.

		For example:
		A = [2,3,1,1,4], return true.

		A = [3,2,1,0,4], return false.
		*/
		//贪心算法可解，每次从当前位置往能跳到的最远距离进行跳，如果最后位置在这个最远距离之内，则表示可以到达，返回true，反之false.
		int icPosition = 0;//保存当前可到达的最远位置
		int ipPosition = 0;//保存当前位置所能跳的最大步数。
		int i = 0;//指向当前位置
		while (i < nums.size())
		{
			ipPosition = icPosition;//保存下上次找到的最远位置
			while (i <= ipPosition)
			{
				if (nums[i] != 0)
					icPosition = max(icPosition, i + nums[i]);//贪婪思想更新最远位置
				i++;//一步一步向后找，直到找到之前位置所能到达的最远位置。
			}

			//每次跳之前判定条件，如果最后一个位置在最远位置范围内，则返回ture。
			if (icPosition >= nums.size() - 1)
			{
				return true;
			}
			//如果找到的下次最远位置出可跳步数为0，则直接返回false.
			if (icPosition == ipPosition)
				return false;
		}
		return false;
	}
	//Definition for an interval.
	struct Interval {
		int start;
		int end;
		Interval() : start(0), end(0) {}
		Interval(int s, int e) : start(s), end(e) {}
	};
	vector<Interval> merge(vector<Interval>& intervals) {
		/*  Accepted
		56. Merge Intervals Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 118385
		Total Submissions: 404383
		Difficulty: Medium
		Contributor: LeetCode
		Given a collection of intervals, merge all overlapping intervals.

		For example,
		Given [1,3],[2,6],[8,10],[15,18],
		return [1,6],[8,10],[15,18].
		*/
		vector<Interval> vIres;
		if (intervals.empty())
		{
			return vIres;
		}
		sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
		Interval temp(intervals[0]);
		for (int i = 1;i < intervals.size();i++)
		{
			if (intervals[i].start > temp.end)
			{
				vIres.push_back(temp);
				temp = intervals[i];
			}
			else
			{
				temp.start = min(intervals[i].start, temp.start);
				temp.end = max(intervals[i].end, temp.end);
			}
		}
		vIres.push_back(temp);
		return vIres;
	}

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		/*   Accepted
		57. Insert Interval Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 89861
		Total Submissions: 332670
		Difficulty: Hard
		Contributor: LeetCode
		Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

		You may assume that the intervals were initially sorted according to their start times.

		Example 1:
		Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

		Example 2:
		Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

		This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
		*/
		/**
		* Definition for an interval.
		* struct Interval {
		*     int start;
		*     int end;
		*     Interval() : start(0), end(0) {}
		*     Interval(int s, int e) : start(s), end(e) {}
		* };
		*/
		vector<Interval> vIres;
		if (intervals.empty())
		{
			vIres.push_back(newInterval);
			return vIres;
		}
		Interval temp;
		bool flag = false;
		for (int i = 0;i < intervals.size();i++)
		{
			if (intervals[i].end < newInterval.start)
			{
				vIres.push_back(intervals[i]);
			}
			else if (intervals[i].start > newInterval.end)
			{
				if (flag == false)
				{
					vIres.push_back(newInterval);
					flag = true;
				}
				vIres.push_back(intervals[i]);
			}
			else
			{
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			}
		}
		if (flag == false)
		{
			vIres.push_back(newInterval);
		}
		return vIres;
	}

	vector<vector<int>> generateMatrix(int n) {
		/*  Accepted
		59. Spiral Matrix II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 77213
		Total Submissions: 198994
		Difficulty: Medium
		Contributor: LeetCode
		Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

		For example,
		Given n = 3,

		You should return the following matrix:
		[
		[ 1, 2, 3 ],
		[ 8, 9, 4 ],
		[ 7, 6, 5 ]
		]
		*/
		vector<vector<int>> vvi(n, vector<int>(n, 0));
		int i = 1;//[1,..,2n]个数
		int j = 0;//[0,...,n/2]行
		for (;j < n / 2;j++)
		{
			for (int k = j;k < n - j - 1;k++)
			{
				vvi[j][k] = i++;
			}
			for (int k = j;k < n - j - 1;k++)
			{
				vvi[k][n - j - 1] = i++;
			}
			for (int k = j;k < n - j - 1;k++)
			{
				vvi[n - j - 1][n - k - 1] = i++;
			}
			for (int k = j;k < n - j - 1;k++)
			{
				vvi[n - k - 1][j] = i++;
			}
		}
		if (n % 2 != 0)
		{
			vvi[n / 2][n / 2] = i;
		}
		printMatrix(vvi);
		return vvi;
	}

	

	

	int minPathSum(vector<vector<int>>& grid) {
		/*  Accepted
		64. Minimum Path Sum Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 107009
		Total Submissions: 282651
		Difficulty: Medium
		Contributor: LeetCode
		Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
		which minimizes the sum of all numbers along its path.

		Note: You can only move either down or right at any point in time.
		*/
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 1;i < m;i++)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int j = 1;j < n;j++)
		{
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		}
		for (int i = 1;i < m;i++)
		{
			for (int j = 1;j < n;j++)
			{
				dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		return dp[m - 1][n - 1];
	}
	vector<int> plusOne(vector<int>& digits) {
		/*  Accepted
		66. Plus One Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 161750
		Total Submissions: 427131
		Difficulty: Easy
		Contributor: LeetCode
		Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

		You may assume the integer do not contain any leading zero, except the number 0 itself.

		The digits are stored such that the most significant digit is at the head of the list.

		Subscribe to see which companies asked this question.
		*/
		//一个非负整数数组表示一个大数(最高位在最前面)，对这个数进行+1运算。
		//依次处理进位即可
		vector<int> viRes;
		int CarryBit = 0;
		for (int i = digits.size() - 1;i >= 0;i--)
		{
			if (i == digits.size() - 1)	
				digits[i] += 1;
			int r = digits[i] + CarryBit;
			viRes.push_back(r % 10);
			CarryBit = r / 10;
		}
		if (CarryBit != 0)
			viRes.push_back(1);
		reverse(viRes.begin(), viRes.end());
		return viRes;
	}

	void setZeroes(vector<vector<int>>& matrix) {
		/*  Accepted
		73. Set Matrix Zeroes Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 98374
		Total Submissions: 276754
		Difficulty: Medium
		Contributor: LeetCode
		Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

		click to show follow up.

		Follow up:
		Did you use extra space?
		A straight forward solution using O(mn) space is probably a bad idea.
		A simple improvement uses O(m + n) space, but still not the best solution.
		Could you devise a constant space solution?
		*/
		int m = matrix.size();
		int n = matrix[0].size();
		bool zeroFlag = false;
		for (int i = 0;i < m;i++)
		{
			if (matrix[i][0] == 0)
				zeroFlag = true;
			for(int j = 1; j<n;j++)
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
		}
		for (int i = m - 1;i >= 0;i--)
		{
			for (int j = 1;j < n;j++)
			{
				if (matrix[0][j] == 0 || matrix[i][0] == 0)
					matrix[i][j] = 0;
			}
			if (zeroFlag)
				matrix[i][0] = 0;
		}
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		/*  Accepted
		74. Search a 2D Matrix Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 118619
		Total Submissions: 336466
		Difficulty: Medium
		Contributor: LeetCode
		Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

		Integers in each row are sorted from left to right.
		The first integer of each row is greater than the last integer of the previous row.
		For example,

		Consider the following matrix:

		[
		  [1,   3,  5,  7],
		  [10, 11, 16, 20],
		  [23, 30, 34, 50]
		]
		Given target = 3, return true.

		Subscribe to see which companies asked this question.

		Show Tags
		Show Similar Problems
		*/
		if (matrix.empty() || matrix[0].empty())
			return false;
		for (int i = 0;i < matrix.size();i++)
		{
			if (matrix[i][0] > target)
				break;
			for (int j = 0;j < matrix[0].size();j++)
			{
				if (matrix[i][j] > target)
					break;
				if (matrix[i][j] == target)
					return true;
			}
		}
		return false;
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		/*  Accepted
		240. Search a 2D Matrix II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 72711
		Total Submissions: 190754
		Difficulty: Medium
		Contributor: LeetCode
		Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

		Integers in each row are sorted in ascending from left to right.
		Integers in each column are sorted in ascending from top to bottom.
		For example,

		Consider the following matrix:

		[
		  [1,   4,  7, 11, 15],
		  [2,   5,  8, 12, 19],
		  [3,   6,  9, 16, 22],
		  [10, 13, 14, 17, 24],
		  [18, 21, 23, 26, 30]
		]
		Given target = 5, return true.

		Given target = 20, return false.
		*/
		if (matrix.empty() || matrix[0].empty())
			return false;
		for (int i = 0;i < matrix.size();i++)
		{
			if (matrix[i][0] > target)
				break;
			for (int j = 0;j < matrix[0].size();j++)
			{
				if (matrix[i][j] > target)
					break;
				if (matrix[i][j] == target)
					return true;
			}
		}
		return false;
	}
	void sortColors(vector<int>& nums) {
		/*  Accepted
		75. Sort Colors Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 153340
		Total Submissions: 410633
		Difficulty: Medium
		Contributor: LeetCode
		Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

		Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

		Note:
		You are not suppose to use the library's sort function for this problem.

		click to show follow up.

		Follow up:
		A rather straight forward solution is a two-pass algorithm using counting sort.
		First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

		Could you come up with an one-pass algorithm using only constant space?
		*/
		//0,1,2三类混杂在nums数组中，类似三路快排的思路，将0看做是小于patition的数字，1看做是等于，2看做是大于
		//三路快排patition操作一遍，即可将所有的0,1,2三类分开。
		//nums[0,...,n - 1]分为前后中三组
		int n = nums.size();
		int lt = -1;//  nums[0,..,lt] == 0...一开始为空集
		int rt = n;// nums[rt,n-1] == 2,...一开始也为空集
		int i = 0;//nums[lt + 1,i) == 1，...一开始为空集
		while (i < rt)
		{
			if (nums[i] == 0)
			{//等于0，加入到nums[0,lt]尾部
				swap(nums[i], nums[lt + 1]);
				lt++;
				i++;
			}
			else if (nums[i] == 1)
			{//等于1，加入到nums[lt+1,i)尾部,即无需移动
				i++;
			}
			else if (nums[i] == 2)
			{//等于2，加入到nums[rt,n-1]头部
				swap(nums[i], nums[rt - 1]);
				rt--;
			}
		}
		printVector(nums);
		return;
	}
}


```
