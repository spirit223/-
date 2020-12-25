/****************************************
 *			定义状态码				    *
 *			解决系统码冲突				*
 *		定义状态码类型和布尔类型			*
 ****************************************/
#ifndef STATUS_H
#define STATUS_H

#include<stdio.h>

 /* 状态码 */
#define TRUE	1	//	真 / 是
#define FALSE	0	//	假 / 否
#define OK		0	//	通过	 / 成功
#define ERROR	-1	//	错误 / 失败
//防止系统码定义冲突
#ifndef OVERFLOW
#define OVERFLOW	-2	//堆栈上溢/对空操作
#endif // !OVERFLOW
#ifndef NULL
#define NULL	((void*)0)
#endif // !NULL

//状态码类型
typedef int Status;
//布尔类型
typedef int Boolean;

#endif // !STATUS_H