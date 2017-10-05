#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int arr[101];
int n,k;
long long int dp [1000001];


void input()
{
    scanf("%d %d", &n,&k);
    for (int i = 0 ; i<k;i++)
        scanf("%d",&arr[i]);

    memset(dp,-1,sizeof(dp));
}
long long int solve (long long int n1)
{
    if (n1 < 0) return 0;
    if (n1 == 0) return 1;

    if (dp[n1] != -1) return dp[n1];

    long long int ans = 0;

    for (int i = 0; i<k;i++)
    {
        ans += solve(n1 - arr[i]);
        ans %= 1000003; // след всяко сумиране, а не при return !!!
    }

    return dp[n1] = ans;
}
int main ()
{
    input();
    printf("%d\n",solve(n));
    return 0;
}
