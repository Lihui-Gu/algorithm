/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-16 11:07:59
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-18 09:09:20
 * @FilePath: \AcWing\基础算法\二分查找.cpp
 * @Description: 二分查找的模板
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */


#include <iostream>
using namespace std;
const int N = 100010;
int n, m;
int q[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    while(m --)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(q[l] != x) printf("-1 -1\n");
        else
        {
            printf("%d ", l);
            l = 0, r = n - 1;
            while(l < r)
            {
                int mid = l + r + 1 >> 1;
                if(q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}