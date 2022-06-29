#include "DoublyLinkList.h"
/*
*		数据结构第二章：双向链表
*	在单链表的基础上增加了前缀结点，一定程度上提升了查找元素的速度
*	特点：在查找元素是，可以反向查找前缀结点
*/


/*初始化双链表*/
void InitDoublyLinkList(DoublyLinkList* dlList, ElementType* dataArray, int length) {
	for (int i = 0; i < length; i++) {
		InsertDoublyLinkList(dlList, i + 1, dataArray[i]);
	}
}

/* 向双向链表中指定位置pos插入元素element*/
void InsertDoublyLinkList(DoublyLinkList* dlList, int pos, ElementType element) {
	DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));//创建一个新空结点，并给予创建内存空间；
	//对新结点进行初始化：指针域都指向为NULL
	node->data = element;
	node->next = NULL;
	node->prev = NULL;

	//如果在第一个位置插入结点
	if (pos == 1) {
		node->next = dlList->next;//将新结点的后缀指针指向后一个结点的数据域（等同于头指针指向的位置）
		dlList->next = node;//头指针指向新结点node的数据域
		node->prev = dlList->next;//前缀指针指向头结点
		dlList->length++;
		return;
	}
	//如果在其他位置插入结点
	//先利用循环找到要插入位置的前置结点currNode，然后新结点的前缀指针指向该前置结点currNode
	//利用前置结点currNode的后缀指针next  >>>>>  找到后缀结点，并将其前缀指针指向新结点node
	//新结点node的后缀指针next 指向 后置结点的数据域（也等同于前缀结点的指针CurrNode->next指向的位置）
	//接着将前缀结点后缀指针currNode->next指向新结点node；
	//最后长度加1；
	
	//找到前缀结点
	DoublyNode* currNode = dlList->next;
	for (int i = 1; currNode && i < pos - 1; i++) {
		currNode = currNode->next;
	}
	if (currNode) {
		node->prev = currNode;
		if (currNode->next) {//如果前缀结点非空（空等于没有后置结点了）
			currNode->next->prev = node;//将插入位置的后一个结点的前缀指针指向新结点
		}
		node->next = currNode->next;
		currNode->next = node;
		dlList->length++;
	}
	
}

/*
	   打印双向链表dlList
*/
void PrintfDoublyLinkList(DoublyLinkList* dlList) {
	printf("\n--------打印双向链表------\n");
	DoublyNode* node = dlList->next;
	if (!node || dlList->length == 0) {
		printf("链表为空，没有内容可以打印");
		dlList->length = 0;
		return;
	}
	for (int i = 0; i < dlList->length; i++) {
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
	printf("--------end------\n");

}