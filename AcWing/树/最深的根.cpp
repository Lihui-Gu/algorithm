#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u, int father)
{
    int depth = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;
        depth = max(depth, dfs(j, u) + 1);
    }
    return depth;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    int k = n;
    for(int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b))
        {
            k -- ;
            p[find(a)] = find(b);
        }
        add(a, b), add(b, a);
    }

    if(k > 1) printf("Error: %d components", k);
    else
    {
        vector<int> v;
        int max_depth = -1;
        for(int i = 1; i <= n; i ++ )
        {
            int depth = dfs(i, -1);
            if(depth > max_depth)
            {
                max_depth = depth;
                v.clear();
                v.push_back(i);
            }
            else if(depth == max_depth)
                v.push_back(i);
        }
        for(auto i : v) cout << i << endl;
    }
    return 0;
}