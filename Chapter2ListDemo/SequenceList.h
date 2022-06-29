/*
		数据结构第二章
		用来定义顺序表
*/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"




/*

	初始化顺序表：创建一个空的线性表
	seqList：要初始化的顺序表
	elemArray  初始化时要添加的元素内容数组
	length 初始化是添加的元素个数
*/
void InitList(SeqList* seqList, ElementType* elemArray, int length);

/*

在线性表的index下标处插入新元素element
	index 要插入的下标
	element 要插入的元素


*/
void InsertElement(SeqList* seqLsit, int index, ElementType element);


/*
	打印顺序表
*/
void PrintfList(SeqList* seqLsit);

/*
	返回顺序表的长度
*/
int GetLength(SeqList* seqList);


/*
	返回顺序表是否为空
*/
int IsEmpty(SeqList* seqList);

/*
	清空顺序表
*/
void clearList(SeqList* seqList);

/*
	删除顺序表中指定下标index的元素
	seqList 要操作的顺序表
	index 要删除的下标
	return 返回删除的的元素，如果失败，返回NULL；
*/
ElementType*  DeleteElement(SeqList* seqList,int index);

/*
	查找顺序表中指定下标index的元素
	seqList 要操作的顺序表
	index 要返回的下标
	return 返回指定下标的元素，如果查找失败，返回NULL；

*/
ElementType* GetElement(SeqList* seqList, int index);