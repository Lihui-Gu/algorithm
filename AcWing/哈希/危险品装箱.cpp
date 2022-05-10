#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int N = 10010;
int a[N], b[N];
unordered_set<int> S;
int n, m;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)  scanf("%d %d", &a[i], &b[i]);
    while(m --)
    {
        S.clear();
        int k;
        scanf("%d", &k);
        while(k --)
        {
            int x;
            scanf("%d", &x);
            S.insert(x);
        }
        int success = true;
        for(int i = 0; i < n; i ++)
        {
            if(S.count(a[i]) && S.count(b[i]))
            {
                success = false;
                break;
            }
        }
        if(success) puts("Yes");
        else puts("No");
    }
    return 0;
}