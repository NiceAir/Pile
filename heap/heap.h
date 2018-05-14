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

void PileInit(QPile pile);  //初始化
int my_cmp_bigger(int a, int b); //比较函数
void PileCreat(QPile pile, DataType datas[], int len); //创建堆
void PileInsert(QPile pile, DataType data);  //向堆中插入元素
DataType GetPileTop(const QPile pile); //获取堆顶元素
int CheckPileIsEmpty(const QPile pile); //检测是否为空堆,1表示堆为空
int GetPileSize(const QPile pile); //获取堆中元素的个数
void DeletePileTop(QPile pile); //删除堆顶元素
void DistoryPile(QPile pile); //销毁堆
void PileTest(); //测试

#endif