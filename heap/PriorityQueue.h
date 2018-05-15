#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "heap.h"

typedef struct PriorityQueue{
    Pile _Pp;
}PriorityQueue; 

void PriorityQueueInit(PriorityQueue* q, int (*func)(int, int)); // 优先级队列初始化 
void PriorityQueuePush(PriorityQueue* q, DataType data); // 向队列中插入元素 
void PriorityQueuePop(PriorityQueue* q); // 删除优先级最高的元素 
int PriorityQueueSize(PriorityQueue* q); // 获取队列中元素的个数
int PriorityQueueEmpty(PriorityQueue* q);   // 检测优先级队列是否为空 
DataType PriorityQueueTop(PriorityQueue* q); // 获取队列顶的元素 
void PriorityQueueDestroy(PriorityQueue* q); // 销毁优先级队列 
void TestPriorityQueue();    //测试优先级队列


#endif