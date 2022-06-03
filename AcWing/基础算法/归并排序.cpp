/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-08 18:30:01
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-06-01 22:15:25
 * @FilePath: \AcWing\基础算法\归并排序.cpp
 * @Description: 排序——归并排序
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if(l >= r)  return;
    int mid = l + r >> 1;
    int i = l, j = mid + 1, k = 0;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    while(i <= mid & j <= r)
    {
        if(q[i] <= q[j])  tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];
    for(i = l, j = 0; i <= r; i ++, j ++ )  q[i] = tmp[j];
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    printf("%d", a[0]);
    for(int i = 1; i < n; i ++) printf(" %d", a[i]);
    return 0;
}