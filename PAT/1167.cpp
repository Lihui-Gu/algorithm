/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-29 17:39:21
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-29 17:39:30
 * @FilePath: \PAT\1167.cpp
 * @Description: 最小堆，建立二叉树方式，理解，大成
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 50;
int n;
int in[N];
int q[N];
unordered_map<int, int> l, r, pos;
int find(int il, int ir)
{
    int res = 0x3f3f3f3f;
    for(int i = il; i <= ir; i ++) res = min(res, in[i]);
    return res;
}

int build(int il, int ir)
{
    int root = find(il, ir);
    int k = pos[root];
    if(k > il)   l[root] = build(il, k - 1);
    if(k < ir)   r[root] = build(k + 1, ir);
    return root;
}

void bfs(int u)
{
    int hh = 0, tt = 0;
    q[0] = u;
    while(hh <= tt)
    {
        int t = q[hh ++];
        if(l.count(t))  q[++ tt] = l[t];
        if(r.count(t))  q[++ tt] = r[t];
    }
    cout << q[0];
    for(int i = 1; i < n; i ++) cout << " " << q[i];
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)  
    {
        cin >> in[i];
        pos[in[i]] = i;
    }
    int root = build(0, n - 1);
    bfs(root);
    return 0;
}