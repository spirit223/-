#define  _CRT_SECURE_NO_WARNINGS
#include"NHLinkList.h"

/* ��ʼ��������: ��ʼ���õ�һ�������Ա�,����ʼ���ɹ�����OK,ʧ�ܷ���OVERFLOW */
Status InitNHLinkList(LinkList* head) {
	*head = NULL;
	return OK;
}

/* �п�: �ж����Ա��Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(LinkList head) {
	if (head == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/* ͷ�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷŻ�OVERFLOW */
Status CreateNHLinkList_AtHead(LinkList* p_head) {
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
		p->next = *p_head;
		*p_head = p;
	}
	return OK;
}

/* β�巨����: ����һ������ĵ�����,�ɹ�����OK,ʧ�ܷ���OVERFLOW */
Status CreateNHLinkList_AtTail(LinkList* p_head) {
	int i, temp_len;
	ElementType temp_elem;
	LNode* p = NULL;
	LNode* p_tail = *p_head;
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
		if (i == 1)
		{
			*p_head = p;
		}
		else
		{
			p_tail->next = p;
		}
		p_tail = p;
	}
	return OK;
}

/* �󳤶�: ���ص�����ĳ��� */
int NHLinkListLength(LinkList head) {
	int count = 0;
	LNode* p = head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

/* ����: �ڵ�����������e,���ҳɹ�����e�����Ա��е�λ��,���򷵻�0 */
int SeqLocateElem(LinkList head, ElementType e) {
	LNode* p = head;
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
Status NHLinkListInsert(LinkList* p_head, int pos, ElementType e) {
	LNode* p = *p_head, * q = NULL;
	int j = 0;
	if (pos == 1)
	{
		q = (LNode*)malloc(sizeof(LNode));
		if (q == NULL)
		{
			return OVERFLOW;
		}
		q->data = e;
		q->next = *p_head;
		*p_head = q;
	}
	else
	{
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
	}
	return OK;
}

/* ɾ��: ɾ��������ָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ر�ɾ����Ԫ�� */
Status NHLinkListDelete(LinkList* p_head, int pos, ElementType* e) {
	LNode* p = *p_head, * q = NULL;
	/* ����j������¼λ�� */
	int j = 1;
	if (IsEmpty(*p_head) == TRUE)
	{
		return OVERFLOW;
	}
	if (pos == 1)
	{
		q = *p_head;
		*e = q->data;
		*p_head = q->next;
		free(q);
	}
	else
	{
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
	}
	return OK;
}

/* ����: ���ʵ�������λ��Ϊpos������Ԫ�� */
Status VisitNHLinkList(LinkList head, int pos, ElementType* e) {
	LNode* p = head;
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
void ShowNHLinkList(LinkList head) {
	LNode* p = head;
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

/* ����: ���ٵ����� */
void DestoryNHLinkList(LinkList* p_head) {
	LNode* p = *p_head, *q = NULL;
	/* �������б��� */
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*p_head = NULL;
}
