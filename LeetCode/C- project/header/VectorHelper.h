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

	//����n���ڵ�����vector��ÿ��Ԫ�ص������ΧΪ[rangeL,rangeR]
	vector<int> generateRandomVector(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		ListHelper::ListNode* p1 = ListHelper::generateRandomList(n, rangeL, rangeR);
		vector<int> vi = ListHelper::translateList(p1);
		return vi;
	}

	//����n���ڵ���������vector��Ԫ�ص���ʼֵΪ[begin,begin+step),ÿ��������Ԫ��֮��Ĳ�����[0,step)
	vector<int> generateSortVector(int n, int begin, int step)
	{
		assert(begin > 0);
		ListHelper::ListNode* p1 = ListHelper::generateSortList(n, begin, step);
		vector<int> vi = ListHelper::translateList(p1);
		return vi;
	}


	//ģ�壬��ӡVector
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
		1,2,3 �� 1,3,2
		3,2,1 �� 1,2,3
		1,1,5 �� 1,5,1
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
		[1,3,5,6], 5 �� 2
		[1,3,5,6], 2 �� 1
		[1,3,5,6], 7 �� 4
		[1,3,5,6], 0 �� 0
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
	{//�Ѽ���ǰ�������ܷ��õ��������֣�������vector<int> �з���
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
		//�����ⷨ���������û��ݵ��㷨�����н��
		//��row,col�жԺ���ĸ��ӽ��в���
		//�����㷨�����ڶ���
		//1����һ���ں�ʱ����׷�ݣ��ҵ�һ��δ��ֵ�ĸ��ӽ��и�ֵ������ֵ�����������壬�����׷��
		//2���ڶ������ڻ���ǰ��Ĳ��������ݻ���֮����뽫׷��ǰ�Ĳ����������á�
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
				if (SolveSudoku(board, i, j + 1))//�����ǰ��������Ҫ���������һ��׷��
					return true;
			}
			else if (i < 8)
			{
				if (SolveSudoku(board, i + 1, 0))//�����ǰ��������Ҫ���������һ��׷��
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
			{//���Ը�1-9 9������
				board[i][j] = canC[k];
				if (j < 8)
				{
					if (SolveSudoku(board, i, j + 1))//�����ǰ��������Ҫ���������һ��׷��
						return true;
				}
				else if (i < 8)
				{
					if (SolveSudoku(board, i + 1, 0))//�����ǰ��������Ҫ���������һ��׷��
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
	{//���ݷ�
		if (target == 0)
		{//���target����0����ʾ��ǰ��path����Ҫ��ѹ��res�У������л���
			vector<int> temp(path);
			sort(temp.begin(), temp.end());
			res.insert(temp);
			return;
		}
		if (target < 0)
		{//���target<0,��ʾ��ǰ��path������Ҫ��ֱ�ӻ���
			return;
		}
		//target> 0 ����ʾ����Ҫ׷�ݣ�������Ҫ��candidates��һ��Ԫ�ؽ���׷�ݡ�
		for (int i = 0;i < candidates.size();i++)
		{//��ÿ��Ԫ�ؽ�����̽�����赱ǰԪ�ؿ�������Ҫ��������Ҫѹ��path�У�Ȼ�����׷��
			path.push_back(candidates[i]);
			CombinationSum(res, path, candidates, target - candidates[i]);
			//����֮�󣬽�֮ǰ�Ѿ��жϹ���Ԫ�ص�����Ҳ���Ǻ���Ҫ�����ò�������������һ�ε���̽��
			path.pop_back();
		}
		//ȫ����̽��ϣ����� or ����
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
		//������Ҫ��ÿ�����ظ�ʹ�ã�����ÿ�ν��еĲ����󲿷�����ͬ�ģ��������û��ݵ��㷨���н��
		//������Ҫ�أ�
		//1����ʱ׷�ݣ����ζ�candidates�е�ÿ��Ԫ�ؽ�����̽����̽һ������׷��
		//2����ʱ���ݣ������뺯��֮��target<= 0ʱ���л���
		//���ݺ��ģ�ÿ�λ�������֮ǰ���еĲ������á�
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
	{//���ݷ�
		if (target == 0)
		{//���target����0����ʾ��ǰ��path����Ҫ��ѹ��res�У������л���
			vector<int> temp(path);
			sort(temp.begin(), temp.end());
			res.insert(temp);
			return;
		}
		if (target < 0 || start == end)
		{//���target<0,��ʾ��ǰ��path������Ҫ��ֱ�ӻ���
			//���start== end����ʾԪ�������꣬��δ����Ҫ����ֱ�ӻ���
			return;
		}
		//target> 0 ����ʾ����Ҫ׷�ݣ�������Ҫ��candidates��һ��Ԫ�ؽ���׷�ݡ�
		while(start!=end)
		{//��candidates[start,end)ÿ��Ԫ�ؽ�����̽�����赱ǰԪ�ؿ�������Ҫ��������Ҫѹ��path�У�Ȼ�����׷��
			path.push_back(*start);
			CombinationSum2(res, path, start + 1, end, target - *start);
			//����֮�󣬽�֮ǰ�Ѿ��жϹ���Ԫ�ص�����Ҳ���Ǻ���Ҫ�����ò�������������һ�ε���̽��
			path.pop_back();
			start++;
		}
		//ȫ����̽��ϣ����� or ����
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
		//�ⷨͬT39,��candidates�Ͻ���������ÿ�γ��Թ���ǰ���ֺ�ÿ��׷��ʱcandidates���ȼ�һ��
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
	{//���ݷ�
		if (target == 0 && length == 0)
		{//���target����0����ǡ��������ô�������ʾ��ǰ��path����Ҫ��ѹ��res�У������л���
			vector<int> temp(path);
			sort(temp.begin(), temp.end());
			res.insert(temp);
			return;
		}
		if (target < 0 || start == end || length == 0)
		{//���target<0,��ʾ��ǰ��path������Ҫ��ֱ�ӻ���
		 //���start== end����ʾԪ�������꣬��δ����Ҫ����ֱ�ӻ���
		//���length == 0�����ʾ���ô��������꣬��δ����Ҫ����ֱ�ӽ��л���
			return;
		}
		//target> 0 ����ʾ����Ҫ׷�ݣ�������Ҫ��candidates��һ��Ԫ�ؽ���׷�ݡ�
		while (start != end)
		{//��candidates[start,end)ÿ��Ԫ�ؽ�����̽�����赱ǰԪ�ؿ�������Ҫ��������Ҫѹ��path�У�Ȼ�����׷��
			path.push_back(*start);
			CombinationSum3(res, path, start + 1, end, target - *start,length -1);
			//����֮�󣬽�֮ǰ�Ѿ��жϹ���Ԫ�ص�����Ҳ���Ǻ���Ҫ�����ò�������������һ�ε���̽��
			path.pop_back();
			start++;
		}
		//ȫ����̽��ϣ����� or ����
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
		//ͬ�������㷨��֮����ʱ��������̶�Ϊ[1,...,9]�������޶�������Ϊ���ȣ�ÿ��׷�ݳ��ȼ�1������Ϊ0���ߴ���targetʱֹͣ���ݡ�
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
		//�����޴󣬿���ʹ��dp������⣬������̨�ס�
		//nums[1,2,3]�������ÿ����̨�ף����������ٽ�̨��
		//target������Ŀ���̨����
		//dp[i] 0<=i<=target ����������i��̨�����е����������ϡ�
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
		{//�������Ŀ����飬��ֱ�ӷ���1��
			return 1;
		}
		//��ÿ��С��nums.size()�������ŵ��Լ����ʵ�λ�ã����ڳ���size()�����Լ�����������Ч��������������Ѱ������Ҫ��missing positive interger û���κ����ã�����һ��ͬ�ʡ�
		for (int i = 0;i < nums.size();i++)
		{
			//��nums[i]Ϊ��Ч��������ŵ����ʺϵ�λ�ã�Ȼ���жϽ������������Ƿ������Ǻ��ʵ�����ֱ��nums[i]��ŵ���Ϊ��Ч��Ϊֹ��
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0;i < nums.size();i++)
		{//��ͷ�Ҳ����������������һ��������Ҫ��ļ�Ϊ����
			if (nums[i] != i + 1)
			{
				return i + 1;
			}
		}
		//�������鶼����Ҫ������һ������Ȼȱʧ��
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
		{//�������Ŀ����飬��ֱ�ӷ���1��
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
		{//��ͷ�Ҳ����������������һ��������Ҫ��ļ�Ϊ����
			if (nums[i] != i)
			{
				return i;
			}
		}
		//�������鶼����Ҫ������һ������Ȼȱʧ��
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
		//ʹ���±�-��Ӧֵ��ӳ�䷽ʽ���й�����ʽ�ṹ��������ظ������֣���ζ�Ŵ�����״�ṹ�л�����ʵ���ϴ������ǽ���Ѱ�һ�״�ṹ����ڡ�
		//ʹ�ÿ���ָ�����������Ļ�״�ṹ��
		int slow = 0;
		int fast = 0;//����ָ����ͬһ��㣬��ָ��һ������������ָ��һ����һ��
		do
		{
			slow = nums[slow];//��һ��
			fast = nums[nums[fast]];//������
		} while (slow != fast);
		int target = 0;
		//����fast��slow������˵��fast����������slow��·�̣������target��0������slow�ӵ�ǰλ�ó���������һ��slow�ľ��룬ǡ�������������
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
		// ��Ѱ��ߵ�һ�����ӣ����������м������Ѱ��ˮλ�϶����뵱ǰ������������ӣ�С����߸߶ȣ���ƽ���������𽥼�����������
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
		//���ֲ���target,��vi[begin,...,end]��(ǰ�պ��)
		//mid = begin+(end - begin)/2 �Ƚ�target/vi[mid]
		//��target > vi[mid],��begin = mid + 1;
		//��target < vi[mid],��end = mid - 1;
		//����ȣ��򷵻�mid+1��
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
		{//�����ǰλ��û�ﵽĿ�ĵأ��������
			ipPosition = icPosition;//�������ҵ�ǰλ�ã����߱��浱ǰλ�ö�Ӧ������Զ���롣
			while (i <= ipPosition)//��������ǰλ��֮���ܹ�����������ǰһ��λ��δ�ܱ�������λ�ý����ж������Ƿ������ĸ�Զ��ȡ��Զ��λ�á�
			{
				icPosition = max(icPosition, i + nums[i]);
				i++;
			}
			//ÿ��������֮�󣬼�������һ��ʾ����һ����
			count++;
			cout << icPosition << " ";
		}
		cout << endl;
		return count;
	}

	void getAllPermution(vector<vector<int>>& res, vector<int>& nums, int begin, int end)
	{//��nums[begin, end]�������е����У����������н������res
		if (begin == end)
		{//���������ȣ���ʾ�Ѿ��ҵ�һ�����У� ����ʱ��nums�������У����л��ݡ�
			res.push_back(nums);
			return;
		}
		//���begin<end,��ӽ�begin��Ӧ�����ͺ������һһ����������׷��begin+1,end
		for (int i = begin;i <= end;i++)
			//i:[begin, end]������begin��ԭ���ǣ���Ҫ�ҵ���ǰ�����䣬������������ȫ���������
			//����end��ԭ���ǵ�ǰ��Ҫ�ͺ����ÿһ���������е�����������Ҫ����end��
		{
			swap(nums[begin], nums[i]);//�����꣬����׷��
			getAllPermution(res, nums, begin + 1, end);
			swap(nums[begin], nums[i]);//����������ò���
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
		//������������ȫ���У����û����㷨��֮��
		vector<vector<int>> res;
		getAllPermution(res, nums, 0, nums.size() - 1);
		return res;
	}

	void getAllUniPermution(set<vector<int>>& res, vector<int>& nums, int begin, int end)
	{//��nums[begin, end]�������е����У����������н������res
		if (begin == end)
		{//���������ȣ���ʾ�Ѿ��ҵ�һ�����У� ����ʱ��nums�������У����л��ݡ�
			res.insert(nums);
			return;
		}
		//���begin<end,��ӽ�begin��Ӧ�����ͺ������һһ����������׷��begin+1,end
		for (int i = begin;i <= end;i++)
			//i:[begin, end]������begin��ԭ���ǣ���Ҫ�ҵ���ǰ�����䣬������������ȫ���������
			//����end��ԭ���ǵ�ǰ��Ҫ�ͺ����ÿһ���������е�����������Ҫ����end��
		{
			swap(nums[begin], nums[i]);//�����꣬����׷��
			getAllUniPermution(res, nums, begin + 1, end);
			swap(nums[begin], nums[i]);//����������ò���
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
		//����row�У�col���ܷ���ûʺ�����ж���������򷵻�true
		for (int i = 0;i < row;i++)//��ǰλ����row�У���֮ǰ�϶��Ѿ���[0,...,row-1]�з����˻ʺ󣬶���ÿһ���ʺ�һһ�����ж�
		{
			//��������ʺ�������ȣ� ��ֱ���ж����ܷ��ã�����false
			//��������ʺ����������ֵ�������������ֵ�����������ʺ���ͬһб���ϣ�Ҳ�ж�Ϊ���ܷ��ã�����false
			if (qFlag[i] == col || (abs(row - i) == abs(col - qFlag[i])))
				return false;
		}
		//�����Ѿ����õ�row���ʺ����������ͻ����ǰ[row,col]���Է��ûʺ󣬷���true
		return true;
	}

	void queen(vector<int> qFlag, vector<vector<int>> &output, int row, int n)
	{
		//N�ʺ����⣬�ݹ�ʵ��
		//row[0,...,N-1]��ʾ�ӵ�һ�е���N�У�
		//qFlagΪNά������������Ӧ����[0,...,N-1]���洢��ֵ�ǻʺ���õ�����[0,...,N-1]��
		//output ΪX*Nά������ ÿһ�ж�Ӧһ�ֽ⣬Xδ֪��
		if (row == n)
		{
			output.push_back(qFlag);//row == N ����ʾ�Ѿ�ǰ��N�㶼���ú��˻ʺ������ǰ�⣬Ȼ����ݡ�
		}
		else
		{
			for (int i = 0;i < n;i++)
			{
				if (CanPlaceQueen(qFlag, row, i))//�����ǰλ�ÿ��Է��ûʺ�����ûʺ��޸�flag��
				{
					qFlag[row] = i;//��ǰλ�÷��ûʺ��޸ĵ�row�ж�Ӧ��flagΪ���õ�������
					queen(qFlag, output, row + 1, n);//����һ�м�����Ѱ
												  //qFlag[row] = -1;//���ݷ����ģ���ÿ��̽����֮������׷��ǰ���޸ġ�
												  //��������£����Բ��ý������ò�������Ҫԭ���ǵ�ǰ���޸ĵ�ֵ�Ի���֮������û���κ�Ӱ�졣
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
		The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.



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
		//����DP���⣬�ӵ�һ��Ԫ�����������Ҳ��ӵ���ǰ�����к���
		//�������к�С�ڵ���0�����ʾ�����в�Ӧ���뵱ǰԪ�أ��������н������ã�����֮ǰ����������к�����֪���������кͱȽϣ�������
		//�������кʹ���0��˵���ɼ����������У�����������ҡ�
		if (nums.empty())
			return 0;
		int MaxSum = nums[0];
		int subMaxSum = nums[0];
		for (int i = 1;i < nums.size();i++)
		{//�ӵ�һ��Ԫ���ҵ����һ��Ԫ�أ�����©��
			if (subMaxSum < 0)
				//���֮ǰ�������к�С��0����ô����Ϊ����������еĸ���
				//����������գ�����ǰԪ�ص����������еĵ�һ��Ԫ��
				subMaxSum = nums[i];
			else
				//���֮ǰ�������в�С��0������Լ���ά�������У�����ǰԪ����ӵ���ǰ�������У��������
				subMaxSum += nums[i];
			MaxSum = max(MaxSum, subMaxSum);//ÿ���޸������к͵�ͬʱ���������ֵ
		}
		return MaxSum;
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
		//����չʾ���Σ��������������һά����
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
		//̰���㷨�ɽ⣬ÿ�δӵ�ǰλ��������������Զ�����������������λ���������Զ����֮�ڣ����ʾ���Ե������true����֮false.
		int icPosition = 0;//���浱ǰ�ɵ������Զλ��
		int ipPosition = 0;//���浱ǰλ�����������������
		int i = 0;//ָ��ǰλ��
		while (i < nums.size())
		{
			ipPosition = icPosition;//�������ϴ��ҵ�����Զλ��
			while (i <= ipPosition)
			{
				if (nums[i] != 0)
					icPosition = max(icPosition, i + nums[i]);//̰��˼�������Զλ��
				i++;//һ��һ������ң�ֱ���ҵ�֮ǰλ�����ܵ������Զλ�á�
			}

			//ÿ����֮ǰ�ж�������������һ��λ������Զλ�÷�Χ�ڣ��򷵻�ture��
			if (icPosition >= nums.size() - 1)
			{
				return true;
			}
			//����ҵ����´���Զλ�ó���������Ϊ0����ֱ�ӷ���false.
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
		int i = 1;//[1,..,2n]����
		int j = 0;//[0,...,n/2]��
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
		//��̬�滮�ɽ⣬��ʼ��һ��m*n�ľ��󣬱�ʾ·������dp[i][j]�����(0,0)��(i,j)�����в�ͬ·����
		//��̬�滮���ģ����ƹ�ϵʽ
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
		//��̬�滮�����ע�⵱ǰλ��Ϊ�ϰ���ע���ܵ��ﵱǰλ�õ�λ�ÿ���Ϊ�ϰ���ע���ʼλ�ÿ���Ϊ�ϰ�.
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
				dp[i][j] = (dp[i - 1][j] * (1- obstacleGrid[i - 1][j]) + dp[i][j - 1] * (1 - obstacleGrid[i][j - 1]))*(1 - obstacleGrid[i][j]);
			}
		}
		printMatrix(dp);
		return dp[m - 1][n - 1];
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
		//һ���Ǹ����������ʾһ������(���λ����ǰ��)�������������+1���㡣
		//���δ����λ����
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
}
