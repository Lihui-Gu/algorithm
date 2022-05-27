/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 20:31:25
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 20:31:34
 * @FilePath: \MOOC_ZJU\03数叶子节点.cpp
 * @Description: 宽度优先找叶子
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20;
int l[N], r[N];
int n;
int q[N];
bool st[N];
bool is_first = true;

void bfs(int u)
{
    int hh = 0, tt = 0;
    q[0] = u;
    while(hh <= tt)
    {
        int t = q[hh ++];
        if(l[t] != -1)  q[++ tt] = l[t];
        if(r[t] != -1)  q[++ tt] = r[t];
        if(l[t] == -1 && r[t] == -1) 
        {
            if(is_first)
            {
                printf("%d", t);
                is_first = false;
            }
            else printf(" %d", t);
        }
    }
}


int main()
{
    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i = 0; i < n; i ++)
    {
        char a, b;
        cin >> a >> b;
        if(a != '-')
        {
            st[a - '0'] = true;
            l[i] = a - '0';
        }
        if(b != '-')
        {
            st[b - '0'] = true;
            r[i] = b - '0';
        }
    }
    int root = 0;
    while(st[root]) root ++;
    bfs(root);
    printf("\n");
    return 0;
}