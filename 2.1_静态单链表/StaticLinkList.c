#define _CRT_SECURE_NO_WARNINGS
#include"StaticLinkList.h"

/* 初始化: 初始化得到一个空静态链表,成功返回OK */
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

/* 判空: 判断线性表是否为空,为空返回TRUE,否则返回FALSE */
Status IsEmpty(SqLinkList SL) {
	if (SL.store[0].indicator == -1)
	{
		return TRUE;
	}
	return FALSE;
}

/* 判满: 判断线性表是否为满,为满返回TRUE,否则返回FALSE */
Status IsFull(SqLinkList SL) {
	if (SL.free_h == -1)
	{
		return TRUE;
	}
	return FALSE;
}

/* 头插法创建静态链表 */
Status CreateStaticList_AtHead(SqLinkList* p_SL) {
	int i, temp_len, p;
	ElementType temp_elem;
	printf("请输入想要创建的链表的长度:  ");
	scanf("%d", &temp_len);
	for (i = temp_len; i >= 1; i--)
	{
		printf("请输入第 %d 个元素: ", i);
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

/* 尾插法创建静态链表 */
Status CreateStaticList_AtTail(SqLinkList* p_SL) {
	int i, temp_len, p, p_tail;
	ElementType temp_elem;
	p_tail = 0;
	printf("请输入你想要创建的链表的大小:  ");
	scanf("%d", &temp_len);
	for (i = 1; i <= temp_len; i++) {
		printf("请输入第 %d 个元素: ", i);
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

/* 求长度: 返回线性表的长度 */
int StaticListLength(SqLinkList SL) {
	int count = 0, p = SL.store[0].indicator;
	while (p != -1)
	{
		count++;
		p = SL.store[p].indicator;
	}
	return count;
}

/* 查找: 在静态链表中搜索e,若查找到则返回e在静态链表中的位序,否则返回0 */
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

/* 插入: 在静态链表的指定位置pos(位序从1开始编址)上插入元素 */
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

/* 删除: 在静态链表指定位置pos(位序从1开始编址)上的元素,并用变量e返回被删除的元素 */
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

/* 访问: 访问静态链表中位序为pos的数据元素 */
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

/* 打印: 输出线性表 */
void ShowStaticList(SqLinkList SL) {
	int p = SL.store[0].indicator;
	while (p != -1)
	{
		printf("%d\t", SL.store[p].data);
		p = SL.store[p].indicator;
	}
	printf("\n");
}

/* 销毁:回收静态链表中已经分配出去的空间,使其重新变为空静态链表 */
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