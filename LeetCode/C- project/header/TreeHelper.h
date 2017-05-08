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
	{//�ݹ�ʵ�ֶ�����ǰ�������
		//��ǰ�ڵ�ǿգ���ֱ�ӽ��з��ʺ���ȥ�������Һ��ӽڵ�
		if (root)
			cout << root->val << " ";
		else
			return;
		preOrder(root->left);//�������ӽڵ�
		preOrder(root->right);//�����Һ��ӽڵ�
		return;
	}
	void preOrderS(TreeNode* root)
	{//�ǵݹ�ʵ�ֶ�����ǰ�������
		//���ڵ�ǰ�ڵ㣬���ʺ�ѹ��ջ�У��������ӽڵ㲻Ϊ�գ���ָ�����ӽڵ����֮ǰ������
		//�����ӽڵ�Ϊ�գ���Ӧ�÷���ջ��Ԫ�ص��Һ��ӽڵ㣨Ҳ��������ĸ��ڵ���Һ��ӣ�ͬ���Һ��ӣ�
		//�ظ�������ֱ��p == NULL ����ջΪ�ա�
		TreeNode* p = root;
		stack<TreeNode*> sTp;
		while (p || !sTp.empty())
		{//���ջ��Ϊ�գ�����p��ΪNULL,�ͽ������²���
			while (p)
			{//���p��Ϊ�գ�����֮��ѹ��ջ�У�����ָ�����ӣ�ֱ��Ϊ��Ϊֹ��Ҳ����һ��p������Ϊ��
				cout << p->val << " ";
				sTp.push(p);
				p = p->left;
			}
			if (!sTp.empty())
			{//ջ���������һ������Ϊ�յĽڵ㣬���Ҵ˽ڵ��Ѿ����й����ʲ�ѹ��ջ������ֱ�ӽ����Һ��ӽڵ�
				//��Ϊ��ǰ�ڵ㣬Ȼ�󵯳�ջ��Ԫ�ء�
				p = sTp.top()->right;
				sTp.pop();
			}
		}
	}
	void inOrder(TreeNode* root)
	{//�ݹ�ʵ�ֶ������и������
		//�ݹ�ʵ���и�������������ӽڵ�->���ڵ�->�Һ��ӽڵ�
		//����ÿ�ν���ݹ麯������ȥ�����ӣ�ֱ�����ӽڵ�Ϊ��
		if (root == NULL)
			return;
		inOrder(root->left);
		cout << root->val << " ";//����������ӷ�������֮�󣬻��ݻ�����ǰ�ڵ�������µ����ӽڵ㣬����֮��
		inOrder(root->right);
		return;
	}
	void inOrderS(TreeNode* root)
	{//�ǵݹ�ʵ�ֶ������и������
	 //���ڵ�ǰ�ڵ㣬ֱ��ѹ��ջ�У��������ӽڵ㲻Ϊ�գ���ָ�����ӽڵ����֮ǰ������
	 //�����ӽڵ�Ϊ�գ������ջ��Ԫ�أ���ʱջ��Ԫ��Ϊ����Ϊ�յĸ��ڵ㣬Ҳ���ǵ�һ���ȼ����ʣ�
		//����ǰԪ����Ϊջ��Ԫ���Һ��ӽڵ㣨Ҳ��������ĸ��ڵ���Һ��ӣ�ͬ���Һ��ӣ�
	 //�ظ�������ֱ��p == NULL ����ջΪ�ա�
		TreeNode* p = root;
		stack<TreeNode*> sTp;
		while (p || !sTp.empty())
		{//���ջ��Ϊ�գ�����p��ΪNULL,�ͽ������²���
			while (p)
			{//���p��Ϊ�գ�ֱ��ѹ��ջ�У�����ָ�����ӣ�ֱ��Ϊ��Ϊֹ��Ҳ����һ��p������Ϊ��
				sTp.push(p);
				p = p->left;
			}
			if (!sTp.empty())
			{//ջ���������һ������Ϊ�յĽڵ㣬�˽ڵ�δ�����ʾͱ�ѹ��ջ������Ҫ���з��ʺ��ٽ����Һ��ӽڵ�
			 //��Ϊ��ǰ�ڵ㣬Ȼ�󵯳�ջ��Ԫ�ء�
				cout << sTp.top()->val << " ";
				p = sTp.top()->right;
				sTp.pop();
			}
		}
	}
	void postOrder(TreeNode* root)
	{//�ݹ�ʵ�ֶ�������������
	 //�ݹ�ʵ���и�������������ӽڵ�->�Һ��ӽڵ�->���ڵ�
	 //����ÿ�ν���ݹ麯������ȥ�����ӣ�ֱ�����ӽڵ�Ϊ��
		//Ȼ��һֱ��Ѱ�Һ��ӣ�ֱ���Һ��ӽڵ�Ϊ��
		//�����Һ��Ӷ������꣬���ʵ�ǰ�ڵ㡣
		if (root == NULL)
			return;
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << " ";
		return;
	}
	void postOrderS(TreeNode* root)
	{//�ǵݹ�ʵ�ֶ�������������
		//���Ƚ����ڵ�ѹ��ջ��ÿ�α���ջ��Ԫ�أ�
		//��ջ��Ԫ�������Һ��ӣ������Һ��Ӱ����ҡ����˳��������ջ(��֤��-��-��˳��)��
		//���ջ��Ԫ��û�����Һ��ӻ���ǰһ���Ѿ����ʵ�Ԫ��Ϊ�亢�ӽڵ㣬����֮����������
		stack<TreeNode*> sTp;
		TreeNode* q;
		TreeNode* pre = NULL;
		sTp.push(root);//ѹ����ڵ�
		while (!sTp.empty())
		{//���ջ��Ϊ����һֱ������
			TreeNode* q = sTp.top();
			//���ջ��Ԫ��û�����Һ��ӽڵ����ǰһ���Ѿ����ʵ�Ԫ��Ϊ�亢�ӽڵ㣬�����֮��������
			if ((q->left == NULL && q->right == NULL) || ((pre != NULL) && (pre == q->right || pre == q->left)))
			{
				cout << q->val << " ";
				pre = q;
				sTp.pop();
			}
			else
			{//��������Һ��ӽڵ㣬������ ���˳��������ջ
				if (q->right)sTp.push(q->right);
				if (q->left)sTp.push(q->left);
			}
		}
	}
	void postOrder2S(TreeNode* root)
	{//�ǵݹ�ʵ�ֶ�������������
	 //˫ջ��
	 //���Ƚ����ڵ�ѹ��ջS1��
		//ѭ������ջS1��ջ��Ԫ�أ���ѹ��ջS2�У�ÿ�ε���ջ��Ԫ��S1��ʱ���������Һ��ӽڵ㰴������ѹ��ջS1��
		//S1Ϊ�պ����δ�ջ������S2��Ԫ�ؼ���
		stack<TreeNode*> sT1;
		stack<TreeNode*> sT2;
		TreeNode* q;
		sT1.push(root);
		while (!sT1.empty())
		{//����sT1��ջ��Ԫ��ֱ����
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
		//ǰ����ݹ�������ҵ�Ҷ�ӽڵ㣬�����С��·������
		if (root == NULL)
			return;
		else if (root->left == NULL && root->right == NULL && count < minD)
			minD = count;
		getMinLeafNodeDepth(root->left, count + 1, minD);//�������ӽڵ�
		getMinLeafNodeDepth(root->right, count + 1, minD);//�����Һ��ӽڵ�
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
		//�ǵݹ�ʵ��ǰ�����������������ջ��ʵ��
		if (root == NULL)
			return 0;
		int minD = INT_MAX;
		getMinLeafNodeDepth(root, 1, minD);
		return minD;
	}
}
