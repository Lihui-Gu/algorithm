/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-26 12:20:37
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-26 12:20:42
 * @FilePath: \AcWing\栈\弹出队列.cpp
 * @Description: 栈的应用
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <stack>
using namespace std;
const int N = 1010;
int m, n, k;
int a[N];
bool check()
{
    stack<int> stk;
    for(int i = 1, j = 0; i <= n; i++)
    {
        stk.push(i);
        if(stk.size() > m) return false;
        while(stk.size() && a[j] == stk.top())
        {
            j ++;
            stk.pop();
        }
    }
    return stk.empty();
}
int main()
{
    scanf("%d%d%d", &m, &n, &k);
    while(k --)
    {
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
        if(check()) puts("YES");
        else puts("NO");
    }
    return 0;
}