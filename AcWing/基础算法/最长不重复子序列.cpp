/**
 * @file 最长不重复子序列.cpp
 * @author Lihui Gu (glh9803@outlook.com)
 * @brief 双指针算法
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

const int N = 100010;

int a[N], s[N];
int n;
int main()
{
    scanf("%d",&n);
    int res = 0;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    
    for(int i = 0, j = 0; i < n; i ++)
    {
        s[a[i]] ++;
        while(s[a[i]] > 1)
        {
            s[a[j]] --, j ++;
        }
        res = max(res, i - j + 1);
    }
    printf("%d\n", res);
    return 0;
}