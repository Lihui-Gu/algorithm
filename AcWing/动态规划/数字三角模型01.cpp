/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-28 19:53:51
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-28 19:53:55
 * @FilePath: \AcWing\动态规划\数字三角模型01.cpp
 * @Description: 最简单的摘花生
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int n, r, c;
int f[N][N], g[N][N];
int main()
{
    cin >> n;
    while(n --)
    {
        cin >> r >> c;
        for(int i = 1; i <= r; i ++)
            for(int j = 1; j <= c; j ++)
                cin >> g[i][j];
        for(int i = 1; i <= r; i ++)
            for(int j = 1; j <= c; j ++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
        cout << f[r][c] << endl;
    }
}