/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-22 21:37:59
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-22 21:38:02
 * @FilePath: \algorithm\AcWing\树\供应链销售总额.cpp
 * @Description: 深度优先求叶子节点的深度
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 100010;
int p[N], f[N], c[N];
int n;
double P, R;

int dfs(int u)
{
    if(f[u] != -1)  return f[u];
    if(p[u] == -1)  return f[u] = 0;
    return f[u] = dfs(p[u]) + 1;
}


int main()
{
    cin >> n >> P >> R;
    memset(p, -1, sizeof p);
    for(int i = 0; i < n; i ++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j ++)
        {
            int son;
            cin >> son;
            p[son] = i;
        }
        if(!k)  cin >> c[i];
    }
    memset(f, -1, sizeof f);
    double res = 0;
    for(int i = 0; i < n; i ++)
    {  
        if(c[i])  res += c[i] * (pow(1 + R / 100, dfs(i))) * P;
    }
    printf("%.1lf\n", res);
    return 0;
}
