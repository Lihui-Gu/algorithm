/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-24 18:35:44
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-24 18:35:48
 * @FilePath: \AcWing\动态规划\最长序列和.cpp
 * @Description: 不够优雅，但是独立完成，动态规划小成
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n;
int f[N], a[N];
int start[N], End[N];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)  scanf("%d", &a[i]);
    int res = -1, st = 1, ed = n;
    f[0] = a[0];
    if(res < f[0])
    {
        res = f[0];
        st = start[0];
        ed = End[0];
    }
    for(int i = 1; i < n; i ++)
    {
        if(f[i - 1] >= 0) 
        {
            f[i] = f[i - 1] + a[i];
            start[i] = start[i - 1];
            End[i] = i;
        }
        else 
        {
            f[i] = a[i];
            start[i] = i;
            End[i] = i;
        }
        if(res < f[i])
        {
            res = f[i];
            st = start[i];
            ed = End[i];
        }
    }
    if(res == -1) cout << "0" << " " << a[0] << " " << a[n - 1] << endl;
    else cout << res << " " << a[st] << " " << a[ed] << endl;
    return 0 ;
}