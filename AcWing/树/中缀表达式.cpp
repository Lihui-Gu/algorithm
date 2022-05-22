/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-22 12:46:37
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-22 12:46:44
 * @FilePath: \algorithm\AcWing\树\中缀表达式.cpp
 * @Description: 一遍过记录一下，左子树右子树判断是否叶子节点，dfs
 */
#include <iostream>
#include <cstring>
using namespace std;

const int N  = 30;
int n;
string w[N];
int l[N], r[N];
bool st[N], is_leaf[N];

string dfs(int u)
{
    string left, right;
    if(l[u] != -1)
    {
        left = dfs(l[u]);
        if(!is_leaf[l[u]]) left = "(" + left + ")";
    }
    if(r[u] != -1)
    {
        right = dfs(r[u]);
        if(!is_leaf[r[u]]) right = "(" + right + ")";
    }
    
    return left + w[u] + right;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> w[i] >> l[i] >> r[i];
        if(l[i] != -1) st[l[i]] = true;
        if(r[i] != -1) st[r[i]] = true;
        if(l[i] == -1 && r[i] == -1)  is_leaf[i] = true;
    }
    int root = 1;
    while(st[root]) root ++;
    cout << dfs(root) << endl;
    return 0;
}