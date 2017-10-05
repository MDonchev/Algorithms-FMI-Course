#include <iostream>
#include <cstring>
#include <cstdio>
int n;
int ans = 1;
int dp[1001];
int arr[1001];
void input()
{
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void make()
{
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > ans) ans = dp[i];
    }
    printf("%d", ans);
}
int main()
{
    input();
    make();
    return 0;
}
