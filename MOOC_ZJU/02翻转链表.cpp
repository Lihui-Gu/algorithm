/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 20:23:01
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 20:25:47
 * @FilePath: \MOOC_ZJU\01最大子序列和问题2.cpp
 * @Description: 翻转链表，k个一转
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N];
int head, n, k;
int main()
{
    cin >> head >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        int address, value, next;
        scanf("%d%d%d", &address, &value, &next);
        e[address] = value, ne[address] = next;
    }
    vector<int> q;
    for(int i = head; ~i; i = ne[i]) q.push_back(i);
    for(int i = 0; i + k - 1< q.size(); i += k)
    {
        reverse(q.begin() + i, q.begin() + k + i);
    }
    for(int i = 0; i < q.size(); i ++)
    {
        if(i + 1 != q.size()) printf("%05d %d %05d\n", q[i], e[q[i]], q[i + 1]);
        else printf("%05d %d -1", q[i], e[q[i]]);
    }
    return 0;
    
}