#include <iostream>
#include <cstring>
using namespace std;
const int N = 100003;
int h[N];
int e[N], ne[N], idx;
void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; ~ i; i = ne[i])
    {
        if(e[i] == x)   return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; i ++)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I')  insert(x);
        else
        {
            if(find(x))  printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}