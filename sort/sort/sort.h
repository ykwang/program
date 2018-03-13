#ifndef SORT_H_
#define SORT_H_

extern void insertSort(int *a,int len);
extern void shellSort(int *a,int d,int len);
extern void selectSort(int *a,int len);
extern void bubbleSort(int *a,int len);
extern void quickSort(int *a,int start,int end);
extern void heapSort(int *a,int len);
extern void mergeSort(int *a,int start,int end);

#endif