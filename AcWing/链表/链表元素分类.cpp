#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N];
int h, n, k;

int main()
{
    scanf("%d%d%d", &h, &n, &k);
    for(int i = 0; i < n; i ++)
    {
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);
        e[address] = data; ne[address] = next;
    }
    vector<int> a, b, c;
    
    for(int i = h; ~i; i = ne[i])
    {
        if(e[i] < 0)    a.push_back(i);
        else if(e[i] <= k)  b.push_back(i);
        else c.push_back(i);
    }
    a.insert(a.end(), b.begin(), b.end());
    a.insert(a.end(), c.begin(), c.end());
    for(int i = 0; i < a.size(); i++)
    {
        printf("%05d %d ", a[i], e[a[i]]);
        if(i == a.size() - 1)   printf("-1\n");
        else    printf("%05d\n", a[i+1]);
    }
    return 0;
}