//
// Created by f on 2023/11/12.
//

#include "Tree.h"
void _CreateBiTree(BiTree&T, const std::string nlr, const std::string lnr) {
    int nl = 0;
    for (; nlr[0] != lnr[nl]; ++nl);
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = nlr[0];
    CreateBiTree(T->lchild, nlr.substr(1, nl), lnr.substr(0, nl));
    CreateBiTree(T->rchild, nlr.substr(nl + 1), lnr.substr(nl + 1));
}
void CreateBiTree(BiTree&T, const std::string nlr, const std::string lnr) {
    if (nlr.empty() || lnr.empty()) {
        T = nullptr;
        return;
    }
    if (nlr.size() != lnr.size()) {
        T = nullptr;
        return;
    }
    _CreateBiTree(T, nlr, lnr);
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
                if(p->lchild != nullptr)
                    ++nodecnt;
                q.push(p->rchild);
                if (p->rchild != nullptr)
                    ++nodecnt;
            }
            if(!nodecnt) {
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
    if (l == -1 ) {
        if(r==-1) {
            return -1;
        }
        return r+1;
    }
    if(r==-1) {
        return l+1;
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

// +求两树是否相等
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

BiThreadNode* FirstNode(BiThreadNode *p) {//+
    while (p->LTag == Link) {
        p = p->lchild;
    }
    return p;
}
BiThreadNode* NextNode(BiThreadNode *p) {//+
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