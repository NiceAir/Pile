#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "heap.h"

typedef struct PriorityQueue{
    Pile _Pp;
}PriorityQueue; 

void PriorityQueueInit(PriorityQueue* q, int (*func)(int, int)); // ���ȼ����г�ʼ�� 
void PriorityQueuePush(PriorityQueue* q, DataType data); // ������в���Ԫ�� 
void PriorityQueuePop(PriorityQueue* q); // ɾ�����ȼ���ߵ�Ԫ�� 
int PriorityQueueSize(PriorityQueue* q); // ��ȡ������Ԫ�صĸ���
int PriorityQueueEmpty(PriorityQueue* q);   // ������ȼ������Ƿ�Ϊ�� 
DataType PriorityQueueTop(PriorityQueue* q); // ��ȡ���ж���Ԫ�� 
void PriorityQueueDestroy(PriorityQueue* q); // �������ȼ����� 
void TestPriorityQueue();    //�������ȼ�����


#endif