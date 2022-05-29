/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-29 20:01:56
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-29 20:01:59
 * @FilePath: \PAT\1166.cpp
 * @Description: 邻接表灵活使用
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 210;
int d[N][N];
bool st[N];
int n, m, k;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b;
        d[a][b] = d[b][a] = 1;
    }
    cin >> k;
    for(int p = 1; p <= k; p ++)
    {
        int l, a[N];
        bool success = true;
        memset(st, 0, sizeof st);
        cin >> l;
        for(int i = 1; i <= l; i ++)  
        {
            cin >> a[i];
            st[a[i]] = true;
        }
        for(int i = 1; i <= l; i ++)
            for(int j = 1; j < i; j ++)
            {
                if(!d[a[i]][a[j]])   
                {
                    success = false; 
                    break;
                }
            }
        if(!success)  printf("Area %d needs help.\n", p);
        else
        {
            int res = 0x3f3f3f3f;
            for(int i = 1; i <= n; i ++)  //遍历列
            {
                bool find = true;
                for(int j = 1; j <= l; j ++)
                    if(!d[a[j]][i]) 
                    {
                        find = false;
                        break;
                    }
                if(find && !st[i]) res = min(res, i); 
            }
            if(res == 0x3f3f3f3f) printf("Area %d is OK.\n", p);
            else printf("Area %d may invite more people, such as %d.\n", p, res);
        }
    }
    return 0;
}