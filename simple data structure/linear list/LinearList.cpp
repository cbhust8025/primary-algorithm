#include "LinearList.h"



LinearList::LinearList()
{
}


LinearList::~LinearList()
{
}
void LinearList::MakeEmpty(LList &L)
{//����һ���յ����Ա�
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); //�洢����ʧ��  
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

void DestroyList(LList &L)
{//�������Ա�L��
	free(&L);
}

ElemType LinearList::Length(LList L)
{//��ʼ���������Ա�L�Ѵ��ڡ�
//�������������L������Ԫ�صĸ�����
	return L.length;
}


ElemType LinearList::Get(LList L, int i)
{//��ʼ���������Ա�L�Ѵ��ڡ�
//�������������L��λ��i����Ԫ�أ�1<=i<=n��
	if (i< 1 || i> L.length)
		return ERROR;
	return L.elem[i - 1];
}


bool LinearList::Prior(LList L, ElemType cur_e, ElemType &pre_e)
{//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e ��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��
//������ǰ�����������ʧ�ܣ�pre_e�޶��塣
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
{//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e ��L�е�����Ԫ�أ��Ҳ������һ��������next_e��
//�����ĺ�̣��������ʧ�ܣ�next_e�޶��塣
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
{//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������Ԫ��x��L�е�����Ԫ�أ��򷵻������ڵ�λ�ã����򷵻�0;
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
{//��ʼ���������Ա�L�Ѵ��ڡ�
//�ڱ�L��λ��i����������Ԫ��x����ԭռ��λ��i��Ԫ�ؼ�������Ԫ�ض������һ��λ�á�

	if (i < 1 || i>L.length + 1) return false;   //iֵ���Ϸ�  
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType * q = &(L.elem[i - 1]);  //qΪ����λ��  
	ElemType * p;
	for (p = &(L.elem[L.length - 1]);p >= q;--p)
		*(p + 1) = *p;    //����  

	*q = x;
	L.length += 1;
	return true;

}

bool LinearList::Delete(LList L, int p, ElemType &e)
{//��ʼ���������Ա�L�Ѵ��ڡ�
//�ӱ�L��ɾ��λ��p��������Ԫ��,����e������ֵ��L�ĳ��ȼ�1��
	if (p<1 || p>L.length) return false;
	ElemType* t = &(L.elem[p-1]);
	e = *t;
	ElemType* q = L.elem + L.length - 1;
	for (++t;t <= q;++t) *(t - 1) = *t;
	L.length -= 1;
	return true;
}


bool LinearList::IsEmpty(LList L)
{//�����LΪ�ձ�Ҳ������Ϊ0���򷵻�true�����򷵻�false��
	if (L.length == 0)
		return true;
	return false;
}


void LinearList::Clear(LList L)
{//��ʼ���������Ա�L�Ѵ��ڣ�
//��L����Ϊ�ձ�
	L.length = 0;
}

void LinearList::Init(LList L)
{//��ʼ���б�L��ͬMakeEmpty(L)��
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); //�洢����ʧ��  
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}


void LinearList::Traverse(LList L)
{//�����������Ԫ�ء�
	for (int i = 0;i < L.length;i++)
	{
		if (i != L.length)
			cout << L.elem[i] << "->";
		else
			cout << L.elem[i] << endl;
	}
}



bool LinearList::Updata(LList L, int i, ElemType x)
{//�޸�λ��i��Ԫ��ֵΪx��
	if (i<1 || i>L.length) return false;
	L.elem[i - 1] = x;
	return true;
}


void LinearList::Sort(LList L)
{//������Ԫ�ؽ�������
	//�����㷨���ᵥ���г����˴�ʹ����򵥵�ð������
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
