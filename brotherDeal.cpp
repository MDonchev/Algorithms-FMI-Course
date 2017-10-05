#include <iostream>
#include <cstdio>
using namespace std;

int n, a[1001];
bool can[1001];
void in()
{
    scanf("%d",&n);
    for (int i = 0; i<n;i++)
        scanf("%d",&a[i]);
}
void solve()
{
    can[0] = true;
    for (int i = 0; i<n;i++)
    {
        for (int j = s; j>=0; j--)
            can[j] |= can[j - a[i]];
    }
    for (int i = s/2; i>=0; i--)
        if(can[i])
        {
            printf("%d\n",(s - i) - i);
            break;
        }
}
int main()
{
    in();
    solve();
}
