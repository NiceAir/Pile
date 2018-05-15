#include "PriorityQueue.h"

void PriorityQueueInit(PriorityQueue* q, int (*func)(int, int)) // 优先级队列初始化 
{
    assert(q);
    PileInit(&(q->_Pp), func);
    q->_Pp.datas = (DataType *)malloc(sizeof(DataType));
    if (q->_Pp.datas != NULL)
    {
        q->_Pp.capacity = 1;
    }
    else
    {
        printf("初始化失败\n");
        exit(0);
    }
    
}

void PriorityQueuePush(PriorityQueue* q, DataType data) // 向队列中插入元素
{
    assert(q);
    PileInsert(&(q->_Pp), data);
}

void PriorityQueuePop(PriorityQueue* q) // 删除优先级最高的元素
{
    assert(q);
    if (!PriorityQueueEmpty(q))
    {
        DeletePileTop(&(q->_Pp));
    }
    else 
    {
        printf("删除失败，队列为空\n");
        exit(0);
    }
    
}

int PriorityQueueSize(PriorityQueue* q) // 获取队列中元素的个数
{
    assert(q);
    if (!PriorityQueueEmpty(q))
    {
        return GetPileSize(&(q->_Pp));
    }
        return 0;
}
DataType PriorityQueueTop(PriorityQueue* q) // 获取队列顶的元素 
{
    assert(q);
    if (!PriorityQueueEmpty(q))
    {
        return GetPileTop(&(q->_Pp));
    }
    else 
    {
        printf("获取失败，队列为空\n");
        exit(0);
    }
}
int PriorityQueueEmpty(PriorityQueue* q)   // 检测优先级队列是否为空 
{
    assert(q);
    return CheckPileIsEmpty(&(q->_Pp));
}

void PriorityQueueDestroy(PriorityQueue* q) // 销毁优先级队列 
{
    assert(q);
    DistoryPile(&(q->_Pp));
    q = NULL;
}

static int less(int a, int b)
{
    return a<b?1:0;
}

void TestPriorityQueue()    //测试优先级队列
{
    PriorityQueue q;
    int i = 0;
    PriorityQueueInit(&q, less);

    PriorityQueuePush(&q, 3);
    PriorityQueuePush(&q, 1);
    PriorityQueuePush(&q, 4);
    PriorityQueuePush(&q, 6);
    PriorityQueuePush(&q, 5);
    PriorityQueuePush(&q, 7);
    PriorityQueuePush(&q, 2);
    PriorityQueuePush(&q, 4);

    while(i<7)
    {
        printf("出之前有%d个元素, 此时出队列的元素为%d ", PriorityQueueSize(&q), PriorityQueueTop(&q));
        PriorityQueuePop(&q);
        printf("出之后还剩%d个元素\n", PriorityQueueSize(&q));
        i++;
    }

    PriorityQueueDestroy(&q);
}