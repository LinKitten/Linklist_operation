#include "SequenceList.h"

/*

	初始化顺序表：创建一个空的线性表
	seqList：要初始化的顺序表
	elemArray  初始化时要添加的元素内容数组
	length 初始化是添加的元素个数
*/
void InitList(SeqList* seqList, ElementType* elemArray, int length) {
	
	//判读初始化的长度是否大于Max_size
	if (length > Max_Size) {
		printf("初始化的长度超出数组的最大容量，初始化失败！\n");
	}
	seqList->length = 0;//将顺序表的长度置零
	for (int i = 0; i <=length - 1; i++) {
		//每次循环都在下标为i的位置插入元素
		InsertElement(seqList, i, elemArray[i]);
	}

}

/*
-1
在线性表的index下标处插入新元素element
	index 要插入的下标
	element 要插入的元素


*/
void InsertElement(SeqList* seqLsit, int index, ElementType element) {

	//1、验证插入后的元素空间是否超过Max_Szie

	if (seqLsit->length + 1 >= Max_Size) {
		printf("数组已满，插入数组失败! \n");
		return ;
	}

	//2、index的值是否合法[0,Max_size-1]
	if (index<0 || index>Max_Size-1) {
		printf("只能在允许的范围内插入元素[0,%d] \n", Max_Size);
		return ;
	}

	//3、插入的index应该在length之内
	if (index > seqLsit->length) {
		printf("插入的下标超过了数组的最大长度-1，插入失败\n");
			return ;
	}

	//4、从第length-1个下标开始，到index，前面一个元素赋值给后面一个元素，

	for (int i = seqLsit->length-1; i >=index; i--) {
		seqLsit->datas[i + 1] = seqLsit->datas[i];
	}
	
	//将插入的元素赋值给下标为index的元素
	seqLsit->datas[index] = element;

	//6、顺序表的总长度加1；
	seqLsit->length++;
	
}

/*
	打印顺序表
*/
void PrintfList(SeqList* seqLsit) {
	for (int i = 0; i<= seqLsit->length-1; i++) {
		printf("%d\t%s\n", seqLsit->datas[i].id, seqLsit->datas[i].name);
	}
}

/*
	返回顺序表的长度
*/
int GetLength(SeqList* seqList) {
	if (seqList == NULL) {
		return 0;
	}
	return seqList->length;
}
 
/*
	返回顺序表是否为空
*/
int IsEmpty(SeqList* seqList) {
	return GetLength(seqList) == 0 ? 1 : 0;
}

/*
	清空顺序表
*/
void clearList(SeqList* seqList) {

	if (seqList == NULL)
	{
		return;
	}
	seqList->length = 0;
}


/*
	删除顺序表中指定下标index的元素
	seqList 要操作的顺序表
	index 要删除的下标
	return 返回删除的的元素，如果失败，返回NULL；

	建议使用完毕后进行free，否则会造成内存泄露
*/
ElementType* DeleteElement(SeqList* seqList, int index) {
	//判断指定下标是否越界
	if (index<0 || index>Max_Size - 1) {
		printf("元素下标越界，无法删除指定的下标元素\n");
		return NULL;
	}
	//进行删除操作
	//1、找到要删除的元素，并保存以便返回(保存的是已删除元素的副本)
	ElementType* delElement=(ElementType * )malloc(sizeof(ElementType));
	if (delElement == NULL) {
		return 0;
	}
	delElement = GetElement(seqList, index);
	//注意：单独定义并调用查找函数，返回要删除的元素指针

	//2\从指定的位置删除，后面一个元素赋值给前面一个元素
	for (int i = index; i < seqList->length - 1; i++) {
		seqList->datas[i] = seqList->datas[i + 1];
	}
	//3、顺序表的长度-1；
	seqList->length--;

	/*free(delElement);*///建议使用完毕后进行free，否则会造成内存泄露
	return delElement;//
}

/*
	查找顺序表中指定下标index的元素
	seqList 要操作的顺序表
	index 要返回的下标
	return 返回指定下标的元素，如果查找失败，返回NULL；

*/
ElementType* GetElement(SeqList* seqList, int index) {
	//判断指定下标是否越界
	if (index<0 || index>Max_Size - 1) {
		printf("元素下标越界，无法找到指定的下标元素\n");
		return NULL;
	}
	ElementType* element;//要查找的元素
	element = &seqList->datas[index];

}
