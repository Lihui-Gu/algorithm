/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-29 20:57:32
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-29 20:57:36
 * @FilePath: \PAT\1003.cpp
 * @Description: 紧急情况，最短路径的应用
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1100;
int d[N][N], dist[N];
int sum[N], cnt[N], w[N];
bool st[N];
int n, m, S, T;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0, sum[S] = w[S], cnt[S] = 1;
    for(int i = 0; i < n; i ++)
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
                sum[j] = sum[t] + w[j];
                cnt[j] = cnt[t];
            }
            else if(dist[j] == dist[t] + d[t][j])
            {
                sum[j] = max(sum[j], sum[t] + w[j]);
                cnt[j] += cnt[t];
            }
        }
    }
    cout << cnt[T] << " " << sum[T] << endl;
}

int main()
{
    cin >> n >> m >> S >> T;
    memset(d, 0x3f, sizeof d);
    for(int i = 0; i < n; i ++)  cin >> w[i];
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }
    dijkstra();
    return 0;
}