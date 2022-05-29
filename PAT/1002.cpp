/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-29 19:02:22
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-29 19:02:25
 * @FilePath: \PAT\1002.cpp
 * @Description: 多项式加法
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
double a[N], b[N], c[N];
int n, m;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int p;
        double q;
        cin >> p >> q;
        a[p] = q;
    }
    cin >> m;
    for(int i = 0; i < m; i ++)
    {
        int p;
        double q;
        cin >> p >> q;
        b[p] = q;
    }
    for(int i = 0; i < N; i ++)
    {
        c[i] = a[i] + b[i];
    }
    int res = 0;
    for(int i = N - 1; i >= 0; i --)   if(c[i]) res ++; 
    printf("%d", res);
    for(int i = N - 1; i >= 0; i --)   
        if(c[i]) printf(" %d %.1f", i, c[i]);
    puts("");
    return 0;
}
