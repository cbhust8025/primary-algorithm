```C++
#pragma once
//
// Created by CB on 04/17-2007
//
#include<iostream>
#include<cassert>
#include<ctime>
#include<vector>
//#include<string>
using namespace std;
namespace ListHelper
{
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	//生成n个节点的随机链表，每个元素的随机范围为[rangeL,rangeR]
	ListNode* generateRandomList(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		ListNode *pHead = new ListNode(rand() % (rangeR - rangeL + 1) + rangeL);
		ListNode *p = pHead;
		srand(time(NULL));
		for (int i = 1;i < n;i++)
		{
			pHead->next = new ListNode(rand() % (rangeR - rangeL + 1) + rangeL);
			pHead = pHead->next;
		}
		return p;
	}

	//生成n个节点的随机有序链表，元素的起始值为[begin,begin+step),每两个相邻元素之间的步长在[0,step)
	ListNode* generateSortList(int n, int begin, int step)
	{
		assert(begin > 0);
		ListNode *pHead = new ListNode(begin);
		ListNode *p = pHead;
		srand(time(NULL));
		for (int i = 1 ;i < n;i++)
		{
			begin = begin + rand() % step;
			pHead->next = new ListNode(begin);
			pHead = pHead->next;
		}
		return p;
	}

	//打印链表
	void printList(ListNode* pHead)
	{
		while (pHead)
		{
			cout << pHead->val << "->";
			pHead = pHead->next;
		}
		cout << "NULL" << endl;
		return;
	}

	//将链表转换成对应元素的vector
	vector<int> translateList(ListNode* pHead)
	{
		vector<int> res;
		while (pHead)
		{
			res.push_back(pHead->val);
			pHead = pHead->next;
		}
		return res;
	}

	//将vector转换成对应元素的链表
	ListNode* translateVector(const vector<int> vi)
	{
		if (vi.empty())
		{
			return NULL;
		}
		ListNode* pHead = new ListNode(vi[0]);
		ListNode* p = pHead;
		for (int i = 1;i < vi.size();i++)
		{
			p->next = new ListNode(vi[i]);
			p = p->next;
		}
		return pHead;
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		/*    Accepted
		LeetCode 21. Merge Two Sorted Lists Add to List
		Total Accepted : 209802 Total Submissions : 544474 Difficulty : Easy Contributor : LeetCode
		Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.

		Subscribe to see which companies asked this question.
		*/
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* p3;
		if (p1 == NULL)
			//若链表l1为空，则直接返回链表l2
		{
			return p2;
		}
		if (p2 == NULL)
			//若链表l2为空，则直接返回链表l1
		{
			return p1;
		}
		if (p1->val < p2->val)
		{
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3 = p2;
			p2 = p2->next;
		}
		ListNode* p4 = p3;
		while (p1 && p2)
		{
			if (p1->val < p2->val)
			{
				p3->next = p1;
				p1 = p1->next;
				p3 = p3->next;
			}
			else if (p1->val >= p2->val)
			{
				p3->next = p2;
				p2 = p2->next;
				p3 = p3->next;
			}
		}
		while (p1)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		while (p2)
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
		return p4;
	}


	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		/*    Accepted
		23. Merge k Sorted Lists Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 140200
		Total Submissions: 527019
		Difficulty: Hard
		Contributor: LeetCode
		Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
		
		Subscribe to see which companies asked this question.*/

		if (lists.empty())
		{
			return (ListNode*)NULL;
		}
		while (lists.size() > 1)
		{
			printList(lists[lists.size() - 1]);
			ListNode* pL = mergeTwoLists(lists[lists.size() - 1], lists[lists.size() - 2]);
			lists.pop_back();
			lists.pop_back();
			lists.push_back(pL);
		}
		return lists[0];
	}

	ListNode* swapPairs(ListNode* head) {
		/*   Accepted
		24. Swap Nodes in Pairs Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 155272
		Total Submissions: 411913
		Difficulty: Medium
		Contributor: LeetCode
		Given a linked list, swap every two adjacent nodes and return its head.

		For example,
		Given 1->2->3->4, you should return the list as 2->1->4->3.

		Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

		Subscribe to see which companies asked this question.
		*/
		if (!head)
		{
			return NULL;
		}
		if (!head->next)
		{
			return head;
		}
		ListNode* pHead = head->next;
		ListNode* temp;
		ListNode* priority = head;
		while (head && head->next)
		{
			temp = head->next;
			head->next = temp->next;
			temp->next = head;
			priority = head;
			head = head->next;
			if (head && head->next)
			{
				priority->next = head->next;
			}
		}
		return pHead;
	}


	ListNode* reverseKGroup(ListNode* head, int k) {
		/*  Accepted
		25. Reverse Nodes in k-Group Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 88513
		Total Submissions: 293121
		Difficulty: Hard
		Contributor: LeetCode
		Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

		k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

		You may not alter the values in the nodes, only nodes itself may be changed.

		Only constant memory is allowed.

		For example,
		Given this linked list: 1->2->3->4->5

		For k = 2, you should return: 2->1->4->3->5

		For k = 3, you should return: 3->2->1->4->5
		*/
		if (!head || k == 1)
		{
			return head;
		}
		vector<int> vi = translateList(head);
		if (k > vi.size())
		{
			return head;
		}
		auto vv = vi.begin();
		for (int i = 0;i <= vi.size() - k;i += k)
		{
			reverse(vv + i, vv + i + k);
		}
		ListNode* res = translateVector(vi);
		return res;
	}
}
```
