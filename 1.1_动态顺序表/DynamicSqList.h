/******************************
 *							  *
 *			��̬˳���		  *
 *							  *
 ******************************/
#ifndef DYNAMICSQLIST_H
#define DYNAMICSQLIST_H

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"

typedef int ElementType;

/* ��̬����ռ�ĳ�ʼ��С */
#define INITSIZE 30
/* ��̬����ռ������ */
#define INCSIZE 20

/* ��̬˳������Ͷ��� */
typedef struct {
	/* ���Ա��е�����Ԫ�ؽ����δ����dataָʾ�Ĵ洢�ռ��� */
	ElementType* data;
	/* ��¼���Ա�ǰ�ĳ��� */
	int len;
	/* ��¼��ǰ���Ա�δ����Ĵ洢�ռ��С(�Կɴ洢������Ԫ�ظ���Ϊ��λ) */
	int listSize;
}SqList_D;

/* ��ʼ��: ��ʼ���õ�һ�������Ա�L,�ɹ�����OK,ʧ�ܷ���ERROR */
Status InitDynamicSqList(SqList_D *L);

/* �п�: �ж����Ա�L�Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(SqList_D L);

/* ����: �ж����Ա�L�Ƿ�Ϊ��,Ϊ������TRUE,���򷵻�FALSE */
Status IsFull(SqList_D L);

/* ����: ����һ�����Ա�,�ɹ�����OK,���򷵻�ERROR */
Status CreateDynamicSqList(SqList_D *L);

/* �󳤶�: �������Ա�ĳ��� */
int DySqListLength(SqList_D L);

/* ˳�����:�ڱ�������e,�����ҳɹ�����e��L�е�λ��,���򷵻�0 */
int SeqLocateElem(SqList_D L, ElementType e);

/* ����: �����Ա�L��ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ�� */
Status DySqListInsert(SqList_D *L, int pos, ElementType e);

/* ɾ��: ɾ�����Ա�Lָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ձ�ɾ����Ԫ�� */
Status DySqListDelete(SqList_D* L, int pos, ElementType* e);

/* ����: �������Ա�L��λ��Ϊpos������Ԫ�� */
Status VisitDySqList(SqList_D L, int pos, ElementType *e);

/* ��ӡ: ������Ա� */
void ShowDySqList(SqList_D L);

/* ����: ��̬˳���ʹ����ɺ�Ҫ���������ڴ洢���Ա��Ԫ�صĴ洢�ռ� */
void DestroyDySqList(SqList_D* L);

#endif // !DYNAMICSQLIST_H