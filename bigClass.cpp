#include <iostream>
#include <cstdio>

struct Students
{
    char name[16];
    long long int counter;
};

Students stud[100001];
long long sumArr[100001];
int n,m;
void input()
{
    scanf("%d %d",&n,&m);
    scanf("%s %lld",&stud[0].name,&stud[0].counter);
    sumArr[0] = stud[0].counter;
    for (int i = 1;i < n; i++)
    {
        scanf("%s %lld",&stud[i].name,&stud[i].counter);
        sumArr[i] = sumArr[i - 1] + stud[i].counter;
    }
}
void solve(long long int test)
{
    if (test <= sumArr[0])
    {
        printf("%s\n", stud[0].name);
        return;
    }
    if (test > sumArr[n - 2])
    {
        printf("%s\n", stud[n - 1].name);
        return;
    }
    int left = 0, right = n - 1;
    int mid = left + (right - left)/2;
    while (left <= right)
    {
        if (sumArr[mid - 1] < test && test <= sumArr[mid])
        {
            printf("%s\n", stud[mid].name);
            return;
        }
        if (sumArr[mid] < test)
        {
            left = mid + 1;
        }
        else right = mid - 1;
        mid = left + (right - left)/2;
    }
}
int main ()
{
    long long int help;
    input();
    for (int i =0 ;i<m;i++)
    {
        scanf("%lld", &help);
        solve(help);
    }
    return 0;
}
