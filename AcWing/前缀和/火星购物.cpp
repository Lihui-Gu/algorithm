/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-25 09:40:47
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-25 09:40:51
 * @FilePath: \AcWing\前缀和\火星购物.cpp
 * @Description: 前缀和的应用
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f;

int a[N];
int s[N];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)  
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    int res = INF;
    for(int i = 1, j = 0; i <= n; i ++)
    {
        while(s[i] - s[j + 1] >= m)  j ++;
        if(s[i] - s[j] >= m) res = min(res, s[i] - s[j]);
    }
    for(int i = 1, j = 0; i <=n; i ++)
    {
        while(s[i] - s[j + 1] >= m) j ++;
        if(s[i] - s[j] == res) printf("%d-%d\n", j + 1, i);
    }
    return 0;
}