#include <iostream>
#include <cstdio>

int n;
int arr[300002];
int counter = 0;
void input()
{
    scanf("%d", &n);
    for (int i = 0; i<n;i++)
        scanf("%d", &arr[i]);
}
void solve()
{
    int searched = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (searched == arr[i])
        {
            searched--;
            continue;
        }
        counter++;
    }
    printf("%d\n", counter);
}
int main ()
{
    input();
    solve();
    return 0;
}
