// #include <iostream>
#include "Tree.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    BiTree t;
    // const ElemType a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    // string s = "ABC  k";
    string nlr = "ABDEFCG",lnr = "DBFEACG";
    CreateBiTree(t, nlr, lnr);
    PrintBiTree(t);
    cout<<Level(t, 'G');
    // CreateBiTree(t, a, 9);
    // PreOrderTraverse(t);cout<<endl;
    // InOrderTraverse(t);cout<<endl;
    // PostOrderTraverse(t);cout<<endl;
    // LevelOrderTraverse(t);
    return 0;
}