# Linear List -- 线性表

### 引用： http://baike.baidu.com/link?url=qhH7tM3ni8XahfYyrC1BJIrSnpYm0or6WAPYJnNjXH6H1-RCCihHNB_UwH340pExKsnx-J11pZRw73PDXseETptTdlE6StwVtk1osYVMOMMQyTlhAHDck_fwstwPoMJQ   百度百科（线性表）
# 定义
<ul>
<li>线性表示是最基本、最简单、也是最常用的一种数据结构。</li>
<li>线性表（linear list）是数据结构的一种，一个线性表是n个具有相同特性的数据元素的有限序列。数据元素是一个抽象的符号，具体含义在不同的情况下一般不同</li>
<li>稍复杂的线性表中，一个数据元素可由多个数据项（item）组成，此种情况下常把数据元素成为记录（record），含有大量记录的线性表又称文件（file）。</li>
<li>线性表中的个数n定义为线性表的长度，n=0时称为空表。在非空表中每个数据元素都有一个确定的位置，如有ai表示数据元素，则i称为数据元素$a_i在线性表中的位序。</li>
<li>线性表的相邻元素之间存在这序偶关系。如用(a1,...,aj-1,aj,aj+1,...,an)表示一个顺序表，则表中aj-1领先于aj,aj领先于aj+1，当i= 1,2,...,n-1时，ai有且仅有一个直接后继，当i= 2,3,...,n时ai有且仅有一个直接前驱。</li>
</ul>  

# 特点
<p>
    <ul>
    <li>集合中必定存在唯一的一个"第一元素"。</li>
    <li>集合中必定存在唯一的一个"最后元素"。</li>
    <li>除最后一个元素之外，均有唯一的后继。</li>
    <li>除第一个元素之外，均有唯一的前驱。</li>
</ul></p>  

# 基本操作
<p>
    <ul>
    <li>MakeEmpty(L):将表L变为空表的方法。</li>
    <li>Length(L):返回表L的长度，即表中元素个数。</li>
    <li>Get(L，i):这是一个函数，函数值为L中位置i处的元素（1≤i≤n）。</li>
    <li>Prior(L, i):取i的前驱元素。</li>
    <li>Next(L, i):取i的后继元素。</li>
    <li>Locate(L, x): 函数值为元素x在L中的位置。</li>
    <li>Insert(L, i, x): 在表L中位置i处插入元素x，将原占据位置i的元素及后面的元素都想后推一个位置。</li>
    <li>Delete(L, p): 从表L中删除位置p处的元素。</li>
    <li>IsEmpty(L):如果表L为空表（长度为0）则返回true，否贼返回false。</li>
    <li>Clear(L):清楚所有元素。</li>
    <li>Init(L):初始化线性表为空，同MakeEmpty()。</li>
    <li>Traverse(L):遍历输出所有元素。</li>
    <li>Find(L, x):查找并返回元素所在索引。</li>
    <li>Update(L, x):修改元素</li>
    <li>Sort(L):对所有元素进行排序。</li>

</ul>
</p>

# 实现
```
void MakeEmpty(LList &L);
	//构造一个空的线性表。

ElemType Length(LList L);
	//初始条件：线性表L已存在。
	//操作结果：返回L中数据元素的个数。

ElemType Get(LList L, int i);
	//初始条件：线性表L已存在。
	//操作结果：返回L中位置i处的元素（1<=i<=n）

void Prior(LList L, ElemType cur_e, ElemType &pre_e);
	//初始条件：线性表L已存在。
	//操作结果：若cur_e 是L中的数据元素，且不是第一个，则用pre_e返
		//回它的前驱，否则操作失败，pre_e无定义。

void Next(LList L, ElemType cur_e, ElemType &next_e);
	//初始条件：线性表L已存在。
	//操作结果：若cur_e 是L中的数据元素，且不是最后一个，则用next_e返			
        //回它的后继，否则操作失败，next_e无定义。
        
int Locate(LList L, ElemType x);
	//初始条件：线性表L已存在。
	//操作结果：若元素x是L中的数据元素，则返回其所在的位置，否则返回0;
    
void Insert(LList L, int i, ElemType x);
	//初始条件：线性表L已存在。
	//在表L中位置i出插入数据元素x，将原占据位置i的元素及其后面的元素都向后推一个位置。
    
void Delete(LList L, int p, ElemType &e);
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

int Find(LList L, ElemType x);
	//查找并返回元素所在索引。

void Updata(LList L, int i, ElemType x);
	//修改位置i的元素值为x。

void Sort(LList L);
	//对所有元素进行排序。
```
