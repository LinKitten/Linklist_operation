#pragma once


#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/*
*	数据结构第二章：静态链表的定义和常用操作
*/

#define Max_Size_SSL 10/*定义静态链表长度*/
#define OK 1
#define ERROR 0

/*定义静态链表结构 静态链表：就是一个结构体数组*/
typedef struct {
	ElementType data;/*数据域*/
	int next;/*游标cursor；如果为0，表示无指向*/
}StaticLinkList[Max_Size_SSL];

/*
	静态链表的初始化
*/
void InitStaticLinkList(StaticLinkList slList);


/*
		静态链表的插入:向指定位置pos插入元素element
*/
int InsertStaticLinkList(StaticLinkList slList, int pos, ElementType element);

/*
* 为静态链表分配一个空间的内存，返回ERROR表示分配失败
*/
int mallocSSL(StaticLinkList slList);

/*
	打印静态链表
*/
void PrintfStaticLinkList(StaticLinkList slList);

/*
*	获得链表长度 
*/
int GetStaticLinkList(StaticLinkList slList);

/*
		静态链表的删除指定位置的元素
*/
int DeleteStaticLinkList(StaticLinkList slList, int pos);

/*
*	销毁指定位置的元素的空间
*/
void FreeStaticLinkList(StaticLinkList slList, int index);