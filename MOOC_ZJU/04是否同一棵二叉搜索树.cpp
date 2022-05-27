/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 21:43:30
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 21:43:33
 * @FilePath: \MOOC_ZJU\04是否同一棵二叉搜索树.cpp
 * @Description: 判断，没有测试点全过18/25
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int a[N], b[N];
int c[N], d[N], e[N], f[N];
int n, m;
bool check(int a[], int b[], int k)
{
    if(k == 0) return true;
    if(a[0] != b[0]) return false;
    int len1 = 0, len2 = 0, len3 = 0, len4 = 0;
    for(int i = 1; i < k; i ++ )
    {
        if(a[i] < a[0]) c[len1 ++] = a[i];
        else d[len2 ++] = a[i];
        if(b[i] < b[0]) e[len3 ++] = b[i];
        else f[len4 ++] = b[i];
    }
    return check(c, e, len1) && check(d, f, len2);
}

int main()
{
    while(cin >> n, n)
    {
        cin >> m;
        for(int i = 0; i < n; i ++) 
        {
            cin >> a[i];
        }
        while(m --)
        {
            for(int i = 0; i < n; i ++) cin >> b[i];
            if(check(a, b, n)) cout << "Yes" << endl;
            else   cout << "No" << endl;
        }
    }
    return 0;
}