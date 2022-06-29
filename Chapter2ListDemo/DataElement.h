#pragma once
#define Max_Size 255
#define TRUE 1
#define FALSE 0
/*
	数据结构第二章
	用来定义数据元素
*/

//1:定义数据元素
//typedef int ElementTpty;
typedef struct {
	int id;
	char* name;
}ElementType;

//2定义顺序表结构
typedef struct {
	ElementType datas[Max_Size]; //顺序表中的元素集合
	int length;					//当前顺序表中的元素个数

}SeqList;