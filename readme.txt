�ѵ���ز�����

void PileInit(QPile pile);  //��ʼ��
int my_cmp_bigger(int a, int b); //�ȽϺ���
void PileCreat(QPile pile, DataType datas[], int len); //������
void PileInsert(QPile pile, DataType data);  //����в���Ԫ��
DataType GetPileTop(const QPile pile); //��ȡ�Ѷ�Ԫ��
int CheckPileIsEmpty(const QPile pile); //����Ƿ�Ϊ�ն�,1��ʾ��Ϊ��
int GetPileSize(const QPile pile); //��ȡ����Ԫ�صĸ���
void DeletePileTop(QPile pile); //ɾ���Ѷ�Ԫ��
void DistoryPile(QPile pile); //���ٶ�
void PileShort(DataType a[], int len);   //������
void TopK(); //��������TopK����

���У� �����Ѻ�����в���Ԫ��ʱ�õ����Զ���ıȽϺ���������ȽϺ���Ϊcmp_bigger���ʶ���������Ϊ�����
����ҪС���ѣ�ֻ����д�ȽϺ�������


�öѷ�װ���������ȼ����У�
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