/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-17 12:29:09
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-18 09:10:22
 * @FilePath: \AcWing\基础算法\高精度加法.cpp
 * @Description: 高精度加法的模板
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> add(vector<int>&A, vector<int>&B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || i < B.size(); i ++)
    {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t = t / 10;
    }
    if(t) C.push_back(1);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0 ; i --)  A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i --)  B.push_back(b[i] - '0');
    auto C = add(A, B);
    for(int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    return 0;
}