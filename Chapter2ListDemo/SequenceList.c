#include "SequenceList.h"

/*

	��ʼ��˳�������һ���յ����Ա�
	seqList��Ҫ��ʼ����˳���
	elemArray  ��ʼ��ʱҪ��ӵ�Ԫ����������
	length ��ʼ������ӵ�Ԫ�ظ���
*/
void InitList(SeqList* seqList, ElementType* elemArray, int length) {
	
	//�ж���ʼ���ĳ����Ƿ����Max_size
	if (length > Max_Size) {
		printf("��ʼ���ĳ��ȳ�������������������ʼ��ʧ�ܣ�\n");
	}
	seqList->length = 0;//��˳���ĳ�������
	for (int i = 0; i <=length - 1; i++) {
		//ÿ��ѭ�������±�Ϊi��λ�ò���Ԫ��
		InsertElement(seqList, i, elemArray[i]);
	}

}

/*
-1
�����Ա��index�±괦������Ԫ��element
	index Ҫ������±�
	element Ҫ�����Ԫ��


*/
void InsertElement(SeqList* seqLsit, int index, ElementType element) {

	//1����֤������Ԫ�ؿռ��Ƿ񳬹�Max_Szie

	if (seqLsit->length + 1 >= Max_Size) {
		printf("������������������ʧ��! \n");
		return ;
	}

	//2��index��ֵ�Ƿ�Ϸ�[0,Max_size-1]
	if (index<0 || index>Max_Size-1) {
		printf("ֻ��������ķ�Χ�ڲ���Ԫ��[0,%d] \n", Max_Size);
		return ;
	}

	//3�������indexӦ����length֮��
	if (index > seqLsit->length) {
		printf("������±곬�����������󳤶�-1������ʧ��\n");
			return ;
	}

	//4���ӵ�length-1���±꿪ʼ����index��ǰ��һ��Ԫ�ظ�ֵ������һ��Ԫ�أ�

	for (int i = seqLsit->length-1; i >=index; i--) {
		seqLsit->datas[i + 1] = seqLsit->datas[i];
	}
	
	//�������Ԫ�ظ�ֵ���±�Ϊindex��Ԫ��
	seqLsit->datas[index] = element;

	//6��˳�����ܳ��ȼ�1��
	seqLsit->length++;
	
}

/*
	��ӡ˳���
*/
void PrintfList(SeqList* seqLsit) {
	for (int i = 0; i<= seqLsit->length-1; i++) {
		printf("%d\t%s\n", seqLsit->datas[i].id, seqLsit->datas[i].name);
	}
}

/*
	����˳���ĳ���
*/
int GetLength(SeqList* seqList) {
	if (seqList == NULL) {
		return 0;
	}
	return seqList->length;
}
 
/*
	����˳����Ƿ�Ϊ��
*/
int IsEmpty(SeqList* seqList) {
	return GetLength(seqList) == 0 ? 1 : 0;
}

/*
	���˳���
*/
void clearList(SeqList* seqList) {

	if (seqList == NULL)
	{
		return;
	}
	seqList->length = 0;
}


/*
	ɾ��˳�����ָ���±�index��Ԫ��
	seqList Ҫ������˳���
	index Ҫɾ�����±�
	return ����ɾ���ĵ�Ԫ�أ����ʧ�ܣ�����NULL��

	����ʹ����Ϻ����free�����������ڴ�й¶
*/
ElementType* DeleteElement(SeqList* seqList, int index) {
	//�ж�ָ���±��Ƿ�Խ��
	if (index<0 || index>Max_Size - 1) {
		printf("Ԫ���±�Խ�磬�޷�ɾ��ָ�����±�Ԫ��\n");
		return NULL;
	}
	//����ɾ������
	//1���ҵ�Ҫɾ����Ԫ�أ��������Ա㷵��(���������ɾ��Ԫ�صĸ���)
	ElementType* delElement=(ElementType * )malloc(sizeof(ElementType));
	if (delElement == NULL) {
		return 0;
	}
	delElement = GetElement(seqList, index);
	//ע�⣺�������岢���ò��Һ���������Ҫɾ����Ԫ��ָ��

	//2\��ָ����λ��ɾ��������һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
	for (int i = index; i < seqList->length - 1; i++) {
		seqList->datas[i] = seqList->datas[i + 1];
	}
	//3��˳���ĳ���-1��
	seqList->length--;

	/*free(delElement);*///����ʹ����Ϻ����free�����������ڴ�й¶
	return delElement;//
}

/*
	����˳�����ָ���±�index��Ԫ��
	seqList Ҫ������˳���
	index Ҫ���ص��±�
	return ����ָ���±��Ԫ�أ��������ʧ�ܣ�����NULL��

*/
ElementType* GetElement(SeqList* seqList, int index) {
	//�ж�ָ���±��Ƿ�Խ��
	if (index<0 || index>Max_Size - 1) {
		printf("Ԫ���±�Խ�磬�޷��ҵ�ָ�����±�Ԫ��\n");
		return NULL;
	}
	ElementType* element;//Ҫ���ҵ�Ԫ��
	element = &seqList->datas[index];

}
