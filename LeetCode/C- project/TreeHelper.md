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

	template<typename T1, typename T2>
	void printAdjList(map<T1, vector<T2>>& mtv)
	{
		for (auto it = mtv.begin();it != mtv.end();it++)
		{
			cout << it->first << ":";
			for (auto it2 = it->second.begin();it2 != it->second.end();it2++)
			{
				cout << *it2 << " ";
			}
			cout << endl;
		}
	}

	template<typename T1, typename T2>
	void printAdjList(map<T1, set<T2>>& mtv)
	{
		for (auto it = mtv.begin();it != mtv.end();it++)
		{
			cout << it->first << ":";
			for (auto it2 = it->second.begin();it2 != it->second.end();it2++)
			{
				cout << *it2 << " ";
			}
			cout << endl;
		}
	}
	template<typename T1, typename T2>
	void printAdjList(unordered_map<T1, unordered_set<T2>>& mtv)
	{
		for (auto it = mtv.begin();it != mtv.end();it++)
		{
			cout << it->first << ":";
			for (auto it2 = it->second.begin();it2 != it->second.end();it2++)
			{
				cout << *it2 << " ";
			}
			cout << endl;
		}
	}
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
	TreeNode* buildTree_ip(vector<int>& inorder, vector<int>& postorder) {
		/* A
		106. Construct Binary Tree from Inorder and Postorder Traversal Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 81572
		Total Submissions: 258482
		Difficulty: Medium
		Contributor: LeetCode
		Given inorder and postorder traversal of a tree, construct the binary tree.

		Note:
		You may assume that duplicates do not exist in the tree.
		*/
		//根据树的后序遍历序列和中序遍历序列，重构出树的结构，并返回根节点。
		//后根序序列中的最后一个元素在中序序列中将中序序列分为两部分，第一部分组成左子树，第二部分组成右子树，根据元素个数，将前根序序列也进行划分
		//划分完后进行递归调用
		if (postorder.empty())
			return NULL;
		TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);//根节点必然是后根序列的最后一个元素
		int index = 0;
		while (index < inorder.size() && inorder[index] != root->val)index++;//根节点对应的元素必然能够在中序序列中找到
																			   //找到的index 将中序序列分为两部分[0,index),[index + 1,inorder.size())
		vector<int> inorder_left = vector<int>(inorder.begin(), inorder.begin() + index);
		vector<int> inorder_right = vector<int>(inorder.begin() + index + 1, inorder.end());
		//同样的index 将后序序列分为两部分[0,index),[index,end()-1)
		vector<int> postorder_left = vector<int>(postorder.begin(), postorder.begin() + index);
		vector<int> postorder_right = vector<int>(postorder.begin() + index, postorder.end() - 1);
		//对于两部分序列递归调用，找到root的左右子树根节点
		TreeNode* rleft = buildTree_ip(inorder_left,postorder_left);
		TreeNode* rright = buildTree_ip(inorder_right,postorder_right);
		root->right = rright;
		root->left = rleft;
		return root;
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		/* A
		107. Binary Tree Level Order Traversal II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 123518
		Total Submissions: 315474
		Difficulty: Easy
		Contributor: LeetCode
		Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

		For example:
		Given binary tree [3,9,20,null,null,15,7],
		   3
		  / \
		 9  20
		   /  \
	   	  15   7
		return its bottom-up level order traversal as:
		[
		[15,7],
		[9,20],
		[3]
		]
		*/
		vector<vector<int>> vviRes;
		//层序遍历即可，利用stl库中的queue适配器，最后将层序结果进行逆序即可
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
		reverse(vviRes.begin(), vviRes.end());
		return vviRes;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		/* A
		108. Convert Sorted Array to Binary Search Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 119052
		Total Submissions: 287331
		Difficulty: Easy
		Contributor: LeetCode
		Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
		*/
		//高度平衡的二叉搜索树，对于有序序列来说，每次都将序列划分为均等的两边并且放在左右子树，递归调用构建即可实现
		if (nums.empty())//如果当前序列为空，则直接返回空子树
			return NULL;
		//根节点肯定属于序列的中间的那个元素
		TreeNode* root = new TreeNode(nums[nums.size() / 2]);
		//nums[nums.size()/2]将序列划分为左右两部分，第一部分[0,nums.size()/2), 第二部分[nums.size()/2 + 1,end())
		vector<int> left = vector<int>(nums.begin(), nums.begin() + nums.size() / 2);
		vector<int> right = vector<int>(nums.begin() + nums.size() / 2 + 1, nums.end());
		//分别递归求解当前根节点的左右子树
		TreeNode* tnLeft = sortedArrayToBST(left);
		TreeNode* tnRight = sortedArrayToBST(right);
		//链接根节点和其左右子树
		root->left = tnLeft;
		root->right = tnRight;
		//返回所求的根节点
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head){
		/* A
		109. Convert Sorted List to Binary Search Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 101863
		Total Submissions: 304995
		Difficulty: Medium
		Contributor: LeetCode
		Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
		*/
		//对于有序链表，采用链表转vector的方式来求解vector的高度平衡BST
		//也可以使用vector求解方式，使用快慢指针找到list中的中间的那个元素，这个元素将原链表划分为两个部分，
		//左边的一部分继续输入头结点，并将中间元素指针指向的节点置为NULL即可，
		//右边的一部分输入中间元素的next节点即可
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return new TreeNode(head->val);
		printList(head);
		//使用快慢指针找到链表的中间元素
		ListNode* slow = head;
		ListNode* pre_slow = head;
		ListNode* fast = head;
		do 
		{
			pre_slow = slow;
			slow = slow->next;
			fast = fast->next->next;
		} while (fast != NULL && fast->next != NULL && slow != NULL);
		//现在slow指向的指针是我们认为的中间元素
		TreeNode* root = new TreeNode(slow->val);
		//由于需要在求解左半部分的时候，将slow指向的节点置为NULL,所以需要先求解右子树
		TreeNode* tnRight = sortedListToBST(slow->next);
		pre_slow->next = NULL;
		TreeNode* tnLeft = sortedListToBST(head);
		//链接根节点和其左右子树
		root->left = tnLeft;
		root->right = tnRight;
		//返回所求的根节点
		return root;
	}

	int depthForBST(TreeNode* root) {//DFS找寻深度，找寻深度的同时进行BST的判定
		if (root == NULL)
			return 0;
		else
		{
			int left_depth = depthForBST(root->left);//找到根节点的左子树深度
			int right_depth = depthForBST(root->right);//找到根节点的右子树深度
			if (left_depth == -1 || right_depth == -1 || abs(left_depth - right_depth) > 1)
				return -1;//不满足BST要求，直接返回-1，传递至最初的根节点
			else//满足BST，返回左右子树深度的较大值
				return max(left_depth, right_depth) + 1;
		}
	}

	bool isBalanced(TreeNode* root) {
		/*
		110. Balanced Binary Tree Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 167788
		Total Submissions: 454410
		Difficulty: Easy
		Contributor: LeetCode
		Given a binary tree, determine if it is height-balanced.

		For this problem, a height-balanced binary tree is defined as a binary tree
		in which the depth of the two subtrees of every node never differ by more than 1.
		*/
		if (root == NULL)
			return true;
		else return(depthForBST(root) != -1);
	}

	bool hasPathSum(TreeNode* root, int sum) {
		/* A
		112. Path Sum Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 157148
		Total Submissions: 468553
		Difficulty: Easy
		Contributor: LeetCode
		Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

		For example:
		Given the below binary tree and sum = 22,
		        5
	           / \
		      4   8
		     /   / \
	    	11  13  4
		   /  \      \
	      7    2      1
		return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
		*/
		if (root == NULL)//如果根节点为NULL，则不管sum为多少，都返回false
			return false;
		if (root->left == NULL && root->right == NULL)//如果根节点为叶子节点，则判断sum是否为0，为0表示找到路径，返回true;
			//不等于0则表示未找到路径，返回false
		{
			if (sum == root->val)
				return true;
			else return false;
		}
		//如果当前节点不是叶子节点，则继续找左右子节点，一旦有一边找到即返回true
		if ((hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)))
			return true;
		return false;
	}

	void getPathSum(TreeNode* root, int sum, vector<vector<int>>& vviRes, vector<int> path)
	{//还是使用DFS进行搜索路径，应用回溯的思想来解决递归的问题
		if (root == NULL)//如果根节点为NULL，则不管sum为多少，都回溯
			return;
		if (root->left == NULL && root->right == NULL)//如果根节点为叶子节点，则判断sum是否为0，为0表示找到路径，保存当前的path到结果中;
													  //不等于0则表示未找到路径，回溯
		{
			if (sum == root->val)
			{
				path.push_back(root->val);
				vviRes.push_back(path);
				path.pop_back();
				return;
			}
			else return;
		}
		//如果当前节点不是叶子节点，则继续找左右子节点，一旦有一边找到即返回true
		path.push_back(root->val);//压入当前节点到路径中
		//找左子节点
		getPathSum(root->left, sum - root->val, vviRes, path);
		//找右子节点
		getPathSum(root->right, sum - root->val, vviRes, path);
		path.pop_back();
		return;

	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		/*
		113. Path Sum II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 122148
		Total Submissions: 373613
		Difficulty: Medium
		Contributor: LeetCode
		Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

		For example:
		Given the below binary tree and sum = 22,
		      5
		     / \
		    4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1
		return
		[
		[5,4,11,2],
		[5,8,4,5]
		]
		*/
		vector<vector<int>> vviRes;
		vector<int> path;
		getPathSum(root, sum, vviRes, path);
		return vviRes;
	}

	void flatten(TreeNode* root) {
		/* A
		114. Flatten Binary Tree to Linked List Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 121854
		Total Submissions: 354383
		Difficulty: Medium
		Contributor: LeetCode
		Given a binary tree, flatten it to a linked list in-place.

		For example,
		Given

		    1
		   / \
		  2   5
		 / \   \
		3   4   6
		The flattened tree should look like:
		1
		 \
		  2
		   \
	    	3
	       	 \
		      4
		       \
		        5
		         \
		          6
		click to show hints.

		Hints:
		If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

		Subscribe to see which companies asked this question.
		*/
		//对当前的根节点进行重构，由于是先序遍历的顺序重构，所以左子树应换到右子树，右子树的值应在左子树的值全都遍历完再去遍历
		//所以当前的根节点的右子树应该放在左子树的先序遍历的最后一个结点
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
		{//如果找到叶子节点，表示已经重构完毕，直接返回
			return;
		}
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		if (left == NULL)
		{//如果左子树为空，则直接重构右子树
			flatten(root->right);
			return;
		}
		//将左子树放在根节点的右子树位置,并清空左子树
		root->right = left;
		root->left = NULL;
		//找到左子树的先序遍历的最后一个结点
		TreeNode* p = root->right;
		while (p->right != NULL)p = p->right;
		//将右子树放在左子树最后一个结点的右子结点处
		p->right = right;
		//继续重构根节点的右子树
		flatten(root->right);
		return;
	}

	void connect(TreeLinkNode *root)
	{ 
		/*  Accepted
		116. Populating Next Right Pointers in Each Node Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 127908
		Total Submissions: 346321
		Difficulty: Medium
		Contributor: LeetCode
		Given a binary tree

		struct TreeLinkNode {
		TreeLinkNode *left;
		TreeLinkNode *right;
		TreeLinkNode *next;
		}
		Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

		Initially, all next pointers are set to NULL.

		Note:

		You may only use constant extra space.
		You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
		For example,
		Given the following perfect binary tree,
		     1
		   /  \
		  2    3
		 / \  / \
		4  5  6  7
		After calling your function, the tree should look like:
		    1 -> NULL
		   /  \
		  2 -> 3 -> NULL
		 / \  / \
		4->5->6->7 -> NULL

		*/
		//层序遍历即可，利用stl库中的queue适配器，每遍历一层，链接当前层的节点
		if (root == NULL)
			return;
		queue<TreeLinkNode*> qT1;
		queue<TreeLinkNode*> qT2;
		qT1.push(root);//将根节点入队列1
					   //每一层遍历启动flag,false表示刚开始启动，true表示已经启动
		bool flag = false;
		TreeLinkNode* p = NULL;
		while (!qT1.empty() || !qT2.empty())
		{
			//每一层遍历完，将flag置为false，等待下一层的遍历启动
			flag = false;
			if (!qT1.empty())
			{
				while (!qT1.empty())
				{
					if (!flag)
					{
						p = qT1.front();
						flag = true;
					}
					else
					{//如果已经启动， 则进行链接
						p->next = qT1.front();
						p = qT1.front();//链接完指向下一个结点
					}
					if (p->left)qT2.push(p->left);
					if (p->right)qT2.push(p->right);
					qT1.pop();
				}
			}
			else if (!qT2.empty())
			{
				while (!qT2.empty())
				{
					if (!flag)
					{
						p = qT2.front();
						flag = true;
					}
					else
					{//如果已经启动， 则进行链接
						p->next = qT2.front();
						p = qT2.front();//链接完指向下一个结点
					}
					if (p->left)qT1.push(p->left);
					if (p->right)qT1.push(p->right);
					qT2.pop();
				}

			}
		}
		return;
	}

	void connectII(TreeLinkNode *root) {
		/*  Accepted
		117. Populating Next Right Pointers in Each Node II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 92825
		Total Submissions: 276070
		Difficulty: Medium
		Contributor: LeetCode
		Follow up for problem "Populating Next Right Pointers in Each Node".

		What if the given tree could be any binary tree? Would your previous solution still work?

		Note:

		You may only use constant extra space.
		For example,
		Given the following binary tree,
		     1
		   /  \
		  2    3
		 / \    \
		4   5    7
		After calling your function, the tree should look like:
		     1 -> NULL
		   /  \
		  2 -> 3 -> NULL
		 / \    \
		4-> 5 -> 7 -> NULL
		*/
		//此题思路完全和T116 Populating Next Right Pointers in Each Node 相同
		//层序遍历即可，利用stl库中的queue适配器，每遍历一层，链接当前层的节点
		if (root == NULL)
			return;
		queue<TreeLinkNode*> qT1;
		queue<TreeLinkNode*> qT2;
		qT1.push(root);//将根节点入队列1
					   //每一层遍历启动flag,false表示刚开始启动，true表示已经启动
		bool flag = false;
		TreeLinkNode* p = NULL;
		while (!qT1.empty() || !qT2.empty())
		{
			//每一层遍历完，将flag置为false，等待下一层的遍历启动
			flag = false;
			if (!qT1.empty())
			{
				while (!qT1.empty())
				{
					if (!flag)
					{
						p = qT1.front();
						flag = true;
					}
					else
					{//如果已经启动， 则进行链接
						p->next = qT1.front();
						p = qT1.front();//链接完指向下一个结点
					}
					if (p->left)qT2.push(p->left);
					if (p->right)qT2.push(p->right);
					qT1.pop();
				}
			}
			else if (!qT2.empty())
			{
				while (!qT2.empty())
				{
					if (!flag)
					{
						p = qT2.front();
						flag = true;
					}
					else
					{//如果已经启动， 则进行链接
						p->next = qT2.front();
						p = qT2.front();//链接完指向下一个结点
					}
					if (p->left)qT1.push(p->left);
					if (p->right)qT1.push(p->right);
					qT2.pop();
				}

			}
		}
		return;
	}

	int maxLinkSum(TreeNode* root, int& maxAll)
	{//联通路径最大和,maxAll存储当前找到的所有路径和的最大值
		//对于以root为根节点的最大路径和，可能出现在以下四种情况中:
		//1、root 2、root+left 3、root+right 4、root+left + right
		if (root == NULL)//根节点为空，直接返回0
			return 0;
		int leftSum = maxLinkSum(root->left, maxAll);//左子树的最大值，如果小于0，则置为0
		int rightSum = maxLinkSum(root->right, maxAll);//右子树的最大值
		int rootSum = root->val + max(0, leftSum) + max(0, rightSum);//找到1,2,3,4四种情况下的最大值
		//因为此时的四种情况最大值是包含根节点，是联通路径和
		if (rootSum > maxAll)
			maxAll = rootSum;//更新最大值
		//如果需要返回值，则证明是另外一个根节点来调用此函数，所以只能返回1,2,3三种情况下的最大和，即最大路径和
		return max(root->val, max(root->val + leftSum, root->val + rightSum));
	}

	int maxPathSum(TreeNode* root) {
		/*
		124. Binary Tree Maximum Path Sum Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 93119
		Total Submissions: 364019
		Difficulty: Hard
		Contributor: LeetCode
		Given a binary tree, find the maximum path sum.

		For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

		For example:
		Given the below binary tree,

		  1
	 	 / \
		2   3
		Return 6.
		*/
		if (root == NULL)//空树直接返回0
			return 0;
		int rootMax = INT_MIN;
		maxLinkSum(root, rootMax);
		return rootMax;
	}


	int GetWordsDistance(string a, string b)
	{
		if (a.size() != b.size())
			return false;
		int count = 0;
		for (int i = 0;i < a.size();i++)
		{
			if (a[i] != b[i])
				count++;
		}
		return count;
	}
	void GetPathFromMsv(vector<vector<string>>& vvsRes, map<string, set<string>>& vviAdjList,
		vector<string>& vsPath, string beginWord, string endWord)
	{
		//回溯法获得路径
		if (beginWord == endWord)//如果找到目标单词，则找到一条路径
		{
			reverse(vsPath.begin(), vsPath.end());//回溯前修改
			vvsRes.push_back(vsPath);
			reverse(vsPath.begin(), vsPath.end());//回溯前的重置
			return;
		}
		for (auto it = vviAdjList[beginWord].begin();it != vviAdjList[beginWord].end();it++)
		{
			vsPath.push_back(*it);
			GetPathFromMsv(vvsRes, vviAdjList, vsPath, *it, endWord);
			vsPath.pop_back();
		}
		return;
	}

	void BFSforCreateTree(map<string, set<string>>& vviAdjList, string beginWord, string endWord, set<string>& wordList)
	{//利用宽搜方法建立层次邻接表，高层节点不会出现在下层中，所以在每个高层节点入队列并保存邻接表后，将高层节点进行删除
	 //宽度搜索的方法核心就是，先从起点开始，搜索距离起点为1的所有未遍历节点，然后再去搜索距离起点为2的所有未遍历节点，以此类推
	 //所以使用两个队列来保存我们需要遍历的下一层节点，和当前正需要遍历的所有节点
	 //接纳的参数有起始单词，目标单词，所有单词的邻接表，保存搜索到的最近路径
	 //注意：当找到目标节点时，任需要将当前正需要遍历的所有节点遍历完，以免遗漏相同长度的路径
	 //建立双队列，来保存两层需要遍历的节点
		set<string> qsNow;//当前正需要遍历的所有节点
		set<string> qsNext;//下一层需要遍历的所有节点
		vector<string> temp;//暂时存当前层遍历的所有节点
		qsNow.insert(beginWord);//将开始节点压入队列
		int Found = 0;
		while (!qsNow.empty() && !wordList.empty())
		{//如果当前行不为空，则仍有需要遍历的节点
			if (Found == 1)
				//如果已经找到目标单词，不需要再进行寻找
				break;
			//cout << qsNow.front() << " " ;
			for (auto itq = qsNow.begin();itq != qsNow.end();itq++)
			{
				if (*itq == endWord)
					Found = 1;
				//对于wordList中的单词，找到距离目前队列中所有单词为1的单词，并存入下一层队列中，其中找到一个距离为1的加入层次邻接表中
				for (auto it = wordList.begin();it != wordList.end();it++)
				{
					if (GetWordsDistance((*it), *itq) == 1)
					{//找到一个距离为1的单词
						temp.push_back(*it);
						qsNext.insert(*it);
						vviAdjList[*it].insert(*itq);
					}
				}
			}
			//找到所有的下一层的单词之后，将下一层的单词全都从wordList中删除，防止进入更下层
			for (auto it = temp.begin();it != temp.end();it++)
				wordList.erase(*it);
			if (qsNext.empty())
				break;
			qsNow = qsNext;
			qsNext.clear();
			//cout << endl;
			temp.clear();
		}
		return;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		/* A
		126. Word Ladder II Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 64765
		Total Submissions: 467025
		Difficulty: Hard
		Contributor: LeetCode
		Given two words (beginWord and endWord), and a dictionary's word list,
		find all shortest transformation sequence(s) from beginWord to endWord, such that:

		Only one letter can be changed at a time
		Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
		For example,

		Given:
		beginWord = "hit"
		endWord = "cog"
		wordList = ["hot","dot","dog","lot","log","cog"]
		Return
		[
		["hit","hot","dot","dog","cog"],
		["hit","hot","lot","log","cog"]
		]

		//vector<string> vs{ "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
		//string a = "qa";
		//string b = "sq";
		//unordered_set<string> vs1{ "hot","dot","tot","hog","dog","cog", "pot","hop"};
		//vector<string>vs2{ "hot","dot","dog","lot","log","cog" };
		//string a = "hit";
		//string b = "cog";
		Note:
		Return an empty list if there is no such transformation sequence.
		All words have the same length.
		All words contain only lowercase alphabetic characters.
		You may assume no duplicates in the word list.
		You may assume beginWord and endWord are non-empty and are not the same.
		UPDATE (2017/1/20):
		The wordList parameter had been changed to a list of strings (instead of a set of strings).
		Please reload the code definition to get the latest changes.
		*/
		vector<vector<string>> vvsRes;//保存所有的路径结果
		vector<string> vsPath;//保存某一条路径
		vsPath.push_back(endWord);//保存路径起点
								  //将距离为1的两个单词进行连接，建立无向图，使用邻接表来进行存储无向图
		map<string, set<string>> vviAdjList;//存储图的层次邻接表(多叉树)，利用BFS思想将所有节点按照离起始节点的距离进行层次划分，相同距离的在同一层
		set<string>wL;
		for (int i = 0;i < wordList.size();i++)
			if (wordList[i] != beginWord)
				wL.insert(wordList[i]);
		BFSforCreateTree(vviAdjList, beginWord, endWord, wL);//利用BFS思想进行建立层次邻接表(多叉树)
		TreeHelper::printAdjList(vviAdjList);
		GetPathFromMsv(vvsRes, vviAdjList, vsPath, endWord, beginWord);
		return vvsRes;
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		/* A
		127. Word Ladder Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 118868
		Total Submissions: 616399
		Difficulty: Medium
		Contributor: LeetCode
		Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

		Only one letter can be changed at a time.
		Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
		For example,

		Given:
		beginWord = "hit"
		endWord = "cog"
		wordList = ["hot","dot","dog","lot","log","cog"]
		As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
		return its length 5.

		Note:
		Return 0 if there is no such transformation sequence.
		All words have the same length.
		All words contain only lowercase alphabetic characters.
		You may assume no duplicates in the word list.
		You may assume beginWord and endWord are non-empty and are not the same.
		UPDATE (2017/1/20):
		The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

		Subscribe to see which companies asked this question.
		*/
		//此题同T126，只不过需要找到到达目标单词的最短路径长度，同样的使用BFS生成逆向邻接表，第一次遇到目标单词则肯定是最短路径，记录层数即为所求
		set<string>wL;
		for (int i = 0;i < wordList.size();i++)
			if (wordList[i] != beginWord)
				wL.insert(wordList[i]);
		//利用宽搜方法建立层次邻接表，高层节点不会出现在下层中，所以在每个高层节点入队列并保存邻接表后，将高层节点进行删除
		//宽度搜索的方法核心就是，先从起点开始，搜索距离起点为1的所有未遍历节点，然后再去搜索距离起点为2的所有未遍历节点，以此类推
		//所以使用两个队列来保存我们需要遍历的下一层节点，和当前正需要遍历的所有节点
		//接纳的参数有起始单词，目标单词，所有单词的邻接表，保存搜索到的最近路径
		//注意：当找到目标节点时，任需要将当前正需要遍历的所有节点遍历完，以免遗漏相同长度的路径
		//建立双队列，来保存两层需要遍历的节点
		set<string> qsNow;//当前正需要遍历的所有节点
		set<string> qsNext;//下一层需要遍历的所有节点
		vector<string> temp;//暂时存当前层遍历的所有节点
		qsNow.insert(beginWord);//将开始节点压入队列
		int Found = 0;
		int count = 0;
		while (!qsNow.empty() || !wL.empty())
		{//如果当前行不为空，则仍有需要遍历的节点
		 //找完一层就+1
			if (Found == 1)
				//如果已经找到目标单词，不需要再进行寻找
				break;
			else//如果没找到，层数+1，进入下一层搜索
				count++;
			//cout << qsNow.front() << " " ;
			for (auto itq = qsNow.begin();itq != qsNow.end();itq++)
			{
				if (*itq == endWord)
					Found = 1;
				//对于wordList中的单词，找到距离目前队列中所有单词为1的单词，并存入下一层队列中，其中找到一个距离为1的加入层次邻接表中
				for (auto it = wL.begin();it != wL.end();it++)
				{
					if (GetWordsDistance((*it), *itq) == 1)
					{//找到一个距离为1的单词
						temp.push_back(*it);
						qsNext.insert(*it);
					}
				}
			}
			//找到所有的下一层的单词之后，将下一层的单词全都从wordList中删除，防止进入更下层
			for (auto it = temp.begin();it != temp.end();it++)
				wL.erase(*it);
			if (qsNext.empty())
				break;
			qsNow = qsNext;
			qsNext.clear();
			//cout << endl;
			temp.clear();
		}
		if (Found == 1)
			return count;
		else
			return 0;
	}

	void DFSforSumPath(TreeNode* root, int pathNum, int& sum)
	{
		if (root == NULL)
			return;//如果是空节点，直接返回
		pathNum = pathNum * 10 + root->val;
		if (root->left == NULL && root->right == NULL)
		{//如果当前节点为叶子节点，则将路径数字加在sum上
			sum += pathNum;
			return;
		}
		//如果不为叶子节点，则继续向下找
		DFSforSumPath(root->left, pathNum, sum);
		DFSforSumPath(root->right, pathNum, sum);
		return;
	}

	int sumNumbers(TreeNode* root) {
		/*  A
		129. Sum Root to  Leaf Numbers Add to List
		DescriptionHintsSubmissionsSolutions
		Total Accepted: 107241
		Total Submissions: 298590
		Difficulty: Medium
		Contributor: LeetCode
		Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

		An example is the root-to-leaf path 1->2->3 which represents the number 123.

		Find the total sum of all root-to-leaf numbers.

		For example,

		  1
		 / \
		2   3
		The root-to-leaf path 1->2 represents the number 12.
		The root-to-leaf path 1->3 represents the number 13.

		Return the sum = 12 + 13 = 25.

		Subscribe to see which companies asked this question.
		*/
		//利用深度搜索找到路径，在叶子节点将路径代表的数字加起来
		int ipathSum = 0;//保存路径和
		if (root == NULL)
			return 0;
		DFSforSumPath(root, 0, ipathSum);
		return ipathSum;
	}

	bool SolveXXOO(vector<vector<char>>& board, vector<vector<bool>>& vvbFlag, int x, int y)
		//对于较大的矩阵，会有栈过深，出现Run Time Error，舍弃
	{//对于输入进来的‘O’符号，基于回溯思想对其联通的‘O’符号做出判断，是否应该修改，如果应该修改，则直接进行修改
		//对于边界上的‘O’极其相连的‘O’不需要修改，直接返回false
		if ((board[x][y] == 'O') && ((x == 0) || (y == 0) || (x == board.size() - 1) || (y == board[0].size() - 1)))
			return false;
		if (board[x][y] == 'X')//对于找到‘X’，表示是正确的边界，返回true，可以进行修改
			return true;
		//对于其他情况下的‘O’，我们对其进行四种方向扩展搜索，如果四个方向都返回true，则表示当前‘O’可以进行修改，
		bool up, down, left, right;//四个方向的bool值
		//向上
		if (x > 0 && vvbFlag[x - 1][y])//如果不在第一行,且上面的元素未被探索，则进行探索
		{
			vvbFlag[x - 1][y] = false;//上面的元素已探索
			up = SolveXXOO(board, vvbFlag, x - 1, y);//向上探索
			if (up == false)//一旦出现false，表示不用修改，直接返回
				return false;
			vvbFlag[x - 1][y] = true;//重置已探索的元素、
		}
		//向下
		if (x < board.size() - 1 && vvbFlag[x + 1][y])//如果不在第一行,且上面的元素未被探索，则进行探索
		{
			vvbFlag[x + 1][y] = false;//上面的元素已探索
			down = SolveXXOO(board, vvbFlag, x + 1, y);//向上探索
			if (down == false)//一旦出现false，表示不用修改，直接返回
				return false;
			vvbFlag[x + 1][y] = true;//重置已探索的元素、
		}
		//向左
		if (y > 0 && vvbFlag[x][y - 1])//如果不在第一行,且上面的元素未被探索，则进行探索
		{
			vvbFlag[x][y - 1] = false;//上面的元素已探索
			left = SolveXXOO(board, vvbFlag, x, y - 1);//向上探索
			if (left == false)//一旦出现false，表示不用修改，直接返回
				return false;
			vvbFlag[x][y - 1] = true;//重置已探索的元素、
		}
		//向右
		if (y < board[0].size() - 1 && vvbFlag[x][y + 1])//如果不在第一行,且上面的元素未被探索，则进行探索
		{
			vvbFlag[x][y + 1] = false;//上面的元素已探索
			up = SolveXXOO(board, vvbFlag, x, y + 1);//向上探索
			if (up == false)//一旦出现false，表示不用修改，直接返回
				return false;
			vvbFlag[x][y + 1] = true;//重置已探索的元素、
		}
		//四个方向都是true，或者是已被探索的元素，则表示当前的‘O’可以修改，修改之后返回true
		board[x][y] = 'X';
		return true;
	}

	
    vector<int> preorderTraversal(TreeNode* root) {
        /*
         * 144. Binary Tree Preorder Traversal Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 174855
        Total Submissions: 395448
        Difficulty: Medium
        Contributor: LeetCode
        Given a binary tree, return the preorder traversal of its nodes' values.

        For example:
        Given binary tree {1,#,2,3},
           1
            \
             2
            /
           3
        return [1,2,3].

        Note: Recursive solution is trivial, could you do it iteratively?
                 */
        //使用迭代的方式来解决前根序遍历树，利用栈来模拟递归的过程
        stack<TreeNode*> sTl;//存储已经遍历过的根节点
        vector<int> preTr;//存储先序遍历序列
        TreeNode* p = root;//从根节点开始遍历
        while(!p || !sTl.empty())//如果当前节点不为空，或者栈中还有节点
        {
            while (p != NULL)//如果当前节点的不为空，则将当前节点进行访问，并将其压入到栈中，指向其左子节点
            {
                preTr.push_back(p->val);
                sTl.push(p);
                p = p->left;
            }
            if (!sTl.empty())//到这一步，肯定是上一步已经走到了一个左子节点为空的节点，并且之前节点已经遍历，栈顶节点就是最近的一个父节点
            {
                //将当前节点置为栈顶节点的右节点后弹出栈顶元素
                p = sTl.top()->right;
                sTl.pop();
            }
        }
        return preTr;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        /*
         * 145. Binary Tree Postorder Traversal Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 138077
        Total Submissions: 349938
        Difficulty: Hard
        Contributor: LeetCode
        Given a binary tree, return the postorder traversal of its nodes' values.

        For example:
        Given binary tree {1,#,2,3},
           1
            \
             2
            /
           3
        return [3,2,1].

        Note: Recursive solution is trivial, could you do it iteratively?

        Subscribe to see which companies asked this question.
         */

        //AC1
        //在这里使用迭代的方式来解决后序遍历,后序遍历的思想也是同前序、中序类似，使用栈来模拟递归调用的过程
        //首先将根节点压入栈，每次遍历栈顶元素，
        //若栈顶元素有左右孩子，则将左右孩子按照右、左的顺序依次入栈(保证左-右-根顺序)。
        //如果栈顶元素没有左右孩子或者前一个已经访问的元素为其孩子节点，访问之，并弹出。
//        stack<TreeNode*> stn;
//        vector<int> viRes;
//        TreeNode* pre;//保存前一个访问的节点
//        if(root == NULL)
//            return viRes;
//        stn.push(root);//将根结点压入栈中准备开始遍历
//        while(!stn.empty()) {
//            TreeNode* p = stn.top();
//            if((p->left == NULL && p->right == NULL) || ((pre != NULL) && (p->left == pre || p->right == pre))){
//                viRes.push_back(p->val);
//                pre = p;
//                stn.pop();
//            }
//            else {
//                if(p->right)stn.push(p->right);
//                if(p->left)stn.push(p->left);
//            }
//        }
//        return viRes;

        //AC2
        //使用双栈法进行后序遍历的迭代
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        vector<int> viRes;
        if(root == NULL)
            return viRes;
        st1.push(root);
        while(!st1.empty()){//将树的节点按照根节点，右子节点，左子节点的顺序压入栈st2中
            TreeNode* p = st1.top();
            st1.pop();
            st2.push(p);
            if(p->left)st1.push(p->left);
            if(p->right)st1.push(p->right);
        }
        while(!st2.empty()){//将储存好的栈st2中的元素一一弹出遍历即为后序序列
            viRes.push_back(st2.top()->val);
            st2.pop();
        }
        return viRes;
    }

    class LRUCache {
        map<int,list<pair<int,int>>::iterator> mliMap;
        list<pair<int, int>> li;//存放删去key的优先级，[0]存放最高优先级
        int MaxSize = 0;

    public:
        LRUCache(int capacity) {
            MaxSize = capacity;
        }

        int get(int key) {
            if(mliMap.find(key) == mliMap.end())
                return -1;
            else {
                li.splice(li.begin(), li,  mliMap[key]);//将当前的key放在[0]，第一优先级上
                return mliMap[key]->second;
            }
        }

        void put(int key, int value) {
            //当前LRUcache未满时，直接插入即可
            auto it = mliMap.find(key);
            if(it != mliMap.end())//如果在map中找到了key,则将value的值进行重置
            {
                it->second->second = value;
                //重置了value之后，把li中对应的pair放到队列头部，第一优先级
                li.splice(li.begin(), li, it->second);
                return;
            }
            // 如果当前的cache已满或者map中未找到所要寻找的元素
            // 我们使用list容器来记录应该删去的元素优先级,把新放入的key-value对放到list头部，同时放入map中
            li.push_front(pair<int,int>(key,value));
            mliMap[key] = li.begin();
            //如果当前的li长度超过了最大长度要求，删除末尾的元素，也就是最低优先级的元素
            if(li.size() > MaxSize){
                mliMap.erase(li.back().first);
                li.pop_back();
            }
            return;
        }
    };
}
```
