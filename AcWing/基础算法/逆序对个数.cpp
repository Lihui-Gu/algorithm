#include <iostream>
using namespace std;

const int N = 100010;
typedef long long LL;
int q[N], tmp[N];

int n;


LL merge_sort(int q[], int l, int r)
{
    if(l >= r) return 0;
    int mid = l + r >> 1;
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k  = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j]) tmp[k ++] = q[i ++];
        else 
        {
            tmp[k ++] = q[j ++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];
    for(int i = l, j =0; i <= r; i ++, j ++) q[i] = tmp[j];
    return res;
    
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    printf("%lld", merge_sort(q, 0, n-1));
    return 0;
}