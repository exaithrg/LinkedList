#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

//////////////////////////////////////////////////////////////////////////////////
//单链表驱动代码
//作者：Genng
//修改日期：2018.12.27
//Reencoding at 2023.02.26
//版本：v1.3
//All rights reserved
//按Ctrl+鼠标左键（或F12)可以追踪函数
//调试环境：Visual Studio 2017
//推荐头文件声明+c文件实现诸声明函数+主函数文件的架构。这对一些较大的项目很有帮助。
//////////////////////////////////////////////////////////////////////////////////


int ListLength(LinkList head) {
	int length = 0;
	if (head == NULL) return length;
	LinkList go;
	go = head;
	while (go->next) {
		length++;
		go = go->next;
	}
	return length;
}
LinkList InitList() {
	Node *head;
	head = (Node*)malloc(sizeof(Node));	//为头结点分配存储空间
	head->next = NULL;
	return head;
}

LinkList CreateList_A(int length) {//头插法建立单链表
	Node *head, *p;
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	int i, go = length;
	for (i = length; i>0; --i) {
		p = (LinkList)malloc(sizeof(Node));
		p->next = head->next;
		head->next = p;
	}
	return head;//head为头指针
};

LinkList CreateList_B(int length) {//尾插法建立单链表
	Node *head, *last;//head为头结点 
	int go = 0;
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("OverFlow!\n");
		return head;
	}
	head->next = NULL;
	last = head;
	while (go<length) {
		Node *p;
		p = (Node*)malloc(sizeof(Node));
		last->next = p;
		last = p;
		/*	p->next=head->next;
		head->next=p;*///头插法 
		go++;
	}
	last->next = NULL;
	return head;
}
ElemType ListFormerInsert(LinkList head, int i, ElemType e) {
	Node *qian;//定义前驱结点
	qian = head;
	int go;
	for (go = 0; qian&&go<i - 1; go++) {
		qian = qian->next;
	} //将qian变成真的qian
	if (!qian || go>i - 1) return ERROR;
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("OVERFLOW!");
		return OVERFLOW;
	}
	p->data = e;
	p->next = qian->next;
	qian->next = p;
	return e;
}

ElemType ListLaterInsert(LinkList head, int i, ElemType e) {
	Node *qian;//定义前驱结点
	qian = head;
	int go;
	for (go = 0; qian&&go<i; go++) {
		qian = qian->next;
	}//直接让qian指向第i个结点
	if (!qian || go>i) return ERROR;
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = qian->next;
	qian->next = p;
	return e;
}

Status InverseLinkedList(LinkList head)
{
	LinkList p, q;  //p用来遍历链表
	//单链表至少有两个元素才有逆置一说
	//如果head->next为NULL，单链表为空
	//如果head->next->next为NULL，单链表只有一个元素
	//因此如果这两个条件满足其一，就不需要逆置直接输出原头结点即可。
	if (head == NULL) {
		printf("链表不存在");
		return OK;
	}
	if (head->next == NULL) {
		printf("链表为空");
		return OK;
	}
	if (head->next->next)
	{
		p = q = head->next; //p,s初始指向第一个结点
		p = p->next;       //p指向第二个结点
		q->next = NULL;
		while (p)
		{
			q = p;        //s指向待插入的结点
			p = p->next;   //p指向原链表的下一个结点
			//插入结点
			q->next = head->next;
			head->next = q;           //两条语句的顺序不能颠倒
		}
		return OK;
	}
	else {
		return OK;
	}
}
void InverseLinkedList_D(LinkList head) {
	Node *p, *q, *r;
	q = head->next;
	p = NULL;
	while (q) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = p;
}

Status DeleteElement(LinkList head, int i, ElemType &e) {
	Node *qian;
	int go;
	qian = head;
	for (go = 0; qian && go< i - 1; go++) {
		qian = qian->next;
	}
	if (!qian || go > i - 1)
	{
		printf("无法删除第%d个元素，删除失败\n",i);
		e = 0;
		return ERROR;
	}
	Node *q;
	q = qian->next; qian->next = q->next;
	e = q->data;
	free(q);
	return OK;
}
Status PrintList(LinkList head) {//输出链表
	if (head == NULL) {
		printf("链表不存在！");
		return OK;
	}
	LinkList p = head->next;//不是p=head
	if (p == NULL) {
		printf("链表为空！");
		return OK;
	}
	while (p) {//不是while(p->next)
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}

Status ClearList(LinkList head) {
	LinkList p, q;
	p = head->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
	return OK;
}

Status DestroyList(LinkList &head) {
	LinkList q;
	while (head)
	{
		q = head->next;
		free(head);
		head = q;
	}
	return OK;
}

/*
//拓展，关于传值，传指针，传引用调用
//传引用调用是C++语法，也就是说文件后缀必须是.cpp才可以使用传引用调用
//定义函数
int test_A(int &a) {	//传引用
	a = 1;
	return a;
}
int test_B(int a) {		//传值
	a = 1;
	return a;
}
int test_C(int *a) {	//传指针
	*a = 1;
	return *a;
}
//而main函数为
int main() {
	int a = 2;
	int A, B, C;

	//传引用调用，将变量本身传入函数内部，好用，但C不支持
	A = test_A(a);
	printf("传引用：a=%d, A=%d\n", a, A);

	//传值调用，将变量拷贝一份传入函数内部
	a = 2;
	B = test_B(a);
	printf("传值：a=%d, B=%d\n", a, B);

	//传指针调用，将变量地址传入函数内部
	a = 2;
	C = test_C(&a);
	printf("传指针：a=%d, C=%d\n", a, C);

	system("pause");
	return 0;
}
*/
