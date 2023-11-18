//
// Created by f on 2023/11/12.
//

#include "Tree.h"

#include <List.h>
#include <stack>

//类似分治法
void PreInCreate_(BiTree&T, const std::string nlr, const std::string lnr) {
  int nl = 0;
  for (; nlr[0] != lnr[nl]; ++nl);
  T = (BiTNode *)malloc(sizeof(BiTNode));
  T->data = nlr[0];
  PreInCreate(T->lchild, nlr.substr(1, nl), lnr.substr(0, nl));
  PreInCreate(T->rchild, nlr.substr(nl + 1), lnr.substr(nl + 1));
}

void PreInCreate(BiTree&T, const std::string nlr, const std::string lnr) {
  if (nlr.empty() || lnr.empty()) {
    T = nullptr;
    return;
  }
  if (nlr.size() != lnr.size()) {
    T = nullptr;
    return;
  }
  PreInCreate_(T, nlr, lnr);
}

void PrintBiTree(BiTree T) {
  if (T == nullptr) {
    return;
  }
  std::queue<const BiTNode *> q;
  q.push(T);
  int depth = 0, nodecnt = 1;
  while (!q.empty()) {
    const int size = q.size();
    for (int i = 0; i < size; ++i) {
      const BiTNode* p = q.front();
      q.pop();
      if (p == nullptr) {
        std::cout << "_";
        q.push(nullptr);
        q.push(nullptr);
      }
      else {
        std::cout << p->data;
        --nodecnt;
        q.push(p->lchild);
        if (p->lchild != nullptr)
          ++nodecnt;
        q.push(p->rchild);
        if (p->rchild != nullptr)
          ++nodecnt;
      }
      if (!nodecnt) {
        goto PrintBiTreeEnd;
      }
      std::cout << " ";
    }
    std::cout << std::endl;
    ++depth;
  }
PrintBiTreeEnd:
  std::cout << "\ndepth: " << ++depth << std::endl;
}

void visit(ElemType e) {
  std::cout << e;
}

void PreOrderRecursion(BiTree T) {
  if (T == nullptr) {
    return;
  }
  visit(T->data);
  PreOrderRecursion(T->lchild);
  PreOrderRecursion(T->rchild);
}

void InOrderRecursion(BiTree T) {
  if (T == nullptr) {
    return;
  }
  InOrderRecursion(T->lchild);
  visit(T->data);
  InOrderRecursion(T->rchild);
}

void PostOrderRecursion(BiTree T) {
  if (T == nullptr) {
    return;
  }
  PostOrderRecursion(T->lchild);
  PostOrderRecursion(T->rchild);
  visit(T->data);
}

void LevelOrder(BiTree T) {
  if (T == nullptr) {
    return;
  }
  std::queue<const BiTNode *> q;
  q.push(T);
  while (!q.empty()) {
    const BiTNode* p = q.front();
    q.pop();
    visit(p->data);
    if (p->lchild != nullptr) {
      q.push(p->lchild);
    }
    if (p->rchild != nullptr) {
      q.push(p->rchild);
    }
  }
}

void PreOrderRecurrence1(BiTree T) {
  if (T == nullptr) return;
  std::stack<const BiTNode *> s;
  s.push(T);
  const BiTNode* node;
  while (!s.empty()) {
    node = s.top();
    s.pop();
    visit(node->data); //任意位置
    if (node->rchild != nullptr) s.push(node->rchild);
    if (node->lchild != nullptr) s.push(node->lchild);
  }
}

void PreOrderRecurrence(BiTree T) {
  std::stack<const BiTNode *> s;
  const BiTNode* p = T;
  while (p != nullptr || !s.empty()) {
    if (p != nullptr) {
      //不是p->lchild
      visit(p->data);
      s.push(p);
      p = p->lchild;
    }
    else {
      p = s.top();
      s.pop();
      p = p->rchild;
    }
  }
}

void InOrderRecurrence(BiTree T) {
  std::stack<const BiTNode *> s;
  const BiTNode* p = T;
  while (p != nullptr || !s.empty()) {
    if (p != nullptr) {
      s.push(p);
      p = p->lchild;
    }
    else {
      p = s.top();
      s.pop();
      visit(p->data); //visit在这，要先获取p
      p = p->rchild;
    }
  }
}

void PostOrderRecurrence(BiTree T) {
  //***
  std::stack<const BiTNode *> s;
  const BiTNode *p = T, *r = nullptr; //r记录上一个visit的结点，初始为nullptr
  while (p != nullptr || !s.empty()) {
    if (p) {
      s.push(p);
      p = p->lchild;
    }
    else {
      p = s.top();
      if (p->rchild != nullptr && p->rchild != r) p = p->rchild; //没有visit过
      else {
        //孩子visit过，或者没有右孩子
        s.pop();
        visit(p->data);
        r = p;
        p = nullptr;
      } //ends
    }
  }
}

int Depth(BiTree T) {
  if (T == nullptr) {
    return 0;
  }
  const int l = Depth(T->lchild);
  const int r = Depth(T->rchild);
  return l > r ? l + 1 : r + 1;
}

int LeafCount(BiTree T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild == nullptr && T->rchild == nullptr) {
    return 1;
  }
  return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int NodeCount(BiTree T, int k) {
  if (T == nullptr || k < 1) {
    return 0;
  }
  if (k == 1) {
    return 1;
  }
  return NodeCount(T->lchild, k - 1) + NodeCount(T->rchild, k - 1);
}

int Level(BiTree T, ElemType x) {
  if (T == nullptr) {
    return -1;
  }
  if (T->data == x) {
    return 1;
  }
  const int l = Level(T->lchild, x);
  const int r = Level(T->rchild, x);
  if (l == -1) {
    if (r == -1) {
      return -1;
    }
    return r + 1;
  }
  if (r == -1) {
    return l + 1;
  }
  return l > r ? l + 1 : r + 1;
}

// +求二叉树中两个结点的最低公共祖先结点
const BiTNode* CommonAncestor(BiTree T, const BiTNode* node1, const BiTNode* node2) {
  if (T == nullptr || node1 == nullptr || node2 == nullptr) {
    return nullptr;
  }
  if (T == node1 || T == node2) {
    return T;
  }
  const BiTNode* l = CommonAncestor(T->lchild, node1, node2);
  const BiTNode* r = CommonAncestor(T->rchild, node1, node2);
  return l != nullptr ? l : r;
}

bool isEqual(BiTree T1, BiTree T2) {
  if (T1 == nullptr && T2 == nullptr) {
    return true;
  }
  if (T1 == nullptr || T2 == nullptr) {
    return false;
  }
  if (T1->data != T2->data) {
    return false;
  }
  if (!isEqual(T1->lchild, T2->lchild)) {
    return false;
  }
  return isEqual(T1->rchild, T2->rchild);
}

bool DestroyBiTree(BiTree&T) {
  if (T == nullptr) {
    return true;
  }
  DestroyBiTree(T->lchild);
  DestroyBiTree(T->rchild);
  free(T);
  T = nullptr;
  return true;
}

void CopyBiTree(BiTree T1, BiTree&T2) {
  if (T1 == nullptr) {
    T2 = nullptr;
    return;
  }
  T2 = (BiTNode *)malloc(sizeof(BiTNode));
  T2->data = T1->data;
  CopyBiTree(T1->lchild, T2->lchild);
  CopyBiTree(T1->rchild, T2->rchild);
}

BiThreadNode* FirstNode(BiThreadNode* p) {
  //+
  while (p->LTag == Link) {
    p = p->lchild;
  }
  return p;
}

BiThreadNode* NextNode(BiThreadNode* p) {
  //+
  if (p->RTag == Link) {
    return FirstNode(p->rchild);
  }
  return p->rchild;
}

void InOrder(BiThreadTree T) {
  if (T == nullptr) {
    return;
  }
  for (BiThreadNode* p = FirstNode(T); p != nullptr; p = NextNode(p)) {
    visit(p->data);
  }
}
