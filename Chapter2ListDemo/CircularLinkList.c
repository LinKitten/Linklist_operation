#pragma once

#include "CircularLinkList.h"


/*
* ��ʼ������
*/
void InitCircularLinkList(CircularLinkList* clList, ElementType* dataArray, int length) {
	for (int i = 0; i < length; i++) {
		InsertCircularLinkList(clList, i + 1, dataArray[i]);
		}
}



/*
	��ѭ���б��ָ��λ��pos����Ԫ��element
*/
void InsertCircularLinkList(CircularLinkList* clList, int pos, ElementType element) {
	//����һ���ս��
	CircularNode* node = (CircularNode*)malloc(sizeof(CircularNode));
	//��ʼ��
	node->data = element;
	node->next = NULL;

	//���������ǵ�һ��Ԫ��
	if (pos == 1) {
		node->next = clList->next;
		if (!node->next) {//�����������Ϊ0��
			node->next = node;
		}
		else {//������Ȳ�Ϊ�㣬��Ҫ�ҵ���������һ����㣬���ı���ָ����
			CircularNode* lastNode = clList->next;
			for (int i = 1; i < clList->length; i++) {
				lastNode = lastNode->next;
			}
			lastNode->next = node;
		}
		clList->next = node;//ͷָ��ָ���½��
		clList->length++;

		return;
	}
	//�������Ĳ��ǵ�һ�����
	//�ҵ�����λ�õ�ǰһ�����
	CircularNode* currNode = clList->next;
	for (int i = 1; currNode &&i < pos - 1; i++) {
		currNode = currNode->next;
	}
	if (currNode) {
		node->next = currNode->next;
		currNode->next = node;
		clList->length++;
		if (pos == clList->length) {//��������λ�������һ�����
			node->next = clList->next;

		}
	}

}

/*
		��ӡ����
*/
void PrintfCircularLinkList(CircularLinkList * clList) {
	printf("---------ѭ�������ӡ:---------\n");
	//�жϵ�һ������Ƿ�Ϊ��
	if (clList->length == 0 || !clList->next) {
		printf("�����ȿգ�û�����ݿ��Դ�ӡ");
		clList->length = 0;
		return;
	}
	//������ʱ���
	CircularNode * node = clList->next;
	for (int i = 0; i <clList->length; i++) {
		
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
	printf("---------end---------\n");
}

/*
		ɾ��ѭ������ָ��λ��pos��Ԫ�أ�������
*/
ElementType DeleteCircularLinkList(CircularLinkList* clList, int pos) {
	ElementType element;//Ҫ���ص�Ԫ��
	element.id = -99;
	
	//���Ҫɾ�����ǵ�һ��Ԫ��
	if (pos == 1) {
		CircularNode* node = clList->next;
			if (node) {
				element = node->data;
				//�ҵ����һ����㣬Ȼ��ı�ָ�����ָ��
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
	//���Ҫɾ�������������
	
	CircularNode* node=clList->next;//Ҫɾ���Ľ��
	CircularNode * preNode=node;//Ҫɾ���Ľ���ǰ�ý��
	//ѭ���ҵ�Ҫɾ���Ľ���ǰ�ý�㡿
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
		����Ԫ������element���ض�Ӧ�Ľ��ָ��CircularNode*
*/
CircularNode* GetCircularLinkListNode(CircularLinkList* clList, ElementType element) {
	CircularNode* node = clList->next;
	if (!node) {
		return NULL;
	}
	//����(��ʹ��ѭ������i������ѭ������ķ���
	do {
		if (element.id == node->data.id && strcmp(element.name,node->data.name)==0 ) {//�ж��Ƿ����
			return node;
		}
		node = node->next;

	} while (node!=clList->next);
	return NULL;

}

/*
	ͨ��������ĳ�ڵ㣬ѭ�������������е�ÿ��Ԫ�أ�
*/
void PrintfCircularLinkListByNode(CircularLinkList* clList, CircularNode* node) {
	printf("\n-------ͨ��������ĳ�ڵ㣬ѭ������------\n");
	if (!node || !clList->next) {
			printf("�����ȿգ�û�����ݿ��Դ�ӡ");
			return;
		}
	//��¼��ʼ�Ľ��ָ��
	CircularNode* oriNode = node;
	do
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	} while (node!=oriNode);

	printf("\n------- ѭ������end ------\n");
}
