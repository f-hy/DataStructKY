// #include <iostream>
#include "Tree.h"
using namespace std;
void tCreatePrintOrder() {
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
}
void tEqualCopyBiTree() {
    string nlr = "ABDEFCG",lnr = "DBFEACG";
    BiTree t1, t2;
    PreInCreate(t1, nlr, lnr);
    PreInCreate(t2, nlr, lnr);
    cout<<isEqual(t1, t2)<<endl;
    DestroyBiTree(t2);
    string nlr2 = "ABDFECG",lnr2 = "DBEFACG";
    PreInCreate(t2, nlr2, lnr2);
    cout<<isEqual(t1, t2)<<endl;
    DestroyBiTree(t2);
    CopyBiTree(t1, t2);
    cout<<isEqual(t1, t2)<<endl;
    PrintBiTree(t1);
    PrintBiTree(t2);
}
void tests() {
    // tCreatePrintOrder();
    tEqualCopyBiTree();
};
int main() {
    tests();
    return 0;
}