#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int arr[1000001];
int n;
void input()
{
    scanf("%d",&n);
    for (int i =0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
}
void solve()
{
   int max_so_far = arr[0];
   int curr_max = arr[0];

   for (int i = 1; i < n; i++)
   {
        curr_max = max(arr[i], curr_max+arr[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   printf("%d\n",max(max_so_far,0));
}
int main()
{
    input();
    solve();
    return 0;
}
