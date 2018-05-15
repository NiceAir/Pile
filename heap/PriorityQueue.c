#include "PriorityQueue.h"

void PriorityQueueInit(PriorityQueue* q, int (*func)(int, int)) // ���ȼ����г�ʼ�� 
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
        printf("��ʼ��ʧ��\n");
        exit(0);
    }
    
}

void PriorityQueuePush(PriorityQueue* q, DataType data) // ������в���Ԫ��
{
    assert(q);
    PileInsert(&(q->_Pp), data);
}

void PriorityQueuePop(PriorityQueue* q) // ɾ�����ȼ���ߵ�Ԫ��
{
    assert(q);
    if (!PriorityQueueEmpty(q))
    {
        DeletePileTop(&(q->_Pp));
    }
    else 
    {
        printf("ɾ��ʧ�ܣ�����Ϊ��\n");
        exit(0);
    }
    
}

int PriorityQueueSize(PriorityQueue* q) // ��ȡ������Ԫ�صĸ���
{
    assert(q);
    if (!PriorityQueueEmpty(q))
    {
        return GetPileSize(&(q->_Pp));
    }
        return 0;
}
DataType PriorityQueueTop(PriorityQueue* q) // ��ȡ���ж���Ԫ�� 
{
    assert(q);
    if (!PriorityQueueEmpty(q))
    {
        return GetPileTop(&(q->_Pp));
    }
    else 
    {
        printf("��ȡʧ�ܣ�����Ϊ��\n");
        exit(0);
    }
}
int PriorityQueueEmpty(PriorityQueue* q)   // ������ȼ������Ƿ�Ϊ�� 
{
    assert(q);
    return CheckPileIsEmpty(&(q->_Pp));
}

void PriorityQueueDestroy(PriorityQueue* q) // �������ȼ����� 
{
    assert(q);
    DistoryPile(&(q->_Pp));
    q = NULL;
}

static int less(int a, int b)
{
    return a<b?1:0;
}

void TestPriorityQueue()    //�������ȼ�����
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
        printf("��֮ǰ��%d��Ԫ��, ��ʱ�����е�Ԫ��Ϊ%d ", PriorityQueueSize(&q), PriorityQueueTop(&q));
        PriorityQueuePop(&q);
        printf("��֮��ʣ%d��Ԫ��\n", PriorityQueueSize(&q));
        i++;
    }

    PriorityQueueDestroy(&q);
}