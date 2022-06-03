/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-30 09:36:15
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-30 09:36:17
 * @FilePath: \PAT\1005.cpp
 * @Description: map创建和使用
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
string s;
int main()
{
    unordered_map<int, string> m = {{1 , "one"}, {2, "two"}, {3, "three"}, 
                                    {4, "four"}, {5, "five"}, {6, "six"}, 
                                    {7, "seven"}, {8, "eight"}, {9, "nine"}, 
                                    {0, "zero"}};
    cin >> s;
    int sum = 0;
    for(auto i : s)
    {
        sum += i - '0';
    }
    string ans = "";
    bool is_first = true;
    if(sum == 0) cout << "zero" << endl;
    else
    {
        while(sum)
        {
            if(is_first)
            {
                is_first = false;
                ans  = m[sum % 10];
            }
            else ans = m[sum % 10] + " " + ans;
            sum /= 10;
        }
        cout << ans << endl; 
    }

    return 0;
}