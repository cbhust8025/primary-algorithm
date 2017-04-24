```C++
#pragma once
//
// Created by CB on 04/18-2007
//
#include<iostream>
#include<cassert>
#include<ctime>
#include<vector>
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

	//打印链表
	void printVector(const vector<int>& vi)
	{
		for (int i = 0;i < vi.size();i++)
		{
			cout << vi[i] << "->";
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
		else if(j == nums.size())
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
}
```
