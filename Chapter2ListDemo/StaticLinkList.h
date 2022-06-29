#pragma once


#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/*
*	���ݽṹ�ڶ��£���̬����Ķ���ͳ��ò���
*/

#define Max_Size_SSL 10/*���徲̬������*/
#define OK 1
#define ERROR 0

/*���徲̬����ṹ ��̬��������һ���ṹ������*/
typedef struct {
	ElementType data;/*������*/
	int next;/*�α�cursor�����Ϊ0����ʾ��ָ��*/
}StaticLinkList[Max_Size_SSL];

/*
	��̬����ĳ�ʼ��
*/
void InitStaticLinkList(StaticLinkList slList);


/*
		��̬����Ĳ���:��ָ��λ��pos����Ԫ��element
*/
int InsertStaticLinkList(StaticLinkList slList, int pos, ElementType element);

/*
* Ϊ��̬�������һ���ռ���ڴ棬����ERROR��ʾ����ʧ��
*/
int mallocSSL(StaticLinkList slList);

/*
	��ӡ��̬����
*/
void PrintfStaticLinkList(StaticLinkList slList);

/*
*	��������� 
*/
int GetStaticLinkList(StaticLinkList slList);

/*
		��̬�����ɾ��ָ��λ�õ�Ԫ��
*/
int DeleteStaticLinkList(StaticLinkList slList, int pos);

/*
*	����ָ��λ�õ�Ԫ�صĿռ�
*/
void FreeStaticLinkList(StaticLinkList slList, int index);