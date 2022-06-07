/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-06-06 15:33:30
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-06-06 15:33:36
 * @FilePath: \PAT\1078.cpp
 * @Description: 二次探测法求哈希
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int h[N];
int s, n;
bool is_prime(int x)
{
    if(x == 1)  return false;
    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0)  return false;
    }
    return true;
}
int find(int x)
{
    int k;
    for(int i = 0; i < s; i ++)
    {
        k = (x + i * i) % s;
        if(!h[k])  return k;
    }
    return -1;
}

int main()
{
    cin >> s >> n;
    bool is_first = true;
    while(!is_prime(s)) s ++;
    for(int i = 0; i < n; i ++)
    {
        int x;
        scanf("%d", &x);
        int k = find(x);
        if(k != -1)
        {
            h[k] = x;
            if(is_first)  
            {
                is_first = false;
                printf("%d", k);
            }
            else printf(" %d", k);
        }
        else
        {
            printf(" -");
        }
    }
    cout << endl;
    return 0;
}