/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 21:53:55
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 21:53:57
 * @FilePath: \MOOC_ZJU\10统计工龄.cpp
 * @Description: 最简单的题
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
int h[N];
int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        h[x] ++;
    }
    for(int i = 0; i < N; i ++)
        if(h[i]) cout << i << ":" << h[i] << endl;
    return 0;
}