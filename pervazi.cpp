#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,arr[501],sum[501],dp[501][501];

void input()
{
    scanf("%d",&n);
    scanf("%d",&arr[0]);
    sum[0] = arr[0];
    for (int i = 1; i< n; i++)
    {
        scanf("%d",&arr[i]);
        sum[i] = sum[i-1] + arr[i];
    }
}

int solve(int i, int j)
{
    if (i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = 2000000000;
    for (int k = i; k < j; k++)
        ans = min(ans, sum[j] - sum[i] + arr[i] + solve(i,k) + solve(k + 1,j));

    return dp[i][j] = ans;
}
int main ()
{
    memset(dp, -1, sizeof(dp));
    input();
    printf("%d\n", solve(0,n - 1));
    return 0;
}
