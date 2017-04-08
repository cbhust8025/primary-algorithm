#pragma once
#include<iostream>
#include<vector>
using namespace std;
#define ElemType int
#define ERROR 0
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10 //线性表存储空间的分配增量

typedef struct {
	ElemType* elem;//存储空间基址，存放第一个元素的地址
	int length; //当前长度
	int listsize;  //当前分配的存储容量（以sizeof(ElemType）为单位）
}LList;
class LinearList
{
public:
	void MakeEmpty(LList &L);
		//构造一个空的线性表。

	void DestroyList(LList &L);
		//销毁线性表L。

	ElemType Length(LList L);
		//初始条件：线性表L已存在。
		//操作结果：返回L中数据元素的个数。

	ElemType Get(LList L, int i);
		//初始条件：线性表L已存在。
		//操作结果：返回L中位置i处的元素（1<=i<=n）

	bool Prior(LList L, ElemType cur_e, ElemType &pre_e);
		//初始条件：线性表L已存在。
		//操作结果：若cur_e 是L中的数据元素，且不是第一个，则用pre_e返
			//回它的前驱，否则操作失败，pre_e无定义。

	bool Next(LList L, ElemType cur_e, ElemType &next_e);
		//初始条件：线性表L已存在。
		//操作结果：若cur_e 是L中的数据元素，且不是最后一个，则用next_e返
			//回它的后继，否则操作失败，next_e无定义。

	int Locate(LList L, ElemType x);
		//初始条件：线性表L已存在。
		//操作结果：若元素x是L中的数据元素，则返回其所在的位置，否则返回0;

	bool Insert(LList L, int i, ElemType x);
		//初始条件：线性表L已存在。
		//在表L中位置i出插入数据元素x，将原占据位置i的元素及其后面的元素都向后推一个位置。

	bool Delete(LList L, int p, ElemType &e);
		//初始条件：线性表L已存在。
		//从表L中删除位置p处的数据元素,并用e返回其值，L的长度减1。

	bool IsEmpty(LList L);
		//如果表L为空表，也即长度为0，则返回true，否则返回false。

	void Clear(LList L);
		//初始条件：线性表L已存在，
		//将L重置为空表。

	void Init(LList L);
		//初始化列表L，同MakeEmpty(L)。

	void Traverse(LList L);
		//遍历输出所有元素。

	bool Updata(LList L, int i, ElemType x);
		//修改位置i的元素值为x。

	void Sort(LList L);
		//对所有元素进行排序。
	LinearList();
	~LinearList();
};

