/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-23 16:04:05
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-23 16:04:09
 * @FilePath: \AcWing\数论\序列第k个数 .cpp
 * @Description: 快速幂
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
int n;
const int mod=200907;

LL qmi(int a, int k)
{
    LL res = 1;
    while(k)
    {
        if(k & 1)  res = (LL) (res * a) % mod;
        a = (LL) a * a % mod;
        k >>= 1;
    }
    return res;
}


int main()
{
    cin >> n;
    while(n --)
    {
        int a, b, c, k;
        cin >> a >> b>> c >> k;
        if(a + c == 2 * b) cout << (a + (b - a) * (LL) (k - 1)) % mod << endl;
        else
        {
            cout << (LL) a * qmi(b/a,k-1) % mod << endl;
        }
        
    }
}