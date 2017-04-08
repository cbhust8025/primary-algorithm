#include "LinearList.h"



LinearList::LinearList()
{
}


LinearList::~LinearList()
{
}
void LinearList::MakeEmpty(LList &L)
{//构造一个空的线性表。
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); //存储分配失败  
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

void DestroyList(LList &L)
{//销毁线性表L。
	free(&L);
}

ElemType LinearList::Length(LList L)
{//初始条件：线性表L已存在。
//操作结果：返回L中数据元素的个数。
	return L.length;
}


ElemType LinearList::Get(LList L, int i)
{//初始条件：线性表L已存在。
//操作结果：返回L中位置i处的元素（1<=i<=n）
	if (i< 1 || i> L.length)
		return ERROR;
	return L.elem[i - 1];
}


bool LinearList::Prior(LList L, ElemType cur_e, ElemType &pre_e)
{//初始条件：线性表L已存在。
//操作结果：若cur_e 是L中的数据元素，且不是第一个，则用pre_e返
//回它的前驱，否则操作失败，pre_e无定义。
	int i = 1;
	while (i <= L.length && L.elem[i - 1] != cur_e)
	{
		i++;
	}
	if (i<2 || i>L.length)
		return false;
	pre_e = L.elem[i - 2];
	return true;
}


bool LinearList::Next(LList L, ElemType cur_e, ElemType &next_e)
{//初始条件：线性表L已存在。
//操作结果：若cur_e 是L中的数据元素，且不是最后一个，则用next_e返
//回它的后继，否则操作失败，next_e无定义。
	int i = 1;
	while (i <= L.length && L.elem[i - 1] != cur_e)
	{
		i++;
	}
	if (i<2 || i>L.length)
		return false;
	next_e = L.elem[i];
	return true;
}


int LinearList::Locate(LList L, ElemType x)
{//初始条件：线性表L已存在。
//操作结果：若元素x是L中的数据元素，则返回其所在的位置，否则返回0;
	int i = 1;
	while (i <= L.length && L.elem[i - 1] != x)
	{
		i++;
	}
	if (i<=L.length)
		return i;
	return ERROR;
}


bool LinearList::Insert(LList L, int i, ElemType x)
{//初始条件：线性表L已存在。
//在表L中位置i出插入数据元素x，将原占据位置i的元素及其后面的元素都向后推一个位置。

	if (i < 1 || i>L.length + 1) return false;   //i值不合法  
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType * q = &(L.elem[i - 1]);  //q为插入位置  
	ElemType * p;
	for (p = &(L.elem[L.length - 1]);p >= q;--p)
		*(p + 1) = *p;    //右移  

	*q = x;
	L.length += 1;
	return true;

}

bool LinearList::Delete(LList L, int p, ElemType &e)
{//初始条件：线性表L已存在。
//从表L中删除位置p处的数据元素,并用e返回其值，L的长度减1。
	if (p<1 || p>L.length) return false;
	ElemType* t = &(L.elem[p-1]);
	e = *t;
	ElemType* q = L.elem + L.length - 1;
	for (++t;t <= q;++t) *(t - 1) = *t;
	L.length -= 1;
	return true;
}


bool LinearList::IsEmpty(LList L)
{//如果表L为空表，也即长度为0，则返回true，否则返回false。
	if (L.length == 0)
		return true;
	return false;
}


void LinearList::Clear(LList L)
{//初始条件：线性表L已存在，
//将L重置为空表。
	L.length = 0;
}

void LinearList::Init(LList L)
{//初始化列表L，同MakeEmpty(L)。
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); //存储分配失败  
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}


void LinearList::Traverse(LList L)
{//遍历输出所有元素。
	for (int i = 0;i < L.length;i++)
	{
		if (i != L.length)
			cout << L.elem[i] << "->";
		else
			cout << L.elem[i] << endl;
	}
}



bool LinearList::Updata(LList L, int i, ElemType x)
{//修改位置i的元素值为x。
	if (i<1 || i>L.length) return false;
	L.elem[i - 1] = x;
	return true;
}


void LinearList::Sort(LList L)
{//对所有元素进行排序。
	//排序算法将会单独列出，此处使用最简单的冒泡排序
	if (L.length <= 1)
		return;
	for (int i = 0;i < L.length;i++)
	{
		for (int j = i;j < L.length;j++)
		{
			if (L.elem[i] > L.elem[j])
			{
				ElemType temp = L.elem[i];
				L.elem[i] = L.elem[j];
				L.elem[j] = temp;
			}
		}
	}
}
