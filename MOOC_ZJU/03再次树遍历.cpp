/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 20:32:37
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 20:32:50
 * @FilePath: \MOOC_ZJU\03再次树遍历.cpp
 * @Description: 已知前序中序，求后序
 *  */
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1010;
int pos[N], in[N], pre[N];
int l[N], r[N];
int n;
stack<int> stk;
bool is_first = true;
int build(int il, int ir,int pl, int pr)
{
    int root = pre[pl];
    int k = pos[root];
    if(il < k) l[root] = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
    if(k < ir) r[root] = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);
    return root;
}
void dfs(int u)
{
    if(l[u])  dfs(l[u]);
    if(r[u])  dfs(r[u]);
    if(is_first) 
    {
        is_first = false;
        cout << u;
    }
    else cout << " " << u;
    return;
}
int main()
{
    int pre_idx = 0, in_index = 0;
    cin >> n;
    string op;
    cin >> op;
    if(op == "Push")
    {
        int x;
        cin >> x;
        stk.push(x);
        pre[pre_idx ++] = x;
    }
    while(!stk.empty() || pre_idx < n)
    {
        cin >> op;
        if(op == "Push")
        {
            int x;
            cin >> x;
            stk.push(x);
            pre[pre_idx ++] = x;
        }
        else
        {
            int x;
            x = stk.top();
            stk.pop();
            in[in_index ++] = x;
        }
    }
    for(int i = 0; i < n; i ++)
        pos[in[i]] = i;
    int root = build(0, n - 1, 0, n - 1);
    dfs(root);
    cout << endl;
    return 0;
}