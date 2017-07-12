# 冒泡、选择、插入排序

## 基本冒泡、选择、插入排序算法：

### 1、基本冒泡排序算法
> 思路：双层循环，将从第一个数开始逐渐进行冒泡（升序向后冒，降序向前冒），利用不断的交换来达到有序。时间复杂度：O(n^2)

> ![选择排序](https://github.com/cbhust8025/primary-algorithm/blob/master/Classical-Algorithm/BubbleSelectInsertSort/bs.jpg)
```C++
void BubbleSort(vector<int>& vi)
{
	// 冒泡排序
	// 双层for循环，外层遍历数列中每个位置，内层遍历当前位置后的所有数字，将其中最大/最小的提取到当前位置。
	for (int i = 0;i < vi.size();i++)
	{
		for (int j = i + 1;j < vi.size();j++)
		{
			if (vi[i] > vi[j])
				swap(vi[i], vi[j]);
		}
	}
}
```

### 2、基本选择排序算法：
>思路：双层循环，不断的从前往后推进，每次挑选出当前位置后面比当前位置上面小的最小的那一个换到当前位置来。比起冒泡算法会少一些交换次数，但是时间复杂度依然是所有数会两两比较一遍。时间复杂度：O(n^2)
> ![选择排序](https://github.com/cbhust8025/primary-algorithm/blob/master/Classical-Algorithm/BubbleSelectInsertSort/ss.jpg)
```C++
void SelectSort(vector<int>& vi)
{
	// 选择排序
	// 双层for循环， 外层for循环遍历数列中的每个位置，
	// 内层for循环遍历数列小于当前位置值的最小值，然后交换这两个值
	int flag = 0;
	for (int Index = 0; Index < vi.size(); Index++)
	{
		flag = Index;
		for (int j = Index + 1; j < vi.size(); j++)
		{
			if (vi[j] < vi[flag])
				flag = j;
		}
		if (flag != Index)
			swap(vi[Index], vi[flag]);
	}
}
```

### 3、基本插入排序算法
>思路：将第一个数视做有序序列，把后面第二个数开始的所有数依次插入到前面的有序序列中，是一种从局部有序逐渐递进到全局有序的算法。由于依然会需要进行大量的比较（最坏情况下所有数依然需要两两比较），所以时间复杂度：O(n^2)
> ![插入排序](https://github.com/cbhust8025/primary-algorithm/blob/master/Classical-Algorithm/BubbleSelectInsertSort/is.jpg)
```C++
void InsertSort(vector<int>& vi)
{
	int j = 0;
	int temp = 0;
	// 插入排序
	// 一种序列逐渐有序的过程，从第一个数开始，将第二个数之后的依次插入之前已经有序的序列并且依旧有序。
	// 在插入排序中，由于需要将后面的数插入到有序的序列中，则需要序列的长度逐次+1，则将当前需要插入的数保存，位置空出来
	// 同样两层循环，外层循环遍历需要插入的每个数(第一个数不需要插入)，内层循环将需要插入的每个数逐一和已经有序的序列进行比较
	for (int i = 1; i < vi.size() ; i++)
	{
		j = i - 1;
		// 遍历每一个需要插入的数，恰好Index是当前数遍历完了之后的有序序列长度
		// 将当前数vi[Index]插入进有序序列vi[0,...,Index - 1]
		// 如果vi[Index]比vi[Index - 1]小的话，需要进行插入
		temp = vi[i];
		while (j >= 0 && vi[j] > temp)
		{
			swap(vi[j], vi[j + 1]);
			j--;
		}
		vi[j + 1] = temp;
	}
}
```
