#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n;
const int N = 100010;
unordered_set<int> S;

int main()
{
    cin >> n;
    while(n --)
    {
        int x;
        scanf("%d", &x);
        if(x > 0)
        {
            S.insert(x);
        }
    }
    for(int i = 1; i <= N; i++)
    {
        if(!S.count(i))
        {
            cout << i <<endl;
            break;
        }
    }
    return 0;
}