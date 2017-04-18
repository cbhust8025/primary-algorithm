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
}
