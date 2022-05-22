/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-20 21:51:16
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-20 21:51:22
 * @FilePath: \AcWing\动态规划\最大子序列和.cpp
 * @Description: 最大子序列和
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1000010;
LL f[N];
int n;
int main()
{
    scanf("%d", &n);
    LL res = -1e18;
    for(int i = 0; i < n; i ++) scanf("%lld", &f[i]);
    for(int i = 1; i < n; i ++)
    {
        f[i] = max(f[i - 1] + f[i], f[i]); 
        if(res < f[i])  res = f[i];
    }
    printf("%lld\n", res);
    return 0;
}