#include "SqList.h"


//��ʼ��˳���(���캯��)
SqList::SqList()//����һ������Ϊ0������Ϊinitlistsize�Ŀձ�
{
	elem = new ElemType[initlistsize];//�����СΪinitlistsize�Ŀռ�
	listsize = initlistsize;//���õ�ǰ˳���Ŀռ��С
	length = 0;//���õ�ǰ˳����Ԫ������Ϊ0
}


//����˳���(��������)
SqList::~SqList()
{
	delete[]elem;//�ͷ�˳���ռ�õĴ洢�ռ�
	listsize = 0;
	length = 0;
}


//����n��Ԫ�ص�˳���
void SqList::CreateList(int n)
{
	if (n<0 || n>initlistsize)return;//n�Ƿ�
	for (int i = 0; i < n; i++)
	{
		cin >> elem[i];
		length++;
	}
}


//����Ԫ��ֵ
int SqList::LocateList(ElemType x)
{
	for (int i = 0;i < length;i++)
	{
		if (x == elem[i])
		{
			return i + 1;//�ҵ�Ԫ��x������λ��
		}
	}
	return -1;
}


//��������Ԫ��
void SqList::InsertList(int i, ElemType e)//i�ǲ���λ��,e������Ԫ��
{
	if (i<1 || i>length + 1)return;//����λ�ò�������������
	if (length >= listsize)//˳��������������¿ռ�
	{
		ElemType* elem1 = new ElemType[listsize + increment];//�����¿ռ�
		for (int j = 0;j < length;j++)
		{
			elem1[j] = elem[j];//����Ԫ��
		}
		delete[]elem;//�ͷžɿռ�
		elem = elem1;
		listsize += increment;//����˳���Ŀռ��С
	}
	for (int k = length - 1;k >= i - 1;k--)//����λ�ü�֮���Ԫ�غ���(k���±�)
	{
		elem[k + 1] = elem[k];
	}
	elem[i - 1] = e;
	length++;
}


//ɾ������Ԫ��
void SqList::DeleteList(int i, ElemType& e)//i��ɾ��λ��
{
	if (i<1 || i>length)return;
	e = elem[i - 1];
	for (int j = i;j <= length - 1;j++)//j���±�
	{
		elem[j - 1] = elem[j];//��ɾ��Ԫ��֮���Ԫ��ǰ��
	}
	length--;
}


//˳����ȡֵ������λ��i��ȡ��Ӧλ������Ԫ�ص�����--˳�������ֻ��Ƴ�Ϊ�����ȡ��
void SqList::GetElem(int i, ElemType& e)
{
	if (i<1 || i>length) return;//�ж�iֵ�Ƿ�������������޷���
	e = elem[i - 1];//i���±���i-1
}


//���˳���
void SqList::ClearList()
{
	length = 0;//�����Ա�ĳ�����Ϊ0
}


//���˳���ĳ���
int SqList::GetLength()
{
	return length;
}

//�ж�˳����Ƿ�Ϊ��
int SqList::IsEmpty()
{
	if (length == 0) return 1;
	else return 0;
}


//����˳���
void SqList::TurnList()
{
	ElemType* p = elem, * q = &elem[length - 1];//ȡ��һ��Ԫ�غ����һ��Ԫ�ص��׵�ַ
	ElemType* temp = new ElemType;
	for (;p < q;p++, q--)//��������Ԫ��
	{
		*temp = *p;
		*p = *q;
		*q = *temp;
	}
}


//�ϲ�˳���
void SqList::Mergelist(SqList LA, SqList LB, SqList& LC)
{
	LC.length = LA.length + LB.length;
	ElemType* pa = LA.elem, * pa_last = &LA.elem[LA.length - 1];//������ĵ�һ��Ԫ�غ����һ��Ԫ��
	ElemType* pb = LB.elem, * pb_last = &LB.elem[LB.length - 1];

	LC.elem = new ElemType[LC.length];//Ϊ�±����ռ�
	ElemType* pc = LC.elem;

	//��ֵ�ǵݼ��ϲ�LA��LB�е�Ԫ��
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}

	// LB�ѵ����β����LA��ʣ��Ԫ�ؼ���LC
	while (pa <= pa_last) *pc++ = *pa++;

	// LA�ѵ����β����LB��ʣ��Ԫ�ؼ���LC
	while (pb <= pb_last) *pc++ = *pb++;
}


//���˳���
void SqList::PrintList()
{
	cout << "��ǰ˳�������Ԫ��:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << elem[i] << "\t";
	}
	cout << endl;
}




