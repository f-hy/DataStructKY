//
// Created by f on 2023/11/26.
//
#include"Tree.h"
using namespace std;
void tWPL() {
  const int n=10;
  ElemType a[n] = { 1,2,4,8,9,5,10,3,6,7 };
  ElemType b[n] = { 8,4,9,2,10,5,1,6,3,7 };
  BiTree t;
  PreInCreate(t, a, b, n);
  PrintBiTree(t);
  int wpl = WPL(t);
  cout<<wpl<<endl;
}
int main() {
  tWPL();
  return 0;
}
