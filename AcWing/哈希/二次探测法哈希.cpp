#include <iostream>
using namespace std;

const int N = 10010;
int h[N];
int s, n;

bool is_prime(int x)
{
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int find(int x)
{
    int k;
    for(int i = 0; i < s; i ++)
    {
        k = (x + i * i) % s;
        if(!h[k]) return k;
    }
    return -1;
}

int main()
{
    cin >> s >> n;
    while(!is_prime(s)) s ++;
    while(n --)
    {
        int x;
        scanf("%d", &x);
        int k = find(x);
        if(k != -1)
        {
            h[k] = x;
            printf("%d ", k);
        }
        else  printf("- ");
    }
    return 0;
}

