/***********************************
 *								   *
 *			  静态链表			   *
 *								   *
 ***********************************/
#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"
#define MAX 100

typedef int ElementType;
typedef struct {
	ElementType data;
	int indicator;
}SLNode;
typedef struct {
	SLNode store[MAX];
	int free_h;
}SqLinkList;

/* 初始化: 初始化得到一个空静态链表,成功返回OK */
Status InitList(SqLinkList* p_SL);

/* 判空: 判断线性表是否为空,为空返回TRUE,否则返回FALSE */
Status IsEmpty(SqLinkList SL);

/* 判满: 判断线性表是否为满,为满返回TRUE,否则返回FALSE */
Status IsFull(SqLinkList SL);

/* 头插法创建静态链表 */
Status CreateStaticList_AtHead(SqLinkList* p_SL);

/* 尾插法创建静态链表 */
Status CreateStaticList_AtTail(SqLinkList* p_SL);

/* 求长度: 返回线性表的长度 */
int StaticListLength(SqLinkList SL);

/* 查找: 在静态链表中搜索e,若查找到则返回e在静态链表中的位序,否则返回0 */
int StaticLocateElem(SqLinkList SL, ElementType e);

/* 插入: 在静态链表的指定位置pos(位序从1开始编址)上插入元素 */
Status StaticListInsert(SqLinkList* p_SL, int pos, ElementType e);

/* 删除: 在静态链表指定位置pos(位序从1开始编址)上的元素,并用变量e返回被删除的元素 */
Status StaticListDelete(SqLinkList* p_SL, int pos, ElementType* e);

/* 访问: 访问静态链表中位序为pos的数据元素 */
Status VisitStaticList(SqLinkList SL, int pos, ElementType* e);

/* 打印: 输出线性表 */
void ShowStaticList(SqLinkList SL);

/* 销毁:回收静态链表中已经分配出去的空间,使其重新变为空静态链表 */
void DestoryStaticList(SqLinkList* p_SL);

#endif // !STATICLINKLIST_H
