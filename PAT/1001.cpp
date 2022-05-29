/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-29 17:09:01
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-29 17:09:08
 * @FilePath: \PAT\1001.cpp
 * @Description: 简单处理
 */
#include <iostream>
#include <cstring>
using namespace std;
int a, b, c, d;

int main()
{
    cin >> a >> b;
    c = a + b;
    d = abs(c);
    string res = "";
    int i = 0;
    while(d)
    {
        if(i % 3 == 0 && i) res = "," + res;
        res = to_string(d % 10) + res;
        d /= 10;
        i ++;
    }
    if(c == 0)  cout << "0" << endl;
    else 
    {
        if(c < 0) res = "-" + res;
        cout << res << endl;
    }
    return 0;
}