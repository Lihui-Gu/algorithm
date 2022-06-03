/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-16 10:04:51
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-06-01 22:28:24
 * @FilePath: \AcWing\基础算法\逆序对个数.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100010;

int a[N], tmp[N];
int n;

int merge_sort(int q[], int l, int r)
{
    int res = 0;
    if(l >= r) return 0;
    int mid = l + r >> 1;
    res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])  tmp[k ++] = q[i ++];
        else
        {
            tmp[k ++] = q[j ++];
            res += mid - i + 1;
        }
    } 
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];
    for(int i = l, j = 0; i <= r; i ++, j ++)   q[i] = tmp[j];
    return res;
}

int main()
{
    scanf("%d", &n);8
    for(int i = 0; i < n; i ++)  scanf("%d", &a[i]);
    int res = merge_sort(a, 0, n - 1);
    printf("%d\n", res);
    return 0;
}