/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 21:47:03
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 21:47:05
 * @FilePath: \MOOC_ZJU\09排序.cpp
 * @Description: 写了个简单的快排
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int q[N];
int n;

void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j)
    {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if(i < j)  swap(q[j], q[i]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}


int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    printf("%d", q[0]);
    for(int i = 1; i < n; i ++) printf(" %d", q[i]);
    printf("\n");
    return 0;
}