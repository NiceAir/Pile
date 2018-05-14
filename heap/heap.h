#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "commom.h"
typedef int DataType;
typedef struct StaticSequenceList{
    int size;
    int capacity;
    DataType *datas;
    int (*function)(int, int);
}Pile, *QPile;

void PileInit(QPile pile);  //��ʼ��
int my_cmp_bigger(int a, int b); //�ȽϺ���
void PileCreat(QPile pile, DataType datas[], int len); //������
void PileInsert(QPile pile, DataType data);  //����в���Ԫ��
DataType GetPileTop(const QPile pile); //��ȡ�Ѷ�Ԫ��
int CheckPileIsEmpty(const QPile pile); //����Ƿ�Ϊ�ն�,1��ʾ��Ϊ��
int GetPileSize(const QPile pile); //��ȡ����Ԫ�صĸ���
void DeletePileTop(QPile pile); //ɾ���Ѷ�Ԫ��
void DistoryPile(QPile pile); //���ٶ�
void PileTest(); //����

#endif