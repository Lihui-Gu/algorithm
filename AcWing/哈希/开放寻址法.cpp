#include <iostream>
#include <cstring>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
    int k = (x % N + N ) % N;
    while(h[k] != null && h[k] != x)
    {
        k ++;
        if(k == N) k = 0;
    }
    return k;
}

int main()
{
    int n; 
    scanf("%d", &n);
    memset(h, 0x3f, sizeof h);
    for(int i = 0; i < n; i ++)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I') 
        {
            int k = find(x);
            h[k] = x;
        }
        else
        {
            int k = find(x);
            if(h[k] == null) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}