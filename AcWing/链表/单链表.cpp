#include <iostream>

using namespace std;

const int N = 100010;

int e[N], ne[N], idx = 0;
int head;
int n;

void init()
{
    head = -1, idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x, ne[idx] = head, head = idx ++;
}
void add_to_k(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
} 

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        char op[2];
        scanf("%s", op);
        if(*op == 'H')
        {
            int x;
            scanf("%d", &x);
            add_to_head(x);
        }
        else if(*op == 'I')
        {
            int k, x;
            scanf("%d %d", &k, &x);
            add_to_k(k - 1, x);
        }
        else
        {
            int k;
            scanf("%d", &k);
            if(!k) head = ne[head];
            else  remove(k - 1);
        }
    }
    for(int i = head; ~i; i = ne[i]) printf("%d ", e[i]);
    return 0;
}