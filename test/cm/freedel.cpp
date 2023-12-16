//
// Created by f on 2023/11/26.
//
#include"ds.h"
using namespace std;

int main() {
  LNode* L = (LNode *)malloc(sizeof(LNode));
  L->data = 5;
  LNode* p = L;
  cout << p->data << endl;
  LNode* L1 = (LNode *)malloc(sizeof(LNode));
  L1->data = 6;
  cout << L1->data << endl;
  cout<<L->data<<endl;
  free(p);
  cout<<L->data<<endl;
  p = L1;
  cout<<p->data<<endl;
  BiTree root = (BiTree) malloc(sizeof(BiTNode));
  root->data = 1;
  root->lchild=nullptr;
  root->rchild=(BiTree) malloc(sizeof(BiTNode));
  root->rchild->data=2;
  root->rchild->lchild=root->rchild->rchild=nullptr;
  cout<<root<<endl;
  cout<<root->data<<endl;
  cout<<sizeof(*root)<<endl;
  cout<<sizeof(root->lchild)<<endl;
  cout<<sizeof(*root->rchild)<<endl;
  cout<<&root->rchild<<endl;
  cout<<root->rchild<<endl;
  return 0;
}
