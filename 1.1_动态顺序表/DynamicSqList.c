#define _CRT_SECURE_NO_WARNINGS
#include"DynamicSqList.h"

/* ��ʼ��: ��ʼ���õ�һ���ն�̬˳���L,�ɹ�����OK,ʧ�ܷ���ERROR */
Status InitDynamicSqList(SqList_D* L) {
	(*L).data = (ElementType *)malloc(sizeof(ElementType) * INITSIZE);
	if ((*L).data == 0)
	{
		return ERROR;
	}
	(*L).len = 0;
	(*L).listSize = INITSIZE;
	return OK;
}

/* �п�: �ж϶�̬˳���L�Ƿ�Ϊ��,Ϊ�շ���TRUE,���򷵻�FALSE */
Status IsEmpty(SqList_D L) {
	if (L.len == 0)
	{
		return TRUE;
	}
	return FALSE;
}

/* ����: �ж϶�̬˳���L�Ƿ�Ϊ��,Ϊ������TRUE,���򷵻�FALSE */
Status IsFull(SqList_D L) {
	if (L.len == L.listSize)
	{
		return TRUE;
	}
	return	FALSE;
}

/* ����: ����һ����̬˳���,�ɹ�����OK,���򷵻�ERROR */
Status CreateDynamicSqList(SqList_D* L) {
	printf("����������Ҫ���������Ա�ĳ���: ");
	scanf("%d", &(*L).len);
	/* ���������Ķ�̬˳���ĳ��ȴ��ڳ�ʼ�洢�ռ��С,��ô��������һ�����������������Ĵ洢�ռ� */
	if ((*L).listSize < (*L).len)
	{
		(*L).listSize = (*L).len + INCSIZE;
		free((*L).data);
		(*L).data = (ElementType*)malloc(sizeof(ElementType) * (*L).listSize);
		if ((*L).data == 0)
		{
			return ERROR;
		}
	}
	for (int i = 0; i < (*L).len; i++)
	{
		printf("������� %d ��Ԫ��: ", i);
		scanf("%d", &((*L).data[i - 1]));
	}
	return OK;
}

/* �󳤶�: ���ض�̬˳���ĳ��� */
int DySqListLength(SqList_D L) {
	return L.len;
}

/* ˳�����:�ڶ�̬˳���������e,�����ҳɹ�����e��L�е�λ��,���򷵻�0 */
int SeqLocateElem(SqList_D L, ElementType e) {
	for (int i = 0; i <= L.len-1; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

/* ����: �ڶ�̬˳���L��ָ��λ��pos(λ���1��ʼ��ַ)�ϲ���Ԫ�� */
Status DySqListInsert(SqList_D* L, int pos, ElementType e) {
	/* ��i���Ϸ����²������ʧ�� */
	if (pos < 1 || pos > (*L).len + 1)
	{
		return ERROR;
	}
	if (IsFull(*L) == TRUE)
	{
		/* ����̬˳���L���������һ������Ĵ洢�ռ� */
		(*L).listSize = (*L).listSize + INCSIZE;
		(*L).data = (ElementType*)realloc((*L).data, sizeof(ElementType) * (*L).listSize);
		/* ��洢����ʧ�ܵ��²������ʧ�� */
		if ((*L).data == 0)
		{
			return OVERFLOW;
		}
	}
	/* ����pos��Ԫ�ص����һ��Ԫ��һ�����ƽ��һλ */
	for (int i = (*L).len - 1; i >= pos - 1; i--) {
		(*L).data[i + 1] = (*L).data[i];
	}
	/* �ڵ�pos��λ���ϴ���µ�Ԫ��e */
	(*L).data[pos - 1] = e;
	(*L).len++;
	return OK;
}

/* ɾ��: ɾ����̬˳���Lָ��λ��pos(λ���1��ʼ��ַ)�ϵ�Ԫ��,���ñ���e���ձ�ɾ����Ԫ�� */
Status DySqListDelete(SqList_D* L, int pos, ElementType* e) {
	if (pos < 1 || pos > (*L).len)
	{
		return ERROR;
	}
	if (IsEmpty(*L) == TRUE)
	{
		return OVERFLOW;
	}
	*e = (*L).data[pos - 1];
	for (int i = pos; i <= (*L).len - 1; i++) {
		(*L).data[i - 1] = (*L).data[i];
	}
	(*L).len--;
	return OK;
}

/* ����: ���ʶ�̬˳���L��λ��Ϊpos������Ԫ�� */
Status VisitDySqList(SqList_D L, int pos, ElementType *e) {
	if (pos < 1 || pos > L.len)
	{
		return ERROR;
	}
	*e = L.data[pos - 1];
	return OK;
}

/* ��ӡ: �����̬˳��� */
void ShowDySqList(SqList_D L) {
	for (int i = 0; i <= L.len - 1; i++) {
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}

/* ����: ��̬˳���ʹ����ɺ�Ҫ���������ڴ洢���Ա��Ԫ�صĴ洢�ռ� */
void DestroyDySqList(SqList_D* L) {
	free((*L).data);
	(*L).data = NULL;
	(*L).len = 0;
	(*L).listSize = 0;
}