#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
int e[N], ne[N];
int st[N];

int h1, h2, n;

int main()
{
    scanf("%d%d%d", &h1, &h2, &n);
    while(n --)
    {
        int address, next;
        char data;
        scanf("%d %c %d", &address, &data, &next);
        e[address] = data, ne[address] = next;
    }
    for(int i = h1; ~i; i = ne[i])
    {
        st[i] = true;
    }
    bool success;
    for(int i = h2; ~i; i = ne[i])
    {
        if(st[i]) 
        {
            success = true;
            printf("%05d\n", i);
            break;
        }
    }
    if(!success) puts("-1");
    return 0;
}