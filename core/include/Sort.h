//
// Created by f on 2023/11/15.
//

#ifndef SORT_H
#define SORT_H
#include "ds.h"
void InsertSort(ElemType a[], int length);//直接插入排序
void HalfInsertSort(ElemType a[], int length);//折半插入排序
void ShellSort(ElemType a[], int length);//希尔排序
void BubbleSort(ElemType a[], int length);//冒泡排序
void QuickSort(ElemType a[], int low, int high);//快速排序
void SelectSort(ElemType a[], int length);//简单选择排序
void HeapSort(ElemType a[], int length);//堆排序
void MergeSort(ElemType a[], int low, int high);//归并排序
void RadixSort(ElemType a[], int length);//基数排序
//外部排序
#endif //SORT_H
