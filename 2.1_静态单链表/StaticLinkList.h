/***********************************
 *								   *
 *			  ��̬����			   *
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

/* ��ʼ��: ��ʼ���õ�һ���վ�̬����,�ɹ�����OK */
Status InitList(SqLinkList* p_SL);

/* �п�: �ж����Ա��Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(SqLinkList SL);

/* ����: �ж����Ա��Ƿ�Ϊ��,Ϊ������TRUE,���򷵻�FALSE */
Status IsFull(SqLinkList SL);

/* ͷ�巨������̬���� */
Status CreateStaticList_AtHead(SqLinkList* p_SL);

/* β�巨������̬���� */
Status CreateStaticList_AtTail(SqLinkList* p_SL);

/* �󳤶�: �������Ա�ĳ��� */
int StaticListLength(SqLinkList SL);

/* ����: �ھ�̬����������e,�����ҵ��򷵻�e�ھ�̬�����е�λ��,���򷵻�0 */
int StaticLocateElem(SqLinkList SL, ElementType e);

/* ����: �ھ�̬�����ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ�� */
Status StaticListInsert(SqLinkList* p_SL, int pos, ElementType e);

/* ɾ��: �ھ�̬����ָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ر�ɾ����Ԫ�� */
Status StaticListDelete(SqLinkList* p_SL, int pos, ElementType* e);

/* ����: ���ʾ�̬������λ��Ϊpos������Ԫ�� */
Status VisitStaticList(SqLinkList SL, int pos, ElementType* e);

/* ��ӡ: ������Ա� */
void ShowStaticList(SqLinkList SL);

/* ����:���վ�̬�������Ѿ������ȥ�Ŀռ�,ʹ�����±�Ϊ�վ�̬���� */
void DestoryStaticList(SqLinkList* p_SL);

#endif // !STATICLINKLIST_H
