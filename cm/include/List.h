//
// Created by f on 2023/11/15.
//

#ifndef LIST_H
#define LIST_H
#include"ds.h"
//线性表
int Length(SqList L);//求线性表长度
bool ListInsert(SqList&L, int i, ElemType e);//插入元素
bool ListDelete(SqList&L, int i, ElemType&e);//删除元素
int LocateElem(SqList L, ElemType e);//按值查找
void PrintList(SqList L);//打印线性表
bool Empty(SqList L);//判断线性表是否为空
bool DestroyList(SqList&L);//销毁线性表

bool Init(SeqList&L, int InitSize);//动态分配线性表

LinkList List_HeadInsert(LinkList&L);//头插法建立单链表
LinkList List_TailInsert(LinkList&L);//尾插法建立单链表
LinkList GetElem(LinkList L, int i);//按位查找
LinkList LocateElem(LinkList L, ElemType e);//按值查找
bool ListInsert(LinkList&L, int i, ElemType e);//插入元素
bool ListDelete(LinkList&L, int i, ElemType&e);//删除元素
//Stack
void InitStack(SqStack&S);//初始化栈
bool StackEmpty(SqStack S);//判断栈是否为空
bool Push(SqStack&S, ElemType e);//入栈
bool Pop(SqStack&S, ElemType&e);//出栈
bool GetTop(SqStack S, ElemType&e);//取栈顶元素
bool DestroyStack(SqStack&S);//销毁栈
//Queue
void InitQueue(SqQueue&Q);//初始化队列
bool QueueEmpty(SqQueue Q);//判断队列是否为空
bool EnQueue(SqQueue&Q, ElemType e);//入队
bool DeQueue(SqQueue&Q, ElemType&e);//出队
bool GetHead(SqQueue Q, ElemType&e);//取队头元素
//串
int StrLength(const char* s);//求串长
int StrCompare(HString S, HString T);//比较串
bool StrAssign(HString& T, const char* chars);//生成一个其值等于chars的串T
bool StrCopy(HString& T, HString S);//由串S复制得串T
bool StrEmpty(HString S);//判断串是否为空
bool Concat(HString& T, HString S1, HString S2);//用T返回由S1和S2联接而成的新串
bool SubString(HString& Sub, HString S, int pos=0, int len=-1);//用Sub返回串S的第pos个字符起长度为len的子串
int Index(HString S, HString T, int pos=0);//返回子串T在主串S中第pos个字符之后的位置，不存在返回0
bool ClearString(HString& S);//清空串
bool DestroyString(HString& S);//销毁串
#endif //LIST_H
