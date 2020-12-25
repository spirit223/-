/**********************************
 *								  * 
 *			��ͷ���ĵ�����		  *
 *								  *
 **********************************/
#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

typedef int ElementType;

typedef struct LNode {
	ElementType data;
	struct LNode* next;
}LNode, *LinkList;

/* ��ʼ��������: ��ʼ���õ�һ�������Ա�,����ʼ���ɹ�����OK,ʧ�ܷ���OVERFLOW */
Status InitLinkList(LinkList* p_head);

/* �п�: �ж����Ա��Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(LinkList head);

/* ͷ�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷŻ�OVERFLOW */
Status CreateLinkList_AtHead(LinkList head);

/* β�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷ���ERROR */
Status CreateLinkList_AtTail(LinkList head);

/* �󳤶�: ���ص�����ĳ��� */
int LinkListLength(LinkList head);

/* ����: �ڵ�����������e,���ҳɹ�����e�����Ա��е�λ��,���򷵻�0 */
int SeqLocateElem(LinkList head, ElementType e);

/* ����: �ڵ������ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ��e */
Status LinkListInsert(LinkList head, int pos, ElementType e);

/* ɾ��: ɾ��������ָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ر�ɾ����Ԫ�� */
Status LinkListDelete(LinkList head, int pos, ElementType* e);

/* ����: ���ʵ�������λ��Ϊpos������Ԫ�� */
Status VisitLinkList(LinkList head, int pos, ElementType* e);

/* ��ӡ: �����ӡ������ */
void ShowLinkList(LinkList head);

/* ����: ���ٵ����� */
void DestoryLinkList(LinkList* p_head);

#endif // !LINKLIST_H