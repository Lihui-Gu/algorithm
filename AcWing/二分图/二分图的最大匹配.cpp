/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-24 23:04:36
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-24 23:13:16
 * @FilePath: \AcWing\二分图\二分图的最大匹配.cpp
 * @Description: 匈牙利算法模板
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[N], ne[N], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool find(int x)
{
    for(int i = h[x]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;

}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);
    memset(h, -1, sizeof h);
    while(m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    int res = 0;
    for(int i = 1; i <=n1; i ++)
    {
        memset(st, false, sizeof st);
        if(find(i)) res ++;
    }
    printf("%d\n", res);
    return 0;
}