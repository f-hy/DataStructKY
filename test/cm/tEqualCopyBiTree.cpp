// #include <iostream>
#include "Tree.h"
using namespace std;
int main() {
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
    return 0;
}
