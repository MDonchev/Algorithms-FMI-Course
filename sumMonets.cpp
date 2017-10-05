//count how many ways are there to represent sum = k
#include <iostream>
#include <cstdio>

using namespace std;

int n,s, a[1001], dp[1001];

void in()
{
    scanf("%d %d", &n,&s);
    for (int i =0 ;i<n;i++)
        scanf("%d",&a[i]);
}
void solve()
{
    //count how many ways to represent s whit LIMITED number of every coin
    //cin all coins -> 1 2 3 1 1 not 1 2 3 [3,1,1]
    dp[0] = 1;
    for(int i =0; i< n; i++)
        for (int j = s -a[i]; j>=0; j--)
            dp[j + a[i]] += dp[j];

    printf("%d\n",dp[s]);
    /*
    dp[0] = 1;
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<=s - a[i];j++)
            dp[j+ a[i]] += dp[j];
        /// for (int j = a[i]; j<=s; j++)
        ///     dp[j] += dp[j - a[i]];
    }
    printf("%d\n",dp[s]);
    */
}
int main()
{

    in();
    solve();

}
