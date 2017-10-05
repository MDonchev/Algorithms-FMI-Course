#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

bool used[100001];
std::queue<std::pair<int,int>> q;
int s,e;
int n;
void solve()
{
    memset(used,0,sizeof(used));
    scanf("%d", &s);
    scanf("%d", &e);
    scanf("%d", &n);
    int help;
    for (int i = 0 ; i < n; i++)
    {
        scanf("%d", &help);
        used[help] = true;
    }
    q.push(std::make_pair(s,0));

    while(!q.empty())
    {
        int p = q.front().first;
        int l = q.front().second;
        q.pop();
        if (p == e)
        {
            printf("%d\n",l);
            return;
        }
        if (used[p])
        {
            //std::cout<<"IF"<<std::endl;
            continue;
        }

        used[p] = true;

        for(int i = 10000 ; i>=1; i/=10)
        {
            int f = (p/i == 0) ? 9 : (p/i - 1) % 10;
            int neighbour = (p/(i*10))*(i*10) + f*i + p%i;
            if(!used[neighbour])
            {
                q.push(std::make_pair(neighbour,l + 1));
            }
        }

        for(int i = 10000 ; i>=1; i/=10)
        {
            int f = (p/i == 9) ? 0 : (p/i + 1) % 10;
            int neighbour = (p/(i*10))*(i*10) + f*i + p%i;
            if(!used[neighbour])
            {
                q.push(std::make_pair(neighbour,l + 1));
            }
        }
    }
    printf("-1\n");
}
int main()
{
    solve();
    return 0;
}
