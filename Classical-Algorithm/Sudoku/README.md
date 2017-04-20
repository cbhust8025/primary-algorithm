# 数独
### 1、定义：[数独（Sudoku）](http://baike.baidu.com/item/%E6%95%B0%E7%8B%AC/74847)是一种运用纸、笔进行演算的逻辑游戏。玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，并满足每一行、每一列、每一个粗线宫内的数字均含1-9，不重复。 每一道合格的数独谜题都有且仅有唯一答案，推理方法也以此为基础，任何无解或多解的题目都是不合格的。
### 2、解决思路：对于数独问题，采用经典的回溯算法进行求解，首先考虑一个数独：![](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)  
### 有如下的解（或许不止一个，我们这里求出一个解即可）：  
![](http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)
### 所有的回溯算法问题，我们都需要从两个方面去进行分析，即追溯和回溯条件。对于数独问题，我们需要从第一个非数字的格子开始，以行列顺序为填充顺序依次往后填充未完成的数独，直至行列数都达到最后一个并且最后一个格子也进行了填充。所以对于数独问题的追溯回溯条件如下：
* 追溯：首先我们对当前的格子进行判断，如果是已经进行了填充，则直接进行追溯下一个格子---下一列或者下一行的第一列；如果当前格子并没有进行填充，先求解所有可以填充的数字，然后一一填充，每次填充完成后进行下一个格子的追溯；
* 回溯：当前格子的可填充数字集为空集，或者当前格子已经试过所有可填充的数字并且都被回溯，则判定当前路径不通，进行回溯。回溯完有以下两种情况：
>* 回溯回来后的状态是进行过修改的（将某个未填充的格子进行填充），进行下一个可填充数字的尝试，直到试完所有数字然后重置为空格子，进行回溯。
>* 回溯回来后的状态是未进行过修改的，则继续回溯。

### 3、代码实现
#### 判断数独的某个格子中的数字是否满足数独要求：
```C++
bool judgeSudoku(vector<vector<char>>& board, int row, int col)
	{//对数独board的row行col列的数字进行判断，true表示满足要求
		if (row < 0 || row > 8 || col < 0 || col > 8)
			return false;
		for (int i = 0;i < board.size();i++)
    //判断行中是否有重复数字
		{
			if (i != col && board[row][i] == board[row][col])
			{
				return false;
			}
		}
		for (int i = 0;i < board.size();i++)
		{
    //判断同一列中是否有重复的数字
			if (i != row && board[i][col] == board[row][col])
			{
				return false;
			}
		}
		int r = 3 * (row / 3);
		int c = 3 * (col / 3);
		for(int i = 0;i<3;i++)
		{
    //判断3*3方格中是否有重复的数字
			for (int j = 0;j < 3;j++)
			{
				if (r + i == row && c + j == col)
					continue;
				if (board[r + i][c + j] == board[row][col])
					return false;
			}
		}
    //经过以上的判断，都未返回false，则返回true
		return true;
	}
```

#### 统计数独中某个格子所有可能放置的数字
```C++
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
		board[row][col] = '.';//对于进入此函数判断的格子，肯定是在数独中未进行填充也即空格子，所以在完成统计之后要将其还原成空格子
		return res;
	}
```

#### 数独的完成求解过程
```C++
bool SolveSudoku(vector<vector<char>>& board, int row, int col) {
		//数独解法，初步采用回溯的算法来进行解决
		//从row,col行对后面的格子进行操作
		//回溯算法核心在二：
		//1、第一点在何时进行追溯：找到一个未赋值的格子进行赋值，若赋值满足数独定义，则进行追溯;或者当前格子已经有数字，则直接进行追溯；
		//2、第二点在于回溯前后的操作，回溯回来之后必须将追溯前的操作进行重置。若未进行操作，则直接进行回溯。
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
			vector<char> canC = CanPlaceNumber(board, i, j);//求解所有可能得数字
			if ((i != 8 || j != 8) && canC.empty())//如果当前的不是最后一行，并且所有可能得数字集为空集，则直接进行回溯
				return false;
			for (int k = 0;k < canC.size();k++)
			{//对可能填充的数字进行尝试
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
				board[i][j] = '.';//回溯后的核心操作，将追溯前的操作重置。
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
```
