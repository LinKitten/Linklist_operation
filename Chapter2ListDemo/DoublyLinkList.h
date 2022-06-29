#pragma once

/*
*		���ݽṹ�ڶ��£�˫������		
*		�ڵ�����Ļ�����������ǰ׺��㣬һ���̶��������˲���Ԫ�ص��ٶ�
* �ص㣺�ڲ���Ԫ���ǣ����Է������ǰ׺���
*/
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"


/*˫������Ľ�㣺����һ������������ָ����*/
 typedef struct DoublyNode{
	 ElementType data;
	 struct DoublyNode* prev;//ָ��ǰ׺���
	 struct DoublyNode* next;//ָ���׺���
}DoublyNode;

 /*����˫����Ľṹ*/
 typedef struct DoublyLinkList {
	 int length;
	 DoublyNode* next;//˫�����ͷָ��
 }DoublyLinkList;
 

 /*��ʼ��˫����*/
 void InitDoublyLinkList(DoublyLinkList* dlList,ElementType * dataArray,int length);

 /* ��˫��������ָ��λ��pos����Ԫ��element*/
 void InsertDoublyLinkList( DoublyLinkList* dlList,int pos, ElementType element);

 /*
		��ӡ˫������
 */
 void PrintfDoublyLinkList(DoublyLinkList* dlList);