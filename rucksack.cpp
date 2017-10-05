#include <iostream>
#include <cstdio>
#include <cstring>
int n, w, values[1001], weights[1001];

int dp [1001][1001];

void in()
{
    scanf("%d %d",&n,&w);
    for (int i = 0 ;i < n; i++)
    {
        scanf("%d",&values[i]);
    }
    for (int i = 0 ;i < n; i++)
    {
        scanf("%d",&weights[i]);
    }
}
int solve(int i, int weight)
{
    if (i == n) return 0;

    if (dp[i][weight] != -1) return dp[i][weight];
    if (weight + weights[i] > w) return dp[i][weight] = solve(i + 1, weight);

    return dp[i][weight] = std::max(values[i] + solve(i + 1, weight + weights[i]), solve(i+1, weight));
}
int main()
{
    in();
    std::memset(dp,-1,sizeof(dp));
    printf("%d\n", solve(0,0));
    return 0;
}
