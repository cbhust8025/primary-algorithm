```C++
//
// Created by cb on 17-5-13.
//

#ifndef LEETCODE_GRAPHHELPER_H
#define LEETCODE_GRAPHHELPER_H

#endif //LEETCODE_GRAPHHELPER_H

#include "head.h"
using namespace std;
namespace GraphHelper
{
    //Definition for undirected graph.
        struct UndirectedGraphNode {
            int label;
            vector<UndirectedGraphNode *> neighbors;
            UndirectedGraphNode(int x) : label(x) {};
        };


    UndirectedGraphNode *SetFind(set<UndirectedGraphNode*> sUGN, UndirectedGraphNode* p)
    {
        UndirectedGraphNode* q = NULL;
        for(auto it = sUGN.begin();it!= sUGN.end();it++)
        {
            if((*it)->label == p->label)
            {
                return *it;
            }
        }
        return NULL;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        /*
         * 133. Clone Graph Add to List
            DescriptionHintsSubmissionsSolutions
            Total Accepted: 106515
            Total Submissions: 424790
            Difficulty: Medium
            Contributor: LeetCode
            Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


            OJ's undirected graph serialization:
            Nodes are labeled uniquely.

            We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
            As an example, consider the serialized graph {0,1,2#1,2#2,2}.

            The graph has a total of three nodes, and therefore contains three parts as separated by #.

            First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
            Second node is labeled as 1. Connect node 1 to node 2.
            Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
            Visually, the graph looks like the following:

               1
              / \
             /   \
            0 --- 2
                 / \
                 \_/
         */
        //由于是无向图，考虑采用BFS算法对其进行遍历，对于遍历到的每个连接关系进行clone，其中利用set-UHNode收集已经遍历过的节点
        //BFS算法，利用两个队列实现，层层递进，对于每个节点只有一次出队入队操作，每次出队后，其所有的neiber关系都将进行复制，但是入队需通过set-UHNode进行判断
        if (node == NULL)
            return NULL;//如果是一个空图，则返回空图
        set<UndirectedGraphNode *> qUGNow;//队列1，当前遍历队列
        set<UndirectedGraphNode *> qUGNext;//队列2，下一层遍历队列
        set<UndirectedGraphNode *> sUGN;//set-UHNode，已经遍历过的节点集合
        map<UndirectedGraphNode *, UndirectedGraphNode*> mapUGN;//存放旧图节点到新图节点的映射
        qUGNow.insert(node);//将图的起始节点压入队列
        sUGN.insert(node);
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);//创建新图的起始节点
        mapUGN[node] = newNode;
        while (true) {
            for(auto itS = qUGNow.begin();itS!= qUGNow.end();itS++)
            {//如果当前遍历队列不为空，则进行下一层的BFS遍历
                UndirectedGraphNode* p = *itS;//队首元素
                UndirectedGraphNode* q = mapUGN[*itS];//压入队列中的元素一定是在map中的元素，所以直接调用即可
                vector<UndirectedGraphNode*> vUGN = p->neighbors;//当前遍历元素的邻居节点
                for(auto it = vUGN.begin();it != vUGN.end();it++)
                {
                    UndirectedGraphNode* newq;
                    if(mapUGN.find(*it) == mapUGN.end())//新图中没有找到这个节点
                    {
                        newq = new UndirectedGraphNode((*it)->label);
                        mapUGN[*it] = newq;
                    } else
                    {
                        newq = mapUGN[*it];
                    }
                    q->neighbors.push_back(newq);//建立新图中的邻居关系
                    if(sUGN.find(*it) == sUGN.end())
                    {
                        qUGNext.insert(*it);//如果在已经遍历节点集合中未找到当前元素的邻居节点，则压入下一层遍历集合中
                    }
                }

            }
            if(qUGNext.empty())//如果下一层队列为空，则每个节点都进行了遍历，直接break;
                break;
            qUGNow = qUGNext;//将非空的下一层队列赋值给当前层队列
            qUGNext.clear();//清空下一层队列
        }
        return newNode;
    }
}

```
