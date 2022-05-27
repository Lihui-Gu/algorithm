#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10010;
int Start[N], End[N];
int a[N];
int f[N];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    f[0] = a[0];
    int res = -1;
    int st = 0, ed = n - 1;
    for(int i = 0; i < n; i ++)
    {
        if(f[i - 1] < 0)
        {
            f[i] = a[i];
            Start[i] = i;
            End[i] = i;
        }
        else
        {
            f[i] = f[i - 1] + a[i];
            Start[i] = Start[i - 1];
            End[i] = i;
        }
        if(res < f[i])
        {
            res = f[i];
            st = Start[i];
            ed = End[i];
        }
    }
    if(res < 0)  cout << "0" << " " << a[0] << " " << a[n - 1] << endl;
    else cout << res << " " << a[st] << " " << a[ed] << endl;
    return 0;
}