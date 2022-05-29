/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-28 20:06:52
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-28 20:06:55
 * @FilePath: \AcWing\动态规划\数字三角模型02.cpp
 * @Description: 最小值的情况，要设边界INF
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int n;
int g[N][N];
int f[N][N];
int main()
{
    cin >> n;
    for(int i = 2; i <= n; i ++)  f[0][i] = INF, f[i][0] = INF;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> g[i][j];
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + g[i][j];
    cout << f[n][n] << endl;
    return 0;
}