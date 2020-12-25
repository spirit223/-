#define _CRT_SECURE_NO_WARNINGS
#include"StaticLinkList.h"

/* ��ʼ��: ��ʼ���õ�һ���վ�̬����,�ɹ�����OK */
Status InitList(SqLinkList* p_SL) {
	(*p_SL).store[0].indicator = -1;
	(*p_SL).free_h = 1;
	for (int i = (*p_SL).free_h; i <= MAX-2; i++)
	{
		(*p_SL).store[i].indicator = i + 1;
	}
	(*p_SL).store[MAX - 1].indicator = -1;
	return OK;
}

/* �п�: �ж����Ա��Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(SqLinkList SL) {
	if (SL.store[0].indicator == -1)
	{
		return TRUE;
	}
	return FALSE;
}

/* ����: �ж����Ա��Ƿ�Ϊ��,Ϊ������TRUE,���򷵻�FALSE */
Status IsFull(SqLinkList SL) {
	if (SL.free_h == -1)
	{
		return TRUE;
	}
	return FALSE;
}

/* ͷ�巨������̬���� */
Status CreateStaticList_AtHead(SqLinkList* p_SL) {
	int i, temp_len, p;
	ElementType temp_elem;
	printf("��������Ҫ����������ĳ���:  ");
	scanf("%d", &temp_len);
	for (i = temp_len; i >= 1; i--)
	{
		printf("������� %d ��Ԫ��: ", i);
		scanf("%d", &temp_elem);
		p = (*p_SL).free_h;
		if (p == -1)
		{
			return ERROR;
		}
		(*p_SL).free_h = (*p_SL).store[(*p_SL).free_h].indicator;
		(*p_SL).store[p].data = temp_elem;
		(*p_SL).store[p].indicator = (*p_SL).store[0].indicator;
		(*p_SL).store[0].indicator = p;
	}
	return OK;
}

/* β�巨������̬���� */
Status CreateStaticList_AtTail(SqLinkList* p_SL) {
	int i, temp_len, p, p_tail;
	ElementType temp_elem;
	p_tail = 0;
	printf("����������Ҫ����������Ĵ�С:  ");
	scanf("%d", &temp_len);
	for (i = 1; i <= temp_len; i++) {
		printf("������� %d ��Ԫ��: ", i);
		scanf("%d", &temp_elem);
		p = (*p_SL).free_h;
		if (p == -1)
		{
			return ERROR;
		}
		(*p_SL).free_h = (*p_SL).store[(*p_SL).free_h].indicator;
		(*p_SL).store[p].data = temp_elem;
		(*p_SL).store[p].indicator = -1;
		(*p_SL).store[p_tail].indicator = p;
		p_tail = p;
	}
	return OK;
}

/* �󳤶�: �������Ա�ĳ��� */
int StaticListLength(SqLinkList SL) {
	int count = 0, p = SL.store[0].indicator;
	while (p != -1)
	{
		count++;
		p = SL.store[p].indicator;
	}
	return count;
}

/* ����: �ھ�̬����������e,�����ҵ��򷵻�e�ھ�̬�����е�λ��,���򷵻�0 */
int StaticLocateElem(SqLinkList SL, ElementType e) {
	int i = 1, p = SL.store[0].indicator;
	while (p != -1)
	{
		if (SL.store[p].data == e)
		{
			return i;
		}
		p = SL.store[p].indicator;
		i++;
	}
	return 0;
}

/* ����: �ھ�̬�����ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ�� */
Status StaticListInsert(SqLinkList* p_SL, int pos, ElementType e) {
	int p = 0, q;
	int j = 0;
	while (p != -1 && j < pos - 1)
	{
		p = (*p_SL).store[p].indicator;
		j++;
	}
	if (p == -1 || j > pos - 1)
	{
		return ERROR;
	}
	else
	{
		q = (*p_SL).free_h;
		if (q == -1)
		{
			return OVERFLOW;
		}
		(*p_SL).free_h = (*p_SL).store[(*p_SL).free_h].indicator;
		(*p_SL).store[q].data = e;
		(*p_SL).store[q].indicator = (*p_SL).store[p].indicator;
		(*p_SL).store[p].indicator = q;
	}
	return OK;
}

/* ɾ��: �ھ�̬����ָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ر�ɾ����Ԫ�� */
Status StaticListDelete(SqLinkList* p_SL, int pos, ElementType* e) {
	int p = 0, q;
	int j = 0;
	if (IsEmpty(*p_SL) == TRUE)
	{
		return OVERFLOW;
	}
	while ((*p_SL).store[p].indicator != -1 && j < pos - 1)
	{
		p = (*p_SL).store[p].indicator;
		j++;
	}
	if ((*p_SL).store[p].indicator == -1 || j > pos - 1)
	{
		return ERROR;
	}
	else
	{
		q = (*p_SL).store[p].indicator;
		*e = (*p_SL).store[q].data;
		(*p_SL).store[p].indicator = (*p_SL).store[q].indicator;
	}
	return OK;
}

/* ����: ���ʾ�̬������λ��Ϊpos������Ԫ�� */
Status VisitStaticList(SqLinkList SL, int pos, ElementType* e) {
	int p = SL.store[0].indicator;
	int j = 1;
	if (IsEmpty(SL) == TRUE)
	{
		return ERROR;
	}
	while (p != -1 && j < pos)
	{
		p = SL.store[p].indicator;
		j++;
	}
	if (p == -1 || j > pos)
	{
		return ERROR;
	}
	else
	{
		*e = SL.store[p].data;
	}
	return OK;
}

/* ��ӡ: ������Ա� */
void ShowStaticList(SqLinkList SL) {
	int p = SL.store[0].indicator;
	while (p != -1)
	{
		printf("%d\t", SL.store[p].data);
		p = SL.store[p].indicator;
	}
	printf("\n");
}

/* ����:���վ�̬�������Ѿ������ȥ�Ŀռ�,ʹ�����±�Ϊ�վ�̬���� */
void DestoryStaticList(SqLinkList* p_SL) {
	int p = (*p_SL).store[0].indicator;
	while (p != -1)
	{
		(*p_SL).store[(*p_SL).free_h].indicator = p;
		(*p_SL).free_h = p;
		p = (*p_SL).store[p].indicator;
	}
	(*p_SL).store[0].indicator = -1;
}