/******************************
 *							  *
 *			动态顺序表		  *
 *							  *
 ******************************/
#ifndef DYNAMICSQLIST_H
#define DYNAMICSQLIST_H

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

typedef int ElementType;

/* 动态分配空间的初始大小 */
#define INITSIZE 30
/* 动态分配空间的增量 */
#define INCSIZE 20

/* 动态顺序表类型定义 */
typedef struct {
	/* 线性表中的数据元素将依次存放在data指示的存储空间中 */
	ElementType* data;
	/* 记录线性表当前的长度 */
	int len;
	/* 记录当前线性表未分配的存储空间大小(以可存储的数据元素个数为单位) */
	int listSize;
}SqList_D;

/* 初始化: 初始化得到一个空线性表L,成功返回OK,失败返回ERROR */
Status InitDynamicSqList(SqList_D *L);

/* 判空: 判断线性表L是否为空,为空返回TRUE,否则返回FALSE */
Status IsEmpty(SqList_D L);

/* 判满: 判断线性表L是否为满,为满返回TRUE,否则返回FALSE */
Status IsFull(SqList_D L);

/* 创建: 创建一个线性表,成功返回OK,否则返回ERROR */
Status CreateDynamicSqList(SqList_D *L);

/* 求长度: 返回线性表的长度 */
int DySqListLength(SqList_D L);

/* 顺序查找:在表中搜索e,若查找成功返回e在L中的位序,否则返回0 */
int SeqLocateElem(SqList_D L, ElementType e);

/* 插入: 在线性表L的指定位置pos(位序从1开始编址)上插入元素 */
Status DySqListInsert(SqList_D *L, int pos, ElementType e);

/* 删除: 删除线性表L指定位置pos(位序从1开始编址)上的元素,并用变量e接收被删除的元素 */
Status DySqListDelete(SqList_D* L, int pos, ElementType* e);

/* 访问: 访问线性表L的位序为pos的数据元素 */
Status VisitDySqList(SqList_D L, int pos, ElementType *e);

/* 打印: 输出线性表 */
void ShowDySqList(SqList_D L);

/* 撤销: 动态顺序表使用完成后要回收其用于存储线性表的元素的存储空间 */
void DestroyDySqList(SqList_D* L);

#endif // !DYNAMICSQLIST_H