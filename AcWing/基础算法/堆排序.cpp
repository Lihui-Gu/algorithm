#include <iostream>
using namespace std;
const int N = 100010;
int h[N];
int n, m, cnt;
void down(int u)
{
    int t = u;
    if(2 * u <= cnt && h[2 * u] < h[t]) t = 2 * u;
    if(2 * u + 1 <= cnt && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if(u != t)
    {
        swap(h[t], h[u]);
        down(t);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    cnt = n;
    
    for(int i = n / 2; i; i --) down(i);
    while(m --)
    {
        printf("%d ", h[1]);
        h[1] = h[cnt --];
        down(1);
    }
    puts("");
    return 0;
}