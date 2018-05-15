#include "heap.h"

int my_cmp_bigger(int a, int b) //�ȽϺ���
{
    return a>b?1:0;
}

void PileInit(QPile pile, int (*cmp)(int, int))  //��ʼ��
{
    assert(pile);
    pile->capacity = 0;
    pile->datas = NULL;
    pile->size = 0;
    pile->function = cmp;
}

static void PileEnlargeCapacity(QPile pile) //����ѵ�����
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
       printf("����reallocʧ�ܣ��ڴ治��\n");
       exit(0);
   }
}

static void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

static void AdjustPileDown(QPile pile, int parent)  //���µ��������ڶԳ�ʼ���Ķѽ��е���
{
/* �ݹ���ʽ */
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
/*  �ǵݹ���ʽ
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

void PileCreat(QPile pile, DataType datas[], int len) //������
{
    int LastParent = (len-2)/2;
    assert(pile);
    pile->datas = (DataType *)malloc(sizeof(DataType)*len); //Ϊ������ռ�
    if (pile->datas != NULL)
    {
        int i;
        pile->size = len;
        pile->capacity = len;
        for (i = 0; i<len; i++)                  //���Ƴ�ʼ�����е�Ԫ�ص�����
            pile->datas[i] = datas[i];
    }
    else
    {
        printf("����mallocʧ�ܣ��ڴ治��\n");
        exit(0);
    }
    for (LastParent; LastParent>=0; LastParent--)
    {
         AdjustPileDown(pile, LastParent);       //������
    }
   
}


static void AdjustPileUp(QPile pile) //���ϵ��������ڶԲ���Ԫ�غ�Ķѵ���
{
    int child = pile->size-1;
    assert(pile);
    while((child-1)>=0 && (pile->function)(pile->datas[child], pile->datas[(child-1)/2]))
    {
        my_swap(&(pile->datas[child]), &(pile->datas[(child-1)/2]));
        child = (child-1)/2;
    }
}

void PileInsert(QPile pile, DataType data)  //����в���Ԫ��
{
    assert(pile);
    if (pile->size >= pile->capacity)
    {
        PileEnlargeCapacity(pile);
    }
    pile->datas[pile->size++] = data;
    AdjustPileUp(pile);
}

int CheckPileIsEmpty(const QPile pile)//����Ƿ�Ϊ�ն�,1��ʾ��Ϊ��
{
    return pile->size == 0 ? 1 : 0;
}

DataType GetPileTop(const QPile pile)//��ȡ�Ѷ�Ԫ��
{
    assert(pile);
    if (!CheckPileIsEmpty(pile))
    {
        return pile->datas[0];
    }
    printf("����Ϊ�գ���ȡʧ��\n");
    exit(0);
}



int GetPileSize(const QPile pile)//��ȡ����Ԫ�صĸ���
{
    return pile->size;
}

void DeletePileTop(QPile pile)//ɾ���Ѷ�Ԫ��
{
    assert(pile);
    if (!CheckPileIsEmpty(pile))
    {
        pile->datas[0] = pile->datas[pile->size-1];
        AdjustPileDown(pile, 0); 
        pile->size--;
    }
}

void DistoryPile(QPile pile)//���ٶ�
{
    assert(pile);
    free(pile->datas);
    pile->datas = NULL;
    pile->capacity = 0;
    pile->size = 0;
    pile->function = NULL;
}

void PileTest() //����
{
    Pile pile;
    DataType datas[] = {53, 17, 78, 9, 45, 65, 87, 23, 31};
    int i = 0;
    PileInit(&pile, my_cmp_bigger);
    PileCreat(&pile, datas, sizeof(datas)/sizeof(DataType));
    PileInsert(&pile, 46);
    printf("�Ѷ�Ԫ��Ϊ%d\n", GetPileTop(&pile));
    printf("������%d��Ԫ��\n", GetPileSize(&pile));
    for (i = 0; i<10; i++)
    {
        DeletePileTop(&pile);
        printf("��%d��ɾ���Ѷ�Ԫ�غ󣬻���%d��Ԫ�أ���ʱ�Ѷ�Ԫ��Ϊ%d\n", i+1, GetPileSize(&pile), GetPileTop(&pile));
    }
    DistoryPile(&pile);
}

void PileShort(DataType a[], int len)   //������
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

void TopK() //��������TopK����
{
    int a;
    int k;
    int i = 0;
    Pile pile;
    printf("Kȡ���٣�");
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