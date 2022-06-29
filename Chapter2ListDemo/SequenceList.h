/*
		���ݽṹ�ڶ���
		��������˳���
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"




/*

	��ʼ��˳�������һ���յ����Ա�
	seqList��Ҫ��ʼ����˳���
	elemArray  ��ʼ��ʱҪ��ӵ�Ԫ����������
	length ��ʼ������ӵ�Ԫ�ظ���
*/
void InitList(SeqList* seqList, ElementType* elemArray, int length);

/*

�����Ա��index�±괦������Ԫ��element
	index Ҫ������±�
	element Ҫ�����Ԫ��


*/
void InsertElement(SeqList* seqLsit, int index, ElementType element);


/*
	��ӡ˳���
*/
void PrintfList(SeqList* seqLsit);

/*
	����˳���ĳ���
*/
int GetLength(SeqList* seqList);


/*
	����˳����Ƿ�Ϊ��
*/
int IsEmpty(SeqList* seqList);

/*
	���˳���
*/
void clearList(SeqList* seqList);

/*
	ɾ��˳�����ָ���±�index��Ԫ��
	seqList Ҫ������˳���
	index Ҫɾ�����±�
	return ����ɾ���ĵ�Ԫ�أ����ʧ�ܣ�����NULL��
*/
ElementType*  DeleteElement(SeqList* seqList,int index);

/*
	����˳�����ָ���±�index��Ԫ��
	seqList Ҫ������˳���
	index Ҫ���ص��±�
	return ����ָ���±��Ԫ�أ��������ʧ�ܣ�����NULL��

*/
ElementType* GetElement(SeqList* seqList, int index);