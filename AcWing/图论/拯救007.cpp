/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 14:04:53
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 14:04:56
 * @FilePath: \AcWing\图论\拯救007.cpp
 * @Description: 宽搜，代码24/30，还有一个测试点没有过
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

const int N = 110, M = N * N;
int h[N], e[M], ne[M], idx;
int n, d;
double x[N], y[N];
bool st[N];
int q[N], depth[N], pre[N];

double cal(int a, int b)
{
    return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
} 

int bfs()
{
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i ++)
        if(sqrt(pow(x[i], 2) + pow(y[i], 2)) <= d + 7.5) 
        {
            q[++ tt] = i;
            st[i] = true;
            depth[i] = 1;
        }
    int res = 0;
    bool success = false;
    while(hh <= tt && !success)
    {
        int t = q[hh ++];
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(st[j]) continue;
            depth[j] = depth[t] + 1;
            pre[j] = t;
            if(x[j] + d >= 50 || x[j] - d <= -50 || y[j] + d >= 50 || y[j] - d <= -50)
            {
                res = j;
                success = true;
                break;
            }
            q[++ tt] = j;
            st[j] = true;
        }
    }
    if(!success) return -1;
    return res;
}

int main()
{
    cin >> n >> d;
    memset(h, -1, sizeof h);
    memset(pre, -1, sizeof pre);
    for(int i = 0; i < n; i ++)  cin >> x[i] >> y[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            if(cal(i, j) <= (double) d) add(i, j), add(j, i);
    int res = bfs();
    if(d >= 42.5) cout << "1" << endl;
    else if(res == -1) cout << "0" << endl;
    else
    {
        cout << depth[res] + 1 << endl;
        vector<int> route;
        for(int i = res; ~i; i = pre[i])
            route.push_back(i);
        reverse(route.begin(), route.end());
        for(auto i : route) cout << x[i] << " " << y[i] << endl;
    }
    return 0;
}