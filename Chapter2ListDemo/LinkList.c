#include "LinkList.h"

/*
		��ʼ������
*/
void InitLinkList(LinkList* linkList, ElementType* dataArray, int length) {
	for (int i = 0; i < length; i++) {
		InsertLinkList(linkList,i+1,dataArray[i]);
	}
}

/*
		��ָ����λ��pos����Ԫ��element
*/
void InsertLinkList(LinkList* linkList, int pos, ElementType element) {

	//1�������ս�㲢Ϊ������ֵ
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;
	node->next = NULL;

	//2���ҵ�Ҫ����λ�õĽ��
		//���������ǵ�һ��Ԫ��
		if (pos == 1) {
			node->next = linkList->next;
			 linkList->next=node;
			linkList->length++;
			return;
		}
		//������ǲ����һ��Ԫ�أ�ͨ��ѭ���ҵ�Ҫ����Ľ��λ��
		Node* currNode = linkList->next;
		for (int i = 1; currNode && i < pos - 1; i++) {
			currNode = currNode->next;
		}
		//3���������벢��ǰ��Ľ��
		if (currNode) {
			node->next = currNode->next;
			currNode->next = node;
			linkList->length++;
		}

}

void PrintLinkList(LinkList* linkList) {
	printf("---------�����ӡ:---------\n");
	Node* node = linkList->next;
	if (!node) {
		printf("����Ϊ��\n");
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
	�����Ƿ�Ϊ��
*/
int IsLinkListEmpty(LinkList* linkList) {
	return linkList->length == 0 ? TRUE : FALSE;
}

/*
	����posλ���ϵ�Ԫ��
*/
ElementType GetLinkListElement(LinkList* linkList, int pos) {
	Node* node = linkList->next;
	for (int i = 1; node && i < pos - 1; i++) {
		node = node->next;
	}
	return node->data;
}

/*
* ɾ��������ָ��λ��pos�Ľ��
*/
ElementType DeleteLinkListElement(LinkList* linkList, int pos) {
	ElementType element;//��ɾ����Ԫ��
	element.id = -99;   //��һ�������ܵ�ֵ�������ж��Ƿ�ɾ���ɹ�
	Node* node = NULL;
	//���ɾ�����ǵ�һ�����
	if (pos == 1) {
		node = linkList->next;
		if (node) {
			element = node->data;
			linkList->next = node->next;
			free(node);//�ͷű�ɾ�������ڴ棬---������©
			linkList->length--;
		}
		return element;
	}
	//���ɾ���Ĳ��ǵ�һ����㣬
		//1���ҵ�Ҫɾ���������ǰ׺���
		//2��Ҫɾ�����->next��ֵ��ǰ׺���->next
		//3���ͷ�Ҫɾ���Ľ���ڴ�
	Node* preNode=NULL;//ǰ׺���
	node = linkList->next;
	for(int i=1;node && i<pos;i++){
		preNode = node;//�ѵ�ǰ��node��¼����
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
	�������
*/
void ClearLinkList(LinkList* linkList) {
	Node* node = linkList->next;
	Node* nextNode;
	while (node){
		nextNode = node->next;//�ȼ�¼��ǰ������һ����㣬�Ա��ͷŵ�ǰ�����ڴ�
		free(node);
		node = nextNode;
	}
	linkList->next = NULL;
	linkList->length = 0;
}