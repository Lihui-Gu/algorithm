/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-29 21:51:40
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-29 21:51:43
 * @FilePath: \PAT\1165.cpp
 * @Description: 链表的分块翻转， 24/25
 */
#include <iostream>
#include <cstring>
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
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);
        e[address] = data, ne[address] = next;
    }
    vector<int> v;
    for(int i = head; ~i; i = ne[i])
        v.push_back(i);
    vector<int> p[N];
    int idx = 0, sum = 0;
    for(int i = 0; i + k < n; i += k)
    {
        for(int j = i; j < i + k; j ++)
        {
            p[idx].push_back(v[j]);
            sum ++;
        }
        idx ++;
    }
    for(int i = sum; i < n; i ++)
        p[idx].push_back(v[i]);
    vector<int> res;
    for(int i = idx; i >= 0; i --)
        for(int j = 0; j < p[i].size(); j ++) 
        {
            res.push_back(p[i][j]);
        }
    for(int  i = 0; i < res.size(); i ++)
    {
        if(i + 1 != res.size())
            printf("%05d %d %05d\n", res[i], e[res[i]], res[i + 1]);
        else   printf("%05d %d -1\n", res[i], e[res[i]]);
    }

    return 0;
}