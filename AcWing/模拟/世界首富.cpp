/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-25 21:36:03
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-25 21:36:06
 * @FilePath: \AcWing\模拟\世界首富.cpp
 * @Description: 重写运算符函数，结构体定义，多路索引排序
 * 
 * Copyright (c) 2022 by 顾立辉 glh9803@outlook.com, All Rights Reserved. 
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 210;

struct Person
{
    string name;
    int age, w;
    
    bool operator < (const Person& t) const
    {
        if(w != t.w)  return w > t.w;
        else if(age != t.age) return age < t.age;
        else return name < t.name;
    }
};
vector<Person> ages[N];

int idx[N];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    char name[10];
    for(int i = 0; i < n; i ++)
    {
        int age, w;
        scanf("%s%d%d", name, &age, &w);
        ages[age].push_back({name, age, w});
    }
    for(auto &age : ages) sort(age.begin(), age.end());
    for(int C = 1;  C<= m; C ++)
    {
        printf("Case #%d:\n", C);
        bool exist = false;
        int cnt, min_age, max_age;
        scanf("%d%d%d", &cnt, &min_age, &max_age);
        memset(idx, 0, sizeof idx);
        
        while(cnt --)
        {
            int t = -1;
            for(int i = min_age; i <= max_age; i ++)
            {
                if(idx[i] < ages[i].size())
                    if(t == -1 || ages[i][idx[i]] < ages[t][idx[t]])
                        t = i;
            }
            
            if(t == -1) break;
            auto& p = ages[t][idx[t]]; 
            idx[t] ++;
            printf("%s %d %d\n", p.name.c_str(), p.age, p.w);
            exist = true;
        }


        if(!exist) puts("None");
    }
    return 0;
}