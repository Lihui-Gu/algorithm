/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-17 12:52:26
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-18 08:57:28
 * @FilePath: \AcWing\基础算法\前缀和.cpp
 * @Description: 前缀和的模板
 */

#include <iostream>
using namespace std;

const int N = 100010;
int s[N], a[N];
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    
    while(m --)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}