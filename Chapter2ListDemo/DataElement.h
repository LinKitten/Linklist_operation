#pragma once
#define Max_Size 255
#define TRUE 1
#define FALSE 0
/*
	���ݽṹ�ڶ���
	������������Ԫ��
*/

//1:��������Ԫ��
//typedef int ElementTpty;
typedef struct {
	int id;
	char* name;
}ElementType;

//2����˳���ṹ
typedef struct {
	ElementType datas[Max_Size]; //˳����е�Ԫ�ؼ���
	int length;					//��ǰ˳����е�Ԫ�ظ���

}SeqList;