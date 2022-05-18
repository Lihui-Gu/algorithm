/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-08 18:30:01
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-18 09:09:55
 * @FilePath: \AcWing\基础算法\归并排序.cpp
 * @Description: 排序——归并排序
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */

#include <iostream>
using namespace std;
int n;
const int N = 100010;
int q[N], tmp[N];
void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j]) tmp[k ++] = q[i ++];
        else  tmp[k ++] = q[j ++];
    }
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];
    for(int i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j]; 
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)  scanf("%d", &q[i]);
    merge_sort(q, 0 ,n - 1);
    for(int i = 0; i < n; i ++)  printf("%d ", q[i]);
    return 0;
}