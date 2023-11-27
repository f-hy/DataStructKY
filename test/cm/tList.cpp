//
// Created by f on 2023/11/26.
//
#include"List.h"
using namespace std;

void tUnion() {
  const int n=10;
  ElemType e1[n]={1,2,3,4,5,6,7,8,9,10};
  ElemType e2[n]={1,2,3,14,15,16,17,18,19,20};
  LinkList L1, L2;
  Init(L1, e1, n);
  visit(L1);
  Init(L2, e2, n);
  visit(L2);
  Union(L1, L2);
  visit(L1);
}
int main() {
  tUnion();
  return 0;
}
