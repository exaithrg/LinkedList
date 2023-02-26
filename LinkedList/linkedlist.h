#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

//////////////////////////////////////////////////////////////////////////////////
//单链表声明代码
//作者：Geng
//修改日期：2018.12.27
//Reencoding at 2023.02.26
//版本：v1.2
//All rights reserved
//按Ctrl+鼠标左键（或F12)可以追踪函数
//调试环境：Visual Studio 2017
//推荐头文件声明+c文件实现诸声明函数+主函数文件的架构。这对一些较大的项目很有帮助。
//////////////////////////////////////////////////////////////////////////////////

#define  TRUE  1  
#define  FALSE 0 
#define  OK    1 
#define  ERROR  0
#define  OVERFLOW   -2  
#define  MALLOC_ERROR  -3
typedef int Status;
typedef int ElemType;  //表数据元素,暂定为int类型

typedef struct LNode {
	ElemType data;		//链表结点数据域
	struct LNode *next;	//链表结点指针域。该指针指向一个LNode型结点，即指向另一个链表结点结构体
}Node, *LinkList;	//通过InitList函数，可以将LinkList置为头结点。

//链表求长，返回长度
int ListLength(LinkList head);

//建立全空白链表，返回头指针
LinkList InitList();

//头插法建立单链表，返回头指针
LinkList CreateList_A(int length);

//尾插法建立单链表，返回头指针
LinkList CreateList_B(int length);

//清空链表，保留头指针
Status ClearList(LinkList head);

//销毁链表。什么也不剩。
Status DestroyList(LinkList &head);		//传引用调用。可以改为传指针调用效果一样。这个更方便。

//在第i个元素前插入元素e。ListFormerInsert函数可以在一个空白链表中插入元素，此时应置i=1.
ElemType ListFormerInsert(LinkList head, int i, ElemType e);

//在第i个元素之后插入元素e。ListLaterInsert函数可以在空白链表中插入元素，此时应置i=0
ElemType ListLaterInsert(LinkList head, int i, ElemType e);

//删除第i个元素并返回。传引用调用，这是C++语法，文件拓展名必须是.cpp才可用，.c不行
//有关传引用调用参见linkedlist_run.cpp文件末尾
Status DeleteElement(LinkList head, int i, ElemType &e);

//单链表就地逆置
Status InverseLinkedList(LinkList L);

//输出链表
Status PrintList(LinkList head);

#endif
