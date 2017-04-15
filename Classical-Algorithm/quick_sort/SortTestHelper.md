```
#pragma once
//
// Created by CB on 04/15-2007
//

//使用时，在代码中include"SortTestHelper.h"即可，然后对于其中的每个函数进行SortTestHelper::调用即可。
#include<iostream>
#include<cassert>
#include<ctime>
#include<string>
using namespace std;

namespace SortTestHelper
{
	//生成n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0;i < n;i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	//打印数组，长度为n
	template <typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0;i < n;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	
	//判断长度为n的数组是否是有序数组（从小到大）
	template <typename T>
	bool IsSorted(T arr[], int n)
	{
		for (int i = 0;i < n - 1;i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	//测试算法的性能，参数（算法的名字，指向算法入口函数的函数指针，需要进行排序的数组，数组长度）
	template <typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(IsSorted(arr, n));
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		return;
	}

}
```
