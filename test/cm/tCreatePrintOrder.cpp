//
// Created by f on 2023/11/18.
//
#include "Tree.h"
using namespace std;
int main() {
  BiTree t;
  // const ElemType a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
  // string s = "ABC  k";
  string nlr = "ABDEFCG",lnr = "DBFEACG";
  PreInCreate(t, nlr, lnr);
  PrintBiTree(t);
  cout<<Level(t, 'G')<<endl;
  PreOrderRecursion(t);cout<<endl;
  PreOrderRecurrence(t);cout<<endl;
  PreOrderRecurrence1(t);cout<<endl;
  InOrderRecursion(t);cout<<endl;
  InOrderRecurrence(t);cout<<endl;
  PostOrderRecursion(t);cout<<endl;
  PostOrderRecurrence(t);cout<<endl;
  LevelOrder(t);
  return 0;
}