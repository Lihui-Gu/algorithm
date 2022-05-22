/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-07 15:29:48
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-22 20:07:42
 * @FilePath: \AcWing\基础算法\快速排序.cpp
 * @Description: 快排打卡一遍过
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
using namespace std;
const int N = 100010;
int q[N];
int n;
void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int i = l - 1, j = r +1, x = q[l + r >> 1];
    while(i < j)
    {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    quick_sort(q, 0, n-1);
    for(int i = 0; i < n; i ++) printf("%d", q[i]);
    return 0;
}