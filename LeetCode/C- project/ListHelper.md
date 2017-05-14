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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		/*  Accepted
		92. Reverse Linked List II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 105075
		Total Submissions: 347869
		Difficulty: Medium
		Contributor: LeetCode
		Reverse a linked list from position m to n. Do it in-place and in one-pass.

		For example:
		Given 1->2->3->4->5->NULL, m = 2 and n = 4,

		return 1->4->3->2->5->NULL.

		Note:
		Given m, n satisfy the following condition:
		1 ≤ m ≤ n ≤ length of list.
		*/
		vector<int> vi = translateList(head);
		reverse(vi.begin() + m - 1, vi.begin() + n);
		return translateVector(vi);
	}

	ListNode* reverseList(ListNode* head) {
		/*  Accepted
		206. Reverse Linked List Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 216535
		Total Submissions: 484606
		Difficulty: Easy
		Contributor: LeetCode
		Reverse a singly linked list.

		click to show more hints.

		Hint:
		A linked list can be reversed either iteratively or recursively. Could you implement both?
		*/
		/*  Accepted
		vector<int> vi = translateList(head);
		reverse(vi.begin(), vi.end());
		return translateVector(vi);
		*/
		if (head == NULL)
			return head;
		ListNode* preNode = NULL;
		ListNode* nowNode = head;
		ListNode* nextNode = head->next;
		while (nowNode)
		{
			nextNode = nowNode->next;
			nowNode->next = preNode;
			preNode = nowNode;
			nowNode = nextNode;
		}
		return preNode;
	}

	bool isPalindrome(ListNode* head) {
		/*   Accepted
		234. Palindrome Linked List Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 98772
		Total Submissions: 306733
		Difficulty: Easy
		Contributor: LeetCode
		Given a singly linked list, determine if it is a palindrome.

		Follow up:
		Could you do it in O(n) time and O(1) space?
		*/
		//回文串链表判断
		if (head == NULL)
			return true;
		ListNode* p = head;
		int length = 0;
		while (p)
		{
			p = p->next;
			length++;
		}
		p = head;
		ListNode* q = head;
		if (length == 1)
			return false;
		if (length % 2 == 0)
		{//偶数个节点，可以平分所有节点，反转后面半部分节点
			int temp = length / 2 + 1;
			q = reverseBetween(head, temp, length);
			while (q && temp-- > 1)
				q = q->next;
		}
		else
		{//奇数个节点，除去中间节点，反转后面部分的节点
			int temp = length / 2 + 2;
			q = reverseBetween(head, temp, length);
			while (q && temp-- > 1)
				q = q->next;
		}
		while (q && p)
		{
			if (p->val == q->val)
			{
				p = p->next;
				q = q->next;
			}
			else
				return false;
		}
		return true;
	}
	RandomListNode *copyRandomList(RandomListNode *head) {
        /*
         * 138. Copy List with Random Pointer Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 108256
        Total Submissions: 408895
        Difficulty: Medium
        Contributor: LeetCode
        A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

        Return a deep copy of the list.
         */
        //复制这样的一个表，我们从头开始，按照next的顺序进行复制，对于没有创建的节点，进行创建节点后放入map，建立原节点到现有节点的map
        //对于当前的每个节点，我们需要建立两个对应关系，next节点和random节点，
        if(head == NULL)//如果为空链表我们返回空链表
            return NULL;
        map<RandomListNode*, RandomListNode*> mRRmap;//建立旧节点到新节点的映射，mRR[旧节点] = 新节点
        RandomListNode* newhead = new RandomListNode(head->label);//建立新的头结点
        mRRmap[head] = newhead;
        RandomListNode* p = head;
        while(p != NULL)//头结点不为空
        {
            //如果在map中肯定能找到当前遍历的p节点（在上一遍循环中已经建立）
            RandomListNode* newNowNode = mRRmap[p];
            if(p->next!=NULL && mRRmap.find(p->next) == mRRmap.end())//如果在map中找不到当前遍历的p节点的下一个节点,建立对应关系，并放入map中
            {
                mRRmap[p->next] = new RandomListNode(p->next->label);
                newNowNode->next = mRRmap[p->next];
            }
            else newNowNode->next = mRRmap[p->next];
            if(p->random!= NULL && mRRmap.find(p->random) == mRRmap.end())//如果在map中找不到当前遍历的p节点的random节点
            {
                mRRmap[p->random] = new RandomListNode(p->random->label);
                newNowNode->random = mRRmap[p->random];
            }
            else newNowNode->random = mRRmap[p->random];
            //建立完了映射关系和新链表关系后，指向下一个节点继续建立
            p = p->next;
        }
        return mRRmap[head];
    }

    bool hasCycle(ListNode *head) {
        /*
         * 141. Linked List Cycle Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 173763
        Total Submissions: 489733
        Difficulty: Easy
        Contributor: LeetCode
        Given a linked list, determine if it has a cycle in it.

        Follow up:
        Can you solve it without using extra space?
         */
        //快慢指针即可解决，若有环，则快慢指针肯定会相遇，若没有环，则不会相遇就会到达终点
        if(head == NULL || head->next == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;//快慢指针都从头结点开始
        do{
            fast = fast->next->next;//快指针一次两步
            slow = slow->next;//慢指针一次一步
            if(slow == fast)
                return true;
        }while(fast != NULL && fast->next != NULL && slow != NULL);
        return false;
    }

    ListNode *detectCycle(ListNode *head) {
        /*
         * 142. Linked List Cycle II Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 110537
        Total Submissions: 356384
        Difficulty: Medium
        Contributor: LeetCode
        Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

        Note: Do not modify the linked list.

        Follow up:
        Can you solve it without using extra space?
         */
        //同样使用快慢指针探测环，当快慢指针相遇时必定是在环起点处
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;//快慢指针都从头结点开始
        bool flag = false;
        do{
            fast = fast->next->next;//快指针一次两步
            slow = slow->next;//慢指针一次一步
            if(slow == fast) {
                flag = true;
                break;
            }
        }while(fast != NULL && fast->next != NULL && slow != NULL);
        if(flag)
        {
            ListNode* res = head;
            while(slow != res)
            {
                slow = slow->next;
                res = res->next;
            }
            return res;
        }
        else return NULL;
    }

    void reorderList(ListNode* head) {
        /*
         * 143. Reorder List Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 89399
        Total Submissions: 355872
        Difficulty: Medium
        Contributor: LeetCode
        Given a singly linked list L: L0→L1→…→Ln-1→Ln,
        reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

        You must do this in-place without altering the nodes' values.

        For example,
        Given {1,2,3,4}, reorder it to {1,4,2,3}.
         */
        if(head == NULL)
            return;
        vector<int> vi = translateList(head);
        vector<int> viR;
        int begin = 0;
        int end = int(vi.size()) - 1;
        while(begin < end)
        {
            viR.push_back(vi[begin++]);
            viR.push_back(vi[end--]);
        }
        if(begin == end)viR.push_back(vi[begin]);
        ListNode* pHead = head;
        for(auto it:vector<int>(viR.begin() + 1,viR.end())) {
            pHead->next = new ListNode(it);
            pHead = pHead->next;
        }
        return;
    }

    ListNode* insertionSortList(ListNode* head) {
        /*
         * 147. Insertion Sort List Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 98129
        Total Submissions: 301762
        Difficulty: Medium
        Contributor: LeetCode
        Sort a linked list using insertion sort.
         */
        //指定了插入排序，使用插入排序的方法对链表进行排序，默认是升序
        if(head == NULL)
            return head;//如果是空链表，则直接返回
        ListNode* lnHead = new ListNode(-1);//初始化一个新的链表，头结点的下一个节点值等于旧链表的头结点值（方便链表头插入）
        lnHead->next = new ListNode(head->val);
        ListNode* p = head->next;//从头结点后面第一个节点开始插入排序
        ListNode* plnHead;
        ListNode* temp;
        while(p)
        {//如果当前需要插入的节点不是NULL,则进行插入
            plnHead = lnHead;//每次都新链表的表头插入
            while(plnHead->next && plnHead->next->val < p->val)//当节点的下个节点值大于等于需要插入的节点值或者下一个节点为NULL时，进行插入
                plnHead = plnHead->next;
            //在此时的plnHead后面进行插入
            temp = plnHead->next;
            plnHead->next = new ListNode(p->val);
            plnHead->next->next = temp;
            p = p->next;
        }
        //当无插入节点时，返回新链表辅助节点的下一个节点即为新链表的头结点
        return lnHead->next;
    }

    ListNode* getMidofList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)//如果是空链表，或者是一个节点的链表，则直接返回此链表，不切
            return head;
        //获取链表的中间节点，并从中间节点开始切断
        //使用快慢指针实现
        ListNode* pre;
        ListNode* slow = head;
        ListNode* fast = head;
        //如果是奇数个节点，fast到了最后一个节点时，slow恰好到了最中间的那个节点
        //如果是偶数个节点，fast到了倒数第二个节点时，slow到了前半部分的最后一个节点，此时slow还要再往后走一步
        do{
            pre = slow;//保存slow节点的之前一个节点，用来切割链表
            slow = slow->next;
            fast = fast->next->next;
        }while(fast && fast->next);
        pre->next = NULL;
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        /*
         * 148. Sort List Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 101187
        Total Submissions: 360116
        Difficulty: Medium
        Contributor: LeetCode
        Sort a linked list in O(n log n) time using constant space complexity.
         */
        //时间复杂度要求O(nlogn),要求常量的空间复杂度
        //使用归并排序,先将链表切断为两段，对两段分别进行排序，然后merge排序后的两段链表
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* preList = head;//第一段链表的头结点为head
        ListNode* behList = getMidofList(head);//第二段链表头结点为慢指针指向的节点
        preList = sortList(preList);//排序后更新链表
        behList = sortList(behList);
        return mergeTwoLists(preList,behList);//merge两个已经排序后的链表
    }
}
```
