#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"

/* ��ʼ������:��ʼ���õ�һ�������Ա� */
Status InitSqList(SqList* L) {
	(*L).len = 0;
	return OK;
}

/* �п�����: �ж����Ա�L�Ƿ�Ϊ��,��Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(SqList L) {
	if (L.len == 0)
	{
		return TRUE;
	}
	return FALSE;
}

/* ��������: �ж����Ա�L�Ƿ�Ϊ��,��Ϊ������TRUE,���򷵻�FALSE */
Status IsFull(SqList L) {
	if (MAX == L.len)
	{
		return TRUE;
	}
	return FALSE;
}

/* ���Ա�Ĵ���: ����һ�����Ա�,�ɹ�����OK,ʧ�ܷ���ERROR */
Status CreateSqList(SqList* L) {
	printf("��������Ҫ������˳���Ĵ�С: ");
	scanf("%d", &((*L).len));
	if ((*L).len > MAX)
	{
		return ERROR;
	}
	for (int i = 1; i <= (*L).len; i++)
	{
		printf("������� %d ��Ԫ��: ", i);
		scanf("%d", &((*L).data[i - 1]));
	}
	return OK;
}

/* �󳤶�����: �������Ա�L�ĳ��� */
int SqListLength(SqList L) {
	return L.len;
}

/* ˳����ҷ�: �����Ա�L������e,�������ɹ�����e��L�е�λ��,δ���ҷ���-1 */
int SeqLocateElem(SqList L, ElementType e) {
	for (int i = 0; i < L.len - 1; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return ERROR;
}

/* ��������: �����Ա�L��ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ��e */
Status SqListInsert(SqList* L, int pos, ElementType e) {
	/* ��pos���Ϸ����²������ʧ�� */
	if (pos < 1 || pos > (*L).len + 1)
	{
		return ERROR;
	}
	/* �����Ա�L�������²������ʧ�� */
	if (IsFull(*L) == TRUE)
	{
		return OVERFLOW;
	}
	/* ����pos��Ԫ�ص����һ��Ԫ��һ�����ƽ��һλ */
	for (int j = (*L).len - 1; j >= pos - 1; j--)
	{
		(*L).data[j + 1] = (*L).data[j];
	}
	/* �ڵ�pos��λ���ϴ���µ�Ԫ��e */
	(*L).data[pos - 1] = e;
	/* ���Ա��ȼ�1 */
	(*L).len++;
	return OK;
}

/* ɾ������: ɾ�����Ա�Lָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ձ�ɾ����Ԫ�� */
Status SqListDelete(SqList* L, int pos, ElementType *e) {
	int j;
	/* ��pos���Ϸ�����ɾ������ʧ�� */
	if (pos < 1 || pos > (*L).len)
	{
		return ERROR;
	}
	/* �����Ա�LΪ�յ���ɾ������ʧ�� */
	if (IsEmpty(*L) == TRUE)
	{
		return OVERFLOW;
	}
	*e = (*L).data[pos - 1];
	for (j = pos; j <= (*L).len - 1; j++) {
		(*L).data[j - 1] = (*L).data[j];
	}
	(*L).len--;
	return OK;
}

/* ��������: �������Ա�L��λ��Ϊpos������Ԫ�� */
Status VisitSqList(SqList L, int pos, ElementType *e) {
	/* ��pos���Ϸ����·��ʲ���ʧ�� */
	if (pos < 1 || pos > L.len)
	{
		return ERROR;
	}
	*e = L.data[pos - 1];
	return OK;
}

/* ��ӡ���Ա� */
void ShowSqList(SqList L) {
	for (int i = 0; i <= L.len - 1; i++)
	{
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}