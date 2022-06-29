#pragma once

/*
*	数据结构第二章 循环链表
* 循环链表的最大的特点:尾结点的指针域指向第一个结点
* 优点:能够通过任意结点遍历整个链表结构
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/*定义循环链表的结点*/
typedef struct CircularNode {
	ElementType data;//数据域
	struct CircularNode* next;//指向下一个结点的指针域
}CircularNode;

/*定义循环链表结构*/
typedef struct CircularLinkList {
	CircularNode* next;//指向第一个结点的指针(头指针）
	int length;//循环链表结构
}CircularLinkList;

/*
	向循环列表的指定位置pos插入元素element
*/
void InsertCircularLinkList(CircularLinkList * clLsit,int pos,ElementType element);

/*
* 初始化链表
*/
void InitCircularLinkList(CircularLinkList* clList, ElementType* dataArray, int length);


/*
		删除循环链表指定位置pos的元素，并返回
*/
ElementType DeleteCircularLinkList(CircularLinkList* clLsit, int pos);

/*
		打印链表
*/
void PrintfCircularLinkList(CircularLinkList* clList);


/*
		通过给定的某节点，循环遍历出链表中的每个元素；
*/
void PrintfCircularLinkListByNode(CircularLinkList* clList,CircularNode * node);

/*
		根据元素内容element返回对应的结点指针CircularNode*
*/
CircularNode* GetCircularLinkListNode(CircularLinkList* clList, ElementType element);