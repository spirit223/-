#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"

/* 初始化运算:初始化得到一个空线性表 */
Status InitSqList(SqList* L) {
	(*L).len = 0;
	return OK;
}

/* 判空运算: 判断线性表L是否为空,若为空返回TRUE,否则返回FALSE */
Status IsEmpty(SqList L) {
	if (L.len == 0)
	{
		return TRUE;
	}
	return FALSE;
}

/* 判满运算: 判断线性表L是否为满,若为满返回TRUE,否则返回FALSE */
Status IsFull(SqList L) {
	if (MAX == L.len)
	{
		return TRUE;
	}
	return FALSE;
}

/* 线性表的创建: 创建一个线性表,成功返回OK,失败返回ERROR */
Status CreateSqList(SqList* L) {
	printf("请输入你要创建的顺序表的大小: ");
	scanf("%d", &((*L).len));
	if ((*L).len > MAX)
	{
		return ERROR;
	}
	for (int i = 1; i <= (*L).len; i++)
	{
		printf("请输入第 %d 个元素: ", i);
		scanf("%d", &((*L).data[i - 1]));
	}
	return OK;
}

/* 求长度运算: 返回线性表L的长度 */
int SqListLength(SqList L) {
	return L.len;
}

/* 顺序查找法: 在线性表L中搜索e,若搜索成功返回e在L中的位序,未查找返回-1 */
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

/* 插入运算: 在线性表L的指定位置pos(位序从1开始编址)上插入元素e */
Status SqListInsert(SqList* L, int pos, ElementType e) {
	/* 因pos不合法导致插入操作失败 */
	if (pos < 1 || pos > (*L).len + 1)
	{
		return ERROR;
	}
	/* 因线性表L已满导致插入操作失败 */
	if (IsFull(*L) == TRUE)
	{
		return OVERFLOW;
	}
	/* 将第pos个元素到最后一个元素一起向后平移一位 */
	for (int j = (*L).len - 1; j >= pos - 1; j--)
	{
		(*L).data[j + 1] = (*L).data[j];
	}
	/* 在第pos个位置上存放新的元素e */
	(*L).data[pos - 1] = e;
	/* 线性表长度加1 */
	(*L).len++;
	return OK;
}

/* 删除运算: 删除线性表L指定位置pos(位序从1开始编址)上的元素,并用变量e接收被删除的元素 */
Status SqListDelete(SqList* L, int pos, ElementType *e) {
	int j;
	/* 因pos不合法导致删除操作失败 */
	if (pos < 1 || pos > (*L).len)
	{
		return ERROR;
	}
	/* 因线性表L为空导致删除操作失败 */
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

/* 访问运算: 访问线性表L的位序为pos的数据元素 */
Status VisitSqList(SqList L, int pos, ElementType *e) {
	/* 因pos不合法导致访问操作失败 */
	if (pos < 1 || pos > L.len)
	{
		return ERROR;
	}
	*e = L.data[pos - 1];
	return OK;
}

/* 打印线性表 */
void ShowSqList(SqList L) {
	for (int i = 0; i <= L.len - 1; i++)
	{
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}