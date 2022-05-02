#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;
const int N = 10010;
int n, m, k;
struct node
{
    int a, b;
}e[N];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        e[i].a = a, e[i].b = b;
    }
    scanf("%d", &k);
    while(k --)
    {
        int color[N];
        unordered_set<int> S;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &color[i]);
            S.insert(color[i]);
        }
        bool success = true;
        for(int i = 0; i < m; i ++)
        {
            if(color[e[i].a] == color[e[i].b]) success = false;
        }
        if(!success) printf("No\n");
        else
        {
            printf("%d-coloring\n", S.size());
        }
    }
    
    return 0;
}


