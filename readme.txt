堆的相关操作：

void PileInit(QPile pile);  //初始化
int my_cmp_bigger(int a, int b); //比较函数
void PileCreat(QPile pile, DataType datas[], int len); //创建堆
void PileInsert(QPile pile, DataType data);  //向堆中插入元素
DataType GetPileTop(const QPile pile); //获取堆顶元素
int CheckPileIsEmpty(const QPile pile); //检测是否为空堆,1表示堆为空
int GetPileSize(const QPile pile); //获取堆中元素的个数
void DeletePileTop(QPile pile); //删除堆顶元素
void DistoryPile(QPile pile); //销毁堆
void PileShort(DataType a[], int len);   //堆排序
void TopK(); //海量数据TopK问题

其中， 创建堆和向堆中插入元素时用到了自定义的比较函数。这里比较函数为cmp_bigger，故而创建出来为大根堆
若想要小根堆，只需重写比较函数即可


用堆封装起来的优先级队列：
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