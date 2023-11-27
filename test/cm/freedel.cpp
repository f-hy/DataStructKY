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
  return 0;
}
