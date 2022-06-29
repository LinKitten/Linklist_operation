#pragma once
/*
	数据结构第二章
	链表抽象数据类型的定义和实现
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/*
	定义链表的结点：包括数据域和指针域
*/
typedef struct Node {
	ElementType data;//数据域
	struct Node* next;//指针域:指向下一个结点
}Node;

/*
* 定义头结点
* 注意：我们在定义链表是，习惯性的会定义头结点，以便统一链表结点的插入和删除操作
* 头结点也可以称为首元结点，最后一个结点叫做尾元结点
* 
*/
typedef struct LinkList {
	Node* next;	//头指针：如果链表有头结点，next就指向头结点，没有就指向第一个结点
	int length;	//链表的长度，初始值为0；
}LinkList;

/*
		初始化链表
*/
void InitLinkList(LinkList* linkList, ElementType* dataArray, int length);

/*
		在指定的位置pos插入元素element
*/
void InsertLinkList(LinkList* linkList, int pos, ElementType element);

/*
	打印链表
*/
void PrintLinkList(LinkList* linkList);

/*
	链表是否为空
*/
int IsLinkListEmpty(LinkList* linkList);

/*
	返回pos位置上的元素
*/
ElementType GetLinkListElement(LinkList* linkList, int pos);

/*
* 删除并返回指定位置pos的结点
*/
ElementType DeleteLinkListElement(LinkList * linkList,int pos);

/*
	清空链表
*/
void ClearLinkList(LinkList* linkList);