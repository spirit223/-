/**********************************
 *								  *
 *		不带头结点的单链表		  *
 *								  *
 **********************************/

#ifndef NHLINKLIST_H
#define NHLINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

typedef int ElementType;

typedef struct LNode {
	ElementType data;
	struct LNode* next;
}LNode, * LinkList;

/* 初始化单链表: 初始化得到一个空线性表,若初始化成功返回OK,失败返回OVERFLOW */
Status InitNHLinkList(LinkList* head);

/* 判空: 判断线性表是否为空,为空返回TRUE,否则返回FALSE */
Status IsEmpty(LinkList head);

/* 头插法创建: 创建一个逆序的单链表,成功返回OK,失败放回OVERFLOW */
Status CreateNHLinkList_AtHead(LinkList* p_head);

/* 尾插法创建: 创建一个正序的单链表,成功返回OK,失败返回ERROR */
Status CreateNHLinkList_AtTail(LinkList* p_head);

/* 求长度: 返回单链表的长度 */
int NHLinkListLength(LinkList head);

/* 查找: 在单链表中搜索e,查找成功返回e在线性表中的位序,否则返回0 */
int SeqLocateElem(LinkList head, ElementType e);

/* 插入: 在单链表的指定位置pos(位序从1开始编址)上插入元素e */
Status NHLinkListInsert(LinkList* p_head, int pos, ElementType e);

/* 删除: 删除单链表指定位置pos(位序从1开始编址)上的元素,并用变量e返回被删除的元素 */
Status NHLinkListDelete(LinkList* p_head, int pos, ElementType* e);

/* 访问: 访问单链表中位序为pos的数据元素 */
Status VisitNHLinkList(LinkList head, int pos, ElementType* e);

/* 打印: 输出打印单链表 */
void ShowNHLinkList(LinkList head);

/* 销毁: 销毁单链表 */
void DestoryNHLinkList(LinkList* p_head);

#endif // !NHLINKLIST_H
