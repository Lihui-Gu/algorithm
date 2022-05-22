/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-21 23:07:14
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-21 23:07:21
 * @FilePath: \AcWing\堆\堆.cpp
 * @Description: 后序遍历
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int h[N];

void dfs(int u)
{
    if(u * 2 <= n) dfs(u * 2);
    if(u * 2 + 1 <= n) dfs(u * 2 + 1);
    printf("%d ", h[u]);
}

int main()
{
    scanf("%d%d", &m, &n);
    while(m --)
    {
        for(int i = 1; i <= n; i ++) scanf("%d", &h[i]);
        bool lt = false, gt = false;
        for(int i = 1; i <= n; i ++)
        {
            int l = i * 2, r = i * 2 + 1;
            if(l <= n)
            {
                if(h[i] < h[l]) lt = true;
                else gt = true;
            }
            if(r <= n)
            {
                if(h[i] < h[r]) lt = true;
                else  gt = true;
            }
        }
        if( lt && gt ) printf("Not Heap\n");
        else if(lt) printf("Min Heap\n");
        else printf("Max Heap\n");
        dfs(1);
        puts("");
    }
    return 0;
}