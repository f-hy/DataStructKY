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