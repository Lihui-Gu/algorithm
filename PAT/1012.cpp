/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-06-06 23:15:55
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-06-06 23:15:58
 * @FilePath: \PAT\1012.cpp
 * @Description: 最佳排名，纯纯的代码能力，非算法
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
vector<int> q[4];
unordered_map<string, vector<int>> grades;
int n, m;

int get_rank(string id, int i)
{
    int score = grades[id][i];
    int l = 0, r = q[i].size() - 1;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(q[i][mid] <= score) l = mid;
        else r = mid - 1;
    }
    return q[i].size() - r;
}
int get_rank(vector<int>& a, int x)
{
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return a.size() - r;
}

int main()
{
    cin >> n >> m;
    string course[4] = {"A", "C", "M", "E"};
    for(int i = 0; i < n; i ++)
    {
        string id;
        int a, b, c;
        cin >> id >> a >> b >> c;
        int d = round((a + b + c) / 3.0);
        grades[id].push_back(d);
        grades[id].push_back(a);
        grades[id].push_back(b);
        grades[id].push_back(c);
        q[0].push_back(d);
        q[1].push_back(a);
        q[2].push_back(b);
        q[3].push_back(c);
    }
    for(int i = 0; i < 4; i ++)
    {
        sort(q[i].begin(), q[i].end());
    }
    for(int i = 0; i < m; i ++)
    {
        string id;
        cin >> id;
        if(!grades.count(id))  cout << "N/A" << endl;
        else
        {
            int best_rank =0x3f3f3f3f;
            string c;
            for(int i = 0; i < 4; i ++)
            {
                int rank = get_rank(id, i);
                if(best_rank > rank)
                {
                    best_rank = rank;
                    c = course[i];
                }
            }
            cout << best_rank << " " << c << endl;
        }
    }
    return 0;
}
