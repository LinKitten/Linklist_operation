#pragma once

/*
*		数据结构第二章：双向链表		
*		在单链表的基础上增加了前缀结点，一定程度上提升了查找元素的速度
* 特点：在查找元素是，可以反向查找前缀结点
*/
#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"


/*双向链表的结点：包含一个数据域，两个指针域*/
 typedef struct DoublyNode{
	 ElementType data;
	 struct DoublyNode* prev;//指向前缀结点
	 struct DoublyNode* next;//指向后缀结点
}DoublyNode;

 /*定义双链表的结构*/
 typedef struct DoublyLinkList {
	 int length;
	 DoublyNode* next;//双链表的头指针
 }DoublyLinkList;
 

 /*初始化双链表*/
 void InitDoublyLinkList(DoublyLinkList* dlList,ElementType * dataArray,int length);

 /* 向双向链表中指定位置pos插入元素element*/
 void InsertDoublyLinkList( DoublyLinkList* dlList,int pos, ElementType element);

 /*
		打印双向链表
 */
 void PrintfDoublyLinkList(DoublyLinkList* dlList);