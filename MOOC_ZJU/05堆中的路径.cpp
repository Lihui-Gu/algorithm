/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 22:57:02
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 22:57:05
 * @FilePath: \MOOC_ZJU\05堆中的路径.cpp
 * @Description: 建堆，这部分还不熟悉，背下来
 */
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], cnt;
int n, k;
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    cin >> n >> k;
    int m = 0;
    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        cnt ++ ;
        m ++ ;
        ph[m] = cnt, hp[cnt] = m;
        h[cnt] = x;
        up(cnt);
    }
    while(m --)
    {
        int x;
        cin >> x;
        while(x)
        {
            if(x == 1) cout << h[x] << endl;
            else cout << h[x] << " ";
            x /= 2;
        }
    }
    return 0;
}