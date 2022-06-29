#include "LinkList.h"

/*
		初始化链表
*/
void InitLinkList(LinkList* linkList, ElementType* dataArray, int length) {
	for (int i = 0; i < length; i++) {
		InsertLinkList(linkList,i+1,dataArray[i]);
	}
}

/*
		在指定的位置pos插入元素element
*/
void InsertLinkList(LinkList* linkList, int pos, ElementType element) {

	//1、创建空结点并为数据域赋值
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;
	node->next = NULL;

	//2、找到要插入位置的结点
		//如果插入的是第一个元素
		if (pos == 1) {
			node->next = linkList->next;
			 linkList->next=node;
			linkList->length++;
			return;
		}
		//如果不是插入第一个元素，通过循环找到要插入的结点位置
		Node* currNode = linkList->next;
		for (int i = 1; currNode && i < pos - 1; i++) {
			currNode = currNode->next;
		}
		//3、将结点插入并接前面的结点
		if (currNode) {
			node->next = currNode->next;
			currNode->next = node;
			linkList->length++;
		}

}

void PrintLinkList(LinkList* linkList) {
	printf("---------链表打印:---------\n");
	Node* node = linkList->next;
	if (!node) {
		printf("链表为空\n");
		linkList->length = 0;
		return;
	}
	for (int i = 0; i < linkList->length; i++) {
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
	printf("---------end---------\n\n");
}

/*
	链表是否为空
*/
int IsLinkListEmpty(LinkList* linkList) {
	return linkList->length == 0 ? TRUE : FALSE;
}

/*
	返回pos位置上的元素
*/
ElementType GetLinkListElement(LinkList* linkList, int pos) {
	Node* node = linkList->next;
	for (int i = 1; node && i < pos - 1; i++) {
		node = node->next;
	}
	return node->data;
}

/*
* 删除并返回指定位置pos的结点
*/
ElementType DeleteLinkListElement(LinkList* linkList, int pos) {
	ElementType element;//被删除的元素
	element.id = -99;   //赋一个不可能的值，用来判断是否删除成功
	Node* node = NULL;
	//如果删除的是第一个结点
	if (pos == 1) {
		node = linkList->next;
		if (node) {
			element = node->data;
			linkList->next = node->next;
			free(node);//释放被删除结点的内存，---容易遗漏
			linkList->length--;
		}
		return element;
	}
	//如果删除的不是第一个结点，
		//1、找到要删除结点它的前缀结点
		//2、要删除结点->next赋值给前缀结点->next
		//3、释放要删除的结点内存
	Node* preNode=NULL;//前缀结点
	node = linkList->next;
	for(int i=1;node && i<pos;i++){
		preNode = node;//把当前的node记录下来
		node = node->next;
	}
	if (node) {
		element = node->data;
		preNode->next = node->next;
		free(node);
		linkList->length--;
	}
		

	return element;
}

/*
	清空链表
*/
void ClearLinkList(LinkList* linkList) {
	Node* node = linkList->next;
	Node* nextNode;
	while (node){
		nextNode = node->next;//先记录当前结点的下一个结点，以便释放当前结点的内存
		free(node);
		node = nextNode;
	}
	linkList->next = NULL;
	linkList->length = 0;
}