#pragma once
/*
	���ݽṹ�ڶ���
	��������������͵Ķ����ʵ��
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/*
	��������Ľ�㣺�����������ָ����
*/
typedef struct Node {
	ElementType data;//������
	struct Node* next;//ָ����:ָ����һ�����
}Node;

/*
* ����ͷ���
* ע�⣺�����ڶ��������ǣ�ϰ���ԵĻᶨ��ͷ��㣬�Ա�ͳһ������Ĳ����ɾ������
* ͷ���Ҳ���Գ�Ϊ��Ԫ��㣬���һ��������βԪ���
* 
*/
typedef struct LinkList {
	Node* next;	//ͷָ�룺���������ͷ��㣬next��ָ��ͷ��㣬û�о�ָ���һ�����
	int length;	//����ĳ��ȣ���ʼֵΪ0��
}LinkList;

/*
		��ʼ������
*/
void InitLinkList(LinkList* linkList, ElementType* dataArray, int length);

/*
		��ָ����λ��pos����Ԫ��element
*/
void InsertLinkList(LinkList* linkList, int pos, ElementType element);

/*
	��ӡ����
*/
void PrintLinkList(LinkList* linkList);

/*
	�����Ƿ�Ϊ��
*/
int IsLinkListEmpty(LinkList* linkList);

/*
	����posλ���ϵ�Ԫ��
*/
ElementType GetLinkListElement(LinkList* linkList, int pos);

/*
* ɾ��������ָ��λ��pos�Ľ��
*/
ElementType DeleteLinkListElement(LinkList * linkList,int pos);

/*
	�������
*/
void ClearLinkList(LinkList* linkList);