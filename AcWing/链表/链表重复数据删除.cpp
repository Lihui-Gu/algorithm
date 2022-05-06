#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N];
bool st[N];
int h, n;

int main()
{
    scanf("%d%d", &h, &n);
    for(int i = 0; i < n; i ++)
    {
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);
        e[address] = data, ne[address] = next;
    }
    vector<int> a, b;
    for(int i = h; ~i; i = ne[i])
    {
        if(!st[abs(e[i])])   
        {
            st[abs(e[i])] = true;
            a.push_back(i);
        }
        else    b.push_back(i);
    }

    
    for(int i = 0; i < a.size(); i ++)
    {
        printf("%05d %d ", a[i], e[a[i]]);
        if(i == a.size() - 1)   puts("-1");
        else printf("%d\n", a[i+1]);
    }
    for(int i = 0; i < b.size(); i ++)
    {
        printf("%05d %d ", b[i], e[b[i]]);
        if(i == b.size() - 1)   puts("-1");
        else printf("%05d\n", b[i+1]);
    }
    return 0;
}