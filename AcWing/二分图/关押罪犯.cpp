/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-24 21:22:52
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-24 21:23:03
 * @FilePath: \AcWing\二分图\关押罪犯.cpp
 * @Description: 深度优先染色法判二分图，算法提高
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20010, M = 200010;

int h[N], e[M], ne[M], w[M], idx;
int n, m;
int color[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c, int mid)
{
    color[u] = c;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(w[i] >= mid) continue;
        if(color[j])
        {
            if(color[j] == c) return false;
        }
        else if(!dfs(j, 3 - c, mid)) return false;
    }
    return true;
}

bool check(int mid)
{
    memset(color, 0, sizeof color);
    for(int i = 1; i <= n; i ++)
    {
        if(color[i] == 0)
            if(!dfs(i, 1, mid))  return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    int l = 0, r = 1e9;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}