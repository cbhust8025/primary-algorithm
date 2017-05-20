//
// Created by cb on 17-5-16.
//

#ifndef LEETCODE_DESIGNHELPER_H
#define LEETCODE_DESIGNHELPER_H

#endif //LEETCODE_DESIGNHELPER_H
//存放leetcode中关于设计类的题目答案
#include "head.h"
#include "TreeHelper.h"
using namespace TreeHelper;
class LRUCache {
    /*
     * 146. LRU Cache Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 121730
        Total Submissions: 714149
        Difficulty: Hard
        Contributor: LeetCode
        Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

        get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
        put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

        Follow up:
        Could you do both operations in O(1) time complexity?

        Example:

        LRUCache* cache = new LRUCache(2  |* capacity *|);

        cache->put(1, 1);
        cache->put(2, 2);
        cout << cache->get(1) << endl;       // returns 1
        cache->put(3, 3);    // evicts key 2
        cout << cache->get(2) << endl;       // returns -1 (not found)
        cache->put(4, 4);    // evicts key 1
        cout << cache->get(1) << endl;       // returns -1 (not found)
        cout << cache->get(3) << endl;       // returns 3
        cout << cache->get(4) << endl;       // returns 4
     */
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



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
class MinStack {
    /*
     * 155. Min Stack Add to List
    DescriptionHintsSubmissionsSolutions
    Total Accepted: 124347
    Total Submissions: 448944
    Difficulty: Easy
    Contributor: LeetCode
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
    Example:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();   --> Returns -3.
    minStack.pop();
    minStack.top();      --> Returns 0.
    minStack.getMin();   --> Returns -2.
     */
    stack<int> si;//存放数据
    stack<int> siMin;//存放最小值
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        si.push(x);
        if(siMin.empty())
            siMin.push(x);
        else
            siMin.push(min(x, siMin.top()));
    }

    void pop() {
        si.pop();
        siMin.pop();
    }

    int top() {
        return si.top();
    }

    int getMin() {//要求常量时间复杂度内找到栈内最小的一个值
        return siMin.top();
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    TreeNode* pRoot;
    stack<TreeNode*> stn;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* pRoot = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {//二叉搜索树的下一个元素，是他中序遍历顺序的下一个节点
        return ((pRoot == NULL) || (stn.empty()));
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p;
        if(pRoot == NULL){
            p = stn.top();
            stn.pop();
            pRoot = p->right;
        }
        else{
            while(pRoot->left){
                stn.push(pRoot);
                pRoot = pRoot->left;
            }
            p = pRoot;
            pRoot = pRoot->right;
        }
        return p->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */