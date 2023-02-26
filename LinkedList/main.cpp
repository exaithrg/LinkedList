#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

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

#pragma warning (disable: 4996)	
//高版本Visual Studio不支持scanf等函数，会报错C4996，这里屏蔽掉这个Error强行运行程序

int main()//链表的操作
{
	system("color 1F");		//把输出黑框框变成深蓝底...还有不少值可以尝试
	printf("链表类似动态数组，可以按照实际需要存储的数据量来变更长度，从而实现对存储空间的有效利用。\n");
	printf("由于单链表的结构特点，插入删除操作非常高效，但元素不能直接访问而必须要从头遍历寻找，因此对于需要大量查找的应用链表效率较差。\n");
	ElemType elem_test;
	int ElemNum = 0;
	int i;
	LinkList head = InitList();		//用于头插法建立链表
	LinkList head2 = InitList();	//用于尾插法建立链表
	printf("链表建立测试：请输入链表元素个数：");
	scanf("%d", &ElemNum);
	for (i = 0; i < ElemNum; i++) {
		printf("请输入第%d个元素（整数）：", i + 1);
		scanf("%d", &elem_test);
		ListFormerInsert(head, 1, elem_test);
		ListLaterInsert(head2, i, elem_test);
	}
	printf("头插法建立的链表为：");
	PrintList(head);
	printf("尾插法建立的链表为（该链表后续不再使用）：");
	PrintList(head2);
	printf("\n删除数据测试：请输入删除链表中的第几个元素\n");
	scanf("%d", &i);
	if (DeleteElement(head, i, elem_test)) {
		printf("删除的数据为%d\n", elem_test);
	}
	printf("此时链表为：\n");
	PrintList(head);
	printf("\n链表逆置测试：\n");
	printf("逆置结果：\n");
	InverseLinkedList(head);	//就地逆置。链表的优势操作之一。
	PrintList(head);			//输出逆置结果
	printf("\n链表清空测试：\n");
	ClearList(head);
	PrintList(head);	//输出清空的链表。链表的清空与否取决于head->next是否为NULL
	printf("\n链表销毁测试：\n");
	DestroyList(head);
	PrintList(head);	//输出不存在的链表。链表的存在与否取决于head是否为NULL
	printf("\n");
	system("pause");
	return 0;
}
