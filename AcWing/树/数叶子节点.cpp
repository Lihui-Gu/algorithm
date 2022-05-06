#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int h[N], e[N], ne[N], idx;
int cnt[N];
int n, m;
int max_depth = 0;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int depth)
{
    if(h[u] == -1)
    {
        cnt[depth]++;
        if(depth > max_depth) max_depth = depth;
        return;
    }
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j, depth + 1);
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++)
    {
        int id, k;
        cin>> id >> k;
        while(k --)
        {
            int son;
            cin >> son;
            add(id, son);
        }
    }
    
    dfs(1, 0);
    cout << cnt[0];
    for(int i = 1; i <= max_depth; i ++)
    {
        cout << " " << cnt[i]; 
    }
    return 0;
}