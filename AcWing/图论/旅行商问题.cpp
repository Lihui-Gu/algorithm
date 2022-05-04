#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 210, INF = 0x3f3f3f3f;
int d[N][N], vers[310];
int st[N];

int n, m;
int main()
{
    cin >> n >> m;
    memset(d, 0x3f, sizeof d);
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }
    int k;
    cin >> k;
    int min_dist = INF, min_id = -1;
    for(int T = 1; T <= k; T ++ )
    {
        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; i ++ ) cin >> vers[i];

        int sum = 0;
        bool success = true;
        memset(st, 0, sizeof st);
        for (int i = 0; i + 1 < cnt; i ++ )
        {
            int a = vers[i], b = vers[i + 1];
            if (d[a][b] == INF)
            {
                sum = -1;
                success = false;
                break;
            }
            else sum += d[a][b];
            st[a] = true;
        }

        for(int i = 1; i <= n; i ++ )
            if (!st[i])
            {
                success = false;
                break;
            }

        if(vers[0] != vers[cnt - 1]) success = false;

        if(sum == -1) printf("Path %d: NA (Not a TS cycle)\n", T);
        else
        {
            if (!success) printf("Path %d: %d (Not a TS cycle)\n", T, sum);
            else
            {
                if (cnt == n + 1) printf("Path %d: %d (TS simple cycle)\n", T, sum);
                else printf("Path %d: %d (TS cycle)\n", T, sum);

                if (min_dist > sum)
                {
                    min_dist = sum;
                    min_id = T;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", min_id, min_dist);
    return 0;
}