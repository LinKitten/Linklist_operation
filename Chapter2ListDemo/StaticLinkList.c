#include "StaticLinkList.h"

/*
	静态链表的初始化
*/
void InitStaticLinkList(StaticLinkList slList) {
	for (int i = 0; i < Max_Size_SSL; i++) {
		slList[i].data.id = -1;
		slList[i].data.name = NULL;
		slList[i].next = i + 1;
	}
	//将最后一个结点置空
	slList[Max_Size_SSL - 1].next = 0;
	//将备用链表的尾结点置为空；
	slList[Max_Size_SSL - 2].next = 0;
}

/*
		静态链表的插入:向指定位置pos插入元素element
*/
int InsertStaticLinkList(StaticLinkList slList, int pos, ElementType element) {
	if (pos<1 || pos>GetStaticLinkList(slList)+1) {
		return ERROR;
	}
	int cursor = Max_Size_SSL-1;//拿到第一个元素的下标；
	//需要判断cursor的范围是否合法

	//1、分配内存
	int newIndex = mallocSSL(slList);
	//赋值
	if (newIndex) {
		slList[newIndex].data = element;
		//找到newIndex的前缀结点
		for (int i = 1; i <= pos - 1; i++) {
			cursor = slList[cursor].next;
		}
		slList[newIndex].next = slList[cursor].next;
		slList[cursor].next = newIndex;
		return OK;
	}
	return ERROR;
}

/*
* 为静态链表分配一个空间的内存，返回ERROR表示分配失败
*/
int mallocSSL(StaticLinkList slList) {
	//1、拿到第一个备用链表（空闲结点）的下标；
	int cursor = slList[0].next;
	if (cursor) {
		slList[0].next = slList[cursor].next;
	}
	return cursor;
}

/*
	打印静态链表
*/
void PrintfStaticLinkList(StaticLinkList slList) {
	for (int i = 0; i < Max_Size_SSL; i++) {
		printf("i:%d\tnext:%d\tid:%d\tname:%s\n", i, slList[i].next,slList[i].data.id,slList[i].data.name);
	}
}

/*
*	获得静态链表长度
*/
int GetStaticLinkList(StaticLinkList slList) {
	int count = 0;//进行计数
	int cursor = slList[Max_Size_SSL - 1].next;//找到第一个元素的下标；
	while (cursor) {
		cursor = slList[cursor].next;//等同于p=p.next;
		count++;
	}
	return count;
}

/*
		静态链表的删除指定位置的元素
*/
int DeleteStaticLinkList(StaticLinkList slList, int pos) {
	//需要销毁空间
	if (pos<1 || pos>GetStaticLinkList(slList)) {
		return ERROR;
	}
	int cursor = Max_Size_SSL - 1;
	//通过循环找到要删除元素的前缀结点
	for (int i = 1; i <= pos - 1; i++) {
		cursor = slList[cursor].next;
	}
	int delIndex = slList[cursor].next;
	slList[cursor].next = slList[delIndex].next;
	//释放空间
	FreeStaticLinkList(slList, delIndex);
	return OK;
}

/*
*	销毁指定位置的元素的空间
*/
void FreeStaticLinkList(StaticLinkList slList, int index) {
	slList[index].next = slList[0].next;//将下标为index的空闲空闲结点回收到备用链表
	slList[0].next = index;//0号元素的next结点指向备用链表的第一个结点，表示index空闲结点
}