/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-28 20:38:45
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-28 20:38:48
 * @FilePath: \AcWing\动态规划\最长上升子序列01.cpp
 * @Description: 统计最长上升与最长下降，得到两者的最大值
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
using namespace std;
const int N = 110;
int a[N];
int f[N], g[N];
int n, m;

int main()
{
    cin >> m;
    while(m --)
    {
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i ++)
        {
            f[i] = 1;
            g[i] = 1;
            for(int j = 1; j < i; j ++)
            {
                if(a[i] < a[j]) f[i] = max(f[i], f[j] + 1);
                if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1);
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i ++) res = max(res, f[i]);
        for(int i = 1; i <= n; i ++) res = max(res, g[i]);
        cout << res << endl;
    }
    return 0;
}