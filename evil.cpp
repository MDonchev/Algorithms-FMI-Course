#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
using lli = long long int;
struct Interval
{
    lli left;
    lli right;
    bool operator< (const Interval& other) const
    {
        return left < other.left;
    }
};
lli n;
int m;
Interval intervals[1000000];
void input()
{
    scanf("%lld %d", &n, &m);
    for (int i = 0; i<m; i++)
    {
        scanf("%lld %lld", &intervals[i].left, &intervals[i].right);
    }
}
void solve()
{
    sort(intervals,intervals+m);
    lli counter = 0, currL, currR;
    currL = intervals[0].left;
    currR = intervals[0].right;
    for (int i=1; i<m; i++)
    {
        if(intervals[i].left <= currR)
        {
            currR = max(intervals[i].right, currR);
        }
        else
        {
            counter += (currR - currL + 1);
            currL = intervals[i].left;
            currR = intervals[i].right;
        }
    }
    counter+= (currR-currL+1);
    printf("%lld\n", counter);
}
int main ()
{
    input();
    solve();
    return 0;
}
