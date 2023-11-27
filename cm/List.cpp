//
// Created by f on 2023/11/15.
//
#include "List.h"
bool Init(SeqList&L, const int InitSize) {
    L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);//C的初始动态分配语句
    // L.data = new ElemType[InitSize];//C++的初始动态分配语句
    if (!L.data) {
        return false;
    }
    L.MaxSize = InitSize;
    L.length = 0;
    return true;
}
void Init(LinkList&L, ElemType *e, int n) {
    LNode * p = (LNode*)malloc(sizeof(LNode));
    L = p;
    for(int i=0;i<n;++i) {
        LNode *node = (LNode*)malloc(sizeof(LNode));
        node->data = e[i];
        p->next=node;
        p=p->next;
    }
    p->next=nullptr;
}
void Union(LinkList &dst, LinkList &src) {//src,dst AscendingOrdered
    if(src->next == nullptr) {
        return;
    }
    if(dst->next==nullptr) {
        dst = src;
        return;
    }
    LNode *p = dst->next, *q = src->next, *pp=dst;
    while(p!=nullptr&&q!=nullptr) {
        if(p->data>q->data) {
            pp->next = q;
            pp=q;
            q=q->next;;
            p->next=p;
        } else if(p->data==q->data) {
            pp=q;
            q=q->next;
            free(pp);
        }
        pp=p;
        p=p->next;
    }
    if(q!=nullptr) {
        pp->next=q;
    }
}
void visit(LinkList L) {
    for(auto p=L->next; p!=nullptr; p=p->next) {
        std::cout<<p->data<<"\t";
    }
    std::cout<<'\n';
}