#include <iostream>
using namespace std;
const int N = 10010;
int h[N];
int s, n, m;
int cnt = 0;
bool is_prime(int x)
{
    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0)  return false;
    }
    return true;
}

int find(int x)
{
    int k;
    for(int i = 0; i < s; i ++)
    {
        cnt ++;
        k = (x + i * i) % s;
        if(!h[k] || h[k] == x)  return k;
    }
    return -1;
}
int main()
{
    scanf("%d%d%d", &s, &n, &m);
    while(!is_prime(s)) s ++;
    
    while(n --)
    {
        int x;
        scanf("%d", &x);
        int k = find(x);
        if(k != -1)
        {
            h[k] = x;
        } 
        else printf("%d cannot be inserted.\n", x);
    }
    int res = 0;
    for(int i = 0; i < m; i ++)
    {
        int x;
        cnt = 0;
        scanf("%d", &x);
        int k = find(x);
        if(k == -1) cnt = s + 1;
        res += cnt;
    }
    printf("%.1lf", (double) res / m);
    return 0;
}