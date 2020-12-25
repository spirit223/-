/**********************************
 *								  *
 *		����ͷ���ĵ�����		  *
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

/* ��ʼ��������: ��ʼ���õ�һ�������Ա�,����ʼ���ɹ�����OK,ʧ�ܷ���OVERFLOW */
Status InitNHLinkList(LinkList* head);

/* �п�: �ж����Ա��Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(LinkList head);

/* ͷ�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷŻ�OVERFLOW */
Status CreateNHLinkList_AtHead(LinkList* p_head);

/* β�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷ���ERROR */
Status CreateNHLinkList_AtTail(LinkList* p_head);

/* �󳤶�: ���ص�����ĳ��� */
int NHLinkListLength(LinkList head);

/* ����: �ڵ�����������e,���ҳɹ�����e�����Ա��е�λ��,���򷵻�0 */
int SeqLocateElem(LinkList head, ElementType e);

/* ����: �ڵ������ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ��e */
Status NHLinkListInsert(LinkList* p_head, int pos, ElementType e);

/* ɾ��: ɾ��������ָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ر�ɾ����Ԫ�� */
Status NHLinkListDelete(LinkList* p_head, int pos, ElementType* e);

/* ����: ���ʵ�������λ��Ϊpos������Ԫ�� */
Status VisitNHLinkList(LinkList head, int pos, ElementType* e);

/* ��ӡ: �����ӡ������ */
void ShowNHLinkList(LinkList head);

/* ����: ���ٵ����� */
void DestoryNHLinkList(LinkList* p_head);

#endif // !NHLINKLIST_H
