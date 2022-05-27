/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 20:21:58
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 20:26:54
 * @FilePath: \MOOC_ZJU\01最大子序列和问题.cpp
 * @Description: 动态规划，简单
 */
#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int N = 100010;
int a[N];
int f[N];
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)  scanf("%d", &a[i]);
    f[0] = a[0];
    int res = 0;
    for(int i = 1; i < n; i ++)
    {
        f[i] = max(a[i], f[i - 1] + a[i]);
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}