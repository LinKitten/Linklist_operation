#pragma once

#include "CircularLinkList.h"


/*
* 初始化链表
*/
void InitCircularLinkList(CircularLinkList* clList, ElementType* dataArray, int length) {
	for (int i = 0; i < length; i++) {
		InsertCircularLinkList(clList, i + 1, dataArray[i]);
		}
}



/*
	向循环列表的指定位置pos插入元素element
*/
void InsertCircularLinkList(CircularLinkList* clList, int pos, ElementType element) {
	//创建一个空结点
	CircularNode* node = (CircularNode*)malloc(sizeof(CircularNode));
	//初始化
	node->data = element;
	node->next = NULL;

	//如果插入的是第一个元素
	if (pos == 1) {
		node->next = clList->next;
		if (!node->next) {//插入的链表长度为0；
			node->next = node;
		}
		else {//如果长度不为零，就要找到链表的最后一个结点，并改变其指针域
			CircularNode* lastNode = clList->next;
			for (int i = 1; i < clList->length; i++) {
				lastNode = lastNode->next;
			}
			lastNode->next = node;
		}
		clList->next = node;//头指针指向新结点
		clList->length++;

		return;
	}
	//如果插入的不是第一个结点
	//找到插入位置的前一个结点
	CircularNode* currNode = clList->next;
	for (int i = 1; currNode &&i < pos - 1; i++) {
		currNode = currNode->next;
	}
	if (currNode) {
		node->next = currNode->next;
		currNode->next = node;
		clList->length++;
		if (pos == clList->length) {//如果插入的位置是最后一个结点
			node->next = clList->next;

		}
	}

}

/*
		打印链表
*/
void PrintfCircularLinkList(CircularLinkList * clList) {
	printf("---------循环链表打印:---------\n");
	//判断第一个结点是否为空
	if (clList->length == 0 || !clList->next) {
		printf("链表长度空，没有内容可以打印");
		clList->length = 0;
		return;
	}
	//创建临时结点
	CircularNode * node = clList->next;
	for (int i = 0; i <clList->length; i++) {
		
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
	printf("---------end---------\n");
}

/*
		删除循环链表指定位置pos的元素，并返回
*/
ElementType DeleteCircularLinkList(CircularLinkList* clList, int pos) {
	ElementType element;//要返回的元素
	element.id = -99;
	
	//如果要删除的是第一个元素
	if (pos == 1) {
		CircularNode* node = clList->next;
			if (node) {
				element = node->data;
				//找到最后一个结点，然后改变指针域的指向
				CircularNode* lastNode = clList->next;
				for (int i = 1; i < clList->length; i++) {
					lastNode = lastNode->next;
				}
				clList->next = node->next;
				lastNode->next = clList->next;
				free(node);
				clList->length--;
				}
			return element;
			}
	//如果要删除的是其他结点
	
	CircularNode* node=clList->next;//要删除的结点
	CircularNode * preNode=node;//要删除的结点的前置结点
	//循环找到要删除的结点和前置结点】
	for (int i = 1; node && i < pos - 1; i++) {
		preNode = node;
		node = node->next;
	}
	if (node) {
		element = node->data;
		preNode->next = node->next;
		free(node);
		clList->length--;
	}
		return element;
	}


/*
		根据元素内容element返回对应的结点指针CircularNode*
*/
CircularNode* GetCircularLinkListNode(CircularLinkList* clList, ElementType element) {
	CircularNode* node = clList->next;
	if (!node) {
		return NULL;
	}
	//遍历(不使用循环变量i来遍历循环链表的方法
	do {
		if (element.id == node->data.id && strcmp(element.name,node->data.name)==0 ) {//判断是否相等
			return node;
		}
		node = node->next;

	} while (node!=clList->next);
	return NULL;

}

/*
	通过给定的某节点，循环遍历出链表中的每个元素；
*/
void PrintfCircularLinkListByNode(CircularLinkList* clList, CircularNode* node) {
	printf("\n-------通过给定的某节点，循环遍历------\n");
	if (!node || !clList->next) {
			printf("链表长度空，没有内容可以打印");
			return;
		}
	//记录初始的结点指针
	CircularNode* oriNode = node;
	do
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	} while (node!=oriNode);

	printf("\n------- 循环遍历end ------\n");
}
