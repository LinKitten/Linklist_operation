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
	{1,"���ݽṹ"},
	{2,"c���Գ������"},
	{3,"�ߵ���ѧ"},
	{4,"java�������"},
	{5,"ui�������"}
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

	SeqList seqList;//Ҫ������˳���
	ElementType* delElement;
	InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));//��ʼ��
	printf("��ʼ����>>>> \n");
	PrintfList(&seqList);

	printf("--------------------------------\n");

	delElement = DeleteElement(&seqList, 2);
	printf("ɾ����>>>> \n");
	PrintfList(&seqList);
	printf("��ɾ����Ԫ���ǣ�\n %d\t%s\n \n",delElement->id,delElement->name);
	free(delElement);//�ͷ��ڴ�

}

void TestLinkList() {
	//��������
	LinkList linkList;
	linkList.length = 0;//���׺��Եĵط�
	//����Ԫ��
	InitLinkList(&linkList, dataArray,sizeof(dataArray) / sizeof(dataArray[0]));
	PrintLinkList(&linkList);

	//��ĳ��λ�ò���Ԫ��
	ElementType newElement;
	newElement.id = 11;
	newElement.name = (char*)malloc(12);
	if (newElement.name == NULL) {
		printf("Ϊname������̬�ռ�ʧ�ܣ�\n");
		return;
	}
	//��name��ֵ
	strcpy(newElement.name, "HTML5+CSS3");
	InsertLinkList(&linkList, 3, newElement);
	printf("�����>>>>>>>\n");
	PrintLinkList(&linkList);

	//ɾ�����
	printf("ɾ����4��Ԫ�غ�>>>\n");
	DeleteLinkListElement(&linkList, 4);
	PrintLinkList(&linkList);

	//�������
	printf("�������*******\n");
	ClearLinkList(&linkList);
	PrintLinkList(&linkList);
	

}

void TestCircularLinkList() {
	CircularLinkList* clList = (CircularLinkList*)malloc(sizeof(CircularLinkList));//����ռ�
	clList->length = 0;
	clList->next = NULL;
	InitCircularLinkList(clList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
	PrintfCircularLinkList(clList);

	////ɾ������һ�����
	//ElementType delEle = DeleteCircularLinkList(clList, 3);
	//printf("ɾ����Ԫ���ǣ�%d\t%s\n", delEle.id,delEle.name);
	//PrintfCircularLinkList(clList);

	//����ĳ�����
	ElementType ele;
	ele.id = 4;
	ele.name = "java�������";
	CircularNode* node = GetCircularLinkListNode(clList,ele);
	printf("\n��\"%s\"��ʼ����\n", ele.name);
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
	StaticLinkList slList;//����һ����̬����
	//�����ʼ��
	InitStaticLinkList(slList);
	PrintfStaticLinkList(slList);
	/*
	
			i:0     next:1  id:-1   name:(null) �����һ��Ԫ�ص��α�next������ŵ�һ�����н����±꣨����������±꣩
			i:1     next:2  id:-1   name:(null)
			i:2     next:3  id:-1   name:(null)
			i:3     next:4  id:-1   name:(null)
			i:4     next:5  id:-1   name:(null)
			i:5     next:6  id:-1   name:(null)
			i:6     next:7  id:-1   name:(null)
			i:7     next:8  id:-1   name:(null)
			i:8     next:0  id:-1   name:(null) //�����������β�����Ϊ�գ�
			i:9     next:0  id:-1   name:(null) ��������һ��Ԫ���α�next���������һ������Ԫ�ص��±�,��ʼʱΪ0��

	*/
	//����
	ElementType ele;
	ele.id = 123;
	ele.name = "�������";
	InsertStaticLinkList(slList, 1, ele);
	printf("����Ԫ�غ�>>>>\n");
	PrintfStaticLinkList(slList);
	/*
			����Ԫ�غ�>>>>
			i:0     next:2  id:-1   name:(null)
			i:1     next:0  id:123  name:�������
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
	ele2.name = "���ݽṹ";
	InsertStaticLinkList(slList, 2, ele2);
	printf("����Ԫ�غ�>>>>\n");
	PrintfStaticLinkList(slList);
	/*
			����Ԫ�غ�>>>>
			i:0     next:3  id:-1   name:(null)
			i:1     next:2  id:123  name:�������
			i:2     next:0  id:124  name:���ݽṹ
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
	printf("����Ԫ�غ�>>>>\n");
	PrintfStaticLinkList(slList);
	/*
			����Ԫ�غ�>>>>
			i:0     next:4  id:-1   name:(null)
			i:1     next:2  id:123  name:�������
			i:2     next:3  id:124  name:���ݽṹ
			i:3     next:0  id:125  name:HTML+css
			i:4     next:5  id:-1   name:(null)
			i:5     next:6  id:-1   name:(null)
			i:6     next:7  id:-1   name:(null)
			i:7     next:8  id:-1   name:(null)
			i:8     next:0  id:-1   name:(null)
			i:9     next:1  id:-1   name:(null)
	*/

	//ɾ��ĳ��Ԫ��
	printf("ɾ��2��Ԫ�أ�>\n");
	DeleteStaticLinkList(slList, 2);
	PrintfStaticLinkList(slList);

}