/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-27 10:35:32
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-27 10:35:35
 * @FilePath: \AcWing\哈希\电话聊天狂人.cpp
 * @Description: Map STL的使用，默认是按照first升序
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <map>
using namespace std;
map<string, int> person;
int n;
int main()
{
    cin >> n;
    while(n --)
    {
        string x, y;
        cin >> x >> y;
        auto p1 = person.find(x);
        if(p1 == person.end())  person.insert(pair<string, int>(x, 1));
        else  p1 -> second ++;
        auto p2 = person.find(y);
        if(p2 == person.end())  person.insert(pair<string, int>(y, 1));
        else  p2 -> second ++;
    }
    string res;
    int cnt = 0, sum = 0;
    for(auto i : person) 
    {
        if(cnt < i.second) 
        {
            res = i.first;
            cnt = i.second;
            sum = 1;
        }
        else if(cnt == i.second) sum ++;
    }
    if(sum > 1) cout << res << " " << cnt << " " << sum << endl;
    else cout << res << " " << cnt << endl;
    return 0;
}