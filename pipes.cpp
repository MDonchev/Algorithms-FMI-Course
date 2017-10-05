#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
int t;
int a[10000];
int countPieces(int len)
{
    int cnt = 0;
    for (int i=0; i<n; i++)
        cnt+=(a[i]/len);
    return cnt;
}
void solve()
{
    int left=1, right = 10000000;
    int mid = left + (right - left)/2;
    int ans = 0;
    while (left<=right)
    {
        int counter = countPieces(mid);
        if (counter >= k)
        {
            left = mid +1;
            ans = mid;
        }
        else right = mid - 1;
        mid = left + (right - left)/2;
    }
    printf("%d\n", ans);
}

void in()
{
    scanf("%d",&t);
    for (int j=0; j<t; j++)
    {
        scanf("%d %d", &n, &k);
        for (int i = 0; i<n; i++)
            scanf("%d", &a[i]);
        solve();
    }
}
int main()
{
    in();
    return 0;
}
