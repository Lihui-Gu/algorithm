/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-25 08:32:48
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-25 08:32:52
 * @FilePath: \AcWing\模拟\切整数.cpp
 * @Description: 字符串处理，考虑除以0特殊情况
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int num1 = 0, num2 = 0;
        string nums = "";
        cin >> nums;
        int mid = nums.size() / 2;
        for(int i = 0; i < mid; i ++)  num1 = num1 * 10 + nums[i] - '0';
        for(int i = mid; i < nums.size(); i ++)  num2 = num2 * 10 + nums[i] - '0';
        if(num2 == 0) 
        {
            puts("No");
            continue;
        }
        if ((LL)(num1 * pow(10, mid) + num2) % (LL)(num1 * num2) == 0)   puts("Yes");
        else puts("No");
    }
    return 0;
}