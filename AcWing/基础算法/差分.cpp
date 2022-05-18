/**
 * @file 差分.cpp
 * @author Lihui Gu (glh9803@outlook.com)
 * @brief 差分——前缀和的逆运算
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int n, m;
const int N = 100010;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)  scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i ++)  insert(i, i, a[i]);
    for(int i = 1; i <= m; i ++)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for(int i = 1; i <= n; i ++)  a[i] = a[i - 1] + b[i];
    for(int i = 1; i <= n; i ++)  printf("%d ", a[i]);
    return 0 ;
}