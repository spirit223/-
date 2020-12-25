/**************************
 *			˳���		  *
 **************************/
#ifndef SQLIST_H
#define SQLIST_H

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

#define MAX 100
#define ElementType int
typedef struct {
	ElementType data[MAX];	//���Ա��Ԫ�ش���ڸ�һά����data��
	int len;				//��¼���Ա�ǰ�ĳ���
}SqList;

/* ��ʼ������:��ʼ���õ�һ�������Ա� */
Status InitSqList(SqList* L);

/* �п�����: �ж����Ա�L�Ƿ�Ϊ��,��Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(SqList L);

/* ��������: �ж����Ա�L�Ƿ�Ϊ��,��Ϊ������TRUE,���򷵻�FALSE */
Status IsFull(SqList L);

/* ���Ա�Ĵ���: ����һ�����Ա�,�ɹ�����OK,ʧ�ܷ���ERROR */
Status CreateSqList(SqList* L);

/* �󳤶�����: �������Ա�L�ĳ��� */
int SqListLength(SqList L);

/* ˳����ҷ�: �����Ա�L������e,�������ɹ�����e��L�е�λ��,δ���ҷ���-1 */
int SeqLocateElem(SqList L, ElementType e);

/* ��������: �����Ա�L��ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ��e */
Status SqListInsert(SqList* L, int pos, ElementType e);

/* ɾ������: ɾ�����Ա�Lָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ձ�ɾ����Ԫ�� */
Status SqListDelete(SqList* L, int pos, ElementType *e);

/* ��������: �������Ա�L��λ��Ϊpos������Ԫ�� */
Status VisitSqList(SqList L, int pos, ElementType *e);

/* ��ӡ���Ա� */
void ShowSqList(SqList L);

#endif // !SQLIST_H