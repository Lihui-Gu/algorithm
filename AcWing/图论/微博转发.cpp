#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1010, M = 100010;

int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
int bfs(int start)
{
    queue<int> q;
    memset(st, 0, sizeof st);
    q.push(start);
    st[start] = true;
    int res = 0;
    for(int step = 0; step < m; step ++ )
    {
        int sz = q.size();
        for(int i = 0; i < sz; i ++ )
        {
            int t = q.front();
            q.pop();
            
            for(int j = h[t]; ~j; j = ne[j])
            {
                int k = e[j];
                if(!st[k])
                {
                    st[k] = true;
                    q.push(k);
                    res ++;
                }
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++ )
    {
        int cnt;
        scanf("%d", &cnt);
        while (cnt -- )
        {
            int x;
            scanf("%d", &x);
            add(x, i);
        }
    }
    int k;
    scanf("%d", &k);
    while(k -- )
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", bfs(x));
    }
    return 0;
}