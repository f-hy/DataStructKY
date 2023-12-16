#include<iostream>
using namespace std;
#define MaxSize 50
typedef struct LNode{
    int data;
    LNode *next;
}LNode, llist[MaxSize];
void print(llist l) {
    while(l) {
        cout<<l->data<<' ';
        l=l->next;
    }
    cout<<endl;
}
int main() {
    llist l1;
    for(int i=0;i<MaxSize;++i) {
        l1[i].data=i;
        l1[i].next=&l1[i+1];
    }
    l1[MaxSize-1].next=nullptr;
    print(l1);
    llist l2;
    print(l2);
    cout<<(l1==l2)<<(&l1==&l2)<<endl;
    cout<<sizeof(l1)<<endl;
    cout<<sizeof(l2)<<endl;
    cout<<sizeof(LNode)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(l1[0].next)<<endl;
    return 0;
}