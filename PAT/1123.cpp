/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-31 15:49:10
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-31 15:49:16
 * @FilePath: \PAT\1123.cpp
 * @Description: AVL, 层序遍历，完全二叉树判断
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int h[N], v[N], l[N], r[N], idx;
int q[N];
int n;
int get_balance(int u)
{
    return h[l[u]] - h[r[u]];
}

void update(int u)
{
    h[u] = max(h[l[u]], h[r[u]]) + 1;
}

void R(int& u)
{
    int p = l[u];
    l[u] = r[p], r[p] = u;
    update(u), update(p);
    u = p;
}

void L(int& u)
{
    int p = r[u];
    r[u] = l[p], l[p] = u;
    update(u), update(p);
    u = p;
}

void insert(int &u, int w)
{
    if(!u) u = ++ idx, v[u] = w;
    else if(w < v[u])
    {
        insert(l[u], w);
        if(get_balance(u) == 2)
        {
            if(get_balance(l[u]) == 1) R(u);
            else L(l[u]), R(u);
        }
    }
    else
    {
        insert(r[u], w);
        if(get_balance(u) == -2)
        {
            if(get_balance(r[u]) == -1) L(u);
            else R(r[u]), L(u);
        }
    }
    update(u);
}

void bfs(int u)
{
    bool find = false, is_compelete = true;
    int hh = 0, tt = 0;        
    q[0] = u;
    while(hh <= tt)
    {
        int t = q[hh ++];
        if(l[t])   q[++ tt] = l[t];
        if(r[t])   q[++ tt] = r[t];
        if(!l[t] && r[t])  is_compelete = false;
        else if(!find && (!l[t] || !r[t]))  find = true;
        else if(find)   if(l[t] || r[t]) is_compelete = false;
    }
    cout << v[q[0]];
    for(int i = 1; i < n; i ++) cout << " " << v[q[i]];
    cout << endl;
    if(is_compelete) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main()
{
    cin >> n;
    int root = 0;
    for(int i = 0; i < n; i ++)
    {
        int m;
        cin >> m;
        insert(root, m);
    }
    bfs(root);
    return 0;
}