#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N  = 10010;

int n;
set<int> S;

int get(int x)
{
    int obj = 0;
    while(x)
    {
        obj += x % 10;
        x /=10;
    }
    return obj;
}
int main()
{
    cin >>n;
    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        S.insert(get(x));
    }
    cout<< S.size() << endl;
    
    bool is_first = true;
    for(auto x : S) 
    {
        if(is_first)
        {
            cout << x ;
            is_first = false;
        }
        else    cout<< " " << x;
    }
    return 0;
}