#include "DoublyLinkList.h"
/*
*		���ݽṹ�ڶ��£�˫������
*	�ڵ�����Ļ�����������ǰ׺��㣬һ���̶��������˲���Ԫ�ص��ٶ�
*	�ص㣺�ڲ���Ԫ���ǣ����Է������ǰ׺���
*/


/*��ʼ��˫����*/
void InitDoublyLinkList(DoublyLinkList* dlList, ElementType* dataArray, int length) {
	for (int i = 0; i < length; i++) {
		InsertDoublyLinkList(dlList, i + 1, dataArray[i]);
	}
}

/* ��˫��������ָ��λ��pos����Ԫ��element*/
void InsertDoublyLinkList(DoublyLinkList* dlList, int pos, ElementType element) {
	DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));//����һ���¿ս�㣬�����贴���ڴ�ռ䣻
	//���½����г�ʼ����ָ����ָ��ΪNULL
	node->data = element;
	node->next = NULL;
	node->prev = NULL;

	//����ڵ�һ��λ�ò�����
	if (pos == 1) {
		node->next = dlList->next;//���½��ĺ�׺ָ��ָ���һ�����������򣨵�ͬ��ͷָ��ָ���λ�ã�
		dlList->next = node;//ͷָ��ָ���½��node��������
		node->prev = dlList->next;//ǰ׺ָ��ָ��ͷ���
		dlList->length++;
		return;
	}
	//���������λ�ò�����
	//������ѭ���ҵ�Ҫ����λ�õ�ǰ�ý��currNode��Ȼ���½���ǰ׺ָ��ָ���ǰ�ý��currNode
	//����ǰ�ý��currNode�ĺ�׺ָ��next  >>>>>  �ҵ���׺��㣬������ǰ׺ָ��ָ���½��node
	//�½��node�ĺ�׺ָ��next ָ�� ���ý���������Ҳ��ͬ��ǰ׺����ָ��CurrNode->nextָ���λ�ã�
	//���Ž�ǰ׺����׺ָ��currNode->nextָ���½��node��
	//��󳤶ȼ�1��
	
	//�ҵ�ǰ׺���
	DoublyNode* currNode = dlList->next;
	for (int i = 1; currNode && i < pos - 1; i++) {
		currNode = currNode->next;
	}
	if (currNode) {
		node->prev = currNode;
		if (currNode->next) {//���ǰ׺���ǿգ��յ���û�к��ý���ˣ�
			currNode->next->prev = node;//������λ�õĺ�һ������ǰ׺ָ��ָ���½��
		}
		node->next = currNode->next;
		currNode->next = node;
		dlList->length++;
	}
	
}

/*
	   ��ӡ˫������dlList
*/
void PrintfDoublyLinkList(DoublyLinkList* dlList) {
	printf("\n--------��ӡ˫������------\n");
	DoublyNode* node = dlList->next;
	if (!node || dlList->length == 0) {
		printf("����Ϊ�գ�û�����ݿ��Դ�ӡ");
		dlList->length = 0;
		return;
	}
	for (int i = 0; i < dlList->length; i++) {
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
	printf("--------end------\n");

}