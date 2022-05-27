/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 22:29:27
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 22:29:30
 * @FilePath: \AcWing\旅游规划.cpp
 * @Description: 最短路径的应用
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 550;
int dist[N];
int d[N][N];
int n, m, S, D;
int w[N][N];
int sum[N];
bool st[N];
void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0, sum[S] = 0;
    for(int i = 0; i < n - 1; i ++)
    {
        int t = -1;
        for(int j = 0; j < n; j ++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for(int j = 0; j < n; j ++)
        {
            if(dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
                sum[j] = sum[t] + w[t][j];
            }
            else if(dist[j] == dist[t] + d[t][j])
                sum[j] = min(sum[j], sum[t] + w[t][j]);
        }
    }
    cout << dist[D] << " " << sum[D] << endl;
}

int main()
{
    cin >> n >> m >> S >> D;
    memset(d, 0x3f, sizeof d);
    memset(w, 0x3f, sizeof w);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        d[a][b] = d[b][a] = min(d[a][b], c);
        w[a][b] = w[b][a] = min(w[a][b], f);
    }
    dijkstra();
    return 0;
}