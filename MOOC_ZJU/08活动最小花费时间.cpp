/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-28 10:26:42
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-28 10:26:46
 * @FilePath: \MOOC_ZJU\08活动最小花费时间.cpp
 * @Description: 拓扑排序的应用
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110, M = N * N / 2;
int h[N], e[M], ne[M], idx;
int w[N][N], q[N], f[N];
int d[N];
bool st[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void topsort()
{
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i ++)  
        if(!d[i])  
        {
            st[i] = true;
            q[++ tt] = i;
        }
    if(tt == -1)
    {
        cout << "Impossible" << endl;
        return;
    }
    while(hh <= tt)
    {
        int t = q[hh ++];
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            f[j] = max(f[j], f[t] + w[t][j]);
            if(-- d[j] == 0)   q[++ tt] = j;
        }
    }
    if(tt != n - 1)  
    {
        cout << "Impossible" << endl;
        return;
    }
    int res = -1;
    for(int i = 0; i < n; i ++) res = max(res, f[i]);
    cout << res << endl;
    return;
}

int main()
{
    cin >> n >> m;
    memset(w, 0x3f, sizeof w);
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b);
        w[a][b] = min(w[a][b], c);
        d[b] ++;
    }
    topsort();
    return 0;
}