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
	ListNode* rotateRight(ListNode* head, int k) {
		/*  Accepted
		61. Rotate List Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 103157
		Total Submissions: 425476
		Difficulty: Medium
		Contributor: LeetCode
		Given a list, rotate the list to the right by k places, where k is non-negative.

		For example:
		Given 1->2->3->4->5->NULL and k = 2,
		return 4->5->1->2->3->NULL.
		*/
		if (!head || k == 0)
			return head;
		ListNode* p = head;
		ListNode* q = head;
		int length = 1;
		while (q->next)
		{
			length++;
			q = q->next;
		}
		q->next = head;
		k %= length;
		while (length - k > 0)
		{
			q = head;
			head = head->next;
			k++;
		}
		q->next = NULL;
		return head;
	}
	ListNode* deleteDuplicates(ListNode* head) {
		/*
		82. Remove Duplicates from Sorted List II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 104108
		Total Submissions: 357962
		Difficulty: Medium
		Contributor: LeetCode
		Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

		For example,
		Given 1->2->3->3->4->4->5, return 1->2->5.
		Given 1->1->1->2->3, return 2->3.
		*/
		//如果头结点为空，则直接返回
		if (head == NULL)
			return head;
		ListNode* preHead = new ListNode(-1);//加一个辅助结点放在头结点前面，这样可以帮助进行删除重复了的头结点。
		preHead->next = head;
		ListNode* pHead = preHead;
		while (pHead && pHead->next)
		{//如果还有下一个结点，那就从下一个结点，依次找到不重复的下一个结点。
			ListNode* p = pHead->next;
			int flag = 0;
			while (p->next && p->val == p->next->val)
			{
				p = p->next;
				flag = 1;
			}
			if(flag == 1)
				pHead->next = p->next;
			else
				pHead = pHead->next;
		}
		printList(preHead);
		return preHead->next;//最后返回辅助结点的下一个结点，即新的头结点。
	}
	ListNode* deleteDuplicatesII(ListNode* head) {
		/*
		83. Remove Duplicates from Sorted List Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 175045
		Total Submissions: 444012
		Difficulty: Easy
		Contributor: LeetCode
		Given a sorted linked list, delete all duplicates such that each element appear only once.

		For example,
		Given 1->1->2, return 1->2.
		Given 1->1->2->3->3, return 1->2->3.
		*/
		//如果头结点为空，则直接返回
		if (head == NULL)
			return head;
		ListNode* preHead = new ListNode(-1);//加一个辅助结点放在头结点前面，这样可以帮助进行删除重复了的头结点。
		preHead->next = head;
		ListNode* pHead = preHead;
		while (pHead && pHead->next)
		{//如果还有下一个结点，那就从下一个结点，依次找到不重复的下一个结点。
			ListNode* p = pHead->next;
			int flag = 0;
			while (p->next && p->val == p->next->val)
			{
				p = p->next;
				flag = 1;
			}
			if (flag == 1)
				pHead->next = p;//每次只保存重复节点中的最后一个结点，并让上一个不重复结点指向之
			else
				pHead = pHead->next;
		}
		printList(preHead);
		return preHead->next;//最后返回辅助结点的下一个结点，即新的头结点。
	}

	ListNode* partition(ListNode* head, int x) {
		/*  Accepted
		86. Partition List Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 94905
		Total Submissions: 295611
		Difficulty: Medium
		Contributor: LeetCode
		Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

		You should preserve the original relative order of the nodes in each of the two partitions.

		For example,
		Given 1->4->3->2->5->2 and x = 3,
		return 1->2->2->4->3->5.
		*/
		//一个新的链表，把小于3的按照之前的顺序依次存入并从原表中删去，最后链接两个表
		if (head == NULL)
			return head;
		ListNode* pHead = new ListNode(-1);//新表辅助头结点
		ListNode* preHead = new ListNode(-1);//原表辅助头结点
		preHead->next = head;
		ListNode* p = preHead;
		ListNode* q = pHead;
		while (p->next)
		{
			if (p->next->val < x)//当前节点值小于x
			{//删去，并附在新表中
				q->next = p->next;
				p->next = p->next->next;
				q = q->next;
			}
			//如果当前节点值大于等于x，直接跳过
			//继续判断下一个结点
			else
				p = p->next;
		}
		q->next = preHead->next;
		return pHead->next;
	}
}
```
