#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

/* ��ʼ��������: ��ʼ���õ�һ�������Ա�,����ʼ���ɹ�����OK,ʧ�ܷ���OVERFLOW */
Status InitLinkList(LinkList* p_head) {
	*p_head = (LNode*)malloc(sizeof(LNode));
	if (*p_head == 0)
	{
		return OVERFLOW;
	}
	(*p_head)->next = NULL;
	return OK;
}

/* �п�: �ж����Ա��Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(LinkList head) {
	if (head->next == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/* ͷ�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷŻ�OVERFLOW */
Status CreateLinkList_AtHead(LinkList head) {
	int i, temp_len;
	ElementType temp_elem;
	LNode* p = NULL;
	printf("���������봴���ĵ�������:  ");
	scanf("%d", &temp_len);
	for (i = temp_len; i >= 1; i--) {
		printf("������� %d ��Ԫ��:  ", i);
		scanf("%d", &temp_elem);
		p = (LNode*)malloc(sizeof(LNode));
		if (p == NULL)
		{
			return OVERFLOW;
		}
		p->data = temp_elem;
		p->next = p;
	}
	return OK;
}

/* β�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷ���ERROR */
Status CreateLinkList_AtTail(LinkList head) {
	int i, temp_len;
	ElementType temp_elem;
	LNode* p = NULL;
	LNode* p_tail = head;
	printf("����������Ҫ�����ĵ�����ĳ���:  ");
	scanf("%d", &temp_len);
	for (i = 1; i <= temp_len; i++) {
		printf("������� %d ��Ԫ��:  ", i);
		scanf("%d", &temp_elem);
		p = (LNode*)malloc(sizeof(LNode));
		if (p == NULL)
		{
			return OVERFLOW;
		}
		p->data = temp_elem;
		p->next = NULL;
		p_tail->next = p;
		p_tail = p;
	}
	return OK;
}

/* �󳤶�: ���ص�����ĳ��� */
int LinkListLength(LinkList head) {
	int count = 0;
	LNode* p = head->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

/* ����: �ڵ�����������e,���ҳɹ�����e�����Ա��е�λ��,���򷵻�0 */
int SeqLocateElem(LinkList head, ElementType e) {
	LNode* p = head->next;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
		i++;
	}
	return 0;
}

/* ����: �ڵ������ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ��e */
Status LinkListInsert(LinkList head, int pos, ElementType e) {
	LNode* p = head, * q = NULL;
	int j = 0;
	while (p != NULL && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > pos - 1)
	{
		return ERROR;
	}
	else
	{
		q = (LNode*)malloc(sizeof(LNode));
		if (q == NULL)
		{
			return OVERFLOW;
		}
		q->data = e;
		q->next = p->next;
		p->next = q;
	}
	return OK;
}

/* ɾ��: ɾ��������ָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ر�ɾ����Ԫ�� */
Status LinkListDelete(LinkList head, int pos, ElementType* e) {
	LNode* p = head, * q = NULL;
	/* ����j������¼λ�� */
	int j = 0;
	if (IsEmpty(head) == TRUE)
	{
		return OVERFLOW;
	}
	/* �ҵ�pos - 1���ڵ�, ����֤�� pos �����Ҳ���� */
	while (p->next != NULL && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	/* ����λ�ò��Ϸ� */
	if (p->next == NULL || j > pos - 1)
	{
		return ERROR;
	}
	else
	{
		/* q��ʱָ���pos����� */
		q = p->next;
		*e = q->data;
		/* ɾ����pos����� */
		p->next = q->next;
		free(q);
	}
	return OK;
}

/* ����: ���ʵ�������λ��Ϊpos������Ԫ�� */
Status VisitLinkList(LinkList head, int pos, ElementType* e) {
	LNode* p = head->next;
	int j = 1;
	if (IsEmpty(head) == TRUE)
	{
		return OVERFLOW;
	}
	/* �ҵ�pos����� */
	while (p != NULL && j < pos)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > pos)
	{
		return ERROR;
	}
	else
	{
		*e = p->data;
	}
	return OK;
}

/* ��ӡ: �����ӡ������ */
void ShowLinkList(LinkList head) {
	LNode* p = head->next;
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

/* ����: ���ٵ����� */
void DestoryLinkList(LinkList* p_head) {
	LNode* p = (*p_head)->next, * q = NULL;
	/* �������б��� */
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	/* ����ͷ��� */
	free(*p_head);
	*p_head = NULL;
}