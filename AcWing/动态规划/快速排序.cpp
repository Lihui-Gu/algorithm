/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-22 22:30:49
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-22 22:30:55
 * @FilePath: \AcWing\动态规划\快速排序.cpp
 * @Description: 判定是否为快排的过程中的排列
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> res;
const int N = 100010, INF = 0x3f3f3f3f;
int n;
int q[N], l[N], r[N];


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> q[i];
    for(int i = 1; i < n; i ++) l[i] = max(l[i - 1], q[i]);
    r[n + 1] =  INF;
    for(int i = n; i > 0; i --) r[i] = min(r[i + 1], q[i]);
    vector<int> res;
    for(int i = 1; i <= n; i ++)
    {
        if(q[i] >= l[i - 1] && q[i] <= r[i + 1] ) res.push_back(q[i]);
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " "; 
    }
    cout <<endl;
    return 0;
}