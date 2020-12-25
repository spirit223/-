/**************************
 *			顺序表		  *
 **************************/
#ifndef SQLIST_H
#define SQLIST_H

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

#define MAX 100
#define ElementType int
typedef struct {
	ElementType data[MAX];	//线性表的元素存放在该一维数组data中
	int len;				//记录线性表当前的长度
}SqList;

/* 初始化运算:初始化得到一个空线性表 */
Status InitSqList(SqList* L);

/* 判空运算: 判断线性表L是否为空,若为空返回TRUE,否则返回FALSE */
Status IsEmpty(SqList L);

/* 判满运算: 判断线性表L是否为满,若为满返回TRUE,否则返回FALSE */
Status IsFull(SqList L);

/* 线性表的创建: 创建一个线性表,成功返回OK,失败返回ERROR */
Status CreateSqList(SqList* L);

/* 求长度运算: 返回线性表L的长度 */
int SqListLength(SqList L);

/* 顺序查找法: 在线性表L中搜索e,若搜索成功返回e在L中的位序,未查找返回-1 */
int SeqLocateElem(SqList L, ElementType e);

/* 插入运算: 在线性表L的指定位置pos(位序从1开始编址)上插入元素e */
Status SqListInsert(SqList* L, int pos, ElementType e);

/* 删除运算: 删除线性表L指定位置pos(位序从1开始编址)上的元素,并用变量e接收被删除的元素 */
Status SqListDelete(SqList* L, int pos, ElementType *e);

/* 访问运算: 访问线性表L的位序为pos的数据元素 */
Status VisitSqList(SqList L, int pos, ElementType *e);

/* 打印线性表 */
void ShowSqList(SqList L);

#endif // !SQLIST_H