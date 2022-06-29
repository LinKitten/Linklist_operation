#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SequenceList.h"
#include "LinkList.h"
#include "CircularLinkList.h"
#include "DoublyLinkList.h"
#include "StaticLinkList.h"


ElementType dataArray[] = {
	{1,"数据结构"},
	{2,"c语言程序设计"},
	{3,"高等数学"},
	{4,"java程序设计"},
	{5,"ui界面设计"}
};
void TestSequenceList();
void TestLinkList();
void TestCircularLinkList();
void TestDoublyLinkList();
void TestStaticLinkList();

int main() {
	//TestSequenceList();
	//TestLinkList();
	 //TestCircularLinkList();
	//TestDoublyLinkList();
	TestStaticLinkList();
	return 0;
}

void TestSequenceList() {

	SeqList seqList;//要操作的顺序表
	ElementType* delElement;
	InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));//初始化
	printf("初始化后：>>>> \n");
	PrintfList(&seqList);

	printf("--------------------------------\n");

	delElement = DeleteElement(&seqList, 2);
	printf("删除后：>>>> \n");
	PrintfList(&seqList);
	printf("被删除的元素是：\n %d\t%s\n \n",delElement->id,delElement->name);
	free(delElement);//释放内存

}

void TestLinkList() {
	//定义链表
	LinkList linkList;
	linkList.length = 0;//容易忽略的地方
	//插入元素
	InitLinkList(&linkList, dataArray,sizeof(dataArray) / sizeof(dataArray[0]));
	PrintLinkList(&linkList);

	//在某个位置插入元素
	ElementType newElement;
	newElement.id = 11;
	newElement.name = (char*)malloc(12);
	if (newElement.name == NULL) {
		printf("为name创建动态空间失败！\n");
		return;
	}
	//给name赋值
	strcpy(newElement.name, "HTML5+CSS3");
	InsertLinkList(&linkList, 3, newElement);
	printf("插入后：>>>>>>>\n");
	PrintLinkList(&linkList);

	//删除结点
	printf("删除第4个元素后：>>>\n");
	DeleteLinkListElement(&linkList, 4);
	PrintLinkList(&linkList);

	//清空链表
	printf("清空链表*******\n");
	ClearLinkList(&linkList);
	PrintLinkList(&linkList);
	

}

void TestCircularLinkList() {
	CircularLinkList* clList = (CircularLinkList*)malloc(sizeof(CircularLinkList));//分配空间
	clList->length = 0;
	clList->next = NULL;
	InitCircularLinkList(clList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
	PrintfCircularLinkList(clList);

	////删除其中一个结点
	//ElementType delEle = DeleteCircularLinkList(clList, 3);
	//printf("删除的元素是：%d\t%s\n", delEle.id,delEle.name);
	//PrintfCircularLinkList(clList);

	//查找某个结点
	ElementType ele;
	ele.id = 4;
	ele.name = "java程序设计";
	CircularNode* node = GetCircularLinkListNode(clList,ele);
	printf("\n从\"%s\"开始遍历\n", ele.name);
	PrintfCircularLinkListByNode(clList, node);
}

void  TestDoublyLinkList() {
	DoublyLinkList* dlList = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
	dlList->length = 0;
	dlList->next = NULL;
	InitDoublyLinkList(dlList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
	PrintfDoublyLinkList(dlList);
}

void TestStaticLinkList() {
	StaticLinkList slList;//声明一个静态链表
	//对其初始化
	InitStaticLinkList(slList);
	PrintfStaticLinkList(slList);
	/*
	
			i:0     next:1  id:-1   name:(null) 数组第一个元素的游标next用来存放第一个空闲结点的下标（备用链表的下标）
			i:1     next:2  id:-1   name:(null)
			i:2     next:3  id:-1   name:(null)
			i:3     next:4  id:-1   name:(null)
			i:4     next:5  id:-1   name:(null)
			i:5     next:6  id:-1   name:(null)
			i:6     next:7  id:-1   name:(null)
			i:7     next:8  id:-1   name:(null)
			i:8     next:0  id:-1   name:(null) //将备用链表的尾结点置为空；
			i:9     next:0  id:-1   name:(null) 数组的最后一个元素游标next用来保存第一个插入元素的下标,初始时为0；

	*/
	//插入
	ElementType ele;
	ele.id = 123;
	ele.name = "软件测试";
	InsertStaticLinkList(slList, 1, ele);
	printf("插入元素后：>>>>\n");
	PrintfStaticLinkList(slList);
	/*
			插入元素后：>>>>
			i:0     next:2  id:-1   name:(null)
			i:1     next:0  id:123  name:软件测试
			i:2     next:3  id:-1   name:(null)
			i:3     next:4  id:-1   name:(null)
			i:4     next:5  id:-1   name:(null)
			i:5     next:6  id:-1   name:(null)
			i:6     next:7  id:-1   name:(null)
			i:7     next:8  id:-1   name:(null)
			i:8     next:0  id:-1   name:(null)
			i:9     next:1  id:-1   name:(null)
	*/
	ElementType ele2;
	ele2.id = 124;
	ele2.name = "数据结构";
	InsertStaticLinkList(slList, 2, ele2);
	printf("插入元素后：>>>>\n");
	PrintfStaticLinkList(slList);
	/*
			插入元素后：>>>>
			i:0     next:3  id:-1   name:(null)
			i:1     next:2  id:123  name:软件测试
			i:2     next:0  id:124  name:数据结构
			i:3     next:4  id:-1   name:(null)
			i:4     next:5  id:-1   name:(null)
			i:5     next:6  id:-1   name:(null)
			i:6     next:7  id:-1   name:(null)
			i:7     next:8  id:-1   name:(null)
			i:8     next:0  id:-1   name:(null)
			i:9     next:1  id:-1   name:(null)
	*/

	ElementType ele3;
	ele3.id = 125;
	ele3.name = "HTML+css";
	InsertStaticLinkList(slList, 3, ele3);
	printf("插入元素后：>>>>\n");
	PrintfStaticLinkList(slList);
	/*
			插入元素后：>>>>
			i:0     next:4  id:-1   name:(null)
			i:1     next:2  id:123  name:软件测试
			i:2     next:3  id:124  name:数据结构
			i:3     next:0  id:125  name:HTML+css
			i:4     next:5  id:-1   name:(null)
			i:5     next:6  id:-1   name:(null)
			i:6     next:7  id:-1   name:(null)
			i:7     next:8  id:-1   name:(null)
			i:8     next:0  id:-1   name:(null)
			i:9     next:1  id:-1   name:(null)
	*/

	//删除某个元素
	printf("删除2号元素：>\n");
	DeleteStaticLinkList(slList, 2);
	PrintfStaticLinkList(slList);

}