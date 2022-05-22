/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-21 09:55:15
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-21 09:56:28
 * @FilePath: \LeetCode\Roman_To_Integer.cpp
 * @Description: LeetCode打卡第一天
 */
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> map={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for(int i = 0; i <= s.size() - 1; i++)
        {
            if(i == s.size() - 1 || map[s[i]] >= map[s[i + 1]])   sum += map[s[i]];
            else sum -= map[s[i]];
        }
        return sum;
    }
};