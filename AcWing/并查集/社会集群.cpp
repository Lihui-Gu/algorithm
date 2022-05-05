#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
int p[N];
int n;
int cnt[N];
vector<int> hobby[N];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int cnt;
        scanf("%d:", &cnt);
        while (cnt -- )
        {
            int h;
            cin >> h;
            hobby[h].push_back(i);
        }
    }
    
    for(int i = 0; i < n; i ++) p[i] = i;
    
     for (int i = 1; i <= 1000; i ++ )
        for (int j = 1; j < hobby[i].size(); j ++ )
        {
            int a = hobby[i][0], b = hobby[i][j];
            p[find(a)] = find(b);
        }
        
    for(int i = 0; i < n; i ++) cnt[find(i)] ++;
    int k = 0;
    for(int i = 0; i < n; i ++) 
    {
        if(cnt[i]) k++;
    }
    
    cout << k <<endl;
    
    sort(cnt, cnt + n, greater<int>());
    cout << cnt[0];
    for(int i = 1; i < k; i ++)
    {
        cout << " " << cnt[i]; 
    }
    return 0;
}