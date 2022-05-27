/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 20:23:17
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 20:25:18
 * @FilePath: \MOOC_ZJU\02一元多项式的乘法与加法运算.cpp
 * @Description: 对应相加，双指针相乘
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int p[N], q[N];
int sum[N], mul[N]; 
int n, m;
int main()
{
    cin >> n;
    int max_p = 0, max_q = 0;
    for(int i = 0; i < n; i ++)
    {
        int a, b;
        cin >> a >> b;
        p[b] = a;
        max_p = max(max_p, b);
    }
    cin >> m;
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b;
        q[b] = a;
        max_q = max(max_q, b);
    }
    for(int i = 0; i <= max(max_p, max_q); i ++)  sum[i] = p[i] + q[i];
    for(int i = 0; i <= max_p; i ++)
        for(int j = 0; j <= max_q; j ++)
            mul[i + j] += p[i] * q[j];
    bool is_first = true, is_none = true;
    for(int i = max_p + max_q; i >= 0; i --)
    {
        if(is_first && mul[i])
        {
            cout << mul[i] << " " << i;
            is_first = false;
            is_none = false;
        }
        else if(mul[i]) cout <<" "<< mul[i] << " " << i; 
    }
    if(is_none) cout << "0" << " " << "0";
    cout << endl;
    
    is_first = true, is_none = true;
    for(int i = max(max_p, max_q); i >= 0; i --) 
    {
        if(is_first && sum[i]) 
        {
            is_first = false;
            is_none = false;
            cout << sum[i] << " " << i;
        }
        else if(sum[i]) cout << " " << sum[i] << " " << i;
    }
    if(is_none) cout << "0" << " " << "0";
    cout << endl;
    return 0;
}