#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
unordered_set<int> S[55];
int n, m;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        int k;
        scanf("%d", &k);
        while(k --)
        {
            int a;
            scanf("%d", &a);
            S[i].insert(a);
        }
    }
    scanf("%d", &m);
    while(m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int nc = 0, nt = 0;
        for(auto x : S[a]) nc += S[b].count(x);
        nt = S[a].size() + S[b].size() - nc;
        printf("%.1f \%\n", (double) nc / nt * 100);
    }
    return 0;
}