/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-22 08:28:56
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-22 08:29:01
 * @FilePath: \AcWing\堆\堆路径.cpp
 * @Description: 深度优先，路径生成
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
int h[N];
int n;
vector<int> path;
bool gt = false, lt = false;
void dfs(int u)
{
    int l = u * 2, r = u * 2 + 1;
    path.push_back(h[u]);
    if(l > n)
    {
        cout << path[0];
        for(int i = 1; i < path.size(); i ++)
        {
            cout << " " <<path[i];
            if(path[i] > path[i - 1]) lt = true;
            else gt = true;
        }
        cout << endl;
    }
    if(r <= n) dfs(r);
    if(l <= n) dfs(l);
    path.pop_back();
    
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)  cin >> h[i];
    dfs(1);
    if(gt && lt)  printf("Not Heap\n");
    else if(gt)   printf("Max Heap\n");
    else printf("Min Heap\n");
    return 0;
}