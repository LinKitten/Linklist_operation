#pragma once

/*
*	���ݽṹ�ڶ��� ѭ������
* ѭ������������ص�:β����ָ����ָ���һ�����
* �ŵ�:�ܹ�ͨ�������������������ṹ
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/*����ѭ������Ľ��*/
typedef struct CircularNode {
	ElementType data;//������
	struct CircularNode* next;//ָ����һ������ָ����
}CircularNode;

/*����ѭ������ṹ*/
typedef struct CircularLinkList {
	CircularNode* next;//ָ���һ������ָ��(ͷָ�룩
	int length;//ѭ������ṹ
}CircularLinkList;

/*
	��ѭ���б��ָ��λ��pos����Ԫ��element
*/
void InsertCircularLinkList(CircularLinkList * clLsit,int pos,ElementType element);

/*
* ��ʼ������
*/
void InitCircularLinkList(CircularLinkList* clList, ElementType* dataArray, int length);


/*
		ɾ��ѭ������ָ��λ��pos��Ԫ�أ�������
*/
ElementType DeleteCircularLinkList(CircularLinkList* clLsit, int pos);

/*
		��ӡ����
*/
void PrintfCircularLinkList(CircularLinkList* clList);


/*
		ͨ��������ĳ�ڵ㣬ѭ�������������е�ÿ��Ԫ�أ�
*/
void PrintfCircularLinkListByNode(CircularLinkList* clList,CircularNode * node);

/*
		����Ԫ������element���ض�Ӧ�Ľ��ָ��CircularNode*
*/
CircularNode* GetCircularLinkListNode(CircularLinkList* clList, ElementType element);