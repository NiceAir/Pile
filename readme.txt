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

���У� �����Ѻ�����в���Ԫ��ʱ�õ����Զ���ıȽϺ���������ȽϺ���Ϊcmp_bigger���ʶ���������Ϊ�����
����ҪС���ѣ�ֻ����д�ȽϺ�������