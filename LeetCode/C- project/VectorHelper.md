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
}
```
