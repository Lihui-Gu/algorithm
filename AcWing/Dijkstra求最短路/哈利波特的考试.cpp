/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 11:13:15
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 11:13:20
 * @FilePath: \AcWing\Dijkstra求最短路\哈利波特的考试.cpp
 * @Description: 最短路径的应用
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int d[N][N], dist[N];
bool st[N];
int n, m;
int dijkstra(int u)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[u]=0;
    for(int i = 0; i < n - 1; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for(int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], dist[t] + d[t][j]);
    }
    int res = -1;
    for(int i = 1; i <= n; i ++)  res = max(res, dist[i]);
    return res;
}

int main()
{
    cin >> n >> m;
    memset(d, 0x3f, sizeof d);
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    int res = 0x3f3f3f3f, animal = 0;
    for(int i = 1; i <= n; i ++)
    {
        int k = dijkstra(i);
        if(res > k)
        {
            res = k;
            animal = i;
        }
    }
    if(res == 0x3f3f3f3f) cout << "0" << endl;
    else cout << animal << " " << res << endl;
    return 0;
}