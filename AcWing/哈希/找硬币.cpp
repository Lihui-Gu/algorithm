#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int> S;
int m, n;
int main()
{
    scanf("%d %d", &n, &m);
    int res = 0x3f3f3f3f;
    while(n --)
    {
        int x;
        scanf("%d", &x);
        int y = m - x;
        if(S.count(y))
        {
            if(x > y) swap(x, y);
            if(x < res)  res = x;
        }
        else  S.insert(x);
    }
    if(res == 0x3f3f3f3f)    printf("No Solution\n");
    else printf("%d %d\n", res, m - res);
    return 0;
}