#include "heap.h"

int my_cmp_bigger(int a, int b) //比较函数
{
    return a>b?1:0;
}

void PileInit(QPile pile, int (*cmp)(int, int))  //初始化
{
    assert(pile);
    pile->capacity = 0;
    pile->datas = NULL;
    pile->size = 0;
    pile->function = cmp;
}

static void PileEnlargeCapacity(QPile pile) //扩大堆的容量
{
   DataType *cache = NULL;
   assert(pile);
   cache = (DataType *)realloc(pile->datas, sizeof(DataType)*2*pile->capacity);
   if (cache != NULL)
   {
       pile->datas = cache;
       pile->capacity *= 2;
   }   
   else
   {
       printf("错误，realloc失败，内存不足\n");
       exit(0);
   }
}

static void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

static void AdjustPileDown(QPile pile, int parent)  //向下调整，用于对初始化的堆进行调整
{
/* 递归形式 */
    assert(pile);
    if (parent>=0 && parent<pile->size)
    {
        int child = parent*2+1;
        if ((child+1) < pile->size && (pile->function)(pile->datas[child+1], pile->datas[child]))
        {
            child++;
        }
        if (child < pile->size && (pile->function)(pile->datas[child], pile->datas[parent]))
        {
            my_swap(&(pile->datas[parent]), &(pile->datas[child]));
        }

        AdjustPileDown(pile, child);
    }
/*  非递归形式
    int child = parent*2+1;
    assert(pile);
    while(child < pile->size)
    {
        if ((child+1) < pile->size && pile->datas[child] > pile->datas[child+1])
            child++;
         if (pile->datas[parent] > pile->datas[child])
         {
             my_swap(&(pile->datas[parent]), &(pile->datas[child]));
             parent = child;
             child = parent*2+1;
         }
         else
             return;
    }
*/
}

void PileCreat(QPile pile, DataType datas[], int len) //创建堆
{
    int LastParent = (len-2)/2;
    assert(pile);
    pile->datas = (DataType *)malloc(sizeof(DataType)*len); //为堆申请空间
    if (pile->datas != NULL)
    {
        int i;
        pile->size = len;
        pile->capacity = len;
        for (i = 0; i<len; i++)                  //复制初始数组中的元素到堆中
            pile->datas[i] = datas[i];
    }
    else
    {
        printf("错误，malloc失败，内存不足\n");
        exit(0);
    }
    for (LastParent; LastParent>=0; LastParent--)
    {
         AdjustPileDown(pile, LastParent);       //调整堆
    }
   
}


static void AdjustPileUp(QPile pile) //向上调整，用于对插入元素后的堆调整
{
    int child = pile->size-1;
    assert(pile);
    while((child-1)>=0 && (pile->function)(pile->datas[child], pile->datas[(child-1)/2]))
    {
        my_swap(&(pile->datas[child]), &(pile->datas[(child-1)/2]));
        child = (child-1)/2;
    }
}

void PileInsert(QPile pile, DataType data)  //向堆中插入元素
{
    assert(pile);
    if (pile->size >= pile->capacity)
    {
        PileEnlargeCapacity(pile);
    }
    pile->datas[pile->size++] = data;
    AdjustPileUp(pile);
}

int CheckPileIsEmpty(const QPile pile)//检测是否为空堆,1表示堆为空
{
    return pile->size == 0 ? 1 : 0;
}

DataType GetPileTop(const QPile pile)//获取堆顶元素
{
    assert(pile);
    if (!CheckPileIsEmpty(pile))
    {
        return pile->datas[0];
    }
    printf("堆中为空，获取失败\n");
    exit(0);
}



int GetPileSize(const QPile pile)//获取堆中元素的个数
{
    return pile->size;
}

void DeletePileTop(QPile pile)//删除堆顶元素
{
    assert(pile);
    if (!CheckPileIsEmpty(pile))
    {
        pile->datas[0] = pile->datas[pile->size-1];
        AdjustPileDown(pile, 0); 
        pile->size--;
    }
}

void DistoryPile(QPile pile)//销毁堆
{
    assert(pile);
    free(pile->datas);
    pile->datas = NULL;
    pile->capacity = 0;
    pile->size = 0;
    pile->function = NULL;
}

void PileTest() //测试
{
    Pile pile;
    DataType datas[] = {53, 17, 78, 9, 45, 65, 87, 23, 31};
    int i = 0;
    PileInit(&pile, my_cmp_bigger);
    PileCreat(&pile, datas, sizeof(datas)/sizeof(DataType));
    PileInsert(&pile, 46);
    printf("堆顶元素为%d\n", GetPileTop(&pile));
    printf("堆中有%d个元素\n", GetPileSize(&pile));
    for (i = 0; i<10; i++)
    {
        DeletePileTop(&pile);
        printf("第%d次删除堆顶元素后，还有%d个元素，此时堆顶元素为%d\n", i+1, GetPileSize(&pile), GetPileTop(&pile));
    }
    DistoryPile(&pile);
}

void PileShort(DataType a[], int len)   //堆排序
{
    Pile pile;
    int i;
    PileInit(&pile, my_cmp_bigger);
    PileCreat(&pile, a, len);
    for (i = 0; i<len; i++)
    {
        a[i] = GetPileTop(&pile);
        DeletePileTop(&pile);
    }
}

void TopK() //海量数据TopK问题
{
    int a;
    int k;
    int i = 0;
    Pile pile;
    printf("K取多少？");
    scanf("%d%*c", &k);
    PileInit(&pile,my_cmp_bigger);
    
    while(scanf("%d%*c", &a))
    {
        if (a == 0)
            break;
        if (i == 0)
            PileCreat(&pile, &a, 1);
        else if (i<k)
            PileInsert(&pile, a);
        else
        {
            if (a>GetPileTop(&pile))
            {
                DeletePileTop(&pile);
                PileInsert(&pile, a);
            }
        }
        i++;
    }
    while(i>1)
    {
        printf("%d ", GetPileTop(&pile));
        DeletePileTop(&pile);
        i--;
    }
}