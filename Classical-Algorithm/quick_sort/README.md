# 快速排序
基本快速排序，以及三种优化的快速排序的实现（都是在patition函数上进行优化），给出代码以及实现的思路。
### 1、快速排序算法
#### 定义：快速排序是对冒泡排序的一种改进。快速排序是指通过一趟排序，令待排序的序列变为两个独立的部分，一部分的所有数据比某个值小，另一部分的所有数据比这个值大，然后对每部分的数据递归的进行此过程，从而使整体的序列达到有序的过程。
#### 一次快排过程：我们考虑下列数组
```
4 6 2 3 1 5 7 8
```
#### 我们希望能将4放到正确的位置，即
```
* * * 4 * * * *
```
#### 所以快排的最核心过程就是不断的将元素放到自己正确位置的过程，我们可以将此过程称为patition过程，这也是快排的核心过程。对于数组，设定第一个元素为标记元素，从第二个元素往后依次寻找，如果是找到的元素大于或等于标记元素，则不用进行任何操作，直接继续往下找即可，若找到的元素小于标记元素，则将此元素与小于标记元素的序列的最后一个元素的下一个元素进行调换，然后进行进行寻找，所以我们需要维护一个指针，指向小元素序列的最后一个元素的下一个位置。
```
v [**比v小**] [**比v大**] 第i个元素（待判定）
//若arr[i] >= v，则变成如下所示：
v [**比v小**] [**比v大** 第i个元素] 第i+1个元素（待判定）

//若arr[i] < v，则变成如下所示：
v [**比v小** 第i个元素] [**比v大**] 第i+1个元素（待判定）
```
#### 基本快排的代码实现
```C++
//对arr[l...r]进行patition操作
//返回一个int p,使arr[l...p-1]都小于arr[p],使arr[p+1...r]都大于arr[p]
template<typename T>
int __patition(T arr[], int l, int r)
{
	T v = arr[l];
	// arr[l+1...j]<v,arr[j+1...i]>v
	int j = l;
	for (int i = l + 1;i <= r;i++)
	{
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[j], arr[l]);
	return j;
}

//对arr[l...r]进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r)
{
	if (l >= r)
		return;
	int p = __patition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n)
{
	__quickSort(arr, 0, n - 1);
}
```

### 2、随机化快速排序算法
#### 优化原因：由于快速排序的算法是树形结构，每次进行patition操作是对数组进行分割成两部分，然后继续进行排序，如果数组本身是基本有序的话，每次挑选数组第一个元素对数组进行分割，快排就退化成冒泡算法，也即具有了O（n^2）的时间复杂度。
#### 对于此类基本有序的数组排序进行优化，在进行挑选标记元素的时候可以进行随机化挑选，每次挑选数组中不定的元素放到之前的标记元素位置，之后的操作和基本快排相似。优化过后的最坏时间复杂度依旧是O(n^2),但是退化成冒泡排序的可能性极其低。
#### 随机化快排的代码实现（其他的过程不变，在进行patition操作时候，对于标记元素的设定会有一个随机挑选的过程）
```C++
//对arr[l...r]进行patition操作
//返回一个int p,使arr[l...p-1]都小于arr[p],使arr[p+1...r]都大于arr[p]
template<typename T>
int __patition(T arr[], int l, int r)
{
  //随机进行挑选标记元素，并将其调换到数组的第一个元素，后面操作与基本快排相同
  srand(time(NULL));
  swap(arr[rand()%(r-l+1)+l],arr[l]);
  
	T v = arr[l];
	// arr[l+1...j]<v,arr[j+1...i]>v
	int j = l;
	for (int i = l + 1;i <= r;i++)
	{
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[j], arr[l]);
	return j;
}
```

### 3、双路快速排序算法
#### 优化原因：当数组中有大量的重复元素，即存在较大可能大量元素等于标记元素，这时候patition操作分割数组（<v 和>= v）将会导致分割出来的两个数组的长度极其不平衡，即头重脚轻的现象，这样快速排序的算法时间复杂度就会变得极其的高，几乎接近O（n^2）。
#### 对于此类基本有序的数组排序进行优化，在patition操作时，对于标记元素的选取不变，但是我们去挑选待定元素时候，可以从头到尾，从尾到头两个方向进行比对，这时候边界条件都包含=v的情况，使得等于标记元素的大量元素能够尽可能的平分到两个数组之中，避免了长度不平衡的现象。
#### 随机化快排的代码实现（其他的过程不变，在进行patition操作时候，对于标记元素的设定会有一个随机挑选的过程）
```C++
//对arr[l...r]进行patition操作 --- 双路快排
//返回一个int p,使arr[l...p-1]都小于等于arr[p],使arr[p+1...r]都大于等于arr[p]
template<typename T>
int __patition2(T arr[], int l, int r)
{
	//随机进行挑选标记元素，并将其调换到数组的第一个元素，后面操作与基本快排相同
	srand(time(NULL));
	swap(arr[rand() % (r - l + 1) + l], arr[l]);

	T v = arr[l];
	// arr[l+1...i)<= v,arr(j...r]>=v
	int j = r;
	int i = l + 1;
	while (true)
	{
		while (i <= r && arr[i] < v)i++;
		while (j >= l + 1 && arr[j] > v)j--;
		if (i > j)break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}
```

### 3、三路快速排序算法
#### 优化原因：当数组中有大量的重复元素，即存在较大可能大量元素等于标记元素，这时候patition操作分割数组（<v 和>= v）将会导致分割出来的两个数组的长度极其不平衡，即头重脚轻的现象，这样快速排序的算法时间复杂度就会变得极其的高，几乎接近O（n^2）。
#### 对于此类基本有序的数组排序进行优化，在patition操作时，对于标记元素的选取不变，但是我们去挑选待定元素时候，可以从头到尾，从尾到头两个方向进行比对，这时候使用三路快速排序的话，可以将数组分割成三部分，其中多出来的一部分存储等于标记元素的元素，避免了长度不平衡的现象。
#### 随机化快排的代码实现（其他的过程不变，在进行patition操作时候，对于标记元素的设定会有一个随机挑选的过程）
```C++
//对arr[l...r]进行三路快速排序
template<typename T>
void __quickSort3Ways(T arr[], int l, int r)
{
	if (l >= r)
		return;
	//patition 操作

	//随机进行挑选标记元素，并将其调换到数组的第一个元素，后面操作与基本快排相同
	srand(time(NULL));
	swap(arr[rand() % (r - l + 1) + l], arr[l]);

	T v = arr[l];

	int lt = l;//arr[l+1,lt]<v
	int gt = r + 1;//arr[gt,r]>v
	int i = l + 1;//arr[lt+1,i) == v
	while (i < gt)
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v)
		{
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else//arr[i] == v
		{
			i++;
		}
	}
	swap(arr[l], arr[lt]);

	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort(T arr[], int n)
{
	__quickSort3Ways(arr, 0, n - 1);
}

```
