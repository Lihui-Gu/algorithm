/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-23 15:09:20
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-23 15:09:23
 * @FilePath: \AcWing\数论\阶乘分解.cpp
 * @Description: 分解质因数
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
using namespace std;
const int N = 1000010;

int n;
int cnt;
int prime[N], st[N];


void init(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i])  prime[cnt ++] = i;
        for(int j = 0; i * prime[j] <= n; j ++)
        {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    init(n);
    for(int i = 0; i < cnt; i ++)
    {
        int s = 0;
        int p = prime[i];

        for(int j = n; j; j /= p)  s += j / p;
        printf("%d %d\n", p, s);
    }
    return 0;
}