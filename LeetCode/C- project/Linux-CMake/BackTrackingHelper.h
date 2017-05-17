//
// Created by cb on 17-5-13.
//

#ifndef LEETCODE_BACKTRACKINGHELPER_H
#define LEETCODE_BACKTRACKINGHELPER_H

#endif //LEETCODE_BACKTRACKINGHELPER_H
#pragma once
//
// Created by CB on 04/05-2017
//
#include "head.h"
#include"VectorHelper.h"


namespace BackTrackingHelper
{
    using namespace VectorHelper;
    bool judgeSudoku(vector<vector<char>>& board, int row, int col)
    {
        if (row < 0 || row > 8 || col < 0 || col > 8)
            return false;
        for (int i = 0;i < board.size();i++)
        {
            if (i != col && board[row][i] == board[row][col])
            {
                return false;
            }
        }
        for (int i = 0;i < board.size();i++)
        {
            if (i != row && board[i][col] == board[row][col])
            {
                return false;
            }
        }
        int r = 3 * (row / 3);
        int c = 3 * (col / 3);
        for (int i = 0;i<3;i++)
        {
            for (int j = 0;j < 3;j++)
            {
                if (r + i == row && c + j == col)
                    continue;
                if (board[r + i][c + j] == board[row][col])
                    return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        /*   Accepted
        36. Valid Sudoku Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 113428
        Total Submissions: 325981
        Difficulty: Medium
        Contributor: LeetCode
        Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

        The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


        A partially filled sudoku which is valid.

        Note:
        A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

        input:
        [".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]
        */
        for (int i = 0;i < board.size();i++)
        {
            printVector(board[i]);
        }
        for (int i = 0;i < board.size();i++)
        {
            for (int j = 0;j < board[0].size();j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (!judgeSudoku(board, i, j))
                    return false;
            }
        }
        return true;
    }



    vector<char> CanPlaceNumber(vector<vector<char>> &board, int row, int col)
    {//搜集当前格子所能放置的所有数字，并存入vector<int> 中返回
        vector<char> res;
        char ci[9]{ '1','2','3','4','5','6','7','8','9' };
        for (int i = 0;i < 9;i++)
        {
            board[row][col] = ci[i];
            if (judgeSudoku(board, row, col))
                res.push_back(ci[i]);
        }
        board[row][col] = '.';
        return res;
    }


    bool SolveSudoku(vector<vector<char>>& board, int row, int col) {
        //数独解法，初步采用回溯的算法来进行解决
        //从row,col行对后面的格子进行操作
        //回溯算法核心在二：
        //1、第一点在何时进行追溯：找到一个未赋值的格子进行赋值，若赋值满足数独定义，则进行追溯
        //2、第二点在于回溯前后的操作，回溯回来之后必须将追溯前的操作进行重置。
        system("cls");
        for (int m = 0;m < board.size();m++)
        {
            printVector(board[m]);
        }
        //Sleep(500);
        int i = row;
        int j = col;
        if (board[i][j] != '.')
        {
            if (j < 8)
            {
                if (SolveSudoku(board, i, j + 1))//如果当前数独满足要求，则进行下一次追溯
                    return true;
            }
            else if (i < 8)
            {
                if (SolveSudoku(board, i + 1, 0))//如果当前数独满足要求，则进行下一次追溯
                    return true;
            }
            else
            {
                return true;
            }
        }
        else
        {
            vector<char> canC = CanPlaceNumber(board, i, j);
            if ((i != 8 || j != 8) && canC.empty())
                return false;
            for (int k = 0;k < canC.size();k++)
            {//尝试赋1-9 9个数字
                board[i][j] = canC[k];
                if (j < 8)
                {
                    if (SolveSudoku(board, i, j + 1))//如果当前数独满足要求，则进行下一次追溯
                        return true;
                }
                else if (i < 8)
                {
                    if (SolveSudoku(board, i + 1, 0))//如果当前数独满足要求，则进行下一次追溯
                        return true;
                }
                else
                {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        /*  Accepted
        37. Sudoku Solver Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 70812
        Total Submissions: 243243
        Difficulty: Hard
        Contributor: LeetCode
        Write a program to solve a Sudoku puzzle by filling the empty cells.

        Empty cells are indicated by the character '.'.

        You may assume that there will be only one unique solution.


        A sudoku puzzle...


        ...and its solution numbers marked in red.

        input:
        vector<vector<char>> vvc{
        { '5','3','.','.','7','.','.','.','.' },
        { '6','.','.','1','9','5','.','.','.' },
        { '.','9','8','.','.','.','.','6','.' },
        { '8','.','.','.','6','.','.','.','3' },
        { '4','.','.','8','.','3','.','.','1' },
        { '7','.','.','.','2','.','.','.','6' },
        { '.','6','.','.','.','.','2','8','.' },
        { '.','.','.','4','1','9','.','.','5' },
        { '.','.','.','.','8','.','.','7','9' }
        };
        */
        SolveSudoku(board, 0, 0);
    }

    void CombinationSum(set<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target)
    {//回溯法
        if (target == 0)
        {//如果target等于0，表示当前的path满足要求，压入res中，并进行回溯
            vector<int> temp(path);
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        if (target < 0)
        {//如果target<0,表示当前的path不满足要求，直接回溯
            return;
        }
        //target> 0 ，表示还需要追溯，所以需要从candidates第一个元素进行追溯。
        for (int i = 0;i < candidates.size();i++)
        {//对每个元素进行试探，假设当前元素可以满足要求，所以需要压入path中，然后进行追溯
            path.push_back(candidates[i]);
            CombinationSum(res, path, candidates, target - candidates[i]);
            //回溯之后，将之前已经判断过的元素弹出（也就是很重要的重置操作），进行下一次的试探。
            path.pop_back();
        }
        //全部试探完毕，返回 or 回溯
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /* Accepted
        39. Combination Sum Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 149292
        Total Submissions: 401665
        Difficulty: Medium
        Contributor: LeetCode
        Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

        The same repeated number may be chosen from C unlimited number of times.

        Note:
        All numbers (including target) will be positive integers.
        The solution set must not contain duplicate combinations.
        For example, given candidate set [2, 3, 6, 7] and target 7,
        A solution set is:
        [
        [7],
        [2, 2, 3]
        ]
        */
        //由于需要对每个数重复使用，并且每次进行的操作大部分是相同的，初步采用回溯的算法进行解决
        //回溯两要素：
        //1、何时追溯：依次对candidates中的每个元素进行试探，试探一个就行追溯
        //2、何时回溯：当进入函数之后，target<= 0时进行回溯
        //回溯核心：每次回溯完后对之前进行的操作重置。
        vector<vector<int>> res;
        vector<int> path;
        set<vector<int>> sr;
        CombinationSum(sr, path, candidates, target);
        for (auto it = sr.begin();it != sr.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }

    void CombinationSum2(set<vector<int>>& res, vector<int>& path, vector<int>::iterator start, vector<int>::iterator end, int target)
    {//回溯法
        if (target == 0)
        {//如果target等于0，表示当前的path满足要求，压入res中，并进行回溯
            vector<int> temp(path);
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        if (target < 0 || start == end)
        {//如果target<0,表示当前的path不满足要求，直接回溯
            //如果start== end，表示元素已用完，还未满足要求，则直接回溯
            return;
        }
        //target> 0 ，表示还需要追溯，所以需要从candidates第一个元素进行追溯。
        while (start != end)
        {//对candidates[start,end)每个元素进行试探，假设当前元素可以满足要求，所以需要压入path中，然后进行追溯
            path.push_back(*start);
            CombinationSum2(res, path, start + 1, end, target - *start);
            //回溯之后，将之前已经判断过的元素弹出（也就是很重要的重置操作），进行下一次的试探。
            path.pop_back();
            start++;
        }
        //全部试探完毕，返回 or 回溯
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /* Accepted
        40. Combination Sum II Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 107670
        Total Submissions: 331764
        Difficulty: Medium
        Contributor: LeetCode
        Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

        Each number in C may only be used once in the combination.

        Note:
        All numbers (including target) will be positive integers.
        The solution set must not contain duplicate combinations.
        For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
        A solution set is:
        [
        [1, 7],
        [1, 2, 5],
        [2, 6],
        [1, 1, 6]
        ]
        */
        //解法同T39,在candidates上进行修正，每次尝试过当前数字后，每次追溯时candidates长度减一。
        vector<vector<int>> res;
        vector<int> path;
        set<vector<int>> sr;
        CombinationSum2(sr, path, candidates.begin(), candidates.end(), target);
        for (auto it = sr.begin();it != sr.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }


    void CombinationSum3(set<vector<int>>& res, vector<int>& path, vector<int>::iterator start, vector<int>::iterator end, int target, int length)
    {//回溯法
        if (target == 0 && length == 0)
        {//如果target等于0并且恰好用完可用次数，表示当前的path满足要求，压入res中，并进行回溯
            vector<int> temp(path);
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        if (target < 0 || start == end || length == 0)
        {//如果target<0,表示当前的path不满足要求，直接回溯
            //如果start== end，表示元素已用完，还未满足要求，则直接回溯
            //如果length == 0，则表示可用次数已用完，还未满足要求，则直接进行回溯
            return;
        }
        //target> 0 ，表示还需要追溯，所以需要从candidates第一个元素进行追溯。
        while (start != end)
        {//对candidates[start,end)每个元素进行试探，假设当前元素可以满足要求，所以需要压入path中，然后进行追溯
            path.push_back(*start);
            CombinationSum3(res, path, start + 1, end, target - *start, length - 1);
            //回溯之后，将之前已经判断过的元素弹出（也就是很重要的重置操作），进行下一次的试探。
            path.pop_back();
            start++;
        }
        //全部试探完毕，返回 or 回溯
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        /* Accepted
        216. Combination Sum III Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 62890
        Total Submissions: 144363
        Difficulty: Medium
        Contributor: LeetCode
        Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


        Example 1:

        Input: k = 3, n = 7

        Output:

        [[1,2,4]]

        Example 2:

        Input: k = 3, n = 9

        Output:

        [[1,2,6], [1,3,5], [2,3,4]]
        Credits:
        Special thanks to @mithmatt for adding this problem and creating all test cases.

        Subscribe to see which companies asked this question.
        */
        //同理，回溯算法解之，此时尝试数组固定为[1,...,9]。回溯限定条件变为长度，每次追溯长度减1，长度为0或者大于target时停止回溯。
        vector<vector<int>> res;
        vector<int> path;
        set<vector<int>> sr;
        vector<int> candidates{ 1,2,3,4,5,6,7,8,9 };
        CombinationSum3(sr, path, candidates.begin(), candidates.end(), n, k);
        for (auto it = sr.begin();it != sr.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }

    void getAllPermution(vector<vector<int>>& res, vector<int>& nums, int begin, int end)
    {//对nums[begin, end]求其所有的排列，并将其排列结果存入res
        if (begin == end)
        {//如果两者相等，表示已经找到一种排列， 将此时的nums存入结果中，进行回溯。
            res.push_back(nums);
            return;
        }
        //如果begin<end,则从将begin对应的数和后面的数一一调换，进行追溯begin+1,end
        for (int i = begin;i <= end;i++)
            //i:[begin, end]，包含begin的原因是，需要找到当前数不变，后面所有数的全排列情况。
            //包含end的原因，是当前数要和后面的每一个数都进行调换，所以需要包含end。
        {
            swap(nums[begin], nums[i]);//调换完，进行追溯
            getAllPermution(res, nums, begin + 1, end);
            swap(nums[begin], nums[i]);//回溯完后重置操作
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        /*  Accepted
        46. Permutations Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 157526
        Total Submissions: 373953
        Difficulty: Medium
        Contributor: LeetCode
        Given a collection of distinct numbers, return all possible permutations.

        For example,
        [1,2,3] have the following permutations:
        [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
        ]
        */
        //获得所给数组的全排列，利用回溯算法求之。
        vector<vector<int>> res;
        getAllPermution(res, nums, 0, nums.size() - 1);
        return res;
    }

    void getAllUniPermution(set<vector<int>>& res, vector<int>& nums, int begin, int end)
    {//对nums[begin, end]求其所有的排列，并将其排列结果存入res
        if (begin == end)
        {//如果两者相等，表示已经找到一种排列， 将此时的nums存入结果中，进行回溯。
            res.insert(nums);
            return;
        }
        //如果begin<end,则从将begin对应的数和后面的数一一调换，进行追溯begin+1,end
        for (int i = begin;i <= end;i++)
            //i:[begin, end]，包含begin的原因是，需要找到当前数不变，后面所有数的全排列情况。
            //包含end的原因，是当前数要和后面的每一个数都进行调换，所以需要包含end。
        {
            swap(nums[begin], nums[i]);//调换完，进行追溯
            getAllUniPermution(res, nums, begin + 1, end);
            swap(nums[begin], nums[i]);//回溯完后重置操作
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*   Accepted
        47. Permutations II Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 113222
        Total Submissions: 354917
        Difficulty: Medium
        Contributor: LeetCode
        Given a collection of numbers that might contain duplicates, return all possible unique permutations.

        For example,
        [1,1,2] have the following unique permutations:
        [
        [1,1,2],
        [1,2,1],
        [2,1,1]
        ]
        */
        set<vector<int>> res;
        getAllUniPermution(res, nums, 0, nums.size() - 1);
        vector<vector<int>> r;
        for (auto it = res.begin();it != res.end();it++)
        {
            r.push_back(*it);
        }
        return r;
    }

    bool CanPlaceQueen(vector<int> qFlag, int row, int col)
    {
        //对于row行，col列能否放置皇后进行判定，如果能则返回true
        for (int i = 0;i < row;i++)//当前位置是row行，则之前肯定已经有[0,...,row-1]行放置了皇后，对于每一个皇后一一进行判定
        {
            //如果两个皇后列数相等， 则直接判定不能放置，返回false
            //如果两个皇后列数差绝对值等于行数差绝对值，则这两个皇后在同一斜线上，也判定为不能放置，返回false
            if (qFlag[i] == col || (abs(row - i) == abs(col - qFlag[i])))
                return false;
        }
        //对于已经放置的row个皇后，如果都不冲突，则当前[row,col]可以放置皇后，返回true
        return true;
    }

    void queen(vector<int> qFlag, vector<vector<int>> &output, int row, int n)
    {
        //N皇后问题，递归实现
        //row[0,...,N-1]表示从第一行到第N行，
        //qFlag为N维向量，索引对应行数[0,...,N-1]，存储的值是皇后放置的列数[0,...,N-1]。
        //output 为X*N维向量， 每一行对应一种解，X未知。
        if (row == n)
        {
            output.push_back(qFlag);//row == N ，表示已经前面N层都放置好了皇后，输出当前解，然后回溯。
        }
        else
        {
            for (int i = 0;i < n;i++)
            {
                if (CanPlaceQueen(qFlag, row, i))//如果当前位置可以放置皇后，则放置皇后并修改flag。
                {
                    qFlag[row] = i;//当前位置放置皇后，修改第row行对应的flag为放置的列数。
                    queen(qFlag, output, row + 1, n);//往下一行继续搜寻
                    //qFlag[row] = -1;//回溯法核心，在每次探索完之后，重置追溯前的修改。
                    //此种情况下，可以不用进行重置操作，主要原因是当前行修改的值对回溯之后的情况没有任何影响。
                }
            }
        }
        return;
    }
    vector<string> viTovsQueen(vector<int> vi)
    {
        vector<string> res;
        for (int i = 0;i < vi.size();i++)
        {
            string temp(vi.size(), '.');
            temp[vi[i]] = 'Q';
            res.push_back(temp);
        }
        return res;
    }
    vector<vector<string>> solveNQueens(int n) {
        /*  Accepted
        51. N-Queens Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 75862
        Total Submissions: 252807
        Difficulty: Hard
        Contributor: LeetCode
        The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



        Given an integer n, return all distinct solutions to the n-queens puzzle.

        Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

        For example,
        There exist two distinct solutions to the 4-queens puzzle:

        [
        [".Q..",  // Solution 1
        "...Q",
        "Q...",
        "..Q."],

        ["..Q.",  // Solution 2
        "Q...",
        "...Q",
        ".Q.."]
        ]
        */
        vector<int> qFlag(n, -1);
        vector<vector<int>> res;
        queen(qFlag, res, 0, n);
        vector<vector<string>> vvs;
        for (int i = 0;i < res.size();i++)
        {
            vvs.push_back(viTovsQueen(res[i]));
        }
        return vvs;
    }

    int totalNQueens(int n) {
        /* Accepted
        52. N-Queens II Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 60267
        Total Submissions: 137622
        Difficulty: Hard
        Contributor: LeetCode
        Follow up for N-Queens problem.

        Now, instead outputting board configurations, return the total number of distinct solutions.
        */
        vector<int> qFlag(n, -1);
        vector<vector<int>> res;
        queen(qFlag, res, 0, n);
        return res.size();
    }

    void Combine(vector<vector<int>>& output, vector<int>& combination, int n, int k)
    {
        //回溯法核心要点之一，如何时候结束，并进行回溯
        //此问题中，若找满k个数，则保存结果，进行回溯
        if (k == 0)//如果k == 0，则找到了k个数存入了combination中，此时将这种组合存入output中，然后回溯
        {
            output.push_back(combination);
            return;
        }
        if (n < k)//如果数都不够k个，直接回溯，返回
        {
            return;
        }
        //如果k 不等于0则需要继续压值进combination
        for (int i = n;i > 0;i--)
        {
            combination.push_back(i);//将n压进去后进行追溯
            Combine(output, combination, i - 1, k - 1);
            combination.pop_back();//压进去的n弹出，回溯法的核心之二，每次追溯完后进行重置。
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        /*   Accepted
        77. Combinations Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 110916
        Total Submissions: 286158
        Difficulty: Medium
        Contributor: LeetCode
        Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

        For example,
        If n = 4 and k = 2, a solution is:

        [
        [2,4],
        [3,4],
        [2,3],
        [1,2],
        [1,3],
        [1,4],
        ]
        */
        //回溯法解决
        vector<vector<int>> vviRes;
        vector<int> combination;
        Combine(vviRes, combination, n, k);
        return vviRes;
    }

    void SubSet(vector<vector<int>>& output, vector<int>nums, int k, vector<int> ComplementarySet)
    {
        //回溯法求解核心要点，停止追溯的时机:k == nums.size() - 1
        //由于是找到所有子集，所以每次追溯进来就保存一下当前结果
        output.push_back(ComplementarySet);
        if (k == nums.size())
        {//已经找完nums所有数字，进行回溯，并保存当前结果
            return;
        }
        for (int i = k;i < nums.size();i++)
        {
            ComplementarySet.push_back(nums[i]);
            SubSet(output, nums, i + 1, ComplementarySet);
            ComplementarySet.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        /*   Accepted
        78. Subsets Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 155020
        Total Submissions: 399926
        Difficulty: Medium
        Contributor: LeetCode
        Given a set of distinct integers, nums, return all possible subsets.

        Note: The solution set must not contain duplicate subsets.

        For example,
        If nums = [1,2,3], a solution is:

        [
        [3],
        [1],
        [2],
        [1,2,3],
        [1,3],
        [2,3],
        [1,2],
        []
        ]
        */
        //回溯法解之
        vector<vector<int>> vviRes;
        SubSet(vviRes, nums, 0, vector<int>());
        return vviRes;
    }

    bool searchWord(vector<vector<char>>& board, vector<vector<bool>>& vvbFlag, string word, int k, int x, int y)
    {//回溯法两大核心：
        //1、追溯终止条件：k == word.size()，即表示找到了字符串，返回true并回溯。
        if (k == word.size())
            return true;
        //2、四个方向，分别追溯。
        //每次进入此函数，当前坐标的字符还未比较，和word中对应k下标的字符进行比较，若相等则进行追溯。
        //向右，变动y
        if (y < board[0].size() - 1 && vvbFlag[x][y + 1] && board[x][y + 1] == word[k])
        {
            vvbFlag[x][y + 1] = false;
            if (searchWord(board, vvbFlag, word, k + 1, x, y + 1))
                return true;
            vvbFlag[x][y + 1] = true;//回溯法核心之二，重置操作
        }
        //向左
        if (y > 0 && vvbFlag[x][y - 1] && board[x][y - 1] == word[k])
        {
            vvbFlag[x][y - 1] = false;
            if (searchWord(board, vvbFlag, word, k + 1, x, y - 1))
                return true;
            vvbFlag[x][y - 1] = true;//回溯法核心之二，重置操作
        }
        //向上
        if (x > 0 && vvbFlag[x - 1][y] && board[x - 1][y] == word[k])
        {
            vvbFlag[x - 1][y] = false;
            if (searchWord(board, vvbFlag, word, k + 1, x - 1, y))
                return true;
            vvbFlag[x - 1][y] = true;//回溯法核心之二，重置操作
        }
        //向下
        if (x < board.size() - 1 && vvbFlag[x + 1][y] && board[x + 1][y] == word[k])
        {
            vvbFlag[x + 1][y] = false;
            if (searchWord(board, vvbFlag, word, k + 1, x + 1, y))
                return true;
            vvbFlag[x + 1][y] = true;//回溯法核心之二，重置操作
        }
        //四个方向都试过了，都找不到，就返回false
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        /*  Accepted
        79. Word Search Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 119477
        Total Submissions: 457660
        Difficulty: Medium
        Contributor: LeetCode
        Given a 2D board and a word, find if the word exists in the grid.

        The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are
        those horizontally or vertically neighboring. The same letter cell may not be used more than once.

        For example,
        Given board =

        [
        ['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']
        ]
        word = "ABCCED", -> returns true,
        word = "SEE", -> returns true,
        word = "ABCB", -> returns false.
        */
        //遍历矩阵，找出所有的入口字母（即等于所求字符串首字母的字母）位置，并对每个位置回溯求解是否有满足要求。
        if (board.empty() || word.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vvbFlag(m, vector<bool>(n, true));
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (board[i][j] == word[0])
                {
                    vvbFlag[i][j] = false;
                    if (searchWord(board, vvbFlag, word, 1, i, j))
                        return true;
                    vvbFlag[i][j] = true;
                }
            }
        }
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /*   NOAccpeted: Time Limit Exceeded
        212. Word Search II Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 41930
        Total Submissions: 183469
        Difficulty: Hard
        Contributor: LeetCode
        Given a 2D board and a list of words from the dictionary, find all words in the board.

        Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those
        horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

        For example,
        Given words = ["oath","pea","eat","rain"] and board =

        [
        ['o','a','a','n'],
        ['e','t','a','e'],
        ['i','h','k','r'],
        ['i','f','l','v']
        ]
        Return ["eat","oath"].
        Note:
        You may assume that all inputs are consist of lowercase letters a-z.

        click to show hint.

        You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

        If the current candidate does not exist in all words' prefix, you could stop backtracking immediately.
        What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not?
        How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.
        */
        set<string> ssRes;
        for (int i = 0;i < words.size();i++)
        {
            if (exist(board, words[i]))
                ssRes.insert(words[i]);
        }
        vector<string> vsRes;
        for (auto it = ssRes.begin();it != ssRes.end();it++)
        {
            vsRes.push_back(*it);
        }
        return vsRes;
    }
    void SubSetWithDup(set<vector<int>>& output, vector<int>nums, int k, vector<int> ComplementarySet)
    {
        //回溯法求解核心要点，停止追溯的时机:k == nums.size() - 1
        //由于是找到所有子集，所以每次追溯进来就保存一下当前结果
        output.insert(ComplementarySet);
        if (k == nums.size())
        {//已经找完nums所有数字，进行回溯，并保存当前结果
            return;
        }
        for (int i = k;i < nums.size();i++)
        {
            ComplementarySet.push_back(nums[i]);
            SubSetWithDup(output, nums, i + 1, ComplementarySet);
            ComplementarySet.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*   Accepted
        90. Subsets II Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 105065
        Total Submissions: 298901
        Difficulty: Medium
        Contributor: LeetCode
        Given a collection of integers that might contain duplicates, nums, return all possible subsets.

        Note: The solution set must not contain duplicate subsets.

        For example,
        If nums = [1,2,2], a solution is:

        [
          [2],
          [1],
          [1,2,2],
          [2,2],
          [1,2],
          []
        ]
        */
        //回溯法解之,利用set容器来剔除重复的
        set<vector<int>> sviRes;
        sort(nums.begin(), nums.end());//先将原始序列进行排序，为后面的去重做准备。
        SubSetWithDup(sviRes, nums, 0, vector<int>());
        vector<vector<int>> vviRes;
        for (auto it = sviRes.begin();it != sviRes.end();it++)
        {
            vviRes.push_back(*it);
        }
        return vviRes;
    }

    int parseInt(string s)
    {//将字符串转换成整型
        int iR = 0;
        for (int i = 0;i < s.size();i++)
        {
            iR = iR * 10 + s[i] - '0';
        }
        return iR;
    }


    void BTforIpAddresses(string s, int begin, vector<string>& vsRes, vector<string> sRes)
    {
        //回溯法核心两要素：
        //1、确定追溯时机，找到一个合适的字段，放入sRes开始追溯
        //2、结束追溯：如果sRes.size() == 4但是begin != s.size() - 1，意味着还有字符剩余，所以不正常，回溯
        //如果sRes.size() == 4并且begin == s.size() - 1，全部寻找完，结果存入vsRes
        //如果s.size() - begin > 13 - sRes.size() * 3, 直接return
        if (s.size() - begin > 13 - sRes.size() * 3)
            return;
        if (sRes.size() == 4 && begin >= s.size())
        {
            string temp = "";
            for (int i = 0;i < sRes.size() - 1;i++)
            {
                temp += sRes[i] + ".";
            }
            temp += sRes[3];
            vsRes.push_back(temp);
            return;
        }
        if (sRes.size() >= 4)
            return;
        for (int i = 1;i < 4;i++)
        {//IP每一个地址的最大长度为3，所以从begin开始的i个字符作为地址进行尝试
            string sR = s.substr(begin, i);
            int iT = parseInt(sR);
            if (iT == 0)//判断当前字符串是否符合要求
            {
                sRes.push_back(sR);//追溯
                BTforIpAddresses(s, begin + i, vsRes, sRes);
                sRes.pop_back();//回溯完后的重置操作
                break;
            }
            else if (iT < 256 && iT > 0)//判断当前字符串是否符合要求
            {
                sRes.push_back(sR);//追溯
                BTforIpAddresses(s, begin + i, vsRes, sRes);
                sRes.pop_back();//回溯完后的重置操作
            }
            else//如果超出了范围，直接返回，不用继续尝试后续
                return;
        }
        //尝试完后仍未结束，进行回溯；
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        /*  Accepted
        93. Restore IP Addresses Add to List
        DescriptionHintsSubmissionsSolutions
        Total Accepted: 80756
        Total Submissions: 303431
        Difficulty: Medium
        Contributor: LeetCode
        Given a string containing only digits, restore it by returning all possible valid IP address combinations.

        For example:
        Given "25525511135",

        return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
        */
        //回溯法解之，对于IP地址，分四段，每一段8位，共32位，8位地址大小在0-255之间
        vector<string> vsRes,sRes;
        BTforIpAddresses(s, 0, vsRes, sRes);
        //printVector(vsRes);
        return vsRes;
    }


    bool  isPalindrome(string s)
    {//判断字符串是否是回文串
        if(s.size() <= 1)
            return true;
        int begin = 0;
        int end = s.size() - 1;
        while(begin < end)
        {
            if(s[begin] == s[end])
            {
                begin++;
                end--;
            }
            else
                return false;
        }
        return true;
    }

    void partitionForpalindrome(vector<vector<string>>& vvsRes, vector<string> vsPath, string s, int begin, int end)
    {
        //对于字符串s进行partition操作，范围[begin, end)
        //当begin == end，表示当前字符串为空，则统计当前partition操作，并将结果保存后进行回溯
        //当begin < end，表示当前字符串不为空，则需进行追溯，从begin开始，依次尝试，若返现[begin,begin+i]字符串不为回文串，则进行回溯
        if(begin == end)//当前字符串为空
        {
            vvsRes.push_back(vsPath);
            return;
        }
        //从begin位置的字符开始寻找，至少找一个字符，所以i=1开始，找到所有的字符为止，所以i = end - begin最大
        for(int i = 1;i<= end - begin;i++)
        {
            string temp = s.substr(begin, i);//从s[begin]开始的i个字符长度的字符串
            if(isPalindrome(temp))//如果当前字符串是回文串，进行追溯
            {
                vsPath.push_back(temp);
                partitionForpalindrome(vvsRes, vsPath, s, begin + i, end);//起点从begin变成了begin + i，中间相差了i个字符长度，符合要求
                vsPath.pop_back();//追溯之后的重置操作
            }
            //当前字符串不是回文串，继续向后找
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        /*
         * 131. Palindrome Partitioning Add to List
            DescriptionHintsSubmissionsSolutions
            Total Accepted: 92439
            Total Submissions: 287375
            Difficulty: Medium
            Contributor: LeetCode
            Given a string s, partition s such that every substring of the partition is a palindrome.

            Return all possible palindrome partitioning of s.

            For example, given s = "aab",
            Return

            [
              ["aa","b"],
              ["a","a","b"]
            ]
         */
        //由于字符串中，至少都可以进行一次partition使得每个字符单独成为一个回文串
        //加上字符串划分之后的所有部分必须都是回文串,则从头开始一一深度优先试探即可
        //使用回溯的思想进行解决
        vector<vector<string>> vvsRes;
        vector<string> vsPath;
        partitionForpalindrome(vvsRes,vsPath,s,0,s.size());
        printMatrix(vvsRes);
        return vvsRes;
    }
}