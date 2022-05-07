#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int h[N], e[N], ne[N], idx;
int q[N], d[N];
int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void topsort()
{
    int hh = 0, tt = -1;
    for(int i =1; i <= n; i ++)  if(!d[i])  q[++ tt] = i;
    while(hh <= tt)
    {
        int t = q[hh ++];
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(-- d[j] == 0)  q[++ tt] = j;
        }
    }
    cout << q[0];
    for(int i = 1; i <= n; i ++)
    {
        cout<< " " << q[i];
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int k;
        while(cin >> k, k)
        {
            add(i, k);
            d[k] ++;
        }
    }
    topsort();
    return 0;
}