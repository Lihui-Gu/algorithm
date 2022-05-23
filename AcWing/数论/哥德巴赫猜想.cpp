/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-01 19:20:24
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-23 13:59:53
 * @FilePath: \AcWing\筛质数\哥德巴赫猜想.cpp
 * @Description: 线性筛法
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;
int cnt;
int prime[N];
bool st[N];

void init(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i])  prime[cnt ++] = i;
        for(int j = 0; i * prime[j] <= n; j ++)
        {
            if(!st[i * prime[j]])  st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    init(N);
    int k;
    while(cin >> k, k)
    {
        for(int j = 0; j < k; j ++)
        {
            int a = prime[j], b = k - a;
            if(!st[b])
            {
                printf("%d = %d + %d\n", k, a, b);
                break;
            }
        }
    }
    return 0;
    
}