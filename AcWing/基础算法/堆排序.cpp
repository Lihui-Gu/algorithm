/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-10 22:08:17
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-21 08:59:57
 * @FilePath: \AcWing\基础算法\堆排序.cpp
 * @Description: 手写down一遍过，深得真传
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
using namespace std;
const int N = 1000010;
int h[N];
int n, m, cnt;

void down(int u)
{
    int t = u;
    if(u * 2 <= cnt && h[u * 2] < h[u]) t = 2 * u;
    if(u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = 2 * u + 1;
    if(t != u)
    {
        swap(h[t], h[u]);
        down(t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    cnt = n;
    for(int i = n / 2; i; i --) down(i);
    while(m --)
    {
        prinf("%d ", h[1]);
        h[1] = h[cnt --];
        down(1);
    }
}