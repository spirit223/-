#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

/* 初始化单链表: 初始化得到一个空线性表,若初始化成功返回OK,失败返回OVERFLOW */
Status InitLinkList(LinkList* p_head) {
	*p_head = (LNode*)malloc(sizeof(LNode));
	if (*p_head == 0)
	{
		return OVERFLOW;
	}
	(*p_head)->next = NULL;
	return OK;
}

/* 判空: 判断线性表是否为空,为空返回TRUE,否则返回FALSE */
Status IsEmpty(LinkList head) {
	if (head->next == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/* 头插法创建: 创建一个逆序的单链表,成功返回OK,失败放回OVERFLOW */
Status CreateLinkList_AtHead(LinkList head) {
	int i, temp_len;
	ElementType temp_elem;
	LNode* p = NULL;
	printf("请输入你想创建的单链表长度:  ");
	scanf("%d", &temp_len);
	for (i = temp_len; i >= 1; i--) {
		printf("请输入第 %d 个元素:  ", i);
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

/* 尾插法创建: 创建一个正序的单链表,成功返回OK,失败返回ERROR */
Status CreateLinkList_AtTail(LinkList head) {
	int i, temp_len;
	ElementType temp_elem;
	LNode* p = NULL;
	LNode* p_tail = head;
	printf("请输入你想要创建的单链表的长度:  ");
	scanf("%d", &temp_len);
	for (i = 1; i <= temp_len; i++) {
		printf("请输入第 %d 个元素:  ", i);
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

/* 求长度: 返回单链表的长度 */
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

/* 查找: 在单链表中搜索e,查找成功返回e在线性表中的位序,否则返回0 */
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

/* 插入: 在单链表的指定位置pos(位序从1开始编址)上插入元素e */
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

/* 删除: 删除单链表指定位置pos(位序从1开始编址)上的元素,并用变量e返回被删除的元素 */
Status LinkListDelete(LinkList head, int pos, ElementType* e) {
	LNode* p = head, * q = NULL;
	/* 变量j用来记录位序 */
	int j = 0;
	if (IsEmpty(head) == TRUE)
	{
		return OVERFLOW;
	}
	/* 找第pos - 1个节点, 并保证第 pos 个结点也存在 */
	while (p->next != NULL && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	/* 插入位置不合法 */
	if (p->next == NULL || j > pos - 1)
	{
		return ERROR;
	}
	else
	{
		/* q此时指向第pos个结点 */
		q = p->next;
		*e = q->data;
		/* 删除第pos个结点 */
		p->next = q->next;
		free(q);
	}
	return OK;
}

/* 访问: 访问单链表中位序为pos的数据元素 */
Status VisitLinkList(LinkList head, int pos, ElementType* e) {
	LNode* p = head->next;
	int j = 1;
	if (IsEmpty(head) == TRUE)
	{
		return OVERFLOW;
	}
	/* 找第pos个结点 */
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

/* 打印: 输出打印单链表 */
void ShowLinkList(LinkList head) {
	LNode* p = head->next;
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

/* 销毁: 销毁单链表 */
void DestoryLinkList(LinkList* p_head) {
	LNode* p = (*p_head)->next, * q = NULL;
	/* 撤销所有表结点 */
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	/* 撤销头结点 */
	free(*p_head);
	*p_head = NULL;
}