#pragma once
#include<iostream>
#include<vector>
using namespace std;
#define ElemType int
#define ERROR 0
#define LIST_INIT_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 //���Ա�洢�ռ�ķ�������

typedef struct {
	ElemType* elem;//�洢�ռ��ַ����ŵ�һ��Ԫ�صĵ�ַ
	int length; //��ǰ����
	int listsize;  //��ǰ����Ĵ洢��������sizeof(ElemType��Ϊ��λ��
}LList;
class LinearList
{
public:
	void MakeEmpty(LList &L);
		//����һ���յ����Ա�

	void DestroyList(LList &L);
		//�������Ա�L��

	ElemType Length(LList L);
		//��ʼ���������Ա�L�Ѵ��ڡ�
		//�������������L������Ԫ�صĸ�����

	ElemType Get(LList L, int i);
		//��ʼ���������Ա�L�Ѵ��ڡ�
		//�������������L��λ��i����Ԫ�أ�1<=i<=n��

	bool Prior(LList L, ElemType cur_e, ElemType &pre_e);
		//��ʼ���������Ա�L�Ѵ��ڡ�
		//�����������cur_e ��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��
			//������ǰ�����������ʧ�ܣ�pre_e�޶��塣

	bool Next(LList L, ElemType cur_e, ElemType &next_e);
		//��ʼ���������Ա�L�Ѵ��ڡ�
		//�����������cur_e ��L�е�����Ԫ�أ��Ҳ������һ��������next_e��
			//�����ĺ�̣��������ʧ�ܣ�next_e�޶��塣

	int Locate(LList L, ElemType x);
		//��ʼ���������Ա�L�Ѵ��ڡ�
		//�����������Ԫ��x��L�е�����Ԫ�أ��򷵻������ڵ�λ�ã����򷵻�0;

	bool Insert(LList L, int i, ElemType x);
		//��ʼ���������Ա�L�Ѵ��ڡ�
		//�ڱ�L��λ��i����������Ԫ��x����ԭռ��λ��i��Ԫ�ؼ�������Ԫ�ض������һ��λ�á�

	bool Delete(LList L, int p, ElemType &e);
		//��ʼ���������Ա�L�Ѵ��ڡ�
		//�ӱ�L��ɾ��λ��p��������Ԫ��,����e������ֵ��L�ĳ��ȼ�1��

	bool IsEmpty(LList L);
		//�����LΪ�ձ�Ҳ������Ϊ0���򷵻�true�����򷵻�false��

	void Clear(LList L);
		//��ʼ���������Ա�L�Ѵ��ڣ�
		//��L����Ϊ�ձ�

	void Init(LList L);
		//��ʼ���б�L��ͬMakeEmpty(L)��

	void Traverse(LList L);
		//�����������Ԫ�ء�

	bool Updata(LList L, int i, ElemType x);
		//�޸�λ��i��Ԫ��ֵΪx��

	void Sort(LList L);
		//������Ԫ�ؽ�������
	LinearList();
	~LinearList();
};

