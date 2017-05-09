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
	vector<TreeNode*> gTrees(int start, int stop)
	{
		vector<TreeNode*> vT;
		if (start > stop)
		{//如果start>stop，直接返回空子树集合
			vT.push_back(NULL);
			return vT;
		}
		if (start == stop)
		{//如果start == stop， 表示只有一个可用值，构建一个元素的子树
			TreeNode* root = new TreeNode(start);
			vT.push_back(root);
			return vT;
		}
		//start < stop，可用值为[start,start + 1,...,stop]，在这所有的元素中挑选一个作为根节点构建子树集合。并保存
		for (int i = start;i <= stop;i++)
		{//start,...,stop中挑选一个出来作为根节点。
			//此时根节点为i，左子树从start,..,i -1,右子树从i+1,...stop
			vector<TreeNode*> left = gTrees(start, i - 1);
			vector<TreeNode*> right = gTrees(i + 1, stop);
			for (auto it = left.begin();it != left.end();it++)
			{
				for (auto it2 = right.begin();it2 != right.end();it2++)
				{
					TreeNode* root = new TreeNode(i);
					root->left = *it;
					root->right = *it2;
					vT.push_back(root);
				}
			}
		}
		return vT;
	}

	vector<TreeNode*> generateTrees(int n) {
		/*
		95. Unique Binary Search Trees II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 79221
		Total Submissions: 255465
		Difficulty: Medium
		Contributor: LeetCode
		Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

		For example,
		Given n = 3, your program should return all 5 unique BST's shown below.

		1         3     3      2      1
		 \       /     /      / \      \
		  3     2     1      1   3      2
		 /     /       \                 \
		2     1         2                 3
		*/
		//采用递归的思想解决，本问题从n个节点出发，要想找出所有的组合情况，需考虑根节点为从[1,n]共n种情况，
		//当选定节点k为根节点时，[1,..,k-1]所有节点自然划分为k的左子树节点，[k+1,...,n]所有节点为k的右子树节点，此时问题划分为求解k的左右子树可能形态
		//每次子问题的求解可以使用递归求解，但是需要不断的刷新区间的两边，所以需要重构一个递归函数来进行求解，返回值vector<TreeNode*>
		if (n < 1)return vector<TreeNode*>();
		return gTrees(1, n);
	}

	bool isValidBST(TreeNode* root) {
		/*  Accepted
		98. Validate Binary Search Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 156719
		Total Submissions: 683859
		Difficulty: Medium
		Contributor: LeetCode
		Given a binary tree, determine if it is a valid binary search tree (BST).

		Assume a BST is defined as follows:

		The left subtree of a node contains only nodes with keys less than the node's key.
		The right subtree of a node contains only nodes with keys greater than the node's key.
		Both the left and right subtrees must also be binary search trees.
		Example 1:
		  2
		 / \
		1   3
		Binary tree [2,1,3], return true.
		Example 2:
		  1
		 / \
		2   3
		Binary tree [1,2,3], return false.
		*/
		//判断是否是二叉搜索树，利用二叉搜索树的中序遍历序列为有序序列的性质即可
		if (root == NULL)
			return true;
		//非递归实现二叉树中根序遍历
		//对于当前节点，直接压入栈中，若其左孩子节点不为空，则指向左孩子节点继续之前操作。
		//若左孩子节点为空，则访问栈顶元素（此时栈顶元素为左孩子为空的父节点，也就是第一优先级访问）
		//将当前元素置为栈顶元素右孩子节点（也就是最近的父节点的右孩子，同级右孩子）
		//重复操作，直至p == NULL 并且栈为空。
		TreeNode* p = root;
		stack<TreeNode*> sTp;
		int flag = 0;
		int now;
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
				if (flag == 0)
					now = sTp.top()->val;
				else if(sTp.top()->val > now)
					now = sTp.top()->val;
				else
					return false;
				p = sTp.top()->right;
				sTp.pop();
			}
		}
		return true;
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		/*
		100. Same Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 196449
		Total Submissions: 427622
		Difficulty: Easy
		Contributor: LeetCode
		Given two binary trees, write a function to check if they are equal or not.

		Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
		*/
		//递归判断，两颗相同的树具有特点：根节点肯定相同，左右子树肯定分别相同
		if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
			return false;
		if (p == NULL && q == NULL)
			return true;
		if (p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else
			return false;
	}

	void exchangeLR(TreeNode* root)
	{
		if (root == NULL)
			return;
		//交换当前根节点的左右子树
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		exchangeLR(root->left);
		exchangeLR(root->right);
		return;
	}

	bool isSymmetric(TreeNode* root) {
		/*
		101. Symmetric Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 169448
		Total Submissions: 446159
		Difficulty: Easy
		Contributor: LeetCode
		Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

		For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

		    1
		   / \
		  2   2
		 / \ / \
		3  4 4  3
		But the following [1,2,2,null,3,null,3] is not:
		  1
		 / \
		2   2
		 \   \
		  3   3
		Note:
		Bonus points if you could solve it both recursively and iteratively.

		Subscribe to see which companies asked this question.
		*/
		//判断是不是镜像树
		if (root == NULL)
			return true;
		//对于根节点的左右子树，对右子树递归调换每个节点的左右节点，然后判断根节点的左右子树是否是同样的树，如果是则表示是镜像
		exchangeLR(root->right);
		return isSameTree(root->left, root->right);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		/*
		102. Binary Tree Level Order Traversal Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 165540
		Total Submissions: 429672
		Difficulty: Medium
		Contributor: LeetCode
		Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

		For example:
		Given binary tree [3,9,20,null,null,15,7],
		    3
		   / \
		  9  20
		    /  \
		   15   7
		return its level order traversal as:
		[
		[3],
		[9,20],
		[15,7]
		]
		*/
		vector<vector<int>> vviRes;
		//层序遍历即可，利用stl库中的queue适配器
		if (root == NULL)
			return vviRes;
		queue<TreeNode*> qT1;
		queue<TreeNode*> qT2;
		qT1.push(root);//将根节点入队列1
		while (!qT1.empty() || !qT2.empty())
		{
			vector<int> temp;
			if (!qT1.empty())
			{
				while (!qT1.empty())
				{
					TreeNode* p = qT1.front();
					temp.push_back(p->val);
					if (p->left)qT2.push(p->left);
					if (p->right)qT2.push(p->right);
					qT1.pop();
				}
				vviRes.push_back(temp);
			}
			else if (!qT2.empty())
			{
				while (!qT2.empty())
				{
					TreeNode* p = qT2.front();
					temp.push_back(p->val);
					if (p->left)qT1.push(p->left);
					if (p->right)qT1.push(p->right);
					qT2.pop();
				}
				vviRes.push_back(temp);
			}
		}
		return vviRes;
	}

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		/*
		103. Binary Tree Zigzag Level Order Traversal Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 96086
		Total Submissions: 286255
		Difficulty: Medium
		Contributor: LeetCode
		Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

		For example:
		Given binary tree [3,9,20,null,null,15,7],
		   3
		  / \
		 9  20
		   /  \
		  15   7
		return its zigzag level order traversal as:
		[
		[3],
		[20,9],
		[15,7]
		]
		*/
		vector<vector<int>> vviRes;
		//层序遍历即可，利用stl库中的queue适配器
		if (root == NULL)
			return vviRes;
		queue<TreeNode*> qT1;
		queue<TreeNode*> qT2;
		qT1.push(root);//将根节点入队列1
		while (!qT1.empty() || !qT2.empty())
		{
			vector<int> temp;
			if (!qT1.empty())
			{
				while (!qT1.empty())
				{
					TreeNode* p = qT1.front();
					temp.push_back(p->val);
					if (p->left)qT2.push(p->left);
					if (p->right)qT2.push(p->right);
					qT1.pop();
				}
				vviRes.push_back(temp);
			}
			else if (!qT2.empty())
			{
				while (!qT2.empty())
				{
					TreeNode* p = qT2.front();
					temp.push_back(p->val);
					if (p->left)qT1.push(p->left);
					if (p->right)qT1.push(p->right);
					qT2.pop();
				}
				//将temp逆序，每个偶数层逆序
				reverse(temp.begin(), temp.end());
				vviRes.push_back(temp);
			}
		}
		return vviRes;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		/*
		105. Construct Binary Tree from Preorder and Inorder Traversal Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 97263
		Total Submissions: 308366
		Difficulty: Medium
		Contributor: LeetCode
		Given preorder and inorder traversal of a tree, construct the binary tree.

		Note:
		You may assume that duplicates do not exist in the tree.
		*/
		//根据树的前序遍历序列和中序遍历序列，重构出树的结构，并返回根节点。
		//前根序序列中的第一个元素在中序序列中将中序序列分为两部分，第一部分组成左子树，第二部分组成右子树，根据元素个数，将前根序序列也进行划分
		//划分完后进行递归调用
		if (preorder.empty())
			return NULL;
		TreeNode* root = new TreeNode(preorder[0]);//根节点必然是前序序列的第一个元素
		int index = 0;
		while (index < inorder.size() && inorder[index] != preorder[0])index++;//根节点对应的元素必然能够在中序序列中找到
		//找到的index 将中序序列分为两部分[0,index),[index + 1,inorder.size())
		vector<int> inorder_left = vector<int>(inorder.begin(), inorder.begin() + index);
		vector<int> inorder_right = vector<int>(inorder.begin() + index + 1, inorder.end());
		//同样的index 将前序序列分为两部分[1,1+index),[1+index,end())
		vector<int> preorder_left = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + index);
		vector<int> preorder_right = vector<int>(preorder.begin() + 1 + index, preorder.end());
		//对于两部分序列递归调用，找到root的左右子树根节点
		TreeNode* rleft = buildTree(preorder_left, inorder_left);
		TreeNode* rright = buildTree(preorder_right, inorder_right);
		root->right = rright;
		root->left = rleft;
		return root;
	}
}
```
