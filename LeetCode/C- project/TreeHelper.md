```C++
#pragma once
//
// Created by CB on 05/08-2017
//
#include"VectorHelper.h"
//#include<string>
using namespace std;
namespace TreeHelper
{
	
	 //Definition for binary tree
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	void preOrder(TreeNode* root)
	{//递归实现二叉树前根序遍历
		//当前节点非空，则直接进行访问后，再去访问左右孩子节点
		if (root)
			cout << root->val << " ";
		else
			return;
		preOrder(root->left);//访问左孩子节点
		preOrder(root->right);//访问右孩子节点
		return;
	}
	void preOrderS(TreeNode* root)
	{//非递归实现二叉树前根序遍历
		//对于当前节点，访问后压入栈中，若其左孩子节点不为空，则指向左孩子节点继续之前操作。
		//若左孩子节点为空，则应该访问栈顶元素的右孩子节点（也就是最近的父节点的右孩子，同级右孩子）
		//重复操作，直至p == NULL 并且栈为空。
		TreeNode* p = root;
		stack<TreeNode*> sTp;
		while (p || !sTp.empty())
		{//如果栈不为空，或者p不为NULL,就进行以下操作
			while (p)
			{//如果p不为空，访问之后压入栈中，并且指向左孩子，直到为空为止，也即上一个p的左孩子为空
				cout << p->val << " ";
				sTp.push(p);
				p = p->left;
			}
			if (!sTp.empty())
			{//栈顶是最近的一个左孩子为空的节点，并且此节点已经进行过访问才压入栈，所以直接将其右孩子节点
				//置为当前节点，然后弹出栈顶元素。
				p = sTp.top()->right;
				sTp.pop();
			}
		}
	}
	void inOrder(TreeNode* root)
	{//递归实现二叉树中根序遍历
		//递归实现中根序遍历，则左孩子节点->根节点->右孩子节点
		//所以每次进入递归函数都是去找左孩子，直到左孩子节点为空
		if (root == NULL)
			return;
		inOrder(root->left);
		cout << root->val << " ";//当最近的左孩子访问完了之后，回溯回来当前节点就是最新的左孩子节点，访问之。
		inOrder(root->right);
		return;
	}
	void inOrderS(TreeNode* root)
	{//非递归实现二叉树中根序遍历
	 //对于当前节点，直接压入栈中，若其左孩子节点不为空，则指向左孩子节点继续之前操作。
	 //若左孩子节点为空，则访问栈顶元素（此时栈顶元素为左孩子为空的父节点，也就是第一优先级访问）
		//将当前元素置为栈顶元素右孩子节点（也就是最近的父节点的右孩子，同级右孩子）
	 //重复操作，直至p == NULL 并且栈为空。
		TreeNode* p = root;
		stack<TreeNode*> sTp;
		while (p || !sTp.empty())
		{//如果栈不为空，或者p不为NULL,就进行以下操作
			while (p)
			{//如果p不为空，直接压入栈中，并且指向左孩子，直到为空为止，也即上一个p的左孩子为空
				sTp.push(p);
				p = p->left;
			}
			if (!sTp.empty())
			{//栈顶是最近的一个左孩子为空的节点，此节点未被访问就被压入栈，所以要进行访问后再将其右孩子节点
			 //置为当前节点，然后弹出栈顶元素。
				cout << sTp.top()->val << " ";
				p = sTp.top()->right;
				sTp.pop();
			}
		}
	}
	void postOrder(TreeNode* root)
	{//递归实现二叉树后根序遍历
	 //递归实现中根序遍历，则左孩子节点->右孩子节点->根节点
	 //所以每次进入递归函数都是去找左孩子，直到左孩子节点为空
		//然后一直找寻右孩子，直到右孩子节点为空
		//当左右孩子都遍历完，访问当前节点。
		if (root == NULL)
			return;
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << " ";
		return;
	}
	void postOrderS(TreeNode* root)
	{//非递归实现二叉树后根序遍历
		//首先将根节点压入栈，每次遍历栈顶元素，
		//若栈顶元素有左右孩子，则将左右孩子按照右、左的顺序依次入栈(保证左-右-根顺序)。
		//如果栈顶元素没有左右孩子或者前一个已经访问的元素为其孩子节点，访问之，并弹出。
		stack<TreeNode*> sTp;
		TreeNode* q;
		TreeNode* pre = NULL;
		sTp.push(root);//压入根节点
		while (!sTp.empty())
		{//如果栈不为空则一直遍历。
			TreeNode* q = sTp.top();
			//如果栈顶元素没有左右孩子节点或者前一个已经访问的元素为其孩子节点，则访问之并弹出。
			if ((q->left == NULL && q->right == NULL) || ((pre != NULL) && (pre == q->right || pre == q->left)))
			{
				cout << q->val << " ";
				pre = q;
				sTp.pop();
			}
			else
			{//如果有左右孩子节点，按照右 左的顺序依次入栈
				if (q->right)sTp.push(q->right);
				if (q->left)sTp.push(q->left);
			}
		}
	}
	void postOrder2S(TreeNode* root)
	{//非递归实现二叉树后根序遍历
	 //双栈法
	 //首先将根节点压入栈S1中
		//循环弹出栈S1中栈顶元素，并压入栈S2中，每次弹出栈顶元素S1中时，将其左右孩子节点按照左、右压入栈S1中
		//S1为空后，依次从栈顶访问S2中元素即可
		stack<TreeNode*> sT1;
		stack<TreeNode*> sT2;
		TreeNode* q;
		sT1.push(root);
		while (!sT1.empty())
		{//弹出sT1的栈顶元素直至空
			q = sT1.top();
			sT1.pop();
			sT2.push(q);
			if (q->left)sT1.push(q->left);
			if (q->right)sT1.push(q->right);
		}
		while (!sT2.empty())
		{
			cout << sT2.top()->val << " ";
			sT2.pop();
		}
 	}


	int maxDepth(TreeNode *root) {
		/*
		104. Maximum Depth of Binary Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 233210
		Total Submissions: 449873
		Difficulty: Easy
		Contributor: LeetCode
		Given a binary tree, find its maximum depth.

		The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
		*/
		if (root == NULL)
			return 0;
		return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);

	}

	void getMinLeafNodeDepth(TreeNode* root, int count, int& minD)
	{
		//前根序递归遍历，找到叶子节点，输出最小的路径长度
		if (root == NULL)
			return;
		else if (root->left == NULL && root->right == NULL && count < minD)
			minD = count;
		getMinLeafNodeDepth(root->left, count + 1, minD);//访问左孩子节点
		getMinLeafNodeDepth(root->right, count + 1, minD);//访问右孩子节点
		return;
	}

	int minDepth(TreeNode* root) {
		/*
		111. Minimum Depth of Binary Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 160840
		Total Submissions: 490896
		Difficulty: Easy
		Contributor: LeetCode
		Given a binary tree, find its minimum depth.

		The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

		Subscribe to see which companies asked this question.
		*/
		//非递归实现前序遍历二叉树，利用栈来实现
		if (root == NULL)
			return 0;
		int minD = INT_MAX;
		getMinLeafNodeDepth(root, 1, minD);
		return minD;
	}
}
```
