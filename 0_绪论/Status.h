/****************************************
 *			����״̬��				    *
 *			���ϵͳ���ͻ				*
 *		����״̬�����ͺͲ�������			*
 ****************************************/
#ifndef STATUS_H
#define STATUS_H

#include<stdio.h>

 /* ״̬�� */
#define TRUE	1	//	�� / ��
#define FALSE	0	//	�� / ��
#define OK		0	//	ͨ��	 / �ɹ�
#define ERROR	-1	//	���� / ʧ��
//��ֹϵͳ�붨���ͻ
#ifndef OVERFLOW
#define OVERFLOW	-2	//��ջ����/�Կղ���
#endif // !OVERFLOW
#ifndef NULL
#define NULL	((void*)0)
#endif // !NULL

//״̬������
typedef int Status;
//��������
typedef int Boolean;

#endif // !STATUS_H