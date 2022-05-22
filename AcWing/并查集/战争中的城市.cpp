/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-22 20:06:20
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-22 20:06:24
 * @FilePath: \AcWing\并查集\战争中的城市.cpp
 * @Description: 并查集，连通块的个数
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
using namespace std;

const int N = 1010, M = N * N / 2;
int n, m, k;
int p[N];

struct
{
    int a, b;
}e[M];

int find(int x)
{
    if(x != p[x]) p[x]  = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++)  cin >> e[i].a >> e[i].b;
    while(k --)
    {
        int x;
        cin >> x;
        for(int i = 1; i <= n; i ++) p[i] = i;
        int num = n - 1;
        for(int i = 1; i <= m; i ++) 
        {
            if(e[i].a != x && e[i].b != x)
            {
                int pa = find(e[i].a), pb = find(e[i].b);
                if(pa != pb)
                {
                    num --;
                    p[pa] = pb;
                } 
            }
        }
        printf("%d\n", num -1);
    }
}