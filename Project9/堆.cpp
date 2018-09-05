#include <iostream>
using namespace std;
#define Max 11//�������
template <class	T>
class MinHeap
{
private: 
	T* Heap = NULL;//�����ն�
	int Length = 0;//����
	int Max = 11;//�������
public :
	MinHeap() { Heap[0] = -2000; }
	void Insert(T x ,T* H);//����
	T DeleteMin(T* H);
	
	
};


template<class T>
void MinHeap<T>::Insert(T x, T * H)
{
	int i;
	if (Length <= Max)
	{
		for (i = Length + 1; H[i / 2] > x; i /= 2)//���ڵ�����Ϊi/2
		{
			H[i] = H[i / 2];
		}
		H[i] = x;
		Length++;
	}
}

template<class T>
T MinHeap<T>::DeleteMin(T * H)
{
	int i;
	int child;
	int MinT = H[1];//��С
	int LastT = H[Length];
	Length--;
	if (Length == 0)
	{
		return H[0];//��һ��Ԫ��
	}
	else 
	{
		for (i = 1; i * 2 < ����Length; i  = child)
		{
			child = i * 2;
			if (child != Length && H[child] > H[child + 1])
				child++;
			if (H[child] < LastT)
			{
				H[i] = H[child];
			}
			else break;
		}
		H[i] = LastT;
		return MinT;
	}
}
