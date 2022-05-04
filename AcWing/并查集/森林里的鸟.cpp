#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10010;
int n;
int birds[10];
int p[N];
bool st[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n;
    for(int i = 0; i < N; i ++) p[i]=i;
    int cnt = 0;
    for(int i = 0; i < n; i ++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> birds[j];
            st[birds[j]] = true;
        }
        for(int j = 1; j < k; j ++)
        {
            int a = birds[j - 1], b = birds[j];
            int pa = find(a), pb = find(b);
            if(pa != pb)
            {
                p[pa] = pb;
                cnt ++;
            }
        }
    }
    int tot = 0;
    for (int i = 0; i < N; i ++ ) tot += st[i];
    printf("%d %d\n", tot - cnt, tot);
    int m;
    cin >> m;
    while(m --)
    {
        int a, b;
        cin >> a >>b;
        int pa = find(a), pb = find(b);
        if(pa == pb)  printf("Yes\n");
        else  printf("No\n");
    }
    return 0;
}