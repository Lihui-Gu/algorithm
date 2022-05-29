/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-29 22:25:02
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-29 22:25:05
 * @FilePath: \PAT\1004.cpp
 * @Description: 深度优先
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110, M = N * N;
int h[N], e[M], ne[M], idx;
int n, m;
bool st[N];
int depth[N], max_depth = 0;
bool is_leaf[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int d)
{
    max_depth = max(max_depth, d);
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(is_leaf[j])  depth[d + 1] ++;
        dfs(j, d + 1);
    }
}

int main()
{
    cin >> n >> m;
    memset(is_leaf, 1, sizeof is_leaf);
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++)
    {
        int fathor;
        cin >> fathor;
        int k;
        cin >> k;
        while(k --)
        {
            int son;
            cin >> son;
            add(fathor, son);
            st[son] = true;
            is_leaf[fathor] = false;
        }
    }
    int root = 1;
    while(st[root]) root ++;
    if(is_leaf[root]) depth[0] ++;
    dfs(root, 0);
    cout << depth[0];
    for(int i = 1; i <= max_depth; i ++)
    {
        cout << " " << depth[i];
    }
    cout << endl;
    return 0;
}