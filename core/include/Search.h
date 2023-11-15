//
// Created by f on 2023/11/15.
//

#ifndef SEARCH_H
#define SEARCH_H
#include "ds.h"
int SeqSearch(SSTable st, ElemType key);//顺序查找w249
int BinSearch(SSTable st, ElemType key);//折半查找
int BlockSearch(SSTable st, ElemType key);//分块查找
BSTNode *BSTSearch(BiTree T, ElemType key);//二叉排序树查找
int BSTInsert(BiTree &T, ElemType key);//二叉排序树插入
int BSTDelete(BiTree &T, ElemType key);//二叉排序树删除
void BSTPrint(BiTree T);//二叉排序树打印
void BSTCreate(BiTree &T, ElemType *e, int n);//二叉排序树创建
//红黑树，B树，散列表
#endif //SEARCH_H
