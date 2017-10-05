#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using lli = long long int;
using namespace std;

struct State
{
    int to;
    lli len;
    State(int _to, lli _len) : to(_to), len(_len){}
    bool operator<(const State &s) const
    {
        return len > s.len;
    }
};
int t;
vector<State> graph[30001];
int n;
int m;
int k;
lli c;
lli dist[30001];
bool used[30001];

void dijkstra(int start)
{
    priority_queue<State> pq;

    memset(dist,63,sizeof(dist));
    memset(used,0,sizeof(used));

    pq.push(State(start,0));
    dist[start] = 0;
    while(!pq.empty())
    {
        int v = pq.top().to;
        pq.pop();

        if(used[v]) continue;
        used[v] = true;
        for( int i = 0; i < graph[v].size(); i++ )
        {
            int to = graph[v][i].to;
            int len = graph[v][i].len;

            if( !used[to] && dist[to] > dist[v] + len )
            {
                dist[to] = dist[v] + len;
                pq.push(State(to, dist[to]));
            }
        }
    }
    if((c - dist[n-1]) >= 0) printf("YES\n");
    else printf("NO\n");

}

void input()
{
    scanf("%d",&t);
    for(int i = 0; i<t;i++)
    {
        int x,y,h;
        scanf("%d %d %d %lld", &n,&m,&k,&c);
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d",&x,&y,&h);
            int help = k - h;
            if(help <= 0)
            {
                graph[x].push_back(State(y,0));
                graph[y].push_back(State(x,0));
            }
            else
            {
                lli lenHelp = (lli)(help*help + help);
                graph[x].push_back(State(y,lenHelp));
                graph[y].push_back(State(x,lenHelp));
            }
        }
        dijkstra(0);
        for(int i = 0; i<n;i++)
            graph[i].clear();
    }
}
int main()
{
    input();
    return 0;
}
