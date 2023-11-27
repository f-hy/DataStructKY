//
// Created by f on 2023/11/12.
//
// #pragma once
#ifndef TREE_H
#define TREE_H
#include<queue>
#include<cstring>
#include"ds.h"
void PreInCreate(BiTree &T, std::string nlr, std::string lnr);//前序和中序创建二叉树
void PreInCreate(BiTree &T, ElemType *nlr, ElemType *lnr, int n);//前序和中序创建二叉树
void PrintBiTree(BiTree T);//打印二叉树
void visit(ElemType e);//访问结点
void PreOrderRecursion(BiTree T);//前序遍历
void InOrderRecursion(BiTree T);//中序遍历
void PostOrderRecursion(BiTree T);//后序遍历
void LevelOrder(BiTree T);//层序遍历
void PreOrderRecurrence(BiTree T);//前序遍历递推
void PreOrderRecurrence1(BiTree T);
void InOrderRecurrence(BiTree T);//中序遍历递推
void PostOrderRecurrence(BiTree T);//后序遍历递推
int Depth(BiTree T);//树的深度
int LeafCount(BiTree T);//叶子结点个数
int NodeCount(BiTree T, int k);//度为k的结点个数
int Level(BiTree T, ElemType x);//结点x的层次
const BiTNode* CommonAncestor(BiTree T, const BiTNode* node1, const BiTNode* node2);//最近公共祖先
bool isEqual(BiTree T1, BiTree T2);//两树是否相等
bool DestroyBiTree(BiTree &T);//销毁二叉树
void CopyBiTree(BiTree T1, BiTree &T2);//复制二叉树
int WPL(BiTree T, int level=1);//带权路径长度
//线索二叉树
void InThread(BiThreadTree &p, BiThreadTree &pre);//中序线索化
void CreateInThread(BiThreadTree &T);//中序线索化
BiThreadNode* FirstNode(BiThreadNode *p);//中序线索二叉树的第一个结点
BiThreadNode* NextNode(BiThreadNode *p);//中序线索二叉树的后继结点
void InOrder(BiThreadTree T);//中序遍历线索二叉树
//并查集
void Init(UFSets &S);//初始化
int Find(UFSets S, int idx);//查找
void Union(UFSets &S, int root1, int root2);//合并
#endif //TREE_H
