/*
 * @Author: 顾立辉 glh9803@outlook.com
 * @Date: 2022-05-30 09:35:39
 * @LastEditors: 顾立辉 glh9803@outlook.com
 * @LastEditTime: 2022-05-30 09:35:41
 * @FilePath: \PAT\1006.cpp
 * @Description: 字符串排序
 */
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;
string id[N], in[N], out[N];
int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)   cin >> id[i] >> in[i] >> out[i];
    int unlock = -1, lock = -1;
    for(int i = 0; i < n; i ++)
    {
        if(unlock == -1 || in[i] < in[unlock])
            unlock = i;
        if(lock == -1 || out[i] > out[lock])
            lock = i;
    }
    cout << id[unlock] << " " << id[lock] << endl;
    return 0;
}