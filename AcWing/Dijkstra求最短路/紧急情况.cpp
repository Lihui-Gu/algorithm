/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-25 23:15:58
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-25 23:16:01
 * @FilePath: \AcWing\Dijkstra求最短路\紧急情况.cpp
 * @Description: 最短路径的应用
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
using namespace std;

const int N = 550;
int d[N][N];
int dist[N], w[N];
bool st[N];
int sum[N], cnt[N];
int n, m, S, T;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0, sum[S] = w[S], cnt[S] = 1;
    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 0; j < n; j ++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;
        for(int j = 0; j < n; j ++)
        {
            if(dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
                cnt[j] = cnt[t];
                sum[j] = sum[t] + w[j];
            }
            else if(dist[j] == dist[t] + d[t][j])
            {
                cnt[j] += cnt[t];
                sum[j] = max(sum[j], sum[t] + w[j]);
            }
        }
    }
}


int main()
{
    memset(d, 0x3f, sizeof d);
    cin >> n >> m >> S >> T;
    for(int i = 0; i < n; i ++) cin >> w[i]; 
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    dijkstra();
    cout << cnt[T] << " " << sum[T] << endl;
    return 0;
    
}
