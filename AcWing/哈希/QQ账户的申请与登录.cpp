/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 09:54:55
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 09:56:18
 * @FilePath: \AcWing\哈希\QQ账户的申请与登录.cpp
 * @Description: map的灵活使用，判断某个键是否存在，查找某个键对应的值，如何插入，插入是否成功
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 100010;
int n;
map<string, string> user;
int main()
{
    scanf("%d", &n);
    while(n --)
    {
        string op, qq, psw;
        cin >> op >> qq >> psw;
        if(op == "L")
        {
            auto p = user.find(qq);  //如果没有找到，返回迭代器尾部
            if(p == user.end()) cout << "ERROR: Not Exist" << endl;
            else if(p -> second == psw) cout << "Login: OK" << endl;
            else cout << "ERROR: Wrong PW" << endl;
        }
        else
        {
            auto p = user.insert(pair<string, string>(qq, psw));
            if(p.second)  cout << "New: OK" << endl;  //返回的是一个pair，第二个元素代表是否插入成功
            else  cout << "ERROR: Exist" << endl;
        }
    }
    return 0;
}