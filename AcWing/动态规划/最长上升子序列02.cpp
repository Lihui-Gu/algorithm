/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-28 20:53:36
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-28 20:53:40
 * @FilePath: \AcWing\动态规划\最长上升子序列02.cpp
 * @Description: 登山问题，先上升，后下降
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int f[N], g[N], a[N];

int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)  cin >> a[i];
    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j ++)
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
    }
    
    for(int i = n; i >= 1; i --)
    {
        g[i] = 1;
        for(int j = n; j > i; j --)
            if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1);
    }
    int res = 0; 
    for(int i = 1; i <= n; i ++) res = max(res, f[i] + g[i] - 1);
    cout << res << endl;
    return 0;
    
}