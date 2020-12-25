#define _CRT_SECURE_NO_WARNINGS
#include"DynamicSqList.h"

/* 初始化: 初始化得到一个空动态顺序表L,成功返回OK,失败返回ERROR */
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

/* 判空: 判断动态顺序表L是否为空,为空返回TRUE,否则返回FALSE */
Status IsEmpty(SqList_D L) {
	if (L.len == 0)
	{
		return TRUE;
	}
	return FALSE;
}

/* 判满: 判断动态顺序表L是否为满,为满返回TRUE,否则返回FALSE */
Status IsFull(SqList_D L) {
	if (L.len == L.listSize)
	{
		return TRUE;
	}
	return	FALSE;
}

/* 创建: 创建一个动态顺序表,成功返回OK,否则返回ERROR */
Status CreateDynamicSqList(SqList_D* L) {
	printf("请输入你想要创建的线性表的长度: ");
	scanf("%d", &(*L).len);
	/* 若被创建的动态顺序表的长度大于初始存储空间大小,那么重新申请一个更大的能满足需求的存储空间 */
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
		printf("请输入第 %d 个元素: ", i);
		scanf("%d", &((*L).data[i - 1]));
	}
	return OK;
}

/* 求长度: 返回动态顺序表的长度 */
int DySqListLength(SqList_D L) {
	return L.len;
}

/* 顺序查找:在动态顺序表中搜索e,若查找成功返回e在L中的位序,否则返回0 */
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

/* 插入: 在动态顺序表L的指定位置pos(位序从1开始编址)上插入元素 */
Status DySqListInsert(SqList_D* L, int pos, ElementType e) {
	/* 因i不合法导致插入操作失败 */
	if (pos < 1 || pos > (*L).len + 1)
	{
		return ERROR;
	}
	if (IsFull(*L) == TRUE)
	{
		/* 若动态顺序表L已满则分配一个更大的存储空间 */
		(*L).listSize = (*L).listSize + INCSIZE;
		(*L).data = (ElementType*)realloc((*L).data, sizeof(ElementType) * (*L).listSize);
		/* 因存储分配失败导致插入操作失败 */
		if ((*L).data == 0)
		{
			return OVERFLOW;
		}
	}
	/* 将第pos个元素到最后一个元素一起向后平移一位 */
	for (int i = (*L).len - 1; i >= pos - 1; i--) {
		(*L).data[i + 1] = (*L).data[i];
	}
	/* 在第pos个位置上存放新的元素e */
	(*L).data[pos - 1] = e;
	(*L).len++;
	return OK;
}

/* 删除: 删除动态顺序表L指定位置pos(位序从1开始编址)上的元素,并用变量e接收被删除的元素 */
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

/* 访问: 访问动态顺序表L的位序为pos的数据元素 */
Status VisitDySqList(SqList_D L, int pos, ElementType *e) {
	if (pos < 1 || pos > L.len)
	{
		return ERROR;
	}
	*e = L.data[pos - 1];
	return OK;
}

/* 打印: 输出动态顺序表 */
void ShowDySqList(SqList_D L) {
	for (int i = 0; i <= L.len - 1; i++) {
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}

/* 撤销: 动态顺序表使用完成后要回收其用于存储线性表的元素的存储空间 */
void DestroyDySqList(SqList_D* L) {
	free((*L).data);
	(*L).data = NULL;
	(*L).len = 0;
	(*L).listSize = 0;
}