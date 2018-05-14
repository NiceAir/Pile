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

其中， 创建堆和向堆中插入元素时用到了自定义的比较函数。这里比较函数为cmp_bigger，故而创建出来为大根堆
若想要小根堆，只需重写比较函数即可