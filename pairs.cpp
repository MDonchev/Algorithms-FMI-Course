#include <iostream>
#include <cstdio>
#include <queue>


using namespace std;


int a,b,c,d;
struct Pair
{
    int first;
    int second;
    Pair(int _a,int _b): first(_a), second(_b){}
};

void solve()
{
    scanf("%d %d %d %d", &a,&b,&c,&d);
    queue<Pair> pq;
    pq.push(Pair(a,b));
    while(!pq.empty())
    {
        if (pq.front().first == c && pq.front().second == d)
        {
            printf("YES\n");
            return;
        }
        else
        {
            pq.push(Pair(pq.front().first,pq.front().second + pq.front().first));
            pq.push(Pair(pq.front().second + pq.front().first,pq.front().second));
            pq.pop();
        }
    }
    printf("NO\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i =0; i<t;i++)
    {
        solve();
    }

    return 0;
}
